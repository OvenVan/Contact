// MainStrategy.cpp: implementation of the MainStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainStrategy.h"

void MainStrategy::print_prsn(const Person& prt_Person, const string info, bool refresh) const{
	system("cls");
	cout<<endl<<info;
	if(refresh) Sleep(20);
	cout<<"\n\tName:     "<<prt_Person.name;
	if(refresh) Sleep(20);
	cout<<"\n\tTel:      "<<prt_Person.tel;
	if(refresh) Sleep(20);
	cout<<"\n\tAddress:  "<<prt_Person.addr;
	if(refresh) Sleep(20);
	cout<<"\n\tGendle:   "<<prt_Person.sex ;
	if(refresh) Sleep(20);
	cout<<"\n\tZip:      "<<prt_Person.zip;
	if(refresh) Sleep(20);
	cout<<"\n\tMail:     "<<prt_Person.mail;
	if(refresh) Sleep(20);
	cout<<"\n\tQQ:       "<<prt_Person.qq;
	if(refresh) Sleep(20);
	cout<<"\n\tCategory: "<<prt_Person.category;
	if(refresh) Sleep(20);
}

void MainStrategy::printAll() const{
	int num = contact_item.size();

	for (int i = 0; i < num; i++){
		cout<<"("<<i+1<<"): "<<&*contact_item[i]->name<<"    TEL: "<<&*contact_item[i]->tel<<"    ADDR: "<<&*contact_item[i]->addr<<endl;
		Sleep(20);
	}
}


bool MainStrategy::delete_prsn(Person& del_Person) const{
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

bool MainStrategy::modify_prsn(Person& m_Person) const{
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
		while((t_c = getchar()) != '\n')
			{t_str += t_c;}
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
		while((t_c = getchar()) != '\n')
			{t_str += t_c;}
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
		while((t_c = getchar()) != '\n')
			{t_str += t_c;}
		if (t_str != "") strcpy(t_info.zip,t_str.c_str());
		if (t_str == " ") strcpy(t_info.zip,"");

	cout<<"\tMail:     "<<m_Person.mail<<"\t: ";
		cin.clear();cin.sync();
		t_str = "";
		while((t_c = getchar()) != '\n')
			{t_str += t_c;}
		if (t_str != "") strcpy(t_info.mail,t_str.c_str());
		if (t_str == " ") strcpy(t_info.mail,"");

	cout<<"\t*QQ:      "<<m_Person.qq<<"\t:(eg:+12345) ";
		cin.clear();cin.sync();
		t_str = "";
		while((t_c = getchar()) != '\n')
			{t_str += t_c;}
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
		while((t_c = getchar()) != '\n')
			{t_str += t_c;}
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
			return false;
		}
		else{
			FILE *fp = fopen(addr.c_str(),"wb+");
			if (fp == NULL	){
				cout<<"\n\t\tError opening file!\n";
				return false;
			}
			else
				if (fwrite(&t_info,sizeof(Person), 1, fp) != 1){
					cout<<"\n\t\tError writing to file!\n";
					return false;
				}
				else{
					cout<<"\n\t\tModify succeed!\n";
					fclose(fp);
				}
		}
	}
	else
		cout<<"\n\t\tCanceled!\n";
	return true;
}