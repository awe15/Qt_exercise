var context_qt;
// 初始化
function init_qt()
{
    if (typeof qt != 'undefined')
    {
        new QWebChannel(qt.webChannelTransport, 
		function(channel){
            context_qt = channel.objects.context_qt;  //从通道中获取交互对象
        })
    }
    else
        console.log("qt object obtain fail!");
}

// 发送消息
function run_func1(msg, para)
{
    if(typeof context_qt == 'undefined')
        console.log("context_qt object obtain fail!");
    else
        context_qt.onRecvFunc1(msg, para);  //调用交互对象接口，接收消息
}

function run_func2(data)
{
	if(typeof context_qt == 'undefined')
        console.log("context_qt object obtain fail!");
    else
        context_qt.onRecvFunc2(data);  //调用交互对象接口，接收消息
}


function recvMessage(msg)
{
	document.getElementById("demo").innerHTML = msg;
    alert("接收到Qt发送的消息：" + msg);
}

var image = '';	
function selectImage(file) { 

	if (!file.files || !file.files[0]) {
		return;
	}

	var reader = new FileReader();
	//reader.readAsBinaryString(file.files[0]);
	reader.onload = function (evt) {
		document.getElementById('pic').src = evt.target.result;
		//image = evt.target.result;
		image = reader.result;
		run_func2(image);	
	}
	reader.readAsDataURL(file.files[0]);
	
}





init_qt();