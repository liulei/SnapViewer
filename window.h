
#include	<QMainWindow>
//#include	<QWidget>

class	GLWidget;
class	QLabel;
class	QLineEdit;
class	QMenu;
class	QAction;

class	Window : public QMainWindow{
	Q_OBJECT

public:
	Window();

signals:
	void	fileOpened(char * newSnap);

private slots:
	void	openFile();
	void	about();
	void	updateInfo();

private:
	char *	snapName;

	void	createActions();
	void	createMenus();

	QWidget *	centralWidget;
	GLWidget *	glWidget;
	
	QLabel *	labelNumPart;
	QLineEdit *	displayNumPart;
	
	QLabel *	labelRedshift;
	QLineEdit *	displayRedshift;
	
	QLabel *	labelBoxSize;
	QLineEdit *	displayBoxSize;

	QLabel *	labelOmega0;
	QLineEdit *	displayOmega0;

	QLabel *	labelOmegaL;
	QLineEdit *	displayOmegaL;

	QLabel *	labelHubble;
	QLineEdit *	displayHubble;	

	QMenu *		fileMenu;
	QMenu *		helpMenu;

	QAction *	openFileAct;
	QAction *	exitAct;
	QAction *	aboutAct;
};

