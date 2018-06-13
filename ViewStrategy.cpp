// ViewStrategy.cpp: implementation of the ViewStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ViewStrategy.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


ViewStrategy::~ViewStrategy()
{

}


string ViewStrategy::title_vew(const char* title, const char* descp) const{
	string info_str;
	Person* viewPerson = NULL;

	system("cls");
	cout<<endl;
	cout<<title<<endl<<endl;
	cout<<descp;
	cin.clear();
	cin.sync();
	cin>>info_str;

	return info_str;

}



Person* ViewStrategy::anythingView(vector<int>& chosen_item) const{
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

void ViewStrategy::all_vew() const{
	int i = 0,j = 0;	
	Person* viewPerson = NULL;

	system("cls");
	cout<<endl;
	cout<<"=====ALL Category======================\n\n";
	return;
}

string ViewStrategy::category_vew() const{
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

	return info_str;
}