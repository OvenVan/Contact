// ViewCategoryMenu.cpp: implementation of the ViewCategoryMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ViewCategoryMenu.h"

Person* ViewCategoryMenu::doViewStrategy(){
	string info_str = ViewStrategy::category_vew();
	int num = contact_item.size();
	vector<int> chosen_item;

	for (int i = 0; i < num; i++){
		if (strcmp(&*contact_item[i]->category,info_str.c_str()) == 0 ){
			chosen_item.push_back(i);
			cout<<"("<<chosen_item.size()<<"): "<<&*contact_item[i]->name<<"    TEL: "<<&*contact_item[i]->tel<<"    ADDR: "<<&*contact_item[i]->addr<<endl;
			Sleep(20);
		}
	}
	return anythingView(chosen_item);
}
