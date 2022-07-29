#pragma once
#include <iostream>
#include "ClientState.h"
#include "InputState.h"
#include "IdHelper.h"
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/string.hpp>

class ClientData
{
public:
	int Id;
	std::string Name;
	ClientState State;
	InputState InputState;
	ClientData() : Id(IdHelper::GetNewId()), Name(""), State(ClientState::PLAYING), InputState(InputState::Idle) {}
private:
	friend class boost::serialization::access;

	template<typename Archive>
	friend void serialize(Archive& ar, ClientData& a, const unsigned int version)
	{
		ar& a.Id;
		ar& a.Name;
		ar& a.State;
		ar& a.State;
	}
};


