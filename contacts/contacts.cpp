// contacts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cls_contact.h"
#include "person.h"

int main_menu();
int new_menu();
int del_menu();
int mdf_menu();
int modify_prsn(person m_person);
int view(person v_person);
int vew_menu();
int ext_vew();
int fuz_vew();
int cgy_vew();
int all_vew();
int cmp_names(char* c1, char* c2);
bool check_exact(person& index, string info_str);
bool delete_prsn(person& del_person);
void print_prsn(person& prt_person, string info, bool refresh);

cls_contact my_contact;
extern vector<person> contact_item;

int main(int argc, char* argv[])
{
	int rtn_num = 0;
	setlocale(LC_ALL,"chs");
	cout<<"\n\n\n----------Welcome to the Address Book System.--------\n\n";
	cout<<"-----now LOADING address book...";
	
	int n = my_contact.refresh();
	Sleep(800);
	if (n > 0)
		cout<<"\t"<<n<<" contact(s) have been imported.\n";
	else
		cout<<"\t"<<"no contact has been imported.\n";
	
	Sleep(50);
	cout<<"  Login...";
	Sleep(300);
	cout<<" Successful!";
	Sleep(40);
	while(1){
		int i;
		if((i = rand()%10)>3)
			my_contact.refresh();
		switch(main_menu()){
		case 1:
			rtn_num = new_menu();
			break;
		case 2:
			rtn_num = del_menu();
			break;
		case 3:
			rtn_num = mdf_menu();
			break;
		case 4:
			rtn_num = vew_menu();
			break;
		case 5:
			exit(0);
		}
	
	}
	//
	return 0;
}

int main_menu(){
	char rtn_int;
	int fuckin_stupid = 0;
	cin.clear();
	cin.sync();
	do{
		system("cls");
		cout<<endl;
		cout<<"\t\t==========MAIN MENU===========\n\t\t|\n";
		cout<<"\t\t ---New____1------------------\n\t\t|\n";
		cout<<"\t\t ---Delete_2------------------\n\t\t|\n";
		cout<<"\t\t ---Modify_3------------------\n\t\t|\n";
		cout<<"\t\t ---View___4------------------\n\t\t|\n";
		cout<<"\t\t ---Quit___5------------------\n\n";

		if (fuckin_stupid != 0)
			cout<<"\t\tError Inputing!\n";
		cout<<"\tEnter number[1-5] to select the corresponding function: ";
		
		cin.clear();
		cin.sync();
		rtn_int = getch();
		fuckin_stupid++;
	}while((rtn_int<'1') || (rtn_int>'5'));
	return (rtn_int - '0');
}
int new_menu(){
	system("cls");
	cout<<endl;
	cout<<"=====New Contact====================\n\n";
	if(!my_contact.create())
		cout<<"\n\n\t\tInfomation Error!";
	else
		cout<<"\n\n\t\tInfomation Entry Success!";
	cin.clear();
	cin.sync();
	getchar();
	return 0;	
}
bool delete_prsn(person& del_person){
	char y_n;
	string addr = ".\\contact\\";
	cout<<"\n\n\t\tReally want to delete?[y/n]: ";
	cin.clear();
	cin.sync();
	
	y_n = getch();
	if ((y_n == 'y') || (y_n == 'Y')){
		addr += del_person.name;
		addr += ".ctt";
		if (remove(addr.c_str())){
			cout<<"\n\t\tError removing data!\n";
			return false;
		}
		cout<<"\n\t\tDelete Successful!\n";
		my_contact.refresh();
		return true;
	}
	else
		cout<<"\n\t\tCanceled!\n";
	return false;
}
void print_prsn(person& prt_person, string info, bool refresh){
	system("cls");
	cout<<endl<<info;
	if(refresh) Sleep(20);
	cout<<"\n\tName:     "<<prt_person.name;
	if(refresh) Sleep(20);
	cout<<"\n\tTel:      "<<prt_person.tel;
	if(refresh) Sleep(20);
	cout<<"\n\tAddress:  "<<prt_person.addr;
	if(refresh) Sleep(20);
	cout<<"\n\tGendle:   "<<prt_person.sex ;
	if(refresh) Sleep(20);
	cout<<"\n\tZip:      "<<prt_person.zip;
	if(refresh) Sleep(20);
	cout<<"\n\tMail:     "<<prt_person.mail;
	if(refresh) Sleep(20);
	cout<<"\n\tQQ:       "<<prt_person.qq;
	if(refresh) Sleep(20);
	cout<<"\n\tCategory: "<<prt_person.category;
	if(refresh) Sleep(20);
}
int del_menu(){
	int num = contact_item.size();
	int index = 0;
	string addr = ".\\contact\\";
	system("cls");
	cout<<endl;
	cout<<"=====Delete Contact====================\n\n";
	if (num > 1){
		for (int i = 0; i < num; i++){
			cout<<"("<<i+1<<"): "<<contact_item[i].name<<"    TEL: "<<contact_item[i].tel<<"    ADDR: "<<contact_item[i].addr<<endl;
			Sleep(20);
		}
		cout<<"\n\tEnter the INDEX(1 - "<<num<<") of the information you want to DELETE:(0 for quit) ";
		cin.clear();
		cin.sync();
		cin>>index;
		if ((index<0) || (index>num)){
			cout<<"\n\n\t\tError Input!\n";
			index = 0;
		}
	}
	else if ( num == 1)
		index = 1;
	if (index == 0)
		return 0;
	index--;
	print_prsn(contact_item[index],"=====Delete Contact====================\n",true);
	delete_prsn(contact_item[index]);
	cin.clear();
	cin.sync();
	getchar();
	return 0;	
}

