// MainVewMenuInterface.h: Frame Gallary
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINVEWMENUINTERFACE_H__7A32F346_890E_45E1_941B_4FC6A6A3714A__INCLUDED_)
#define AFX_MAINVEWMENUINTERFACE_H__7A32F346_890E_45E1_941B_4FC6A6A3714A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainStrategy.h"
#include "ViewStrategy.h"
#include "PrtMenuInterface.h"

class MainVewMenuInterface : public MainStrategy, public PrtMenuInterface
{
private:
	ViewStrategy* viewStrategy;

	virtual ViewStrategy*  setViewStrategy(int) = 0;
	virtual void				 removeViewStrategy(void*) = 0;
	virtual int					  view(Person* v_Person) const;								//View a Person member with details
public:
	virtual ~MainVewMenuInterface(){};
	virtual int doMainStrategy();
};

#endif // !defined(AFX_MAINVEWMENUINTERFACE_H__7A32F346_890E_45E1_941B_4FC6A6A3714A__INCLUDED_)
