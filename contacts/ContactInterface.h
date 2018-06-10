#if !defined(AFX_CONTACTINTERFACE_H__61397655_84DB_48A0_A5E4_041E75321807__INCLUDED_)
#define AFX_CONTACTINTERFACE_H__61397655_84DB_48A0_A5E4_041E75321807__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Person.h"

class ContactInterface : public Person
{
public:
	virtual int new_menu();
	virtual int del_menu();
	virtual int mdf_menu();
	virtual int vew_menu();
	virtual int refresh() const = 0;	



protected:
	virtual bool create() const = 0;
	virtual bool delete_prsn(Person&) const = 0;
	virtual void printAll() const = 0;
	virtual int modify_prsn(Person&) const = 0;	
	virtual void print_prsn(const Person&, const string, bool) const = 0;
	virtual int cgy_vew() const = 0;
	virtual int all_vew() const = 0;
	virtual int exfz_vew(const char*, const char*, const char*) const = 0;

	virtual int view(Person& v_Person) const;

	bool check(Person&, const bool _check_repe) const;
	vector<string> part_tq(const Person&, const char* const) const;
};

#endif // !defined(AFX_CONTACTINTERFACE_H__61397655_84DB_48A0_A5E4_041E75321807__INCLUDED_)
