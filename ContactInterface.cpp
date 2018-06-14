

#include "stdafx.h"
#include "ContactInterface.h"

extern vector<Person*> contact_item;
extern string errorMsg;

int ContactInterface::main_menu(){
	char rtn_int;
	int fuckin_stupid = 0;
	cin.clear();
	cin.sync();
	do{
		system("cls");
		cout<<endl<<endl;
		cout<<"\t\t==========MAIN MENU===========\n\t\t|\n";
		cout<<"\t\t ---New____1------------------\n\t\t|\n";
		cout<<"\t\t ---Delete_2------------------\n\t\t|\n";
		cout<<"\t\t ---Modify_3------------------\n\t\t|\n";
		cout<<"\t\t ---View___4------------------\n\t\t|\n";
		cout<<"\t\t ---Quit___5------------------\n\n";

		if (fuckin_stupid != 0)
			cout<<"\t\tError Inputing!\n";
		cout<<"\tEnter number[1-5] to select the corresponding function: ";
		
		cin.clear();
		cin.sync();
		rtn_int = getch();
		fuckin_stupid++;
	}while((rtn_int<'1') || (rtn_int>'5'));

	mainStrategy = setMainStrategy(rtn_int-'0');
	if (mainStrategy == NULL)
		return -1;
	mainStrategy->doMainStrategy();
	removeMainStrategy(mainStrategy);
	return 0;
}
