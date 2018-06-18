

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
		readFile(".\\io\\MainMenu.io");
		if (fuckin_stupid != 0)
			cout<<"\t\tError Inputing!\n";
		cout<<"\tEnter number[1-"<<MainFunctionsNum<<"] to select the corresponding function: ";
		cin.clear();
		cin.sync();
		rtn_int = getch();
		fuckin_stupid++;
	}while((rtn_int<'1') || (rtn_int>'0' + MainFunctionsNum));

	mainStrategy = setMainStrategy(rtn_int-'0');
	if (mainStrategy == NULL){
		return -1;
	}
	mainStrategy->doMainStrategy();
	removeMainStrategy(mainStrategy);
	return 0;
}
