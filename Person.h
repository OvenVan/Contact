// Person.h: interface for the Person class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_Person_H__4EDC1B44_F6DC_404A_ADA9_E56095080841__INCLUDED_)
#define AFX_Person_H__4EDC1B44_F6DC_404A_ADA9_E56095080841__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAXNAME	100
#define MAXTEL	80
#define	MAXADDR	100
#define MAXZIP	10
#define	MAXMAIL	80
#define MAXQQ	40
#define MAXCTGY	20



class Person  
{
public:
	//why procted does not work?
	char name[MAXNAME];
	char sex;
	char tel[MAXTEL];
	char addr[MAXADDR];
	char zip[MAXZIP];	
	char mail[MAXMAIL];
	char qq[MAXQQ];
	char category[MAXCTGY];

	Person();
	~Person();
};

extern vector<Person*> contact_item;
extern string errorMsg;

#endif // !defined(AFX_Person_H__4EDC1B44_F6DC_404A_ADA9_E56095080841__INCLUDED_)
