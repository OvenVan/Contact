
#include "stdafx.h"
#include "Person.h"

Person::Person()
{
	strcpy(this->addr,"");
	strcpy(this->category,"");
	strcpy(this->mail, "");
	strcpy(this->name, "");
	strcpy(this->qq, "");
	this->sex = '\0';
	strcpy(this->tel, "");
	strcpy(this->zip, "");
}

