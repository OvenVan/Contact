// MainDelMenu.cpp: implementation of the MainDelMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDelMenu.h"

MainDelMenu::doMainStrategy()
{
	int num = contact_item.size();
	int index = 0;
	string addr = ".\\contact\\";
	system("cls");
	cout<<endl;
	cout<<"=====Delete Contact====================\n\n";
	if (num > 1){
		printAll();
		cout<<"\n\tEnter the INDEX(1 - "<<num<<") of the information you want to DELETE:(0 for quit) ";
		cin.clear();
		cin.sync();
		cin>>index;
		if ((index<0) || (index>num)){
			cout<<"\n\n\t\tError Input!\n";
			index = 0;
		}
	}
	else if ( num == 1)
		index = 1;
	if (index == 0)
		return 0;
	index--;
	print_prsn(*contact_item[index],"=====Delete Contact====================\n",true);
	delete_prsn(*contact_item[index]);
	cin.clear();
	cin.sync();
	getchar();
	return 0;	
}