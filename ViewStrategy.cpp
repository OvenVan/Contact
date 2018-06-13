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


const char* ViewStrategy::title_vew(const char* title, const char* descp) const{
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
		return NULL;
	}
	else{	
		return info_str.c_str();
	}
	return 0;
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