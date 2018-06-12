// ViewFuzzyMenu.h: interface for the ViewFuzzyMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWFUZZYMENU_H__D10D5C93_EEF6_40EA_AEBB_C289EE09C1EF__INCLUDED_)
#define AFX_VIEWFUZZYMENU_H__D10D5C93_EEF6_40EA_AEBB_C289EE09C1EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ViewStrategy.h"
#include "ViewFactory.h"

class ViewFuzzyMenu : public ViewStrategy
{
public:
	ViewFuzzyMenu();
	virtual ~ViewFuzzyMenu();
	Person* doViewStrategy(){return NULL;}

};

class ViewFuzzyMenuFactory : public ViewFactory
{
public:
	ViewStrategy* createStrategy();
};


#endif // !defined(AFX_VIEWFUZZYMENU_H__D10D5C93_EEF6_40EA_AEBB_C289EE09C1EF__INCLUDED_)
