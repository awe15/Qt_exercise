#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_WebEngineTest.h"
#include <QNetworkProxyFactory>
#include <QWebEnginePage>
#include <QWebChannel>
#include <QFileDialog>
#include "JsRespon.h"


class WebEngineTest : public QMainWindow
{
	Q_OBJECT

public:
	WebEngineTest(QWidget *parent = Q_NULLPTR);

private:
	Ui::WebMarkTestClass ui;
	QWebChannel *m_pWebChannel;
	JsRespon *m_pJsContext;
	QString m_urlPath;

private slots:
	//button
	void on_loadBtn_clicked();
	void on_sendDataBtn_clicked();
	void on_openHtml_clicked();
	
	//test
	void call_func1(QString str);
	void show_image(QByteArray);
private:
	void load_pic();

};
