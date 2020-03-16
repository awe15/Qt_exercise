#include "JsRespon.h"



JsRespon::JsRespon(QObject *parent) : QObject(parent)
{

}


JsRespon::~JsRespon()
{

}


void JsRespon::onRecvFunc1(const QString &msg, const QString para)
{
	if (msg == "func1")
		emit sign_func1(para);
}

void JsRespon::onRecvFunc2(const QByteArray &byte)
{
	emit sign_sendImg(byte);
}


void JsRespon::sendMsg(QWebEnginePage* page, const QString& msg)
{ 
	page->runJavaScript(QString("recvMessage('%1');").arg(msg)); 
} 



