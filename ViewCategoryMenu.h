// ViewCategoryMenu.h: interface for the ViewCategoryMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWCATEGORYMENU_H__48B023E6_1B4C_4082_A1E2_BB55EEC3B766__INCLUDED_)
#define AFX_VIEWCATEGORYMENU_H__48B023E6_1B4C_4082_A1E2_BB55EEC3B766__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ViewStrategy.h"
#include "ViewFactory.h"

class ViewCategoryMenu : public ViewStrategy
{
public:
	ViewCategoryMenu();
	virtual ~ViewCategoryMenu();
	Person* doViewStrategy(){return NULL;}

};

class ViewCategoryMenuFactory : public ViewFactory
{
public:
	ViewStrategy* createStrategy();
};


#endif // !defined(AFX_VIEWCATEGORYMENU_H__48B023E6_1B4C_4082_A1E2_BB55EEC3B766__INCLUDED_)
