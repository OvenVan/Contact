// cls_contact.h: interface for the cls_contact class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLS_CONTACT_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_)
#define AFX_CLS_CONTACT_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "person.h"


class cls_contact  
{
public:
	cls_contact();
	virtual ~cls_contact();
	bool create();
	int refresh();
	
};

#endif // !defined(AFX_CLS_CONTACT_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_)
