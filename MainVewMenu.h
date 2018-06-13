// MainVewMenu.h: interface for the MainVewMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINVEWMENU_H__30EDC353_618B_4196_A8BB_4A59557068CD__INCLUDED_)
#define AFX_MAINVEWMENU_H__30EDC353_618B_4196_A8BB_4A59557068CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainVewMenuInterface.h"

#include "ViewExactMenu.h"
#include "ViewAllMenu.h"
#include "ViewCategoryMenu.h"
#include "ViewFuzzyMenu.h"


class MainVewMenu : public MainVewMenuInterface
{
private:
	ViewStrategy* setViewStrategy(int);
public:
	MainVewMenu();
	virtual ~MainVewMenu();
};

#endif // !defined(AFX_MAINVEWMENU_H__30EDC353_618B_4196_A8BB_4A59557068CD__INCLUDED_)
