// Contact.h: interface for the Contact class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_)
#define AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "ContactInterface.h"

class Contact : public ContactInterface 
{
private:
	Person* anything_view(vector<int>&) const;
	bool check_exact(const Person&, const string) const;		//check if index.name == info_str
	Person* exactView(const string) const;
	Person* fuzzyView(const string) const;
	Person* categoryView(const string) const;
	Person* allView() const;

	Contact(const Contact&);
	const Contact& operator = (const Contact&);

public:
	Contact();
	~Contact();

	int refresh() const;										//override

protected:
	bool create() const;										//override
	bool delete_prsn(Person&) const;							//override
	void printAll() const;										//override
	int modify_prsn(Person&) const;								//override
	void print_prsn(const Person&, const string, bool) const;	//override
	int cgy_vew() const;										//override
	int all_vew() const;										//override
	int exfz_vew(const char*, const char*, const char*) const;	//override
};							

#endif // !defined(AFX_Contact_H__578FBE4B_85A0_4A32_B651_7CF4D553E488__INCLUDED_)
