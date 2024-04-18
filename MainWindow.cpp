#include "MainWindow.h"
#include <QMenuBar>              //菜单栏
#include <QMenu>                //菜单
#include <QAction>             //菜单项
#include <QToolBar>           //工具栏
#include <QStatusBar>        //状态栏
#include <QDockWidget>      //浮动窗口
#include <QFileDialog>     //文件对话框
#include <QFontDialog>    //字体对话框
#include <QColorDialog>  //颜色对话框
#include <QLabel>
#include <QTextEdit>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
	resize(500,500);
	setStyleSheet("background-image:url(./Image/beijing.png)");
	QMenuBar* bar = menuBar();

	setMenuBar(bar);
	//创建菜单
	QMenu *file=bar->addMenu("File");
	QMenu* edit=bar->addMenu("Eidt");
	QMenu* view=bar->addMenu("View");
	QMenu* Help=bar->addMenu("Help");
	//创建菜单项目
	QAction * newaction = file->addAction("New");
	QAction* openaction = file->addAction("Open");
	//创建分隔符
	file->addSeparator();
	QAction* saveaction = file->addAction("Save");
	QAction* Copyaction = edit->addAction("Copy");
	QAction* Pasteaction = edit->addAction("Paste");
	edit->addSeparator();
	QAction* cutaction = edit->addAction("Cut");
	QAction* delaction = edit->addAction("Delete");
	QAction* toolaction = view->addAction("Tools");
	QAction* codeaction = view->addAction("Code");
	view->addSeparator();
	QAction* noticeaction = view->addAction("Notice");
	QAction* bookaction = Help->addAction("Open books window");
	QAction* aboutaction = Help->addAction("about this");
	//添加工具栏
	QToolBar* toolbar = new QToolBar(this);
	addToolBar(Qt::TopToolBarArea,toolbar);
	toolbar->setMovable(false);
	//工具栏内部可以设置相关内容
	toolbar->addAction(newaction);
	newaction->setIcon(QIcon("./Image/new.png"));
	toolbar->addAction(openaction);
	openaction->setIcon(QIcon("./Image/fileopen.png"));
	toolbar->addAction(saveaction);
	saveaction->setIcon(QIcon("./Image/save.png"));
	toolbar->addSeparator();
	toolbar->addAction(Copyaction);
	Copyaction->setIcon(QIcon("./Image/Copy.png"));
	toolbar->addAction(Pasteaction);
	Pasteaction->setIcon(QIcon("./Image/pa.png"));
	//状态栏
	//QStatusBar* stbar = statusBar();
	//设置到窗口中
	setStatusBar(stbar);
	//放置标签控件
	//QLabel* label = new QLabel("About",this);
	//stbar->addWidget(label);
	//铆接部件 
	QDockWidget* dockwidget = new QDockWidget("Text", this);
	addDockWidget(Qt::TopDockWidgetArea,dockwidget);
	//设置中心部件
	QTextEdit* textedit = new QTextEdit(dockwidget);
	setCentralWidget(this);
	//点击新建按钮弹出一个对话框
	connect(newaction, &QAction::triggered, []() {
		QDialog dia;
		dia.resize(500,500);
		QDockWidget* dockwidget2 = new QDockWidget("Text", &dia);
		QTextEdit* textedit2 = new QTextEdit(&dia);
		textedit2->resize(500, 500);
		dia.exec();
		});
	//点击打开按钮弹出文本对话框
	QObject::connect(openaction, &QAction::triggered, this, &MainWindow::Open_Clicked);
}


void MainWindow::Open_Clicked()
{
	QString filename = QFileDialog::getOpenFileName(this, "打开文件",
		"E:/QtTemplate/Temp_MSVC/MSVC_MenuLab", "haeder(*.h);;src(*.cpp)");
	QLabel* label = new QLabel(filename, this);
	stbar->addWidget(label);
}

MainWindow::~MainWindow()
{}
