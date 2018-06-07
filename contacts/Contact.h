// Contact.h: interface for the Contact class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_)
#define AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Person.h"

class Contact : public Person
{
private:
	Person* anything_view(vector<int>&);

public:
	Contact();
	virtual ~Contact();

	bool create();
	int refresh();
	bool delete_prsn(Person&);
	void print_prsn(const Person&, const string, bool);
	void printAll();
	int modify_prsn(Person& m_Person);
	Person* exactView(const string);
	Person* fuzzyView(const string);
	Person* categoryView(const string);
	Person* allView();
	bool check_exact(Person&, string);		//check if index.name == info_str

};

#endif // !defined(AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_)
