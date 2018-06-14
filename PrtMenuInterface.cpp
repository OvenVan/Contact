// PrtMenuInterface.cpp: implementation of the PrtMenuInterface class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PrtMenuInterface.h"

bool PrtMenuInterface::readFile(const char* file, void(*events)()) const{
	char line[1024];
	memset(line, 0, 1024);
	FILE* fp = fopen(file,"r");
	if (fp == NULL){
		return false;
	}
	while(!feof(fp)){
		fgets(line, 1024, fp);
		cout<<line;
		strcpy(line, "");
		if (events != NULL){
			events();
		}
	}
	fclose(fp);
	return true;
}
