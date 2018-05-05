// BTCoDDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BTCoD.h"
#include "BTCoDDlg.h"

#define CLASS_INFORMATION    0x00800000
#define CLASS_TELEPHONY      0x00400000
#define CLASS_AUDIO          0x00200000
#define CLASS_OBJECT         0x00100000
#define CLASS_CAPTURE        0x00080000
#define CLASS_RENDER         0x00040000
#define CLASS_NETWORK        0x00020000
#define CLASS_POSITION       0x00010000
#define CLASS_RESERVED01     0x00008000
#define CLASS_RESERVED02     0x00004000
#define CLASS_LIMIT          0x00002000

#define CLASS_MISCELLANEOUS  0x00000000
#define CLASS_COMPUTER       0x00000100
#define CLASS_PHONE          0x00000200
#define CLASS_LAN            0x00000300
#define CLASS_AUDIOVIEDO     0x00000400
#define CLASS_PERIPHERAL     0x00000500
#define CLASS_IMAGING        0x00000600
#define CLASS_WEARABLE       0x00000700
#define CLASS_TOY            0x00000800
#define CLASS_UNCATEGORIZED  0x00001F00
 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	DWORD m_dwClass;
	CAboutDlg();

	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:

};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	m_dwClass = 0;
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBTCoDDlg dialog

CBTCoDDlg::CBTCoDDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBTCoDDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBTCoDDlg)
	m_bCheckAudio = FALSE;
	m_bCheckCapture = FALSE;
	m_bCheckLimited = FALSE;
	m_bCheckNetwork = FALSE;
	m_bCheckObject = FALSE;
	m_bCheckPosition = FALSE;
	m_bCheckRender = FALSE;
	m_bCheckTelephony = FALSE;
	m_strClassHex = _T("");
	m_dwClass = 0;
	m_bCheckInformation = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	sprintf(m_strClassHex.GetBuffer(16), "0x%06X", m_dwClass);
}

void CBTCoDDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBTCoDDlg)
	DDX_Control(pDX, IDC_COMBO_MINOR, m_ctrlMinor);
	DDX_Control(pDX, IDC_COMBO_MAJOR, m_ctrlMajor);
	DDX_Check(pDX, IDC_CHECK_AUDIO, m_bCheckAudio);
	DDX_Check(pDX, IDC_CHECK_CAPTURE, m_bCheckCapture);
	DDX_Check(pDX, IDC_CHECK_LIMITED, m_bCheckLimited);
	DDX_Check(pDX, IDC_CHECK_NETWORK, m_bCheckNetwork);
	DDX_Check(pDX, IDC_CHECK_OBJECT, m_bCheckObject);
	DDX_Check(pDX, IDC_CHECK_POSITION, m_bCheckPosition);
	DDX_Check(pDX, IDC_CHECK_RENDER, m_bCheckRender);
	DDX_Check(pDX, IDC_CHECK_TELEPHONY, m_bCheckTelephony);
	DDX_Text(pDX, IDC_EDIT_CLASS_HEX, m_strClassHex);
	DDX_Check(pDX, IDC_CHECK_INFORMATION, m_bCheckInformation);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBTCoDDlg, CDialog)
	//{{AFX_MSG_MAP(CBTCoDDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK_AUDIO, OnCheckAudio)
	ON_BN_CLICKED(IDC_CHECK_CAPTURE, OnCheckCapture)
	ON_BN_CLICKED(IDC_CHECK_LIMITED, OnCheckLimited)
	ON_BN_CLICKED(IDC_CHECK_NETWORK, OnCheckNetwork)
	ON_BN_CLICKED(IDC_CHECK_OBJECT, OnCheckObject)
	ON_BN_CLICKED(IDC_CHECK_POSITION, OnCheckPosition)
	ON_BN_CLICKED(IDC_CHECK_RENDER, OnCheckRender)
	ON_BN_CLICKED(IDC_CHECK_TELEPHONY, OnCheckTelephony)
	ON_CBN_SELCHANGE(IDC_COMBO_MAJOR, OnSelchangeComboMajor)
	ON_BN_CLICKED(IDABOUT, OnAbout)
	ON_CBN_SELCHANGE(IDC_COMBO_MINOR, OnSelchangeComboMinor)
	ON_BN_CLICKED(IDC_CHECK_INFORMATION, OnCheckInformation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBTCoDDlg message handlers

BOOL CBTCoDDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBTCoDDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CBTCoDDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBTCoDDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CBTCoDDlg::OnCheckInformation() 
{
	UpdateData(TRUE);
	if ( m_bCheckInformation )
		m_dwClass |=  CLASS_INFORMATION;
	else
		m_dwClass &= ~CLASS_INFORMATION;	
	sprintf(m_strClassHex.GetBuffer(16), "0x%06X", m_dwClass);
	UpdateData(FALSE);	
}

void CBTCoDDlg::OnCheckAudio() 
{
	UpdateData(TRUE);
	if ( m_bCheckAudio )
		m_dwClass |=  CLASS_AUDIO;
	else
		m_dwClass &= ~CLASS_AUDIO;	
	sprintf(m_strClassHex.GetBuffer(16), "0x%06X", m_dwClass);
	UpdateData(FALSE);
}

void CBTCoDDlg::OnCheckCapture() 
{
	UpdateData(TRUE);
	if ( m_bCheckCapture )
		m_dwClass |=  CLASS_CAPTURE;
	else
		m_dwClass &= ~CLASS_CAPTURE;	
	sprintf(m_strClassHex.GetBuffer(16), "0x%06X", m_dwClass);
	UpdateData(FALSE);
}

void CBTCoDDlg::OnCheckLimited() 
{
	UpdateData(TRUE);
	if ( m_bCheckLimited )
		m_dwClass |=  CLASS_LIMIT;
	else
		m_dwClass &= ~CLASS_LIMIT;	
	sprintf(m_strClassHex.GetBuffer(16), "0x%06X", m_dwClass);
	UpdateData(FALSE);
}

void CBTCoDDlg::OnCheckNetwork() 
{
	UpdateData(TRUE);
	if ( m_bCheckNetwork )
		m_dwClass |=  CLASS_NETWORK;
	else
		m_dwClass &= ~CLASS_NETWORK;		
	sprintf(m_strClassHex.GetBuffer(16), "0x%06X", m_dwClass);
	UpdateData(FALSE);
}

void CBTCoDDlg::OnCheckObject() 
{
	UpdateData(TRUE);
	if ( m_bCheckObject )
		m_dwClass |=  CLASS_OBJECT;
	else
		m_dwClass &= ~CLASS_OBJECT;	
	sprintf(m_strClassHex.GetBuffer(16), "0x%06X", m_dwClass);
	UpdateData(FALSE);
}

void CBTCoDDlg::OnCheckPosition() 
{
	UpdateData(TRUE);
	if ( m_bCheckPosition )
		m_dwClass |=  CLASS_POSITION;
	else
		m_dwClass &= ~CLASS_POSITION;	
	sprintf(m_strClassHex.GetBuffer(16), "0x%06X", m_dwClass);
	UpdateData(FALSE);
}

void CBTCoDDlg::OnCheckRender() 
{
	UpdateData(TRUE);
	if ( m_bCheckRender )
		m_dwClass |=  CLASS_RENDER;
	else
		m_dwClass &= ~CLASS_RENDER;
	sprintf(m_strClassHex.GetBuffer(16), "0x%06X", m_dwClass);
	UpdateData(FALSE);	
}

void CBTCoDDlg::OnCheckTelephony() 
{
	UpdateData(TRUE);
	if ( m_bCheckTelephony )
		m_dwClass |=  CLASS_TELEPHONY;
	else
		m_dwClass &= ~CLASS_TELEPHONY;	
	sprintf(m_strClassHex.GetBuffer(16), "0x%06X", m_dwClass);
	UpdateData(FALSE);
}

void DeleteAllItem(CComboBox& ctrl)
{
	int i;
	
	for (i=ctrl.GetCount(); i>=0; i--)
		ctrl.DeleteString(i);

	ctrl.Clear();
}

void CBTCoDDlg::OnSelchangeComboMajor() 
{
	int iCurSel;

	UpdateData(TRUE);
	iCurSel = m_ctrlMajor.GetCurSel();

	m_dwClass &= ~CLASS_UNCATEGORIZED; // clear 8-12 bits
	m_dwClass &= 0xFFFFFF03; // clear 2-7 bits

	switch ( iCurSel )
	{
	case 0:
		DeleteAllItem(m_ctrlMinor);
		m_ctrlMinor.SetCurSel(0);
		break;
	case 1: // Computer Major Class
		DeleteAllItem(m_ctrlMinor);
		m_ctrlMinor.AddString("Uncategorized, code for device not assigned");
		m_ctrlMinor.AddString("Desktop workstation");
		m_ctrlMinor.AddString("Server-class computer");
		m_ctrlMinor.AddString("Laptop");
		m_ctrlMinor.AddString("Handheld PC/PDA (clam shell)");
		m_ctrlMinor.AddString("Palm sized PC/PDA");
		m_ctrlMinor.AddString("Wearable computer (Watch sized)");
		m_ctrlMinor.SetCurSel(0);
		m_dwClass |= CLASS_COMPUTER;
		break;
	case 2: // Phone Major Class
		DeleteAllItem(m_ctrlMinor);
		m_ctrlMinor.AddString("Uncategorized, code for device not assigned");
		m_ctrlMinor.AddString("Cellular");
		m_ctrlMinor.AddString("Cordless");
		m_ctrlMinor.AddString("Smart phone");
		m_ctrlMinor.AddString("Wired modem or voice gateway");
		m_ctrlMinor.AddString("Common ISDN Access");
		m_ctrlMinor.SetCurSel(0);
		m_dwClass |= CLASS_PHONE;
		break;
	case 3: // LAN/Network Access Point Major Class
		DeleteAllItem(m_ctrlMinor);
		m_ctrlMinor.AddString("Fully available");
		m_ctrlMinor.AddString("1 - 17% utilized");
		m_ctrlMinor.AddString("17 - 33% utilized");
		m_ctrlMinor.AddString("33 - 50% utilized");
		m_ctrlMinor.AddString("50 - 67% utilized");
		m_ctrlMinor.AddString("67 - 83% utilized");
		m_ctrlMinor.AddString("83 - 99% utilized");
		m_ctrlMinor.AddString("No service available");
		m_ctrlMinor.SetCurSel(0);
		m_dwClass |= CLASS_LAN;
		break;
	case 4: //  Audio/Video Major Class
		DeleteAllItem(m_ctrlMinor);
		m_ctrlMinor.AddString("Uncategorized, code not assigned");
		m_ctrlMinor.AddString("Wearable Headset Device");
		m_ctrlMinor.AddString("Hands-free Device");
		m_ctrlMinor.AddString("Reserved");
		m_ctrlMinor.AddString("Microphone");
		m_ctrlMinor.AddString("Loudspeaker");
		m_ctrlMinor.AddString("Headphones");
		m_ctrlMinor.AddString("Portable Audio");
		m_ctrlMinor.AddString("Car audio");
		m_ctrlMinor.AddString("Set-top box");
		m_ctrlMinor.AddString("HiFi Audio Device");
		m_ctrlMinor.AddString("VCR");
		m_ctrlMinor.AddString("Video Camera");
		m_ctrlMinor.AddString("Camcorder");
		m_ctrlMinor.AddString("Video Monitor");
		m_ctrlMinor.AddString("Video Display and Loudspeaker");
		m_ctrlMinor.AddString("Video Conferencing");
		m_ctrlMinor.AddString("Reserved");
		m_ctrlMinor.AddString("Gaming//Toy");
		m_ctrlMinor.SetCurSel(0);
		m_dwClass |= CLASS_AUDIOVIEDO;
		break;
	case 5: // Peripheral Major Class
		DeleteAllItem(m_ctrlMinor);
		m_ctrlMinor.AddString("Not Keyboard / Not Pointing Device");
		m_ctrlMinor.AddString("Keyboard-Uncategorized device");
		m_ctrlMinor.AddString("Keyboard-Joystick");
		m_ctrlMinor.AddString("Keyboard-Gamepad");
		m_ctrlMinor.AddString("Keyboard-Remote control");
		m_ctrlMinor.AddString("Keyboard-Sensing device");
		m_ctrlMinor.AddString("Keyboard-Digitizer tablet");
		m_ctrlMinor.AddString("Keyboard-Card Reader");
		m_ctrlMinor.AddString("Pointing device-Uncategorized device");
		m_ctrlMinor.AddString("Pointing device-Joystick");
		m_ctrlMinor.AddString("Pointing device-Gamepad");
		m_ctrlMinor.AddString("Pointing device-Remote control");
		m_ctrlMinor.AddString("Pointing device-Sensing device");
		m_ctrlMinor.AddString("Pointing device-Digitizer tablet");
		m_ctrlMinor.AddString("Pointing device-Card Reader");
		m_ctrlMinor.AddString("Combo-Uncategorized device");
		m_ctrlMinor.AddString("Combo-Joystick");
		m_ctrlMinor.AddString("Combo-Gamepad");
		m_ctrlMinor.AddString("Combo-Remote control");
		m_ctrlMinor.AddString("Combo-Sensing device");
		m_ctrlMinor.AddString("Combo-Digitizer tablet");
		m_ctrlMinor.AddString("Combo-Card Reader");
		m_ctrlMinor.SetCurSel(0);
		m_dwClass |= CLASS_PERIPHERAL;
		break;
	case 6: // Imaging Major Class
		DeleteAllItem(m_ctrlMinor);
		m_ctrlMinor.AddString("Display");
		m_ctrlMinor.AddString("Camera");
		m_ctrlMinor.AddString("Scanner");
		m_ctrlMinor.AddString("Printer");
		m_ctrlMinor.SetCurSel(0);
		m_dwClass |= 0x00000010;
		m_dwClass |= CLASS_IMAGING;
		break;
	case 7: // Wearable Major Class
		DeleteAllItem(m_ctrlMinor);
		m_ctrlMinor.AddString("Wrist Watch");
		m_ctrlMinor.AddString("Pager");
		m_ctrlMinor.AddString("Jacket");
		m_ctrlMinor.AddString("Helmet");
		m_ctrlMinor.AddString("Glasses");
		m_ctrlMinor.SetCurSel(0);
		m_dwClass |= 0x00000004;
		m_dwClass |= CLASS_WEARABLE;
		break;
	case 8: // Toy Major Class
		DeleteAllItem(m_ctrlMinor);
		m_ctrlMinor.AddString("Robot");
		m_ctrlMinor.AddString("Vehicle");
		m_ctrlMinor.AddString("Doll / Action Figure");
		m_ctrlMinor.AddString("Controller");
		m_ctrlMinor.AddString("Game");
		m_ctrlMinor.SetCurSel(0);
		m_dwClass |= 0x00000004;
		m_dwClass |= CLASS_TOY;
		break;
	default:
		DeleteAllItem(m_ctrlMinor);
		m_ctrlMinor.SetCurSel(0);
		break;
	}
	sprintf(m_strClassHex.GetBuffer(16), "0x%06X", m_dwClass);
	UpdateData(FALSE);
}

void CBTCoDDlg::OnAbout() 
{
	CAboutDlg dlg;

	dlg.DoModal();	
}

void CBTCoDDlg::OnSelchangeComboMinor() 
{
	int iCurSel1, iCurSel2;

	UpdateData(TRUE);
	iCurSel1 = m_ctrlMajor.GetCurSel();
	iCurSel2 = m_ctrlMinor.GetCurSel();

	m_dwClass &= 0xFFFFFF03; // clear 2-7 bits

	switch ( iCurSel1 )
	{
	case 0:
		break;
	case 1: // Computer Major Class
		switch ( iCurSel2 )
		{
		case 0: // Uncategorized
			break;
		case 1: // Desktop workstation
			m_dwClass |= 0x00000004;
			break;
		case 2: // Server-class computer
			m_dwClass |= 0x00000008;
			break;
		case 3: // Laptop
			m_dwClass |= 0x0000000C;
			break;
		case 4: // Handheld PC/PDA
			m_dwClass |= 0x00000010;
			break;
		case 5: // Palm sized PC/PDA
			m_dwClass |= 0x00000014;
			break;
		case 6: // Wearable computer
			m_dwClass |= 0x00000018;
			break;
		default:
			break;
		}
		break;
	case 2: // Phone Major Class
		switch ( iCurSel2 )
		{
		case 0: // Uncategorized
			break;
		case 1: // Cellular
			m_dwClass |= 0x00000004;
			break;
		case 2: // Cordless
			m_dwClass |= 0x00000008;
			break;
		case 3: // Smart phone
			m_dwClass |= 0x0000000C;
			break;
		case 4: // Wired modem or voice gateway
			m_dwClass |= 0x00000010;
			break;
		case 5: // Common ISDN Access
			m_dwClass |= 0x00000014;
			break;
		default:
			break;
		}
		break;
	case 3: // LAN/Network Access Point Major Class
		switch ( iCurSel2 )
		{
		case 0: // Fully available
			break;
		case 1: // 1 - 17% utilized
			m_dwClass |= 0x00000020;
			break;
		case 2: // 17 - 33% utilized
			m_dwClass |= 0x00000040;
			break;
		case 3: // 33 - 50% utilized
			m_dwClass |= 0x00000060;
			break;
		case 4: // 50 - 67% utilized
			m_dwClass |= 0x00000080;
			break;
		case 5: // 67 - 83% utilized
			m_dwClass |= 0x000000A0;
			break;
		case 6: // 83 - 99% utilized
			m_dwClass |= 0x000000C0;
			break;
		case 7: // No service available 
			m_dwClass |= 0x000000E0;
			break;
		default:
			break;
		}		
		break;
	case 4: //  Audio/Video Major Class
		switch ( iCurSel2 )
		{
		case 0: // Uncategorized
			break;
		case 1: // Wearable Headset Device
			m_dwClass |= 0x00000004;
			break;
		case 2: // Hands-free Device
			m_dwClass |= 0x00000008;
			break;
		case 3: // Reserved
			m_dwClass |= 0x0000000C;
			break;
		case 4: // Microphone
			m_dwClass |= 0x00000010;
			break;
		case 5: // Loudspeaker
			m_dwClass |= 0x00000014;
			break;
		case 6: // Headphones
			m_dwClass |= 0x00000018;
			break;
		case 7: // Portable Audio
			m_dwClass |= 0x0000001C;
			break;
		case 8: // Car audio
			m_dwClass |= 0x00000020;
			break;
		case 9: // Set-top box
			m_dwClass |= 0x00000024;
			break;
		case 10: // HiFi Audio Device
			m_dwClass |= 0x00000028;
			break;
		case 11: // VCR
			m_dwClass |= 0x0000002C;
			break;
		case 12: // Video Camera
			m_dwClass |= 0x00000030;
			break;
		case 13: // Camcorder
			m_dwClass |= 0x00000034;
			break;
		case 14: // Video Monitor
			m_dwClass |= 0x00000038;
			break;
		case 15: // Video Display and Loudspeaker
			m_dwClass |= 0x0000003C;
			break;
		case 16: // Video Conferencing
			m_dwClass |= 0x00000040;
			break;
		case 17: // Reserved
			m_dwClass |= 0x00000044;
			break;
		case 18: // Gaming/Toy
			m_dwClass |= 0x00000048;
			break;
		default:
			break;
		}
		break;
	case 5: // Peripheral Major Class
		switch ( iCurSel2 )
		{
		case 0: // Uncategorized
			break;
		case 1: // Keyboard-Uncategorized device
			m_dwClass |= 0x00000040;
			break;
		case 2: // Keyboard-Joystick
			m_dwClass |= 0x00000044;
			break;
		case 3: // Keyboard-Gamepad
			m_dwClass |= 0x00000048;
			break;
		case 4: // Keyboard-Remote control
			m_dwClass |= 0x0000004C;
			break;
		case 5: // Keyboard-Sensing device
			m_dwClass |= 0x00000050;
			break;
		case 6: // Keyboard-Digitizer tablet
			m_dwClass |= 0x00000054;
			break;
		case 7: // Keyboard-Card Reader
			m_dwClass |= 0x00000058;
			break;
		case 8: // Pointing device-Uncategorized device
			m_dwClass |= 0x00000080;
			break;
		case 9: // Pointing device-Joystick
			m_dwClass |= 0x00000084;
			break;
		case 10: // Pointing device-Gamepad
			m_dwClass |= 0x00000088;
			break;
		case 11: // Pointing device-Remote control
			m_dwClass |= 0x0000008C;
			break;
		case 12: // Pointing device-Sensing device
			m_dwClass |= 0x00000090;
			break;
		case 13: // Pointing device-Digitizer tablet
			m_dwClass |= 0x00000094;
			break;
		case 14: // Pointing device-Card Reader
			m_dwClass |= 0x00000098;
			break;
		case 15: // Combo-Uncategorized device
			m_dwClass |= 0x000000C0;
			break;
		case 16: // Combo-Joystick
			m_dwClass |= 0x000000C4;
			break;
		case 17: // Combo-Gamepad
			m_dwClass |= 0x000000C8;
			break;
		case 18: // Combo-Remote control
			m_dwClass |= 0x000000CC;
			break;
		case 19: // Combo-Sensing device
			m_dwClass |= 0x000000D0;
			break;
		case 20: // Combo-Digitizer tablet
			m_dwClass |= 0x000000D4;
			break;
		case 21: // Combo-Card Reader
			m_dwClass |= 0x000000D8;
			break;
		default:
			break;
		}
		break;
	case 6: // Imaging Major Class
		switch ( iCurSel2 )
		{
		case 0: // Display
			m_dwClass |= 0x00000010;
			break;
		case 1: // Camera
			m_dwClass |= 0x00000020;
			break;
		case 2: // Scanner
			m_dwClass |= 0x00000040;
			break;
		case 3: // Printer
			m_dwClass |= 0x00000080;
			break;
		default:
			break;
		}
		break;
	case 7: // Wearable Major Class
		switch ( iCurSel2 )
		{
		case 0: // Wrist Watch 
			m_dwClass |= 0x00000004;
			break;
		case 1: // Pager
			m_dwClass |= 0x00000008;
			break;
		case 2: // Jacket
			m_dwClass |= 0x0000000C;
			break;
		case 3: // Helmet
			m_dwClass |= 0x00000010;
			break;
		case 4: // Helmet
			m_dwClass |= 0x00000014;
			break;
		default:
			break;
		}
		break;
	case 8: // Toy Major Class
		switch ( iCurSel2 )
		{
		case 0: // Robot
 			m_dwClass |= 0x00000004;
			break;
		case 1: // Vehicle
			m_dwClass |= 0x00000008;
			break;
		case 2: // Doll / Action Figure
			m_dwClass |= 0x0000000C;
			break;
		case 3: // Controller
			m_dwClass |= 0x00000010;
			break;
		case 4: // Game
			m_dwClass |= 0x00000014;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	sprintf(m_strClassHex.GetBuffer(16), "0x%06X", m_dwClass);
	UpdateData(FALSE);
}
