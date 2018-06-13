// MainVewMenu.cpp: implementation of the MainVewMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainVewMenu.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MainVewMenu::MainVewMenu()
{

}

MainVewMenu::~MainVewMenu()
{

}

ViewStrategy* MainVewMenu::setViewStrategy(int slct_num){

	switch(slct_num){
	case '1':
		return new ViewExactMenu();
	case '2':
		return new ViewFuzzyMenu();
	case '3':
		return new ViewCategoryMenu();
	case '4':
		return new ViewAllMenu();
	case '5':
		break;
	}
	return NULL;
}

int MainVewMenu::doMainStrategy()
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

	view(*(viewStrategy->doViewStrategy()));
	return 0;
}

bool MainVewMenu::delete_prsn(Person& del_Person) const{
	char y_n;
	string addr = ".\\contact\\";
	cout<<"\n\n\t\tReally want to delete?[y/n]: ";
	cin.clear();
	cin.sync();
	
	y_n = getch();
	if ((y_n == 'y') || (y_n == 'Y')){
		addr += del_Person.name;
		addr += ".ctt";
		if (remove(addr.c_str())){
			cout<<"\n\t\tError removing data!\n";
			return false;
		}
		cout<<"\n\t\tDelete Successful!\n";
		return true;
	}
	else
		cout<<"\n\t\tCanceled!\n";
	return false;
}

int MainVewMenu::modify_prsn(Person& m_Person) const{
	char t_c;
	char y_n;
	string addr = ".\\contact\\";
	string t_str = "";
	addr += m_Person.name;
	addr += ".ctt";
	Person t_info = m_Person;

	system("cls");
	cout<<endl<<"=====Modify Contact====================(Enter a new value at the cursor.ENTER to SKIP.)\n";
	cout<<"\n  When you entering Tel and QQ information, you can input '+' at the beginning to add the data to the end of the existing data.\n  I will remind you later.(*)\n";
	
	cout<<"\n\tName:     "<<m_Person.name;	
	cout<<"\n\t*Tel:     "<<m_Person.tel<<"\t:(eg:+12345) ";
		cin.clear();cin.sync();
		t_str = "";
		while((t_c = getchar()) != '\n'){t_str += t_c;}
		if (t_str[0] == '+'){
			t_str.erase(&t_str[0]);
			string _t_str = t_info.tel;
			_t_str += ",";
			_t_str += t_str;
			t_str = _t_str;
			strcpy(t_info.tel,t_str.c_str());
		}
		else{
			if (t_str != "") strcpy(t_info.tel,t_str.c_str());
			if (t_str == " ") strcpy(t_info.tel,"");
		}

	cout<<"\tAddress:  "<<m_Person.addr<<"\t: ";
		cin.clear();cin.sync();
		t_str = "";
		while((t_c = getchar()) != '\n') {t_str += t_c;}
		if (t_str != "") strcpy(t_info.addr,t_str.c_str());
		if (t_str == " ") strcpy(t_info.addr,"");

	cout<<"\tGendle:   "<<m_Person.sex <<"\t: ";
	
		cin.clear();cin.sync();
		t_c= getchar();
		if (t_c != '\n')	
			t_info.sex = t_c;
		if (t_c == ' ')
			t_info.sex = '\0';

	cout<<"\tZip:      "<<m_Person.zip<<"\t: ";
		cin.clear();cin.sync();
		t_str = "";
		while((t_c = getchar()) != '\n'){t_str += t_c;}
		if (t_str != "") strcpy(t_info.zip,t_str.c_str());
		if (t_str == " ") strcpy(t_info.zip,"");

	cout<<"\tMail:     "<<m_Person.mail<<"\t: ";
		cin.clear();cin.sync();
		t_str = "";
		while((t_c = getchar()) != '\n'){t_str += t_c;}
		if (t_str != "") strcpy(t_info.mail,t_str.c_str());
		if (t_str == " ") strcpy(t_info.mail,"");

	cout<<"\t*QQ:      "<<m_Person.qq<<"\t:(eg:+12345) ";
		cin.clear();cin.sync();
		t_str = "";
		while((t_c = getchar()) != '\n'){t_str += t_c;}
		if (t_str[0] == '+'){
			t_str.erase(&t_str[0]);
			string _t_str = t_info.qq;
			_t_str += ",";
			_t_str += t_str;
			t_str = _t_str;
			strcpy(t_info.qq,t_str.c_str());
		}
		else{
			if (t_str != "") strcpy(t_info.qq,t_str.c_str());
			if (t_str == " ") strcpy(t_info.qq,"");
		}

	cout<<"\tCategory: "<<m_Person.category<<"\t: ";
		cin.clear();cin.sync();
		t_str = "";
		while((t_c = getchar()) != '\n'){t_str += t_c;}
		if (t_str != "") strcpy(t_info.category,t_str.c_str());
		if (t_str == " ") strcpy(t_info.category,"");

	this->print_prsn(t_info,"=====Modify Contact====================\n",true);
	cout<<"\n\n\t\tReally want to modify?[y/n]: ";
	cin.clear();
	cin.sync();
	y_n = getch();
	if ((y_n == 'y') || (y_n == 'Y')){
		if(!check(t_info, false)  ){
			cout<<"\n\t\tInfomation Error!";
			return -1;
		}
		else{
			FILE *fp = fopen(addr.c_str(),"wb+");
			if (fp == NULL	){
				cout<<"\n\t\tError opening file!\n";
				return -1;
			}
			else
				if (fwrite(&t_info,sizeof(Person), 1, fp) != 1){
					cout<<"\n\t\tError writing to file!\n";
					return -1;
				}
				else{
					cout<<"\n\t\tModify succeed!\n";
					fclose(fp);
				}
		}
	}
	else
		cout<<"\n\t\tCanceled!\n";

	return 0;
}
			
int MainVewMenu::view(Person& v_Person) const{
	bool refresh = true;
	string addr = ".\\contact\\";
	int fuckin_stupid = 0;
	int slct_num = 0;
	do{
		print_prsn(v_Person,"=====VIEW Contact====================\n",refresh);
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
		delete_prsn(v_Person);
		cin.clear();
		cin.sync();
		getch();
		break;
	case '2':
		modify_prsn(v_Person);
		cin.clear();
		cin.sync();
		getch();
		break;
	case '3':
		break;
	}
	return 0;
}
