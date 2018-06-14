// MainNewMenu.h: Application Library
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINNEWMENU_H__FAE001ED_B300_4102_8F33_09E79DFDAEA6__INCLUDED_)
#define AFX_MAINNEWMENU_H__FAE001ED_B300_4102_8F33_09E79DFDAEA6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainStrategy.h"

class MainNewMenu : public MainStrategy
{
private:
	bool create() const;
public:
	virtual ~MainNewMenu(){};
	int doMainStrategy();
};

#endif // !defined(AFX_MAINNEWMENU_H__FAE001ED_B300_4102_8F33_09E79DFDAEA6__INCLUDED_)
