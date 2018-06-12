

#include "stdafx.h"
#include "Contact.h"

int main_menu();

extern vector<Person*> contact_item;

int main(int argc, char* argv[])
{
	Contact* my_contact = new Contact();

	ContactInterface* my_interface = my_contact;
	ContactInit* my_init = my_contact;
	my_init->welcome();

	while(1){
		my_init->refresh();
		switch (main_menu()){
		case 1:
			my_interface->new_menu();
			break;
		case 2:
			my_interface->del_menu();
			break;
		case 3:
			my_interface->mdf_menu();
			break;
		case 4:
			my_interface->vew_menu();
			break;
		case 5:
			exit(0);
			break;
		}
	}
	delete my_contact;
	return 0;
}

int main_menu(){
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
	return (rtn_int - '0');
}

