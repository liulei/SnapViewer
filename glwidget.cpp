#include	<QtGui>
#include	<QKeyEvent>
#include	<QtOpenGL>
#include	<stdio.h>
#include	<math.h>
#include	"glwidget.h"

GLWidget::GLWidget(QWidget * parent) : QGLWidget(parent){
	object	=	0;
	xRot	=	0;
	yRot	=	0;
	zRot	=	0;
	lookAt.x	=	0.0;
	lookAt.y	=	0.0;
	lookAt.z	=	NEAR;
//	snap	=	new Snap;
//	snap->readSnap();
	
	isFocusChanged	=	false;
	isCtrl			=	false;
	isCenChanged	=	false;

	lastFocus.x	=	curFocus.x	=	0.0;
	lastFocus.y	=	curFocus.y	=	0.0;
	lastFocus.z	=	curFocus.z	=	-10.0;

	lastCen.x	=	curCen.x	=	BOXSIZE/2.0;
	lastCen.y	=	curCen.y	=	BOXSIZE/2.0;
	lastCen.z	=	curCen.z	=	BOXSIZE/2.0;
}

GLWidget::~GLWidget(){
}

void	GLWidget::initializeGL(){
	setFocusPolicy(Qt::ClickFocus);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0,0.0,0.0,0.0);
	glClearDepth(1.0);
//	object	=	makeObject();
//	delete snap;
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void	GLWidget::resizeGL(int width, int height){
	int	side	=	qMin(width, height);
	printf("side: %d\n", side);
	printf("width: %d\n", width);
	printf("height: %d\n", height);
//	glViewport((width-side)/2, (height-side)/2, side, side);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(35.0, width*1.0/height, 0.01, 20.0);				
	glMatrixMode(GL_MODELVIEW);
}

QSize	GLWidget::sizeHint() const{
	return	QSize(425, 425);
}

QSize	GLWidget::minimumSizeHint() const{
	return(QSize(50, 50));
}

GLuint	GLWidget::makeObject(){
	GLuint	list	=	glGenLists(1);
	glNewList(list, GL_COMPILE);

	glBegin(GL_LINES);
		glVertex3f( 0.0, 0.0, 0.0);
		glVertex3f( BOXSIZE, 0.0, 0.0);
		glVertex3f( 0.0, 0.0, 0.0);
		glVertex3f( 0.0, BOXSIZE, 0.0);
		glVertex3f( 0.0, 0.0, 0.0);
		glVertex3f( 0.0, 0.0, BOXSIZE);
	glEnd();

	glBegin(GL_POINTS);
		float	side;
		int		i;
		side	=	snap->BoxSize;
		glPointSize(0.2);
		for(i=1; i<=snap->NumPart; ++i){
			glVertex3f(snap->P[i].Pos[0]/side, 
						snap->P[i].Pos[1]/side,
						snap->P[i].Pos[2]/side);
		}
	glEnd();

	glEndList();
	return	list;
}

void	GLWidget::paintGL(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(lookAt.x, lookAt.y, lookAt.z,
				0.0, 0.0, -20.0,
				0.0, 1.0, 0.0);

	if(!isCtrl){
		setCenter();
	}else{
		setFocus();
	}

	lastRotX	=	xRot/16.0;
	lastRotY	=	yRot/16.0;
	lastRotZ	=	zRot/16.0;

	glTranslatef(curFocus.x, curFocus.y, curFocus.z);


	glRotated(xRot/16.0, 1.0, 0.0, 0.0);
	glRotated(yRot/16.0, 0.0, 1.0, 0.0);
	glRotated(zRot/16.0, 0.0, 0.0, 1.0);
	
	if(isCtrl){
		drawFocus();
	}

	glTranslatef(-curCen.x, -curCen.y, -curCen.z);
	if(object != 0){
		glCallList(object);
	
		glColor3f(1.0, 0.0, 0.0);
		float	dlen	=	0.1;
		glBegin(GL_LINES);
			glVertex3f(0.5, 0.5, 0.5);
			glVertex3f(0.5+dlen, 0.5, 0.5);
			glVertex3f(0.5, 0.5, 0.5);
			glVertex3f(0.5, 0.5+dlen, 0.5);
			glVertex3f(0.5, 0.5, 0.5);
			glVertex3f(0.5, 0.5, 0.5+dlen);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
	}
}

