#if !defined(AFX_CONTACTINTERFACE_H__61397655_84DB_48A0_A5E4_041E75321807__INCLUDED_)
#define AFX_CONTACTINTERFACE_H__61397655_84DB_48A0_A5E4_041E75321807__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Person.h"

class ContactInterface
{
public:
	virtual int main_menu();
	virtual int new_menu();
	virtual int del_menu();
	virtual int mdf_menu();
	virtual int vew_menu();

	virtual ~ContactInterface(){};

protected:
	virtual int exfz_vew(const char*, const char*, const char*) const;		//Menu of Exact/Fuzzy view
	virtual int cgy_vew() const;											//Menu of Category view
	virtual int all_vew() const;											//Menu of All view

	virtual bool create() const = 0;										//Way to create a Person member
	virtual bool delete_prsn(Person&) const = 0;							//Way to delete a spefic Person member
	virtual void printAll() const = 0;										//Way to print all Person member
	virtual int modify_prsn(Person&) const = 0;								//Way to modify a spefic Person member, with 0->success, -1->fail
	virtual void print_prsn(const Person&, const string, bool) const = 0;	//Way to print a spefic Person member 

	virtual Person* exactView(const string) const = 0;						//Return the Person member under the guide of string
	virtual Person* fuzzyView(const string) const = 0;						//  return NULL if nothing is found. 
	virtual Person* categoryView(const string) const = 0;
	virtual Person* allView() const = 0;



	virtual int view(Person& v_Person) const;								//View a Person member with details

	bool check(Person&, const bool _check_repe) const;
	vector<string> part_tq(const Person&, const char* const) const;
};

#endif // !defined(AFX_CONTACTINTERFACE_H__61397655_84DB_48A0_A5E4_041E75321807__INCLUDED_)
