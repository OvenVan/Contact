// CheckInterface.cpp: implementation of the CheckInterface class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CheckInterface.h"


bool CheckInterface::check(Person& person, const bool _check_repe) const {	
	unsigned i = 0, j = 0;						//common loop variable
	string re_write = "";				//rewrite tel and qq(if valid) into good format
	vector<string> temp_str;
	bool mailFlag = false;			 //check mailbox's format
//===============================

	if (!((strlen(person.name)>0) && (strlen(person.tel)>0) && (strlen(person.addr)>0)) ){
		errorMsg = "Name/Tel/Address is null.";
		return false;
	}	
//===============================

	if (_check_repe){				//here to use _check_repe only once.
		for (i = 0; i < contact_item.size(); i++)
			if (strcmp(person.name,&*contact_item[i]->name) == 0){
				errorMsg = "Item already exists.";
				return false;
			}
	}	
//===============================

	for (i = 0; i<strlen(person.tel); i++){
		if (!(( (person.tel[i]>='0')&&(person.tel[i]<='9') ) || (person.tel[i] == ','))){
			errorMsg = "Unknown character in Tel option.";
			return false;
		}
	}
	temp_str = this->part_tq(person, "tel");
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
//===============================
	
	if (person.sex != '\0'){
		if ((person.sex == 'f') || (person.sex == 'm'))
			person.sex -=32;
		if ( !( (person.sex == 'F') || (person.sex == 'M') ) ){
			errorMsg = "Unknown character in Gender option.";
			return false;
		}
	}	
//===============================

	if (strcmp(person.mail,"") != 0){
		mailFlag = false;
		for (i = 0; i<strlen(person.mail); ++i){
			if (person.mail[i] == '@'){
				if (mailFlag){
					errorMsg = "Format of Mailbox fill is incorrect.";
					return false;
				}
				(!mailFlag) && (mailFlag = true);
			}
		}//for
		if (!mailFlag){
			errorMsg = "Format of Mailbox fill is incorrect.";
			return false;
		}
	}	
//===============================
	
	if (strcmp(person.qq, "") != 0){
		re_write = "";
		for (i = 0; i<strlen(person.qq); i++)
			if (!(( (person.qq[i]>='0')&&(person.qq[i]<='9') ) || (person.qq[i] == ','))){
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
//===============================
	//...
}

bool CheckInterface::check_exact(const Person& index, const string info_str) const{
	if (strcmp(index.name,info_str.c_str()) == 0)
		return true;
	vector<string> temp_vec = part_tq(index, "tel");
	for (unsigned i = 0; i<temp_vec.size(); i++){
		if (strcmp(temp_vec.at(i).c_str(),info_str.c_str()) == 0)
			return true;
	}
	return false;
}

vector<string> CheckInterface::part_tq(const Person& person, const char* const TEL_QQ) const {
	vector<string> rtn_vec;
	string src_str;
	string temp_str = "";
	if (strcmp(TEL_QQ,"tel") == 0)
		src_str = person.tel;
	else if (strcmp(TEL_QQ,"qq") == 0)
		src_str = person.qq;
	else
		return rtn_vec;

	for (unsigned i = 0; i<strlen(src_str.c_str()); i++){
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
