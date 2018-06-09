
#include "stdafx.h"
#include "Person.h"

extern string errorMsg;
extern vector<Person*> contact_item;

Person::Person()
{
	strcpy(this->addr,"");
	strcpy(this->category,"");
	strcpy(this->mail, "");
	strcpy(this->name, "");
	strcpy(this->qq, "");
	this->sex = '\0';
	strcpy(this->tel, "");
	strcpy(this->zip, "");
}

Person::~Person()
{

}

bool Person::check(const bool _check_repe) {	
	int i = 0, j = 0;
	string re_write = "";
	if (!((strlen(name)>0) && (strlen(tel)>0) && (strlen(addr)>0)) ){
		errorMsg = "Name/Tel/Address is null.";
		return false;
	}

	if (_check_repe){				//here to use _check_repe only once.
		for (i = 0; i < contact_item.size(); i++)
			if (strcmp(name,&*contact_item[i]->name) == 0){
				sizeof(*contact_item[i]);
				errorMsg = "Item already exists.";
				return false;
			}
	}

	for (i = 0; i<strlen(tel); i++){
		if (!(( (tel[i]>='0')&&(tel[i]<='9') ) || (tel[i] == ','))){
			errorMsg = "Unknown character in Tel option.";
			return false;
		}
	}
	vector<string> temp_str = this->part_tq("tel");
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
	strcpy(tel,re_write.c_str());
	
	if (sex != '\0'){
		if ((sex == 'f') || (sex == 'm'))
			sex -=32;
		if ( !( (sex == 'F') || (sex == 'M') ) ){
			errorMsg = "Unknown character in Gender option.";
			return false;
		}
	}
	
	if (strcmp(qq, "") != 0){
		re_write = "";
		for (i = 0; i<strlen(qq); i++)
			if (!(( (qq[i]>='0')&&(qq[i]<='9') ) || (qq[i] = ','))){
				errorMsg = "Unknown character in QQ option.";
				return false;
			}
		temp_str.clear();
		temp_str = this->part_tq("qq");
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
		strcpy(qq,re_write.c_str());
	}
	
	return true;
}

vector<string> Person::part_tq(const char* const TEL_QQ) const {
	vector<string> rtn_vec;
	string src_str;
	string temp_str = "";
	if (strcmp(TEL_QQ,"tel") == 0)
		src_str = this->tel;
	else if (strcmp(TEL_QQ,"qq") == 0)
		src_str = this->qq;
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