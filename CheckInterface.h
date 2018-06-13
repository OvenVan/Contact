// CheckInterface.h: interface for the CheckInterface class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHECKINTERFACE_H__ABFADC84_DBE2_4985_9360_97CF317116D0__INCLUDED_)
#define AFX_CHECKINTERFACE_H__ABFADC84_DBE2_4985_9360_97CF317116D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Person.h"

class CheckInterface  
{
public:
	bool check(Person&, const bool _check_repe) const;
	bool check_exact(const Person&, const string) const;		//check if index.name == info_str
	virtual ~CheckInterface(){};

private:
	vector<string> part_tq(const Person&, const char* const) const;
};

#endif // !defined(AFX_CHECKINTERFACE_H__ABFADC84_DBE2_4985_9360_97CF317116D0__INCLUDED_)
