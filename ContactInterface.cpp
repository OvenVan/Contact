

#include "stdafx.h"
#include "ContactInterface.h"

extern vector<Person*> contact_item;
extern string errorMsg;

int ContactInterface::new_menu(){
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

int ContactInterface::del_menu(){
	int num = contact_item.size();
	int index = 0;
	string addr = ".\\contact\\";
	system("cls");
	cout<<endl;
	cout<<"=====Delete Contact====================\n\n";
	if (num > 1){
		printAll();
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
	print_prsn(*contact_item[index],"=====Delete Contact====================\n",true);
	delete_prsn(*contact_item[index]);
	cin.clear();
	cin.sync();
	getchar();
	return 0;
}

int ContactInterface::mdf_menu(){
	int num = contact_item.size();
	int index = 0;
	char* c_item[8] = {"Name","Tel","Address","Gender:(M for Male, F for Female)","Zip","Mail","QQ","Category"};

	system("cls");
	cout<<endl;
	cout<<"=====Modify Contact====================\n\n";
	if (num > 1){
		printAll();
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

	modify_prsn(*contact_item.at(index));
	cin.clear();
	cin.sync();
	getch();
	return 0;	
}

int ContactInterface::view(Person& v_Person) const{
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

int ContactInterface::vew_menu(){
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
		exfz_vew("=====Exact Query Contact===============", 
				 "\tEnter infomation that needs to be querying: ", 
				 "exact");
		break;
	case '2':
		exfz_vew("=====Fuzzy Query Contact===============", 
				 "\tEnter infomation that needs to be querying(accroding to NAME, TEL, ADDR): ", 
				 "fuzzy");
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

bool ContactInterface::check(Person& person, const bool _check_repe) const {	
	int i = 0, j = 0;
	string re_write = "";
	if (!((strlen(person.name)>0) && (strlen(person.tel)>0) && (strlen(person.addr)>0)) ){
		errorMsg = "Name/Tel/Address is null.";
		return false;
	}

	if (_check_repe){				//here to use _check_repe only once.
		for (i = 0; i < contact_item.size(); i++)
			if (strcmp(person.name,&*contact_item[i]->name) == 0){
				sizeof(*contact_item[i]);
				errorMsg = "Item already exists.";
				return false;
			}
	}

	for (i = 0; i<strlen(person.tel); i++){
		if (!(( (person.tel[i]>='0')&&(person.tel[i]<='9') ) || (person.tel[i] == ','))){
			errorMsg = "Unknown character in Tel option.";
			return false;
		}
	}

	vector<string> temp_str = this->part_tq(person, "tel");

	re_write = "";
	for (i = 0; i<temp_str.size(); i++){
		for (j = i + 1; j<temp_str.size();j++){
			if ((temp_str.at(i) == temp_str.at(j)) && (temp_str.at(i) != "")){
				errorMsg = "Duplicated Tel number(s).";
				return false;
			}
		}
		if (temp_str.at(i) != ""){
			re_write += temp_str.at(i);
			re_write += ",";
		}
	}
	re_write = re_write.substr(0,re_write.length()-1);
	strcpy(person.tel,re_write.c_str());
	
	if (person.sex != '\0'){
		if ((person.sex == 'f') || (person.sex == 'm'))
			person.sex -=32;
		if ( !( (person.sex == 'F') || (person.sex == 'M') ) ){
			errorMsg = "Unknown character in Gender option.";
			return false;
		}
	}
	
	if (strcmp(person.qq, "") != 0){
		re_write = "";
		for (i = 0; i<strlen(person.qq); i++)
			if (!(( (person.qq[i]>='0')&&(person.qq[i]<='9') ) || (person.qq[i] = ','))){
				errorMsg = "Unknown character in QQ option.";
				return false;
			}
		temp_str.clear();
		temp_str = this->part_tq(person, "qq");
		for (i = 0; i<temp_str.size(); i++){
			for (j = i + 1; j<temp_str.size();j++){
				if (temp_str.at(i) == temp_str.at(j)){
					errorMsg = "Duplicated QQ number(s).";
					return false;
				}
			}
			if (temp_str.at(i) != ""){
				re_write += temp_str.at(i);
				re_write += ",";
			}
		}
		re_write = re_write.substr(0,re_write.length()-1);
		strcpy(person.qq,re_write.c_str());
	}
	
	return true;
}

vector<string> ContactInterface::part_tq(const Person& person, const char* const TEL_QQ) const {
	vector<string> rtn_vec;
	string src_str;
	string temp_str = "";
	if (strcmp(TEL_QQ,"tel") == 0)
		src_str = person.tel;
	else if (strcmp(TEL_QQ,"qq") == 0)
		src_str = person.qq;
	else
		return rtn_vec;

	for (int i = 0; i<strlen(src_str.c_str()); i++){
		if (src_str[i] == ','){
			rtn_vec.push_back(temp_str);
			temp_str = "";
		}
		else
			temp_str += src_str[i];
	}
	rtn_vec.push_back(temp_str);
	return rtn_vec;
}