int modify_prsn(person m_person){
	char t_c;
	char y_n;
	//int index = 0;
	string addr = ".\\contact\\";
	string t_str = "";
	addr += m_person.name;
	addr += ".ctt";
	person t_info = m_person;

	system("cls");
	cout<<endl<<"=====Modify Contact====================(Enter a new value at the cursor.ENTER to SKIP,SPACE to ERACE)\n";
	cout<<"\n  When you entering Tel and QQ information, you can input '+' at the beginning to add the data to the end of the existing data.\n  I will remind you later.(*)\n";
	
	cout<<"\n\tName:     "<<m_person.name;	
	cout<<"\n\t*Tel:     "<<m_person.tel<<"\t:(eg:+12345) ";
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

	cout<<"\tAddress:  "<<m_person.addr<<"\t: ";
		cin.clear();cin.sync();
		t_str = "";
		while((t_c = getchar()) != '\n') {t_str += t_c;}
		if (t_str != "") strcpy(t_info.addr,t_str.c_str());
		if (t_str == " ") strcpy(t_info.addr,"");

	cout<<"\tGendle:   "<<m_person.sex <<"\t: ";
		cin.clear();cin.sync();
		t_c= getchar();
		if (t_c != '\n')	
			t_info.sex = t_c;
		if (t_c == ' ')
			t_info.sex = '\0';

	cout<<"\tZip:      "<<m_person.zip<<"\t: ";
		cin.clear();cin.sync();
		t_str = "";
		while((t_c = getchar()) != '\n'){t_str += t_c;}
		if (t_str != "") strcpy(t_info.zip,t_str.c_str());
		if (t_str == " ") strcpy(t_info.zip,"");

	cout<<"\tMail:     "<<m_person.mail<<"\t: ";
		cin.clear();cin.sync();
		t_str = "";
		while((t_c = getchar()) != '\n'){t_str += t_c;}
		if (t_str != "") strcpy(t_info.mail,t_str.c_str());
		if (t_str == " ") strcpy(t_info.mail,"");

	cout<<"\t*QQ:      "<<m_person.qq<<"\t:(eg:+12345) ";
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

	cout<<"\tCategory: "<<m_person.category<<"\t: ";
		cin.clear();cin.sync();
		t_str = "";
		while((t_c = getchar()) != '\n'){t_str += t_c;}
		if (t_str != "") strcpy(t_info.category,t_str.c_str());
		if (t_str == " ") strcpy(t_info.category,"");

	print_prsn(t_info,"=====Modify Contact====================\n",true);
	cout<<"\n\n\t\tReally want to modify?[y/n]: ";
	cin.clear();
	cin.sync();
	y_n = getch();
	if ((y_n == 'y') || (y_n == 'Y')){
		if(!t_info.check(false)){
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
				if (fwrite(&t_info,sizeof(person), 1, fp) != 1){
					cout<<"\n\t\tError writing to file!\n";
					return -1;
				}
				else{
					cout<<"\n\t\tModify succeed!\n";
					fclose(fp);
				}
			my_contact.refresh();
		}
	}
	else
		cout<<"\n\t\tCanceled!\n";

	cin.clear();
	cin.sync();
	getchar();
	return 0;
}

