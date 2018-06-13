// MainVewMenuInterface.cpp: implementation of the MainVewMenuInterface class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainVewMenuInterface.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MainVewMenuInterface::MainVewMenuInterface()
{

}

MainVewMenuInterface::~MainVewMenuInterface()
{

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
		cout<<endl<<endl;	
		cout<<" ====Options=======\n|\n";
		if(refresh) Sleep(20);				
		cout<<" -------Delete_1---\n|\n";
		if(refresh) Sleep(20);
		cout<<" -------Modify_2---\n|\n";	
		if(refresh) Sleep(20);
		cout<<" -------Back___3---\n\n";
		if(refresh) Sleep(20);				
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
		cout<<endl;
		cout<<"\t\t==========VIEW CONTACT========\n\t\t|\n";
		cout<<"\t\t ---********------------------\n\t\t|\n";
		cout<<"\t\t ---********------------------\n\t\t|\n";
		cout<<"\t\t ---********------------------\n\t\t|\n";
		cout<<"\t\t ---View___*------------------\n\t\t|  |\n";
		cout<<"\t\t    -----Exact query__1-------\n\t\t|  |\n";
		cout<<"\t\t    -----Fuzzy query__2-------\n\t\t|  |\n";
		cout<<"\t\t    -----Category_____3-------\n\t\t|  |\n";
		cout<<"\t\t    -----All__________4-------\n\t\t|  |\n";
		cout<<"\t\t    -----Back_________5-------\n\t\t|   \n";

		cout<<"\t\t ---********------------------\n\n";

		if (fuckin_stupid != 0)
			cout<<"\t\tError Inputing!\n";
		cout<<"\tEnter number[1-5] to select the corresponding function: ";
		
		cin.clear();
		cin.sync();
		slct_num = getch();
		fuckin_stupid++;
	}while((slct_num<'1') || (slct_num>'5'));

	viewStrategy = setViewStrategy(slct_num);
	if (viewStrategy == NULL)
		return -1;
	
	view(viewStrategy->doViewStrategy());
	return 0;
}
			
