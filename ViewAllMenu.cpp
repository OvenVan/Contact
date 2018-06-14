// ViewAllMenu.cpp: implementation of the ViewAllMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ViewAllMenu.h"

Person* ViewAllMenu::doViewStrategy(){
	int num = contact_item.size();
	int index = 0;
	vector<int> chosen_item;

	ViewStrategy::all_vew();

	for (int i = 0;i<num;i++){
		chosen_item.push_back(i);
		cout<<"("<<chosen_item.size()<<"): "<<&*contact_item[i]->name<<"    TEL: "<<&*contact_item[i]->tel<<"    ADDR: "<<&*contact_item[i]->addr<<endl;
		Sleep(20);
	}
	return anythingView(chosen_item);
}
