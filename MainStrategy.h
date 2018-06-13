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
	virtual void printAll() const;	
	virtual void print_prsn(const Person&, const string, bool) const;




};

//extern vector<Person*> contact_item;

#endif // !defined(AFX_MAINSTRATEGY_H__EC9C2730_7A1B_40AF_AB90_CC8AC25EC1B5__INCLUDED_)
