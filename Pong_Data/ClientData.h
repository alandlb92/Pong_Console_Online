#pragma once
#include <iostream>
#include "ClientState.h"
#include "InputState.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>

class ClientData
{
public:
	std::string Name;
	ClientState State;
	InputState InputState;
private:
	friend class boost::serialization::access;

	template<typename Archive>
	friend void serialize(Archive& ar, ClientData& a, const unsigned int version)
	{
		ar& a.Name;
		ar& a.State;
		ar& a.State;
	}
};


