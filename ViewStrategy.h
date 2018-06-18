// ViewStrategy.h: Frame Gallary
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWSTRATEGY_H__EC4D2837_CB82_4C72_90B0_0F5B88767A63__INCLUDED_)
#define AFX_VIEWSTRATEGY_H__EC4D2837_CB82_4C72_90B0_0F5B88767A63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CheckInterface.h"

class ViewStrategy : public CheckInterface
{
protected:
	string title_vew(const char*, const char*) const;		//for exact/fuzzy view
	void all_vew() const;
	string category_vew() const;
	Person* anythingView(vector<int>&) const;
public:
	virtual ~ViewStrategy(){};
	virtual Person* doViewStrategy() = 0;
};

#endif // !defined(AFX_VIEWSTRATEGY_H__EC4D2837_CB82_4C72_90B0_0F5B88767A63__INCLUDED_)
