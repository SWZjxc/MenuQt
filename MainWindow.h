#pragma once

#include <QMainWindow>
#include <QDialog>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QTextEdit>
#include <QMessageBox>


class MainWindow  :public QMainWindow
{
	Q_OBJECT

public:

	MainWindow(QWidget *parent = nullptr);
	~MainWindow();
private:
	void Open_Clicked();
	QStatusBar* stbar = statusBar();
};
