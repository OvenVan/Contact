// contacts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Contact.h"

int main_menu();
int new_menu();
int del_menu();
int mdf_menu();
int view(Person& v_Person);
int vew_menu();
int cgy_vew();
int all_vew();
int cmp_names(char*, char*);
int exfz_vew(const char*, const char*, const char*);

extern vector<Person*> contact_item;


static Contact* my_contact = NULL;


int main(int argc, char* argv[])
{
	int rtn_num = 0;
	int n = 0;		//number of imported contact(s)
	Contact default_contact;

	my_contact = &default_contact;
	setlocale(LC_ALL,"chs");
	cout<<"\n\n\n----------Welcome to the Address Book System.--------\n\n";
	cout<<"-----now LOADING address book...";
	
	n = my_contact->refresh();

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
	while(1){
		int i;
		if((i = rand()%10)>3)
			my_contact->refresh();
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
		cout<<endl<<endl;
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
	if(!my_contact->create())
		cout<<"\n\n\t\tInfomation Error!";
	else
		cout<<"\n\n\t\tInfomation Entry Success!";
	cin.clear();
	cin.sync();
	getchar();
	return 0;	
}


int del_menu(){
	int num = contact_item.size();
	int index = 0;
	string addr = ".\\contact\\";
	system("cls");
	cout<<endl;
	cout<<"=====Delete Contact====================\n\n";
	if (num > 1){
		my_contact->printAll();
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
	my_contact->print_prsn(*contact_item[index],"=====Delete Contact====================\n",true);
	my_contact->delete_prsn(*contact_item[index]);
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
		my_contact->printAll();
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

	my_contact->modify_prsn(*contact_item.at(index));
	cin.clear();
	cin.sync();
	getch();
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
int view(Person& v_Person){
	bool refresh = true;
	string addr = ".\\contact\\";
	int fuckin_stupid = 0;
	int slct_num = 0;
	do{
		my_contact->print_prsn(v_Person,"=====VIEW Contact====================\n",refresh);
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
		my_contact->delete_prsn(v_Person);
		break;
	case '2':
		my_contact->modify_prsn(v_Person);
		break;
	case '3':
		return 0;
	}
	return 0;
}

int exfz_vew(const char* title, const char* descp, const char* flag){
	string info_str;

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
		Person* viewPerson = NULL;
		if (flag == "exact")
			viewPerson = my_contact->exactView(info_str);
		else
			viewPerson = my_contact->fuzzyView(info_str);
		if (viewPerson != NULL){
			view(*viewPerson);
		}
	}
	cin.clear();
	cin.sync();
	getch();
	return 0;
}

int cgy_vew(){
	string info_str;
	vector<string> cur_ctg;
	string tmp_ctg;
	bool add_ctg;
	int index = 0;
	int i = 0,j = 0;
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
	
	Person* viewPerson = my_contact->categoryView(info_str);
	if (viewPerson != NULL){
		view(*viewPerson);
	}
	cin.clear();
	cin.sync();
	getch();
	return 0;

}
int all_vew(){
	int i = 0,j = 0;	
	Person temp_p;
	system("cls");
	cout<<endl;
	cout<<"=====ALL Category======================\n\n";
	Person* viewPerson = my_contact->allView();
	if (viewPerson != NULL){
		view(*viewPerson);
	}
	cin.clear();
	cin.sync();
	getch();
	return 0;
}

int cmp_names(char* c1, char* c2){
	string s1 = c1;
	string s2 = c2;
	if (s1 > s2) return 1;
	else return -1;
}
