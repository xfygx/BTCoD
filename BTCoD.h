// BTCoD.h : main header file for the BTCOD application
//

#if !defined(AFX_BTCOD_H__FBA961B6_2970_403F_848F_2454499A19BE__INCLUDED_)
#define AFX_BTCOD_H__FBA961B6_2970_403F_848F_2454499A19BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBTCoDApp:
// See BTCoD.cpp for the implementation of this class
//

class CBTCoDApp : public CWinApp
{
public:
	CBTCoDApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBTCoDApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBTCoDApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BTCOD_H__FBA961B6_2970_403F_848F_2454499A19BE__INCLUDED_)
