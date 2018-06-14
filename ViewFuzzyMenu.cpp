// ViewFuzzyMenu.cpp: implementation of the ViewFuzzyMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ViewFuzzyMenu.h"

Person* ViewFuzzyMenu::doViewStrategy(){
	string info_str = ViewStrategy::title_vew("=====Fuzzy Query Contact===============", "\tEnter infomation that needs to be querying: ");
	int num = contact_item.size();
	int index = 0;
	vector<int> chosen_item;

	for (int i = 0; i < num; i++){
		if ((strstr(&*contact_item[i]->addr,info_str.c_str()) != NULL) || (strstr(&*contact_item[i]->name ,info_str.c_str()) != NULL) || (strstr(&*contact_item[i]->tel ,info_str.c_str()) != NULL)  )    {
			chosen_item.push_back(i);
			cout<<"("<<chosen_item.size()<<"): "<<&*contact_item[i]->name<<"    TEL: "<<&*contact_item[i]->tel<<"    ADDR: "<<&*contact_item[i]->addr<<endl;
			Sleep(20);
		}
	}
	return anythingView(chosen_item);
}
