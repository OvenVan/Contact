// PrtMenuInterface.h: Frame Gallary
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRTMENUINTERFACE_H__77F54599_9711_43E8_97E8_278F62DD0880__INCLUDED_)
#define AFX_PRTMENUINTERFACE_H__77F54599_9711_43E8_97E8_278F62DD0880__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class PrtMenuInterface  
{
protected:
	virtual bool readFile(const char*, void(*)() = NULL) const;
public:
	virtual ~PrtMenuInterface(){};
};

#endif // !defined(AFX_PRTMENUINTERFACE_H__77F54599_9711_43E8_97E8_278F62DD0880__INCLUDED_)
