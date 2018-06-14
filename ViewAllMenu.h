// ViewAllMenu.h: Application Library
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWALLMENU_H__8C79467E_E8F5_483F_8EBE_66DD4CE77A44__INCLUDED_)
#define AFX_VIEWALLMENU_H__8C79467E_E8F5_483F_8EBE_66DD4CE77A44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ViewStrategy.h"

class ViewAllMenu : public ViewStrategy
{
public:
	virtual ~ViewAllMenu(){};
	Person* doViewStrategy();
};

#endif // !defined(AFX_VIEWALLMENU_H__8C79467E_E8F5_483F_8EBE_66DD4CE77A44__INCLUDED_)
