#if !defined(AFX_CONTACTINTERFACE_H__61397655_84DB_48A0_A5E4_041E75321807__INCLUDED_)
#define AFX_CONTACTINTERFACE_H__61397655_84DB_48A0_A5E4_041E75321807__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainStrategy.h"
#include "MainNewMenu.h"
#include "MainDelMenu.h"
#include "MainMdfMenu.h"
#include "MainVewMenu.h"

class ContactInterface
{
private:
	MainStrategy* mainStrategy;
	virtual MainStrategy* setMainStrategy(int) = 0;

public:
	virtual int main_menu();
	virtual ~ContactInterface(){};
};

#endif // !defined(AFX_CONTACTINTERFACE_H__61397655_84DB_48A0_A5E4_041E75321807__INCLUDED_)
