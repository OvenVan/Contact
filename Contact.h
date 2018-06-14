// Contact.h: Application Library
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_)
#define AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "ContactInterface.h"
#include "ContactInit.h"

#include "MainNewMenu.h"
#include "MainDelMenu.h"
#include "MainMdfMenu.h"
#include "MainVewMenu.h"

#include "MainTestMenu.h"

class Contact : public ContactInterface, public ContactInit
{
private:
	MainStrategy* setMainStrategy(int);		//override from ContactInterface
	void removeMainStrategy(void*);
public:
	Contact();
	~Contact();
	int refresh() const;	
	void welcome() const;
};							

#endif // !defined(AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_)
