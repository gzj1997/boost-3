// boost-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <string>
#include <sstream>
#include<fstream>
using namespace std;
//void TestPointerArchive();
//std::stringstream ss;
//std::stringstream ss1;
//void save1()
//{
//	boost::archive::text_oarchive oa(ss);
//	boost::archive::text_oarchive oa2(ss1);
//	person *p = new developer(31, "C++");
//	person *p2 = new developer2(32, "C+2+");
//	oa << p << p2;
//	oa2 << p2;
//	delete p2;
//	delete p;
//}
//
//void load1()
//{
//	boost::archive::text_iarchive ia(ss);
//	boost::archive::text_iarchive ia2(ss1);
//	person *p;
//	person *p2;
//	person *p3;
//
//	ia >> p;
//	ia >> p3;
//	ia2 >> p2;
//	std::cout << p->kk() << std::endl;
//	std::cout << p3->kk() << std::endl;
//	std::cout << p2->kk() << std::endl;
//	delete p;
//	delete p2;
//}

void save()
{
	std::ofstream file("archiv.txt");
	boost::archive::text_oarchive oa(file);
	//tperson p(31);
	list<person *>* kk;
	kk =  new list<person *>();
	person *p = new developer(32, "C++");
	person *p2 = new developer2(31, "C++");
	kk->push_back(p);
	kk->push_back(p2);
	oa << kk;
	delete p;
	delete p2;
	delete kk;

}

void load()
{
	std::ifstream file("archiv.txt");
	boost::archive::text_iarchive ia(file);
	int i = 0;
	list<person *>* kk;
	kk = new list<person *>();
	//person *p;
	ia >> kk;
	
	for each (person*p in *kk)
	{
		std::cout << p->age();
		//std::cout << p->age() << std::endl;
	}
	//delete p;

	/*tperson p;
	ia >> p;
	std::cout << p.age() << std::endl;*/
	std::cin >> i;
}

int main()
{

	save();
	load();
	//list<person *> listp;
	//list<person *> listp2;
	//std::ofstream file("archiv.txt");
	//boost::archive::text_oarchive oa(file);
	//listp = *new list<person *>();
	//listp2 = *new list<person *>();
	//person *p = new developer(31, "C++");
	//person *p2 = new developer2(32, "C+2+");



	//test *tt = new test();
	//tt->sss = 99;

	//pal *pal2 = new pal();
	//pal2->bb = 111;
	//pal2->kk = 112;
	//pal2->test1 = tt->cloner();


	//pal *pal3 = pal2->cloner();
	//pal3->kk = 113;
//	p->pal1 = *pal2;
//	p2->pal1 = *pal3;


	//listp.push_back(p);
	//listp.push_back(p2);
	//oa << listp;


	//std::ifstream file2("archiv.txt");
	//boost::archive::text_iarchive ia(file2);

	//ia >> listp2;

	//for each (person*p in listp2)
	//{
	//	std::cout << p->kk() << "   " <<std::endl;
	//}
}
