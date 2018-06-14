// ViewExactMenu.cpp: implementation of the ViewExactMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ViewExactMenu.h"

Person* ViewExactMenu::doViewStrategy(){
	string info_str = ViewStrategy::title_vew("=====Exact Query Contact===============", "\tEnter infomation that needs to be querying: ");
	int num = contact_item.size();
	int index = 0;
	vector<int> chosen_item;

	for (int i = 0; i < num; i++){
		if (  check_exact(*contact_item[i], info_str)){
			chosen_item.push_back(i);
			cout<<"("<<chosen_item.size()<<"): "<<&*contact_item[i]->name<<"    TEL: "<<&*contact_item[i]->tel<<"    ADDR: "<<&*contact_item[i]->addr<<endl;
			Sleep(20);
		}
	}
	return anythingView(chosen_item);	
}	