int mdf_menu(){
	int num = contact_item.size();
	int index = 0;
	char* c_item[8] = {"Name","Tel","Address","Gender:(M for Male, F for Female)","Zip","Mail","QQ","Category"};

	system("cls");
	cout<<endl;
	cout<<"=====Modify Contact====================\n\n";
	if (num > 1){
		for (int i = 0; i < num; i++){
			cout<<"("<<i+1<<"): "<<contact_item[i].name<<"    TEL: "<<contact_item[i].tel<<"    ADDR: "<<contact_item[i].addr<<endl;
			Sleep(20);
		}
		cout<<"\n\tEnter the INDEX(1 - "<<num<<") of the information you want to MODIFY:(0 for quit) ";
		cin.clear();
		cin.sync();
		cin>>index;
		if ( (index<0) || (index>num) ){
			cout<<"\n\t\tError Input!\n";
			index = 0;
		}
	}
	else if ( num == 1)
		index = 1;
	if (index == 0)
		return 0;
	index--;

	modify_prsn(contact_item.at(index));
	//
	


	return 0;	
}

int vew_menu(){
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
	switch(slct_num){
	case '1':
		ext_vew();
		break;
	case '2':
		fuz_vew();
		break;
	case '3':
		cgy_vew();
		break;
	case '4':
		all_vew();
		break;
	case '5':
		break;
	}
	return 0;
}
int view(person v_person){
	bool refresh = true;
	string addr = ".\\contact\\";
	int fuckin_stupid = 0;
	int slct_num = 0;
	do{
		print_prsn(v_person,"=====VIEW Contact====================\n",refresh);
		cout<<endl<<endl;	
		cout<<" ====Options=======\n|\n";
		if(refresh) Sleep(20);				
		cout<<" -------Delete_1---\n|\n";
		if(refresh) Sleep(20);
		cout<<" -------Modify_2---\n|\n";	
		if(refresh) Sleep(20);
		cout<<" -------Back___3---\n\n";
		if(refresh) Sleep(20);
		//cout<<"\t\t";					
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
		delete_prsn(v_person);
		break;
	case '2':
		modify_prsn(v_person);
		break;
	case '3':
		break;
	}//switch
	return 0;
}

bool check_exact(person& index, string info_str){
	if ((strcmp(index.name,info_str.c_str()) == 0) || (strcmp(index.name,info_str.c_str()) == 0))
		return true;
	vector<string> temp_vec = index.part_tq("tel");
	for (int i = 0; i<temp_vec.size(); i++){
		//cout<<temp_vec.at(i)<<endl;
		if (strcmp(temp_vec.at(i).c_str(),info_str.c_str()) == 0)
			return true;
	}
	return false;
}