void	GLWidget::setXRotation(int angle){
	normalizeAngle(&angle);
	if(angle != xRot){
		xRot	=	angle;
		updateGL();
	}
}

void	GLWidget::setYRotation(int angle){
	normalizeAngle(&angle);
	if(angle != yRot){
		yRot	=	angle;
		updateGL();
	}
}

void	GLWidget::setZRotation(int angle){
	normalizeAngle(&angle);
	if(angle != zRot){
		zRot	=	angle;
		updateGL();
	}
}

void	GLWidget::mousePressEvent(QMouseEvent * event){
	lastPos	=	event->pos();
}

void	GLWidget::mouseMoveEvent(QMouseEvent * event){
	int	dx	=	event->x()-lastPos.x();
	int	dy	=	event->y()-lastPos.y();

	if(event->buttons() & Qt::LeftButton){
		setXRotation(xRot+8*dy);
		setYRotation(yRot+8*dx);
	}

	lastPos	=	event->pos();
}

void	GLWidget::keyPressEvent(QKeyEvent * event){
	float	delta	=	0.01;
	if(isCtrl){
		delta	*=	0.1;
	}
	switch(event->key()){
		case Qt::Key_Left:
			lookAt.x	-=	delta;
//			if(lookAt.x < -EDGE){
//				lookAt.x	=	-EDGE;
//			}
			isFocusChanged	=	true;
			updateGL();
			break;
		case Qt::Key_Right:
			lookAt.x	+=	delta;
//			if(lookAt.x > EDGE){
//				lookAt.x	=	EDGE;
//			}
			isFocusChanged	=	true;
			updateGL();
			break;
		case Qt::Key_Down:
			lookAt.y	-=	delta;
//			if(lookAt.y < -EDGE){
//				lookAt.y	=	-EDGE;
//			}
			isFocusChanged	=	true;
			updateGL();
			break;
		case Qt::Key_Up:
			lookAt.y	+=	delta;
//			if(lookAt.y > EDGE){
//				lookAt.y	=	EDGE;
//			}
			isFocusChanged	=	true;
			updateGL();
			break;
		case Qt::Key_Control:
			isCtrl	=	!isCtrl;
			updateGL();
			break;
	}
}

void	GLWidget::wheelEvent(QWheelEvent * e){
	float	delta	=	0.05;
	if(isCtrl){
		delta	*=0.1;
	}
	if(e->delta() < 0){
		lookAt.z	-=	delta;
		isFocusChanged	=	true;
	}else{
		lookAt.z	+=	delta;
		isFocusChanged	=	true;
	}
//	if(lookAt.z > NEAR){
//		lookAt.z	=	NEAR;
//	}
//	if(lookAt.z < FAR){
//		lookAt.z	=	FAR;
//	}
	updateGL();
}

void	GLWidget::normalizeAngle(int * angle){
	while(*angle < 0){
		*angle	+=	360*16;
	}
	while(*angle > 360*16){
		*angle	-=	360*16;
	}
}

void	GLWidget::xRotation(float angle, float * d){
/*	Note! In opengl, angle is in units of degree, while in c lib, it is 
 *	arc. Therefore, the first step of this function is to convert degree
 *	to arc.
 */
	angle	=	angle*M_PI/180.0;

	double	x,y,z;

	x	=	d[0];
	y	=	d[1];
	z	=	d[2];

	d[0]	=	x;
	d[1]	=	y*cos(angle)-z*sin(angle);
	d[2]	=	y*sin(angle)+z*cos(angle);
}

