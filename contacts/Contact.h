// Contact.h: interface for the Contact class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_)
#define AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Person.h"

class Contact
{
private:
	Person* anything_view(vector<int>&) const;
	bool check_exact(const Person&, const string) const;		//check if index.name == info_str
public:
	Contact();
	virtual ~Contact();

	bool create() const;
	int refresh() const;
	bool delete_prsn(Person&) const;
	void print_prsn(const Person&, const string, bool) const;
	void printAll() const;
	int modify_prsn(Person&) const;
	Person* exactView(const string) const;
	Person* fuzzyView(const string) const;
	Person* categoryView(const string) const;
	Person* allView() const;	
};

#endif // !defined(AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_)
