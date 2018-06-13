// ViewExactMenu.h: interface for the ViewExactMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWEXACTMENU_H__33A9D84C_B321_4F0C_A59B_3777BF3AE004__INCLUDED_)
#define AFX_VIEWEXACTMENU_H__33A9D84C_B321_4F0C_A59B_3777BF3AE004__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ViewStrategy.h"

class ViewExactMenu : public ViewStrategy
{
public:
	ViewExactMenu();
	virtual ~ViewExactMenu();
	Person* doViewStrategy();

private:

};

#endif // !defined(AFX_VIEWEXACTMENU_H__33A9D84C_B321_4F0C_A59B_3777BF3AE004__INCLUDED_)
