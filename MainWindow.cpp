#include "MainWindow.h"
#include <QMenuBar>              //�˵���
#include <QMenu>                //�˵�
#include <QAction>             //�˵���
#include <QToolBar>           //������
#include <QStatusBar>        //״̬��
#include <QDockWidget>      //��������
#include <QFileDialog>     //�ļ��Ի���
#include <QFontDialog>    //����Ի���
#include <QColorDialog>  //��ɫ�Ի���
#include <QLabel>
#include <QTextEdit>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
	resize(500,500);
	setStyleSheet("background-image:url(./Image/beijing.png)");
	QMenuBar* bar = menuBar();

	setMenuBar(bar);
	//�����˵�
	QMenu *file=bar->addMenu("File");
	QMenu* edit=bar->addMenu("Eidt");
	QMenu* view=bar->addMenu("View");
	QMenu* Help=bar->addMenu("Help");
	//�����˵���Ŀ
	QAction * newaction = file->addAction("New");
	QAction* openaction = file->addAction("Open");
	//�����ָ���
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
	//��ӹ�����
	QToolBar* toolbar = new QToolBar(this);
	addToolBar(Qt::TopToolBarArea,toolbar);
	toolbar->setMovable(false);
	//�������ڲ����������������
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
	//״̬��
	//QStatusBar* stbar = statusBar();
	//���õ�������
	setStatusBar(stbar);
	//���ñ�ǩ�ؼ�
	//QLabel* label = new QLabel("About",this);
	//stbar->addWidget(label);
	//í�Ӳ��� 
	QDockWidget* dockwidget = new QDockWidget("Text", this);
	addDockWidget(Qt::TopDockWidgetArea,dockwidget);
	//�������Ĳ���
	QTextEdit* textedit = new QTextEdit(dockwidget);
	setCentralWidget(this);
	//����½���ť����һ���Ի���
	connect(newaction, &QAction::triggered, []() {
		QDialog dia;
		dia.resize(500,500);
		QDockWidget* dockwidget2 = new QDockWidget("Text", &dia);
		QTextEdit* textedit2 = new QTextEdit(&dia);
		textedit2->resize(500, 500);
		dia.exec();
		});
	//����򿪰�ť�����ı��Ի���
	QObject::connect(openaction, &QAction::triggered, this, &MainWindow::Open_Clicked);
}


void MainWindow::Open_Clicked()
{
	QString filename = QFileDialog::getOpenFileName(this, "���ļ�",
		"E:/QtTemplate/Temp_MSVC/MSVC_MenuLab", "haeder(*.h);;src(*.cpp)");
	QLabel* label = new QLabel(filename, this);
	stbar->addWidget(label);
}

MainWindow::~MainWindow()
{}
