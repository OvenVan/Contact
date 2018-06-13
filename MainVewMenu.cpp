// MainVewMenu.cpp: implementation of the MainVewMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainVewMenu.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MainVewMenu::MainVewMenu()
{

}

MainVewMenu::~MainVewMenu()
{

}

ViewStrategy* MainVewMenu::setViewStrategy(int slct_num){

	switch(slct_num){
	case '1':
		return new ViewExactMenu();
	case '2':
		return new ViewFuzzyMenu();
	case '3':
		return new ViewCategoryMenu();
	case '4':
		return new ViewAllMenu();
	case '5':
		break;
	}
	return NULL;
}

