/*
========Program Entry========
Author: ÑÏ¶÷Î°
Version: 1.2
Submit Date: 18.06.14
=========================
 */

#include "stdafx.h"
#include "Contact.h"

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



