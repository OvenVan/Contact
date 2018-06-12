// MainMdfMenu.h: interface for the MainMdfMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINMDFMENU_H__4AF95322_636F_4CB7_B574_C8FB878AFB87__INCLUDED_)
#define AFX_MAINMDFMENU_H__4AF95322_636F_4CB7_B574_C8FB878AFB87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainVewMenu.h"

class MainMdfMenu : public MainVewMenu
{
public:
	MainMdfMenu();
	virtual ~MainMdfMenu();
	int doMainStrategy();

};

#endif // !defined(AFX_MAINMDFMENU_H__4AF95322_636F_4CB7_B574_C8FB878AFB87__INCLUDED_)
