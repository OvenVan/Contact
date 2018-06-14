// MainDelMenu.h: Application Library
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINDELMENU_H__59F8280E_220C_4D11_9B6E_96B22BB96034__INCLUDED_)
#define AFX_MAINDELMENU_H__59F8280E_220C_4D11_9B6E_96B22BB96034__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainStrategy.h"

class MainDelMenu : public MainStrategy
{
public:
	virtual ~MainDelMenu(){};
	int doMainStrategy();
};

#endif // !defined(AFX_MAINDELMENU_H__59F8280E_220C_4D11_9B6E_96B22BB96034__INCLUDED_)
