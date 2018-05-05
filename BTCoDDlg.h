// BTCoDDlg.h : header file
//

#if !defined(AFX_BTCODDLG_H__9701A2D7_3865_4922_B8AE_C035FFC83CBB__INCLUDED_)
#define AFX_BTCODDLG_H__9701A2D7_3865_4922_B8AE_C035FFC83CBB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CBTCoDDlg dialog

class CBTCoDDlg : public CDialog
{
// Construction
public:
	CBTCoDDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CBTCoDDlg)
	enum { IDD = IDD_BTCOD_DIALOG };
	CComboBox	m_ctrlMinor;
	CComboBox	m_ctrlMajor;
	BOOL	m_bCheckAudio;
	BOOL	m_bCheckCapture;
	BOOL	m_bCheckLimited;
	BOOL	m_bCheckNetwork;
	BOOL	m_bCheckObject;
	BOOL	m_bCheckPosition;
	BOOL	m_bCheckRender;
	BOOL	m_bCheckTelephony;
	CString	m_strClassHex;
	BOOL	m_bCheckInformation;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBTCoDDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBTCoDDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheckAudio();
	afx_msg void OnCheckCapture();
	afx_msg void OnCheckLimited();
	afx_msg void OnCheckNetwork();
	afx_msg void OnCheckObject();
	afx_msg void OnCheckPosition();
	afx_msg void OnCheckRender();
	afx_msg void OnCheckTelephony();
	afx_msg void OnSelchangeComboMajor();
	afx_msg void OnAbout();
	afx_msg void OnSelchangeComboMinor();
	afx_msg void OnCheckInformation();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	DWORD m_dwClass;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BTCODDLG_H__9701A2D7_3865_4922_B8AE_C035FFC83CBB__INCLUDED_)
