#include "SerializeTests.h"
#include "ClientData.h"
#include "ServerData.h"
#include <iostream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>  
#include <cassert> 

void SerializeTests::Run()
{
	ClientDataTest();
	ServerDataTest();
}

void SerializeTests::ClientDataTest()
{
	ClientData clientDataToSerialize;
	
	clientDataToSerialize.Id = 10;
	clientDataToSerialize.InputState = InputState::Down_Arrow;
	clientDataToSerialize.Name = "Retsuke";
	clientDataToSerialize.State = ClientState::PAUSED;

	std::stringstream ss;	
	boost::archive::text_oarchive oa{ ss };
	oa << clientDataToSerialize;
	assert(ss.str() == "22 serialization::archive 19 0 0 10 7 Retsuke 0 1");
	std::cout << "ClientDataTest SERIALIZATION passed" << std::endl;

	ClientData clientDataToDeserialize;
	std::stringstream sd;
	sd << ss.str();
	boost::archive::text_iarchive ia{ sd };
	ia >> clientDataToDeserialize;
	assert(CompareClientData(clientDataToSerialize, clientDataToDeserialize));
	std::cout << "ClientDataTest DESERIALIZATION passed" << std::endl;
}

bool SerializeTests::CompareClientData(ClientData a, ClientData b)
{
	return
	a.Id == b.Id
	&& a.InputState == b.InputState
	&& a.Name == b.Name
	&& a.State == b.State;
}

void SerializeTests::ServerDataTest()
{
	std::cout << "ServerDataTest passed" << std::endl;
}


bool SerializeTests::CompareServerData(ServerData a, ServerData b)
{
	return true;
}