
#include	<QtOpenGL>
#include	<QFrame>
#include	"snap.h"

#define		WINSIZE	1.2
#define		BOXSIZE	1.0	
#define		NEAR	-7.0
#define		FAR		-12.0
#define		EDGE	0.5

class Position{

public:
	float	x;
	float	y;
	float	z;
};

class GLWidget : public QGLWidget{
	
	Q_OBJECT

public:
	GLWidget(QWidget * parent = 0);
	~GLWidget();
	QSize	sizeHint() const;
	QSize	minimumSizeHint() const;

	Snap *	snap;

	bool	isFocusChanged;
	bool	isCenChanged;
	bool	isCtrl;

signals:
	void	infoChanged();

public slots:
	void	setXRotation(int angle);
	void	setYRotation(int angle);
	void	setZRotation(int angle);

	void	updateSnap(char * snapName);

protected:
	void	initializeGL();
	void	paintGL();
	void	resizeGL(int width, int height);
	void	mousePressEvent(QMouseEvent * event);
	void	mouseMoveEvent(QMouseEvent * event);
	void	wheelEvent(QWheelEvent * e);
	void	keyPressEvent(QKeyEvent * e);

private:
	GLuint	makeObject();
	void	normalizeAngle(int *angle);
	void	xRotation(float angle, float * d);
	void	yRotation(float angle, float * d);
	void	zRotation(float angle, float * d);
	int		setFocus();
	int		setCenter();
	void	drawFocus();

	GLuint	object;
	
	int		xRot;
	int		yRot;
	int		zRot;
	
	QPoint	lastPos;
	
/*	viewport frame:
 */
	Position	lookAt;
	Position	lastFocus;
	Position	curFocus;

/*	data frame(without rotation and translation):
 */
	Position	lastCen;
	Position	curCen;

	float	lastRotX;
	float	lastRotY;
	float	lastRotZ;
};
