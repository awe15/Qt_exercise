#pragma once
#include <qobject.h>
#include <QWebEnginePage>

//refer:https://www.jianshu.com/p/e25646ee2977

class JsRespon :
	public QObject
{
	Q_OBJECT
public:
	explicit  JsRespon(QObject *parent);
	~JsRespon();

signals:
	void sign_func1( QString );
	void sign_sendImg(QByteArray);

public:
	// ����
	void sendMsg(QWebEnginePage* page, const QString& msg);



public slots:
	// ����
	void onRecvFunc1(const QString& msg, const QString para);
	void onRecvFunc2(const QByteArray &byte);
};

