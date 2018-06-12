// Contact.h: interface for the Contact class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_)
#define AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "ContactInterface.h"
#include "ContactInit.h"

class Contact : public ContactInterface, public ContactInit
{
private:

	bool check_exact(const Person&, const string) const;		//check if index.name == info_str
	Person* exactView(const string) const;						//override
	Person* fuzzyView(const string) const;						//override
	Person* categoryView(const string) const;					//override
	Person* allView() const;									//override
	Person* anythingView(vector<int>&) const;

	Contact(const Contact&);
	const Contact& operator = (const Contact&);

public:
	Contact();
	~Contact();

	int refresh() const;	
	void welcome() const;

protected:
	bool create() const;										//override
	bool delete_prsn(Person&) const;							//override
	void printAll() const;										//override
	int modify_prsn(Person&) const;								//override
	void print_prsn(const Person&, const string, bool) const;	//override
};							

#endif // !defined(AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_)
