

#include "stdafx.h"
#include "Contact.h"

int main_menu();
int welcome(ContactInterface*);

extern vector<Person*> contact_item;

int main(int argc, char* argv[])
{
	ContactInterface* my_contact = new Contact();
	welcome(my_contact);


	while(1){
		switch (main_menu()){
		case 1:
			my_contact->new_menu();
			break;
		case 2:
			my_contact->del_menu();
			break;
		case 3:
			my_contact->mdf_menu();
			break;
		case 4:
			my_contact->vew_menu();
			break;
		case 5:
			exit(0);
			break;
		}
	}
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

int welcome(ContactInterface* my_contact){
	int n = 0;
	cout<<"\n\n\n----------Welcome to the Address Book System.--------\n\n";
	cout<<"-----now LOADING address book...";
	n = my_contact->refresh();
	Sleep(800);
	if (n > 0){
		cout<<"\t"<<n<<" contact(s) have been imported.\n";
	}
	else if (n == -1){
		cout<<"\tFolder contact does not exist!.Please retry later!\n";
		getch();
		exit(0);
	}
	else{
		cout<<"\t"<<"no contact has been imported.\n";
	}
	
	Sleep(50);
	cout<<"  Login...";
	Sleep(300);
	cout<<" Successful!";
	Sleep(40);
	return 0;
}
