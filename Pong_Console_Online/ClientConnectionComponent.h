#pragma once
#include "Component.h"
#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include "ClientData.h"
#include "ServerData.h"
#include <boost/archive/text_oarchive.hpp>
#include "InputState.h"

namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>
using namespace boost::archive;

class ClientConnectionComponent : public Component
{
public:
	typedef Component super;
	ClientConnectionComponent(std::string serverIp, int port);
	virtual void Start() override;
	virtual void Update(double deltaTime) override;
	void ReaderThread();
	void SetUpClientData(std::string name);
	void SetPlayerInput(InputState inputState);

	std::function<void(ServerData)> OnReceiveData;

private:
	void WriteData();
	ClientData _clientData;
	ServerData _data;

	std::thread* _readerThread;
	std::string dataTest;
	net::io_context ioc;
	tcp::resolver resolver { ioc };

	websocket::stream<tcp::socket> ws{ ioc};

};

