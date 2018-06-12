// MainVewMenu.h: interface for the MainVewMenu class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINVEWMENU_H__30EDC353_618B_4196_A8BB_4A59557068CD__INCLUDED_)
#define AFX_MAINVEWMENU_H__30EDC353_618B_4196_A8BB_4A59557068CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainStrategy.h"
#include "ViewFactory.h"

class MainVewMenu : public MainStrategy
{
public:
	MainVewMenu();
	virtual ~MainVewMenu();
	virtual int doMainStrategy();

protected:
	bool delete_prsn(Person&) const;
	int modify_prsn(Person&) const;								//Way to modify a spefic Person member, with 0->success, -1->fail

private:
	ViewStrategy* viewStrategy;

	void before_doMainStrategy();
	int exfz_vew(const char*, const char*, const char*) const{return 0;}		//Menu of Exact/Fuzzy view
	int cgy_vew() const{return 0;}										//Menu of Category view
	int all_vew() const{return 0;}											//Menu of All view
	bool check(Person&, const bool _check_repe) const{return true;}
};

#endif // !defined(AFX_MAINVEWMENU_H__30EDC353_618B_4196_A8BB_4A59557068CD__INCLUDED_)
