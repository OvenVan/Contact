// MainNewMenu.cpp: implementation of the MainNewMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainNewMenu.h"

MainNewMenu::doMainStrategy()
{
	system("cls");
	cout<<endl;
	cout<<"=====New Contact====================\n\n";
	if(!create())
		cout<<"\n\n\t\tInfomation Error!";
	else
		cout<<"\n\n\t\tInfomation Entry Success!";
	cin.clear();
	cin.sync();
	getchar();
	return 0;
}

bool MainNewMenu::create() const{
	Person t_info;
	string t_str = "";
	cout<<"You can use ',[en]'(NOT '£¬[chs]') to enter more than one data(Only for *Tel and *QQ)"<<endl<<endl;
	cout<<"Name:";
	cin.clear();
	cin.sync();
	cin>>t_info.name;
	cout<<"Address:";
	cin.clear();
	cin.sync();
	cin>>t_info.addr;
	cout<<"*Tel:";
	cin.clear();
	cin.sync();
	cin>>t_info.tel;

	char t_c;
	cout<<"\n\tthe following data can be set as NULL.Press ENTER to skip\n\n";

	cin.clear();
	cin.sync();

	cout<<"Gender:(M for Male, F for Female)";
	char _c= getchar();
	if (_c != '\n')	
		t_info.sex = _c;
	cin.clear();
	cin.sync();

	cout<<"Zip:";
	while((t_c = getchar()) != '\n'){
		t_str += t_c;
	}
	strcpy(t_info.zip,t_str.c_str());

	cin.clear();
	cin.sync();
	t_str = "";

	cout<<"Mailbox:";
	while((t_c = getchar()) != '\n'){
		t_str += t_c;
	}
	strcpy(t_info.mail,t_str.c_str());
	cin.clear();
	cin.sync();
	t_str = "";

	cout<<"*QQ:";
	while((t_c = getchar()) != '\n'){
		t_str += t_c;
	}
	strcpy(t_info.qq, t_str.c_str());
	cin.clear();
	cin.sync();
	t_str = "";

	cout<<"Category:";
	while((t_c = getchar()) != '\n'){
		t_str += t_c;
	}
	strcpy(t_info.category,t_str.c_str());
	cin.clear();
	cin.sync();
	t_str = "";

	if(!check(t_info, true)  ){
		cout<<"\n\t\t"<<errorMsg<<endl;
		return false;
	}

//--------------------------------------------------------
	char _char[30] = "";
	char* t_addr = _char;
	sprintf(t_addr,".\\contact\\%s.ctt",t_info.name);


	FILE* fp = fopen(t_addr ,"wb+");
	if(fwrite(&t_info, sizeof(t_info), 1, fp) != 1)
		printf("err");
	fclose(fp);
//--------------------------------------------------------	
	return true;
}