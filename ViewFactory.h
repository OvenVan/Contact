// ViewFactory.h: interface for the ViewFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWFACTORY_H__E0CD206D_4361_4A36_AC92_D5E2884FA297__INCLUDED_)
#define AFX_VIEWFACTORY_H__E0CD206D_4361_4A36_AC92_D5E2884FA297__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ViewStrategy.h"

class ViewFactory	//abstrat class interface
{
public:
	virtual ViewStrategy* createStrategy() = 0;
	virtual ~ViewFactory();

};

#endif // !defined(AFX_VIEWFACTORY_H__E0CD206D_4361_4A36_AC92_D5E2884FA297__INCLUDED_)
