// MainVewMenuInterface.h: interface for the MainVewMenuInterface class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINVEWMENUINTERFACE_H__7A32F346_890E_45E1_941B_4FC6A6A3714A__INCLUDED_)
#define AFX_MAINVEWMENUINTERFACE_H__7A32F346_890E_45E1_941B_4FC6A6A3714A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainStrategy.h"
#include "ViewStrategy.h"

class MainVewMenuInterface : public MainStrategy
{
public:
private:
	ViewStrategy* viewStrategy;

	virtual ViewStrategy* setViewStrategy(int) = 0;
	int view(Person* v_Person) const;								//View a Person member with details

public:
	MainVewMenuInterface();
	virtual ~MainVewMenuInterface();
	virtual int doMainStrategy();

};

#endif // !defined(AFX_MAINVEWMENUINTERFACE_H__7A32F346_890E_45E1_941B_4FC6A6A3714A__INCLUDED_)
