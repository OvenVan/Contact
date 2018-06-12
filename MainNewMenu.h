// MainNewMenu.h: interface for the MainNewMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINNEWMENU_H__FAE001ED_B300_4102_8F33_09E79DFDAEA6__INCLUDED_)
#define AFX_MAINNEWMENU_H__FAE001ED_B300_4102_8F33_09E79DFDAEA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainVewMenu.h"

class MainNewMenu : public MainVewMenu
{
public:
	MainNewMenu();
	virtual ~MainNewMenu();
	int doMainStrategy();

protected:
	bool create() const{return true;}

};

#endif // !defined(AFX_MAINNEWMENU_H__FAE001ED_B300_4102_8F33_09E79DFDAEA6__INCLUDED_)
