// MainFactory.h: interface for the MainFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFACTORY_H__1E35C24D_7CA6_45D1_AFA9_7DB534280A45__INCLUDED_)
#define AFX_MAINFACTORY_H__1E35C24D_7CA6_45D1_AFA9_7DB534280A45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MainStrategy.h"

class MainFactory  
{
public:
	virtual ~MainFactory(){};
	virtual MainStrategy* createStrategy() = 0;
};



#endif // !defined(AFX_MAINFACTORY_H__1E35C24D_7CA6_45D1_AFA9_7DB534280A45__INCLUDED_)
