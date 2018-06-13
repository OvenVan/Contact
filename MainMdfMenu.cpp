// MainMdfMenu.cpp: implementation of the MainMdfMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainMdfMenu.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MainMdfMenu::MainMdfMenu()
{

}

MainMdfMenu::~MainMdfMenu()
{

}

MainMdfMenu::doMainStrategy()
{
	int num = contact_item.size();
	int index = 0;
	char* c_item[8] = {"Name","Tel","Address","Gender:(M for Male, F for Female)","Zip","Mail","QQ","Category"};

	system("cls");
	cout<<endl;
	cout<<"=====Modify Contact====================\n\n";
	if (num > 1){
		printAll();
		cout<<"\n\tEnter the INDEX(1 - "<<num<<") of the information you want to MODIFY:(0 for quit) ";
		cin.clear();
		cin.sync();
		cin>>index;
		if ( (index<0) || (index>num) ){
			cout<<"\n\t\tError Input!\n";
			index = 0;
		}
	}
	else if ( num == 1)
		index = 1;
	if (index == 0)
		return 0;
	index--;

	modify_prsn(*contact_item.at(index));
	cin.clear();
	cin.sync();
	getch();
	return 0;
}