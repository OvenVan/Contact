// ContactInit.h: interface for the CContactInit class.
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
	virtual int refresh() const = 0;	
	virtual void welcome() const= 0;
	//virtual void joke() const = 0;

	virtual ~ContactInit(){};

};

#endif // !defined(AFX_CONTACTINIT_H__5C8BC83A_4BE8_4C6A_A36F_6CF4CC06AA7B__INCLUDED_)
