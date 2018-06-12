// ViewCategoryMenu.cpp: implementation of the ViewCategoryMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ViewCategoryMenu.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ViewCategoryMenu::ViewCategoryMenu()
{

}

ViewCategoryMenu::~ViewCategoryMenu()
{

}

ViewStrategy* ViewCategoryMenuFactory::createStrategy(){
	return (new ViewCategoryMenu);
}
