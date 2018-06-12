// MainNewMenu.cpp: implementation of the MainNewMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainNewMenu.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MainNewMenu::MainNewMenu()
{

}

MainNewMenu::~MainNewMenu()
{

}

MainNewMenu::doMainStrategy()
{
	system("cls");
	cout<<endl;
	cout<<"=====New Contact====================\n\n";
	if(!create())
		cout<<"\n\n\t\tInfomation Error!";
	else
		cout<<"\n\n\t\tInfomation Entry Success!";
	cin.clear();
	cin.sync();
	getchar();
	return 0;
}