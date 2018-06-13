// MainStrategy.h: interface for the MainStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINSTRATEGY_H__EC9C2730_7A1B_40AF_AB90_CC8AC25EC1B5__INCLUDED_)
#define AFX_MAINSTRATEGY_H__EC9C2730_7A1B_40AF_AB90_CC8AC25EC1B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CheckInterface.h"

class MainStrategy : public CheckInterface
{
public:
	MainStrategy();
	virtual ~MainStrategy();
	virtual int doMainStrategy() = 0;

protected:
	void printAll() const;	
	void print_prsn(const Person&, const string, bool) const;

	bool delete_prsn(Person&) const;
	int modify_prsn(Person&) const;								//Way to modify a spefic Person member, with 0->success, -1->fail
};

//extern vector<Person*> contact_item;

#endif // !defined(AFX_MAINSTRATEGY_H__EC9C2730_7A1B_40AF_AB90_CC8AC25EC1B5__INCLUDED_)
