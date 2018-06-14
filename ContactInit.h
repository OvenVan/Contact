// ContactInit.h: Frame Gallary
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTACTINIT_H__5C8BC83A_4BE8_4C6A_A36F_6CF4CC06AA7B__INCLUDED_)
#define AFX_CONTACTINIT_H__5C8BC83A_4BE8_4C6A_A36F_6CF4CC06AA7B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ContactInit  
{
public:
	virtual ~ContactInit(){};
	virtual int refresh() const = 0;	
	virtual void welcome() const= 0;
};

#endif // !defined(AFX_CONTACTINIT_H__5C8BC83A_4BE8_4C6A_A36F_6CF4CC06AA7B__INCLUDED_)
