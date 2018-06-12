

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
		switch (my_interface->main_menu()){
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



