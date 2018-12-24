#include <boost/archive/text_oarchive.hpp> 
#include <boost/archive/text_iarchive.hpp> 
#include <boost/serialization/string.hpp> 
#include <boost/serialization/export.hpp> 
#include <boost/serialization/list.hpp> 
#include <iostream> 
#include <sstream> 
#include <string> 

std::stringstream ss;

class person
{
public:
	person()
	{
	}

	person(int age);


	virtual int age() = 0;

private:
	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & age_;
	}

	int age_;
};

class developer
	: public person
{
public:
	developer()
	{
	}

	developer(int age, const std::string &language);

	virtual int age();
	std::string language() const;
	

private:
	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<person>(*this);
		ar & language_;
	}

	std::string language_;
};


class developer2
	: public person
{
public:
	developer2()
	{
	}

	developer2(int age, const std::string &language);
		
	virtual int age();
	std::string language() const;


private:
	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & boost::serialization::base_object<person>(*this);
		ar & language_;
	}

	std::string language_;
};

