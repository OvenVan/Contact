// MainStrategy.cpp: implementation of the MainStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainStrategy.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MainStrategy::MainStrategy()
{

}

MainStrategy::~MainStrategy()
{

}

void MainStrategy::print_prsn(const Person& prt_Person, const string info, bool refresh) const{
	system("cls");
	cout<<endl<<info;
	if(refresh) Sleep(20);
	cout<<"\n\tName:     "<<prt_Person.name;
	if(refresh) Sleep(20);
	cout<<"\n\tTel:      "<<prt_Person.tel;
	if(refresh) Sleep(20);
	cout<<"\n\tAddress:  "<<prt_Person.addr;
	if(refresh) Sleep(20);
	cout<<"\n\tGendle:   "<<prt_Person.sex ;
	if(refresh) Sleep(20);
	cout<<"\n\tZip:      "<<prt_Person.zip;
	if(refresh) Sleep(20);
	cout<<"\n\tMail:     "<<prt_Person.mail;
	if(refresh) Sleep(20);
	cout<<"\n\tQQ:       "<<prt_Person.qq;
	if(refresh) Sleep(20);
	cout<<"\n\tCategory: "<<prt_Person.category;
	if(refresh) Sleep(20);
}

void MainStrategy::printAll() const{
	int num = contact_item.size();

	for (int i = 0; i < num; i++){
		cout<<"("<<i+1<<"): "<<&*contact_item[i]->name<<"    TEL: "<<&*contact_item[i]->tel<<"    ADDR: "<<&*contact_item[i]->addr<<endl;
		Sleep(20);
	}
}