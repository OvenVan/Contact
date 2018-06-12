// ViewFuzzyMenu.cpp: implementation of the ViewFuzzyMenu class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ViewFuzzyMenu.h"

ViewFuzzyMenu::ViewFuzzyMenu()
{

}

ViewFuzzyMenu::~ViewFuzzyMenu()
{

}

ViewStrategy* ViewFuzzyMenuFactory::createStrategy(){
	return (new ViewFuzzyMenu);
}
