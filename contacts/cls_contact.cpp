// cls_contact.cpp: implementation of the cls_contact class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "cls_contact.h"
//#include "person.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
extern vector<person> contact_item;
//extern errorMsg;


cls_contact::cls_contact()
{

}

cls_contact::~cls_contact()
{

}

bool cls_contact::create(){
	person t_info;
	string t_str = "";
	//struct temp_contact_info ;
	cout<<"You can use ',[en]'(NOT '£¬[chs]') to enter more than one data(Only for *Tel and *QQ)"<<endl<<endl;
	cout<<"Name:";
	cin.clear();
	cin.sync();
	cin>>t_info.name;
	//t_info.name[99] = '\0';
	cout<<"Address:";
	cin.clear();
	cin.sync();
	//t_info.name[99] = '\0';
	cin>>t_info.addr;
	cout<<"*Tel:";
	cin.clear();
	cin.sync();
	cin>>t_info.tel;
	//strcpy(t_info.tel, resetStrwithcomma(t_info.tel));

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
	//strcpy(t_info.qq, resetStrwithcomma(t_str.c_str()));
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

	if(!t_info.check(true)){
		cout<<"\n\t\t"<<errorMsg<<endl;
		return false;
	}

	char _char[30] = "";
	char* t_addr = _char;
	sprintf(t_addr,".\\contact\\%s.ctt",t_info.name);


	FILE* fp = fopen(t_addr ,"wb+");
	if(fwrite(&t_info, sizeof(t_info), 1, fp) != 1)
		printf("err");
	fclose(fp);
	
	//readfile(t_addr);
	refresh();
	
	return true;
}

int cls_contact::refresh(){

	string info_check;
	contact_item.clear();

	long hFile = 0;
	struct _finddata_t fileinfo;
	const char* cp = ".\\contact\\*";

	if ((hFile = _findfirst(cp, &fileinfo)) != -1){
		do{
			if (!(fileinfo.attrib &  _A_SUBDIR)){
				string path = ".\\contact\\";
				path += fileinfo.name;

				person temp_p;
				FILE* fp = fopen(path.c_str(), "rb");
				
				fread(&temp_p, sizeof(temp_p), 1, fp);	
				fclose(fp);
				info_check = temp_p.name;
				info_check += ".ctt";
				if (info_check == fileinfo.name)
					contact_item.push_back(temp_p);
			}
					
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}

	return contact_item.size();
}


