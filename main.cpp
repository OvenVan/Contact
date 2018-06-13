

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
		if (my_interface->main_menu() == -1)
			break;
	
	}
	delete my_contact;
	return 0;
}



