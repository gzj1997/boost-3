#include "stdafx.h"

person::person(int age) : age_(age)
{
}

developer::developer(int age, const std::string & language)
	: person(age), language_(language)
{
}

int developer::age()
{

	return 199;

}

std::string developer::language() const
{
	return language_;
}

developer2::developer2(int age, const std::string & language)
	: person(age), language_(language)
{
}

int developer2::age()
{

	return 192;

}

std::string developer2::language() const
{
	return language_;
}
BOOST_CLASS_EXPORT(developer)
BOOST_CLASS_EXPORT(developer2)