void	GLWidget::yRotation(float angle, float * d){

	angle	=	angle*M_PI/180.0;

	double	x,y,z;

	x	=	d[0];
	y	=	d[1];
	z	=	d[2];

	d[0]	=	x*cos(angle)+z*sin(angle);
	d[1]	=	y;
	d[2]	=	-x*sin(angle)+z*cos(angle);
}

void	GLWidget::zRotation(float angle, float * d){
}

int		GLWidget::setFocus(){

	if(!(isFocusChanged)){
		return(0);
	}
	isFocusChanged	=	false;
	isCenChanged	=	true;

	curFocus.x	=	lookAt.x;
	curFocus.y	=	lookAt.y;
	curFocus.z	=	lookAt.z-0.1;
	
	float	d[3];

	d[0]	=	curFocus.x-lastFocus.x;
	d[1]	=	curFocus.y-lastFocus.y;
	d[2]	=	curFocus.z-lastFocus.z;

	lastFocus.x	=	curFocus.x;
	lastFocus.y	=	curFocus.y;
	lastFocus.z	=	curFocus.z;

	xRotation(-lastRotX, d);
	yRotation(-lastRotY, d);
//	zRotation(-lastRotZ, d);

	curCen.x	=	lastCen.x+d[0];
	curCen.y	=	lastCen.y+d[1];
	curCen.z	=	lastCen.z+d[2];

	lastCen.x	=	curCen.x;
	lastCen.y	=	curCen.y;
	lastCen.z	=	curCen.z;

	return(0);
}

int		GLWidget::setCenter(){
	
	if(!isCenChanged){
		return(0);
	}
	isCenChanged	=	false;
	isFocusChanged	=	true;

	curCen.x	=	BOXSIZE/2.0;
	curCen.y	=	BOXSIZE/2.0;
	curCen.z	=	BOXSIZE/2.0;

	float	d[3];

	d[0]	=	curCen.x-lastCen.x;
	d[1]	=	curCen.y-lastCen.y;
	d[2]	=	curCen.z-lastCen.z;

	lastCen.x	=	curCen.x;
	lastCen.y	=	curCen.y;
	lastCen.z	=	curCen.z;

	yRotation(lastRotY, d);
	xRotation(lastRotX, d);

	curFocus.x	=	lastFocus.x+d[0];
	curFocus.y	=	lastFocus.y+d[1];
	curFocus.z	=	lastFocus.z+d[2];

	lastFocus.x	=	curFocus.x;
	lastFocus.y	=	curFocus.y;
	lastFocus.z	=	curFocus.z;

	return(0);
}

void	GLWidget::drawFocus(){
	
	float	hlen	=	0.005;
	
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINES);
		glVertex3f(-hlen, 0.0, 0.0);
		glVertex3f( hlen, 0.0, 0.0);
		glVertex3f(0.0, -hlen, 0.0);
		glVertex3f(0.0,  hlen, 0.0);
		glVertex3f(0.0, 0.0, -hlen);
		glVertex3f(0.0, 0.0,  hlen);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
}

void	GLWidget::updateSnap(char * snapName){
	if(object != 0){
		glDeleteLists(object, 1);
		object	=	0;
	}
	
	xRot	=	0;
	yRot	=	0;
	zRot	=	0;
	
	lookAt.x	=	0.0;
	lookAt.y	=	0.0;
	lookAt.z	=	NEAR;
	
	isFocusChanged	=	false;
	isCtrl			=	false;
	isCenChanged	=	false;

	lastFocus.x	=	curFocus.x	=	0.0;
	lastFocus.y	=	curFocus.y	=	0.0;
	lastFocus.z	=	curFocus.z	=	-10.0;

	lastCen.x	=	curCen.x	=	BOXSIZE/2.0;
	lastCen.y	=	curCen.y	=	BOXSIZE/2.0;
	lastCen.z	=	curCen.z	=	BOXSIZE/2.0;

	snap	=	new Snap;
	snap->readSnap(snapName);

	object	=	makeObject();	
	updateGL();

	emit infoChanged();
	delete snap;
}
