// person.h: interface for the person class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PERSON_H__4EDC1B44_F6DC_404A_ADA9_E56095080841__INCLUDED_)
#define AFX_PERSON_H__4EDC1B44_F6DC_404A_ADA9_E56095080841__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "cls_contact.h"

extern string errorMsg;			//stdafx.cpp


class person  
{
public:
	char name[100];
	char sex;
	char tel[80];
	char addr[100];
	char zip[10];	//” ±‡
	char mail[80];
	char qq[40];
	char category[20];

	person();
	virtual ~person();
	bool check(bool _check_repe);
	vector<string> part_tq(const char* TEL_QQ);
};

extern vector<person> contact_item;

#endif // !defined(AFX_PERSON_H__4EDC1B44_F6DC_404A_ADA9_E56095080841__INCLUDED_)
