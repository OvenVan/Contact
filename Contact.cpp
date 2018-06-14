
#include "stdafx.h"
#include "Contact.h"

extern vector<Person*> contact_item;
extern string errorMsg;

Contact::Contact()
{
	MainFunctionsNum = 5;
	refresh();
}

Contact::~Contact()
{
	int freei = contact_item.size();
	for (int i = 0; i<freei; ++i){
		delete(contact_item.at(i));
	}
}

MainStrategy* Contact::setMainStrategy(int num){
		switch (num){
		case 1:
			return new MainNewMenu();
		case 2:
			return new MainDelMenu();
		case 3:
			return new MainMdfMenu();
		case 4:
			return new MainVewMenu();
		case 5:
			return NULL;
		}
		return NULL;
}

void Contact::removeMainStrategy(void* p){
	delete p;
}

void Contact::welcome() const{
	int n = 0;
	cout<<"\n\n\n----------Welcome to the Address Book System.--------\n\n";
	cout<<"-----now LOADING address book...";
	n = refresh();
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
}


int Contact::refresh() const{

	string info_check;
	contact_item.clear();

	long hFile = 0;
	struct _finddata_t fileinfo;
	const char* cp = ".\\contact\\*";
	const char* dir = ".\\contact";

	int freei = contact_item.size();
	for (int i = 0; i<freei; ++i){
		delete(contact_item.at(i));
	}

	if ((hFile = _findfirst(cp, &fileinfo)) != -1){
		do{
			if (!(fileinfo.attrib &  _A_SUBDIR)){
				string path = ".\\contact\\";
				path += fileinfo.name;

				Person *temp_p = new Person;
				FILE* fp = fopen(path.c_str(), "rb");
				
				fread(temp_p, sizeof(*temp_p), 1, fp);	
				fclose(fp);
				info_check = temp_p->name;
				info_check += ".ctt";
				if (info_check == fileinfo.name)
					contact_item.push_back(temp_p);
			}
					
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
	else{  
		if (!CreateDirectory(dir, NULL)) return -1;
	}
	return contact_item.size();
}

