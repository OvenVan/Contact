// MainVewMenuInterface.cpp: implementation of the MainVewMenuInterface class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainVewMenuInterface.h"

void sleep(){
	Sleep(20);
	return;
}

int MainVewMenuInterface::view(Person* v_Person) const{
	if (v_Person == NULL)
		return -1;
	bool refresh = true;
	string addr = ".\\contact\\";
	int fuckin_stupid = 0;
	int slct_num = 0;
	do{
		print_prsn(*v_Person,"=====VIEW Contact====================\n",refresh);
		if (refresh){
			readFile(".\\io\\View.io",sleep);
		}
		else{
			readFile(".\\io\\View.io");
		}
		cin.clear();
		cin.sync();
		if (fuckin_stupid != 0)
			cout<<"\t\tError Inputing!\n";
		cout<<"\tEnter number[1-3] to select the corresponding function: ";
		cin.clear();
		cin.sync();
		slct_num = getch();
		fuckin_stupid++;
		refresh = false;
	}while((slct_num<'1') || (slct_num>'3'));
			
	switch (slct_num){
	case '1':
		delete_prsn(*v_Person);
		cin.clear();
		cin.sync();
		getch();
		break;
	case '2':
		modify_prsn(*v_Person);
		cin.clear();
		cin.sync();
		getch();
		break;
	case '3':
		break;
	}
	return 0;
}

int MainVewMenuInterface::doMainStrategy()
{
	int fuckin_stupid = 0;
	char slct_num = 0;
	do{
		system("cls");
		readFile(".\\io\\ViewMenu.io");

		if (fuckin_stupid != 0)
			cout<<"\t\tError Inputing!\n";
		cout<<"\tEnter number[1-5] to select the corresponding function: ";
		
		cin.clear();
		cin.sync();
		slct_num = getch();
		fuckin_stupid++;
	}while((slct_num<'1') || (slct_num>'5'));

	viewStrategy = setViewStrategy(slct_num - '0');
	if (viewStrategy == NULL)
		return -1;
	view(viewStrategy->doViewStrategy());
	removeViewStrategy(viewStrategy);
	return 0;
}
			
