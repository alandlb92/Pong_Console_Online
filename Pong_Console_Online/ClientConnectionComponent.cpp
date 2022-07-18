#include "ClientConnectionComponent.h"

ClientConnectionComponent::ClientConnectionComponent(std::string serverURL)
{
	resolver = tcp::resolver{ioc};
	ws = websocket::stream<tcp::socket>{ resolver };
}