int ext_vew(){
	string info_str;
	int num = contact_item.size();
	int index = 0;
	vector<int> chosen_item;
	system("cls");
	cout<<endl;
	cout<<"=====Exact Query Contact===============\n\n";
	cout<<"\tEnter infomation that needs to be querying:";
	cin.clear();
	cin.sync();
	cin>>info_str;
	if (info_str == "")
		cout<<"\n\n\t\tNo Infomation Found!\n";
	else{
		for (int i = 0; i < num; i++){
			if (check_exact(contact_item[i], info_str)){
				chosen_item.push_back(i);
				cout<<"("<<chosen_item.size()<<"): "<<contact_item[i].name<<"    TEL: "<<contact_item[i].tel<<"    ADDR: "<<contact_item[i].addr<<endl;
				Sleep(20);
			}
		}//for
		if (chosen_item.size() == 0){
			cout<<"\n\n\t\tNo Item Found!\n";
			cin.clear();
			cin.sync();
			getchar();
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
					cout<<"\n\n\t\tError Input!\n";
					index = 0;
					cin.clear();
					cin.sync();
					getchar();
				}
			}//if (chosen_item.size() == 1)
			if (index > 0)
				view(contact_item.at(chosen_item.at(index-1)));
		}//if (chosen_item.size() == 0)
	}//if (info_str == "")
	cin.clear();
	cin.sync();
	return 0;	
}
int fuz_vew(){
	string info_str;
	int num = contact_item.size();
	int index = 0;
	int i = 0;
	vector<person> chosen_item;
	system("cls");
	cout<<endl;
	cout<<"=====Fuzzy Query Contact===============\n\n";
	cout<<"\tEnter infomation that needs to be querying:";
	cin.clear();
	cin.sync();
	cin>>info_str;
	if (info_str == "")
		cout<<"\n\n\t\tNo Infomation Found!\n";
	else{
		cout<<endl;
		for (i = 0;i<num;i++)
			if ((strstr(contact_item.at(i).addr,info_str.c_str()) != NULL) || (strstr(contact_item.at(i).name ,info_str.c_str()) != NULL) || (strstr(contact_item.at(i).tel ,info_str.c_str()) != NULL)  )    {
				chosen_item.push_back(contact_item.at(i));
				cout<<"("<<chosen_item.size()<<"): "<<contact_item[i].name<<"    TEL: "<<contact_item[i].tel<<"    ADDR: "<<contact_item[i].addr<<endl;
				Sleep(20);
			}
		if (chosen_item.size() == 0){
			cout<<"\n\n\t\tNo Item Found!\n";
			cin.clear();
			cin.sync();
			getchar();
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
					cout<<"\n\n\t\tError Input!";
					index = 0;
					cin.clear();
					cin.sync();
					getchar();
				}
			}//if (chosen_item.size() == 1)
			if (index > 0)
				view(chosen_item.at(index-1));
		}//if (chosen_item.size() == 0)		
	}
	//cin.clear();
	//cin.sync();
	return 0;
}
int cgy_vew(){
	string info_str;
	vector<string> cur_ctg;
	string tmp_ctg;
	bool add_ctg;
	int num = contact_item.size();
	int index = 0;
	int i = 0,j = 0;
	vector<person> chosen_item;
	system("cls");
	cout<<endl;
	cout<<"=====List by Category==================\n\n";
	cout<<"\tCurrent category:";
	for (i = 0; i<contact_item.size();i++){
		tmp_ctg = contact_item[i].category;
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
		for (i = 0;i<num;i++)
			if (strcmp(contact_item[i].category,info_str.c_str()) == 0 ){
				chosen_item.push_back(contact_item.at(i));
				cout<<"("<<chosen_item.size()<<"): "<<contact_item[i].name<<"    TEL: "<<contact_item[i].tel<<"    ADDR: "<<contact_item[i].addr<<endl;
				Sleep(20);
			}
		if (chosen_item.size() == 0){
			cout<<"\n\n\t\tNo Item Found!\n";
			cin.clear();
			cin.sync();
			getchar();
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
				if ((index<0) || (index>(num + 1))){
					cout<<"\n\n\t\tError Input!\n";
					index = 0;
					cin.clear();
					cin.sync();
					getchar();
				}
			}
			if (index > 0)
				view(chosen_item.at(index-1));
		}		
	cin.clear();
	cin.sync();
	return 0;

}
int all_vew(){
	int i = 0,j = 0;
	int index;
	person temp_p;
	system("cls");
	cout<<endl;
	cout<<"=====ALL Category======================\n\n";
	for (i = 0;i<contact_item.size();i++){
		for (j = i+1;j<contact_item.size();j++)
			if (cmp_names(contact_item[i].name,contact_item[j].name) == 1){	//strcmp(contact_item[i].name,contact_item[j].name) == 1
				temp_p = contact_item[i];
				contact_item[i] = contact_item[j];
				contact_item[j] = temp_p;
			}
	}
	for (i = 0;i<contact_item.size();i++){
		cout<<"("<<i+1<<"): "<<contact_item[i].name<<"    TEL: "<<contact_item[i].tel<<"    ADDR: "<<contact_item[i].addr<<endl;
		Sleep(20);
	}
	if (contact_item.size() == 1){
		Sleep(400);
		index = 1;
	}
	else{
		cout<<"\n\tEnter the INDEX(1 - "<<contact_item.size()<<") of the information you want to VIEW:(0 for quit) ";
		cin.clear();
		cin.sync();
		cin>>index;
		if ((index<0) || (index>contact_item.size() )){
			cout<<"\n\n\t\tError Input!\n";
			index = 0;
			cin.clear();
			cin.sync();
			getchar();
		}
	}//if (chosen_item.size() == 1)
	if (index > 0)
		view(contact_item.at(index-1));
	
	cin.clear();
	cin.sync();
	//getchar();
	return 0;
}

int cmp_names(char* c1, char* c2){
	string s1 = c1;
	string s2 = c2;
	if (s1 > s2) return 1;
	else return -1;
}