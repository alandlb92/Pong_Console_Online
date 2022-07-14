#include "EchoWebsocket.h"
void EchoWebsocket::run()
{
	ws.async_accept([this](beast::error_code err) {
		if (err) {
			std::cout << err.message() << std::endl;
		}

		canSendAndReceiveData = true;
		echo();
	});
}

void EchoWebsocket::echo()
{
	ws.async_read(buffer, [this](beast::error_code err, std::size_t bytes_transferred)
	{
		if (err == websocket::error::closed) return;
		if (err) { std::cout << err.message() << std::endl; return; };

		auto out = beast::buffers_to_string(buffer.cdata());
		std::cout << out << std::endl << std::endl;
		echo();
	});
}

void EchoWebsocket::sendMesage(std::string msg)
{		
	if(canSendAndReceiveData)
		ws.write(boost::asio::buffer(msg));	
}