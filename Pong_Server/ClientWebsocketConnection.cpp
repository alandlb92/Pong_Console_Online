#include "ClientWebsocketConnection.h"

void ClientWebsocketConnection::run()
{
	ws.binary(true);
	ws.async_accept([this](beast::error_code err) {
		if (err) {
			std::cout << err.message() << std::endl;
		}
		canSendAndReceiveData = true;
		echo();
		});
}

void ClientWebsocketConnection::echo()
{
	if (canSendAndReceiveData)
		ws.async_read(buffer, [this](beast::error_code err, std::size_t bytes_transferred)
			{
				if (err == websocket::error::closed) return;
				if (err) { std::cout << err.message() << std::endl; return; };

				bool logClientStart = false;
				if (_data.Name == "")
					logClientStart = true;

				auto out = beast::buffers_to_string(buffer.cdata());
				std::stringstream ss;
				ss << out;
				text_iarchive ia { ss };
				ia >> _data;

				if (logClientStart)
					std::cout << _data.Name << " has connected" << std::endl << std::endl;

				OnReceiveData(_data, id);
				buffer.clear();
				echo();
			});
}

void ClientWebsocketConnection::sendMesage(std::string serializedData)
{
	if (canSendAndReceiveData) 
	{
		if (ws.is_open())
		{
			boost::beast::error_code err;
			ws.write(boost::asio::buffer(serializedData), err);
		}
		else {
			OnDisconectClient(this);
		}
	}
}