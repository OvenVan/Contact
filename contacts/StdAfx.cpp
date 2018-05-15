// stdafx.cpp : source file that includes just the standard includes
//	contacts.pch will be the pre-compiled header
//	stdafx.obj will contain the pre-compiled type information

#include "stdafx.h"
#include "cls_contact.h"
#include "person.h"

vector<string> category_type;
vector<person> contact_item;

string errorMsg;

/*

char* resetStrwithcomma(const char* str){
	int length = strlen(str);
	size_t findComma = 0;

	//setlocale(LC_ALL,"chs");
	wchar_t* wc = c2wc(str);
	wstring wstr = wc;

	//setlocale(LC_ALL,"chs");
	while(findComma < length){
		findComma = wstr.find(L'£¬');
		if (findComma < length){
			wc[findComma] = L',';
			wstr = wc;
		}
	}	
	//setlocale(LC_ALL,"C");
	return wc2c(wc);
}

wchar_t* c2wc(const char* c){
	//setlocale(LC_ALL,"chs");
	size_t charNum = sizeof(char) * strlen(c) + 1;
	wchar_t* dest = (wchar_t*)malloc(charNum);
	mbstowcs(dest,c,charNum);
	//setlocale(LC_ALL, curLocale.c_str());
	return dest;
}

char* wc2c(const wchar_t* wc){
	//setlocale(LC_ALL,"chs");
	wstring wstr = wc;
	size_t charNum = wstr.size() + 1;
	char* dest = (char*)malloc(charNum);
	wcstombs(dest,wc,charNum);
	//setlocale(LC_ALL, curLocale.c_str());
	return dest;
}

  */