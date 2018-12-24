#pragma once
#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 
#include <iostream> 
#include <sstream> 


class tperson
{
public:
	tperson()
	{
	}

	tperson(int age)
		: age_(age)
	{
	}

	int age() const
	{
		return age_;
	}

private:
	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & age_;
	}

	int age_;
};
