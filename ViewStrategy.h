// ViewStrategy.h: interface for the ViewStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWSTRATEGY_H__EC4D2837_CB82_4C72_90B0_0F5B88767A63__INCLUDED_)
#define AFX_VIEWSTRATEGY_H__EC4D2837_CB82_4C72_90B0_0F5B88767A63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Person.h"
#include "CheckInterface.h"

class ViewStrategy : public CheckInterface
{
public:

	virtual ~ViewStrategy();
	virtual Person* doViewStrategy() = 0;

protected:
	
	virtual const char* title_vew(const char*, const char*) const;		//for exact/fuzzy view
	virtual void all_vew() const;
	virtual const char* category_vew() const;


	Person* anythingView(vector<int>&) const;


};

#endif // !defined(AFX_VIEWSTRATEGY_H__EC4D2837_CB82_4C72_90B0_0F5B88767A63__INCLUDED_)
