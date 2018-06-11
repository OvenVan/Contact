
#include "stdafx.h"
#include "Contact.h"

extern vector<Person*> contact_item;
extern string errorMsg;

Contact::Contact()
{
	refresh();
}

Contact::~Contact()
{
	int freei = contact_item.size();
	for (int i = 0; i<freei; ++i){
		delete(contact_item.at(i));
	}
}

bool Contact::create() const{
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

	char _char[30] = "";
	char* t_addr = _char;
	sprintf(t_addr,".\\contact\\%s.ctt",t_info.name);


	FILE* fp = fopen(t_addr ,"wb+");
	if(fwrite(&t_info, sizeof(t_info), 1, fp) != 1)
		printf("err");
	fclose(fp);

	refresh();
	
	return true;
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

bool Contact::delete_prsn(Person& del_Person) const{
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
		this->refresh();
		return true;
	}
	else
		cout<<"\n\t\tCanceled!\n";
	return false;
}

void Contact::print_prsn(const Person& prt_Person, const string info, bool refresh) const{
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


int Contact::modify_prsn(Person& m_Person) const{
	char t_c;
	char y_n;
	//int index = 0;
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
			this->refresh();
		}
	}
	else
		cout<<"\n\t\tCanceled!\n";

	return 0;
}

bool Contact::check_exact(const Person& index, const string info_str) const{
	if (strcmp(index.name,info_str.c_str()) == 0)
		return true;
	vector<string> temp_vec = part_tq(index, "tel");
	for (int i = 0; i<temp_vec.size(); i++){
		if (strcmp(temp_vec.at(i).c_str(),info_str.c_str()) == 0)
			return true;
	}
	return false;
}

Person* Contact::exactView(const string info_str) const{
	int num = contact_item.size();
	int index = 0;
	vector<int> chosen_item;

	for (int i = 0; i < num; i++){
		if (this->check_exact(*contact_item[i], info_str)){
			chosen_item.push_back(i);
			cout<<"("<<chosen_item.size()<<"): "<<&*contact_item[i]->name<<"    TEL: "<<&*contact_item[i]->tel<<"    ADDR: "<<&*contact_item[i]->addr<<endl;
			Sleep(20);
		}
	}
	return anything_view(chosen_item);
}

Person* Contact::fuzzyView(const string info_str) const{
	int num = contact_item.size();
	int index = 0;
	vector<int> chosen_item;

	for (int i = 0;i<num;i++){
		if ((strstr(&*contact_item[i]->addr,info_str.c_str()) != NULL) || (strstr(&*contact_item[i]->name ,info_str.c_str()) != NULL) || (strstr(&*contact_item[i]->tel ,info_str.c_str()) != NULL)  )    {
			chosen_item.push_back(i);
			cout<<"("<<chosen_item.size()<<"): "<<&*contact_item[i]->name<<"    TEL: "<<&*contact_item[i]->tel<<"    ADDR: "<<&*contact_item[i]->addr<<endl;
			Sleep(20);
		}
	}
	return anything_view(chosen_item);
}
Person* Contact::categoryView(const string info_str) const{
	int num = contact_item.size();
	int index = 0;
	vector<int> chosen_item;

	for (int i = 0; i < num; i++){
		if (strcmp(&*contact_item[i]->category,info_str.c_str()) == 0 ){
			chosen_item.push_back(i);
			cout<<"("<<chosen_item.size()<<"): "<<&*contact_item[i]->name<<"    TEL: "<<&*contact_item[i]->tel<<"    ADDR: "<<&*contact_item[i]->addr<<endl;
			Sleep(20);
		}
	}
	return anything_view(chosen_item);
}

Person* Contact::allView() const{
	int num = contact_item.size();
	int index = 0;
	vector<int> chosen_item;

	for (int i = 0;i<num;i++){
		chosen_item.push_back(i);
		cout<<"("<<chosen_item.size()<<"): "<<&*contact_item[i]->name<<"    TEL: "<<&*contact_item[i]->tel<<"    ADDR: "<<&*contact_item[i]->addr<<endl;
		Sleep(20);
	}
	return anything_view(chosen_item);
}

Person* Contact::anything_view(vector<int>& chosen_item) const{
	int index = 0;

	if (chosen_item.size() == 0){
		cout<<"\n\n\t\tNo Item Found!\n";
		return NULL;
	}
	else {
		if (chosen_item.size() == 1){
			Sleep(400);
			index = 1;
		}
		else{
			cout<<"\n\tEnter the INDEX(1 - "<<chosen_item.size()<<") of the information you want to VIEW:(0 for quit) ";
			cin.clear();
			cin.sync();
			cin>>index;
			if ((index<0) || (index>chosen_item.size())){
				return NULL;
			}
		}//if (chosen_item.size() == 1)
		if (index > 0){
			return contact_item.at(chosen_item.at(index-1));
		}
		return NULL;
	}//if (chosen_item.size() == 0)
}

void Contact::printAll() const{
	int num = contact_item.size();

	for (int i = 0; i < num; i++){
		cout<<"("<<i+1<<"): "<<&*contact_item[i]->name<<"    TEL: "<<&*contact_item[i]->tel<<"    ADDR: "<<&*contact_item[i]->addr<<endl;
		Sleep(20);
	}
}

int Contact::exfz_vew(const char* title, const char* descp, const char* flag) const{
	string info_str;
	Person* viewPerson = NULL;

	system("cls");
	cout<<endl;
	cout<<title<<endl<<endl;
	cout<<descp;
	cin.clear();
	cin.sync();
	cin>>info_str;
	if (info_str == ""){
		cout<<"\n\n\t\tNo Infomation Found!\n";
	}
	else{	
		if (flag == "exact")
			viewPerson = exactView(info_str);
		else
			viewPerson = fuzzyView(info_str);
		if (viewPerson != NULL){
			view(*viewPerson);
		}
	}
	return 0;
}

int Contact::cgy_vew() const{
	string info_str;
	vector<string> cur_ctg;
	string tmp_ctg;
	bool add_ctg;
	int index = 0;
	int i = 0,j = 0;
	Person* viewPerson = NULL;

	system("cls");
	cout<<endl;
	cout<<"=====List by Category==================\n\n";
	cout<<"\tCurrent category:";
	for (i = 0; i<contact_item.size();i++){
		tmp_ctg = &*contact_item[i]->category;
		if (tmp_ctg == "")
			tmp_ctg = "Unset";
		add_ctg = true;
		for (j = 0; j<cur_ctg.size();j++){
			if (cur_ctg[j] == tmp_ctg)
				add_ctg = false;
		}
		if (add_ctg){
			cur_ctg.push_back(tmp_ctg);
			cout<<"  "<<tmp_ctg;
		}
	}

	cout<<"\n\n\tEnter category infomation:";
	cin.clear();
	cin.sync();
	cin>>info_str;
	if ((info_str == "Unset") || (info_str == "unset"))
		info_str = "";
	
	viewPerson =categoryView(info_str);
	if (viewPerson != NULL){
		view(*viewPerson);
	}
	return 0;

}
int Contact::all_vew() const{
	int i = 0,j = 0;	
	Person* viewPerson = NULL;

	system("cls");
	cout<<endl;
	cout<<"=====ALL Category======================\n\n";
	viewPerson = allView();
	if (viewPerson != NULL){
		view(*viewPerson);
	}
	return 0;
}