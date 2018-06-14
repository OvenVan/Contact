// ViewFuzzyMenu.h: Application Library
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWFUZZYMENU_H__D10D5C93_EEF6_40EA_AEBB_C289EE09C1EF__INCLUDED_)
#define AFX_VIEWFUZZYMENU_H__D10D5C93_EEF6_40EA_AEBB_C289EE09C1EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ViewStrategy.h"

class ViewFuzzyMenu : public ViewStrategy
{
public:
	virtual ~ViewFuzzyMenu(){};
	Person* doViewStrategy();
};

#endif // !defined(AFX_VIEWFUZZYMENU_H__D10D5C93_EEF6_40EA_AEBB_C289EE09C1EF__INCLUDED_)
