#include "WebEngineTest.h"

WebEngineTest::WebEngineTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_pJsContext = new JsRespon(this);
	m_pWebChannel = new QWebChannel(this);
	m_pWebChannel->registerObject("context_qt", m_pJsContext); 
	ui.webEngineView->page()->setWebChannel(m_pWebChannel);


	QNetworkProxyFactory::setUseSystemConfiguration(false);

//	connect(ui.webEngineView, SIGNAL(loadFinished(bool)), this, SLOT(loadFinished(bool)));
	connect(ui.load_btn, SIGNAL(clicked()), this, SLOT(on_loadBtn_clicked()));
	connect(ui.sendData_btn, SIGNAL(clicked()), this, SLOT(on_sendDataBtn_clicked()));
	connect(ui.openHtml_btn, SIGNAL(clicked()), this, SLOT(on_openHtml_clicked()));


	connect(m_pJsContext, SIGNAL(sign_func1(QString)), this, SLOT(call_func1(QString)));
	connect(m_pJsContext, SIGNAL(sign_sendImg(QByteArray)), this, SLOT(show_image(QByteArray)));
}


void WebEngineTest::on_loadBtn_clicked()
{
	if (!m_urlPath.isEmpty())
		ui.webEngineView->load(QUrl(m_urlPath));
}


void WebEngineTest::on_sendDataBtn_clicked()
{
	m_pJsContext->sendMsg(ui.webEngineView->page(), "test");

}

void WebEngineTest::on_openHtml_clicked()
{
	QString fileName = QFileDialog::getOpenFileName(this, 
		("open html file"), "./", "(*.html)");
	if (fileName != NULL)
	{
		m_urlPath = fileName;
		ui.path_lEdit->setText(m_urlPath);
	}
}



void WebEngineTest::load_pic()
{

}


void WebEngineTest::call_func1(QString str)
{
	m_pJsContext->sendMsg(ui.webEngineView->page(), "HELLO");
}


void WebEngineTest::show_image(QByteArray data)
{
	QPixmap pixmap;
	int pos = data.indexOf("base64,")+sizeof("base64");
	data = data.mid(pos);
	pixmap.loadFromData(QByteArray::fromBase64(data));
	ui.img_lb->setPixmap(pixmap);
}