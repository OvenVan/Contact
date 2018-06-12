// MainDelMenu.h: interface for the MainDelMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINDELMENU_H__59F8280E_220C_4D11_9B6E_96B22BB96034__INCLUDED_)
#define AFX_MAINDELMENU_H__59F8280E_220C_4D11_9B6E_96B22BB96034__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainVewMenu.h"

class MainDelMenu : public MainVewMenu
{
public:
	MainDelMenu();
	virtual ~MainDelMenu();
	int doMainStrategy();

};

#endif // !defined(AFX_MAINDELMENU_H__59F8280E_220C_4D11_9B6E_96B22BB96034__INCLUDED_)
