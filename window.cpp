
#include	<QtGui>
#include	<QtOpenGL>
#include	<QFileDialog>
#include	<QString>
#include	<stdio.h>
#include	"glwidget.h"
#include	"window.h"

Window::Window(){
	
	centralWidget	=	new QWidget;
	setCentralWidget(centralWidget);

	glWidget	=	new GLWidget;

	labelNumPart	=	new QLabel(tr("Particle Number:"));
	displayNumPart	=	new QLineEdit("0");
	displayNumPart->setReadOnly(true);
	displayNumPart->setAlignment(Qt::AlignRight);
	displayNumPart->setFixedWidth(80);

	labelRedshift	=	new QLabel(tr("Redshift:"));
	displayRedshift	=	new QLineEdit("0");
	displayRedshift->setReadOnly(true);
	displayRedshift->setAlignment(Qt::AlignRight);
	displayRedshift->setFixedWidth(80);

	labelBoxSize	=	new QLabel(tr("Box Size(kpc/h):"));
	displayBoxSize	=	new QLineEdit("0");
	displayBoxSize->setReadOnly(true);
	displayBoxSize->setAlignment(Qt::AlignRight);
	displayBoxSize->setFixedWidth(80);
	
	labelOmega0	=	new QLabel(tr("Omega0:"));
	displayOmega0	=	new QLineEdit("0");
	displayOmega0->setReadOnly(true);
	displayOmega0->setAlignment(Qt::AlignRight);
	displayOmega0->setFixedWidth(80);
	
	labelOmegaL	=	new QLabel(tr("OmegaL:"));
	displayOmegaL	=	new QLineEdit("0");
	displayOmegaL->setReadOnly(true);
	displayOmegaL->setAlignment(Qt::AlignRight);
	displayOmegaL->setFixedWidth(80);
	
	labelHubble	=	new QLabel(tr("Hubble:"));
	displayHubble	=	new QLineEdit("0");
	displayHubble->setReadOnly(true);
	displayHubble->setAlignment(Qt::AlignRight);
	displayHubble->setFixedWidth(80);

	QGroupBox *	gridGroupBox	=	new QGroupBox(tr("parameters"));
	QGridLayout *	layout		=	new QGridLayout;

	layout->addWidget(labelNumPart, 0, 0);
	layout->addWidget(displayNumPart, 0, 1);
	
	layout->addWidget(labelRedshift, 1, 0);
	layout->addWidget(displayRedshift, 1, 1);

	layout->addWidget(labelBoxSize, 2, 0);
	layout->addWidget(displayBoxSize, 2, 1);

	layout->addWidget(labelOmega0, 3, 0);
	layout->addWidget(displayOmega0, 3, 1);

	layout->addWidget(labelOmegaL, 4, 0);
	layout->addWidget(displayOmegaL, 4, 1);

	layout->addWidget(labelHubble, 5, 0);
	layout->addWidget(displayHubble, 5, 1);

	gridGroupBox->setLayout(layout);

	QHBoxLayout *	mainLayout	=	new QHBoxLayout;
	mainLayout->addWidget(glWidget);
	mainLayout->addWidget(gridGroupBox);
	mainLayout->setStretchFactor(glWidget, 1);

/*
	QString	filename;
	filename	=	QFileDialog::getOpenFileName(this,
						tr("Open Snapshot"), "/", tr("Snapshot files(*)"));

	printf("filename: %s\n", filename.data());
*/

	createActions();
	createMenus();

	centralWidget->setLayout(mainLayout);

	setWindowTitle(tr("SnapViewer"));
	
	connect(this, SIGNAL(fileOpened(char *)), 
			glWidget, SLOT(updateSnap(char *)));
	connect(glWidget, SIGNAL(infoChanged()), this, SLOT(updateInfo()));
}

void	Window::createActions(){
	openFileAct	=	new QAction(tr("&Open File"), this);
	openFileAct->setShortcut(tr("Ctrl+O"));
	connect(openFileAct, SIGNAL(triggered()), this, SLOT(openFile()));

	exitAct		=	new QAction(tr("E&xit"), this);
	exitAct->setShortcut(tr("Ctrl+Q"));
	connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

	aboutAct	=	new QAction(tr("&About"), this);
	connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}

void	Window::createMenus(){
	fileMenu	=	menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(openFileAct);
	fileMenu->addSeparator();
	fileMenu->addAction(exitAct);

	helpMenu	=	menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(aboutAct);
}

void	Window::openFile(){
	QString	fileName;
	fileName	=	QFileDialog::getOpenFileName(this,
						tr("Open Snapshot"), 
						"/home/liulei/program/N-body/Gadget-2.0.3/Gadget2/output_32", 
						tr("Snapshot files(*)"));
	snapName	=	fileName.toAscii().data();
	printf("filename: %s\n", snapName);
	emit fileOpened(snapName);
}

void	Window::about(){
	QMessageBox::about(this, tr("About SnapViewer"),
		tr("the SnapViewer shows the distribution of dark "
			"matter particles in a snapshot."));
}

void	Window::updateInfo(){
	
	float	redshift	=	glWidget->snap->Redshift;
	if(redshift < 0.00001){
		redshift	=	0;
	}
	
	displayNumPart->setText(QString::number(glWidget->snap->NumPart));
	displayRedshift->setText(QString::number(redshift));
	displayBoxSize->setText(QString::number(glWidget->snap->BoxSize));
	displayOmega0->setText(QString::number(glWidget->snap->Omega0));
	displayOmegaL->setText(QString::number(glWidget->snap->OmegaLambda));
	displayHubble->setText(QString::number(glWidget->snap->HubbleParam));
}
