// MainTestMenu.h: interface for the MainTestMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINTESTMENU_H__4F0A9680_D41C_411A_B456_680B37EB8308__INCLUDED_)
#define AFX_MAINTESTMENU_H__4F0A9680_D41C_411A_B456_680B37EB8308__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainStrategy.h"

class MainTestMenu : public MainStrategy  
{
public:
	MainTestMenu();
	virtual ~MainTestMenu();
	virtual int doMainStrategy(){
		cout<<"test!\n";
		getch();
		return 0;
	}
};

#endif // !defined(AFX_MAINTESTMENU_H__4F0A9680_D41C_411A_B456_680B37EB8308__INCLUDED_)
