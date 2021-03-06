// EqSampleDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "EqSample.h"
#include "EqSampleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define VALUE_I1        10
#define VALUE_I2        32555
#define VALUE_I4        655360
#define VALUE_I8        240000001
#define VALUE_U1        250
#define VALUE_U2        65000
#define VALUE_U4        4294967290         
#define VALUE_U8        1844674400
#define VALUE_F4        1234.567f
#define VALUE_F8        123456789.87654321
#define VALUE_BOOL      1
#define VALUE_BINARY    10
#define VALUE_STRING    "STRING; Linkgenesis XComPro Sample"
#define VALUE_JIS8      "JIS8; Linkgenesis XComPro Sample"
// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
//	void OnSecsEvent(void);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CEqSampleDlg 대화 상자




CEqSampleDlg::CEqSampleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEqSampleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_cmbDevice = _T("");
	m_cmbMsg = _T("");
}

void CEqSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_DEVICE, m_cmbDevice);
	DDX_CBString(pDX, IDC_COMBO_MSG, m_cmbMsg);
	DDX_Control(pDX, IDC_LST_MSG, m_lstbxMsg);
	//	DDX_Control(pDX, IDC_XCOMPROCTRL1, m_XComPro);
	DDX_Control(pDX, IDC_BTN_Close, rbEvent);
}

BEGIN_MESSAGE_MAP(CEqSampleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDOK, &CEqSampleDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BTN_START, &CEqSampleDlg::OnBnClickedBtnStart)
	ON_BN_CLICKED(IDC_BTN_STOP, &CEqSampleDlg::OnBnClickedBtnStop)
	ON_BN_CLICKED(IDC_BTN_SEND_MSG, &CEqSampleDlg::OnBnClickedBtnSendMsg)
	ON_LBN_DBLCLK(IDC_LST_MSG, &CEqSampleDlg::OnLbnDblclkLstMsg)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CEqSampleDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BTN_INIT, &CEqSampleDlg::OnBnClickedBtnInit)
	ON_BN_CLICKED(IDC_BTN_Close, &CEqSampleDlg::OnBnClickedBtnClose)
END_MESSAGE_MAP()



// CEqSampleDlg 메시지 처리기



BOOL CEqSampleDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다. 응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	GetDlgItem(IDC_BTN_STOP)->EnableWindow(false);
	GetDlgItem(IDC_BTN_Close)->EnableWindow(false);
	GetDlgItem(IDC_BTN_START)->EnableWindow(false);

	CButton *pButton1 = (CButton*)GetDlgItem(IDC_EVENT);
	CButton *pButton2 = (CButton*)GetDlgItem(IDC_POLLING);

	pButton1->SetCheck(TRUE);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CEqSampleDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다. 문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CEqSampleDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CEqSampleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CEqSampleDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    // Close 
    // Stop the XCom control
    m_XComPro.Stop();
	CDialogEx::OnOK();
}


void CEqSampleDlg::OnBnClickedBtnStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    char        szMsg[256];
    int         nReturn;

    //  Start the XCom1 control
    if( (nReturn = m_XComPro.Start()) == 0 ) {
        m_lstbxMsg.AddString( "m_XComPro started successfully" );
    }
    else {
        sprintf( szMsg, "Fail to start m_XComPro (%d)", nReturn );
        m_lstbxMsg.AddString( szMsg );
        return;
    }
    // Setting button enable state
    GetDlgItem(IDC_BTN_START)->EnableWindow(false);
    GetDlgItem(IDC_BTN_STOP)->EnableWindow(true);
}


void CEqSampleDlg::OnBnClickedBtnStop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    // Stop the XCom control
    m_XComPro.Stop();
    // Change button state
    GetDlgItem(IDC_BTN_START)->EnableWindow(true);
    GetDlgItem(IDC_BTN_STOP)->EnableWindow(false);
}


void CEqSampleDlg::OnBnClickedBtnSendMsg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString     sData;
    char        szMsg[256];
    long        lMsgId;
    int         nDeviceID, nReturn;
	int		i = 0;
	BYTE    nBinary = 0;
	BYTE	nBool = 0;

	char	nI1 = 0;
	short	nI2 = 0;
	long	lI4 = 0;
	LONGLONG lI8 = 0;

	BYTE	nU1 = 0;
	WORD    nU2 = 0;
	ULONG	nU4 = 0;
	ULONGLONG nU8 = 0;

    float   rF4;
    double  rF8;
    CString sAscii, sJis8;

    UpdateData( TRUE );
    if (!m_SECSCommunicationOK)
    {
		m_lstbxMsg.AddString( "[Warning] Cannot send xcom message because HSMS is not selected yet" );
	}
    else
    {
			if( m_cmbMsg == "S1F1" ) {
			// Getting Device ID
			nDeviceID = atoi( m_cmbDevice.GetBuffer(2) );
			// Send S1F1
			nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDeviceID, 1, 1, 0 );
            if (nReturn < 0)
            {
				sprintf( szMsg, "MakeSecsMsg failed: error=%d", nReturn );
				m_lstbxMsg.AddString( szMsg );
                return;
            } 
			
			nReturn = m_XComPro.Send( lMsgId );
			if( nReturn == 0 ) {
				m_lstbxMsg.AddString( "Send S1F1 successfully" );
			}
			else {
				sprintf( szMsg, "Fail to send S1F1 (%d)", nReturn );
				m_lstbxMsg.AddString( szMsg );
			}
			
		}
		else if( m_cmbMsg == "S1F13_1" ) {
			// Getting Device ID
			nDeviceID = atoi( m_cmbDevice.GetBuffer(2) );
			// Send S1F13
			nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDeviceID, 1, 13, 0 );
            if (nReturn < 0)
            {
				sprintf( szMsg, "MakeSecsMsg failed: error=%d", nReturn );
				m_lstbxMsg.AddString( szMsg );
                return;
            } 

			nReturn = m_XComPro.SetListItem( lMsgId, 0 );      // L 0
			sprintf( szMsg, "LIST %d: error=%d", 0, nReturn );
			m_lstbxMsg.AddString( szMsg );

			nReturn = m_XComPro.Send( lMsgId );
			if( nReturn == 0 ) {
				m_lstbxMsg.AddString( "Send S1F13 successfully" );
			}
			else {
				sprintf( szMsg, "Fail to send S1F13 (%d)", nReturn );
				m_lstbxMsg.AddString( szMsg );
			}
		}
		else if( m_cmbMsg == "S1F13_2" ) {
			// Getting Device ID
			nDeviceID = atoi( m_cmbDevice.GetBuffer(2) );
			// Send S1F13
			nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDeviceID, 1, 13, 0 );
            if (nReturn < 0)
            {
				sprintf( szMsg, "MakeSecsMsg failed: error=%d", nReturn );
				m_lstbxMsg.AddString( szMsg );
                return;
            } 

			nReturn = m_XComPro.SetListItem( lMsgId, 2 );
			sprintf( szMsg, "LIST %d: error=%d", 2, nReturn );
			m_lstbxMsg.AddString( szMsg );

				sAscii = "XComV2";
				nReturn = m_XComPro.SetAsciiItem( lMsgId, sAscii.GetBuffer(), sAscii.GetLength() );
				sprintf( szMsg, "   ASCII %s: error=%d", sAscii, nReturn );
				m_lstbxMsg.AddString( szMsg );
				sAscii = "V2.0.0";
				nReturn = m_XComPro.SetAsciiItem( lMsgId, sAscii.GetBuffer(), sAscii.GetLength() );
				sprintf( szMsg, "   ASCII %s: error=%d", sAscii, nReturn );
				m_lstbxMsg.AddString( szMsg );
			nReturn = m_XComPro.Send( lMsgId );
			if( nReturn == 0 ) {
				m_lstbxMsg.AddString( "Send S1F13 successfully" );
			}
			else {
				sprintf( szMsg, "Fail to send S1F13 (%d)", nReturn );
				m_lstbxMsg.AddString( szMsg );
			}
		}
		else if( m_cmbMsg =="S2F13" ) {
			// Getting Device ID
			nDeviceID = atoi( m_cmbDevice.GetBuffer(2) );
			// Send S2F13
			nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDeviceID, 2, 13, 0 );
            if (nReturn < 0)
            {
				sprintf( szMsg, "MakeSecsMsg failed: error=%d", nReturn );
				m_lstbxMsg.AddString( szMsg );
                return;
            } 
			nReturn = m_XComPro.SetListItem( lMsgId, 2 );
				sprintf( szMsg, "LIST %d: error=%d", 2, nReturn );
				m_lstbxMsg.AddString( szMsg );
				nU2 = 1;    
				nReturn = m_XComPro.SetU2Item( lMsgId, &nU2, 1 );    //  ECID
				sprintf( szMsg, "   UINT2 %u: error=%d", nU2, nReturn );
				m_lstbxMsg.AddString( szMsg );
				nU2 = 2;    
				nReturn = m_XComPro.SetU2Item( lMsgId, &nU2, 1 );    //  ECID
				sprintf( szMsg, "   UINT2 %u: error=%d", nU2, nReturn );
				m_lstbxMsg.AddString( szMsg );
			nReturn = m_XComPro.Send( lMsgId );
			if( nReturn == 0 ) {
				m_lstbxMsg.AddString( "Send S2F13 successfully" );
			}
			else {
				sprintf( szMsg, "Fail to send S2F13 (%d)", nReturn );
				m_lstbxMsg.AddString( szMsg );
			}
		}
		else if( m_cmbMsg =="S2F33" ) { //  Define Report
			// Getting Device ID
			nDeviceID = atoi( m_cmbDevice.GetBuffer(2) );
			// Send S2F33
			nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDeviceID, 2, 33, 0 );
            if (nReturn < 0)
            {
				sprintf( szMsg, "MakeSecsMsg failed: error=%d", nReturn );
				m_lstbxMsg.AddString( szMsg );
                return;
            } 
			// Setting values
			nReturn = m_XComPro.SetListItem( lMsgId, 2 );
			sprintf( szMsg, "LIST %d: error=%d", 2, nReturn );
			m_lstbxMsg.AddString( szMsg );
				nReturn = m_XComPro.SetListItem( lMsgId, 10 );   //  L 10
				sprintf( szMsg, "LIST %d: error=%d", 10, nReturn );
				m_lstbxMsg.AddString( szMsg );
					nI1 = VALUE_I1;     
					nReturn = m_XComPro.SetI1Item( lMsgId, &nI1, 1 );
					sprintf( szMsg, "       INT1 %d: error=%d", nI1, nReturn );
					m_lstbxMsg.AddString( szMsg );
					nI2 = VALUE_I2;     
					nReturn = m_XComPro.SetI2Item( lMsgId, &nI2, 1 );
					sprintf( szMsg, "       INT2 %d: error=%d", nI2, nReturn );
					m_lstbxMsg.AddString( szMsg );
					lI4 = VALUE_I4;  
					nReturn = m_XComPro.SetI4Item( lMsgId, &lI4, 1 );
					sprintf( szMsg, "       INT4 %d: error=%d", lI4, nReturn );
					m_lstbxMsg.AddString( szMsg );
					lI8 = VALUE_I8;  
					nReturn = m_XComPro.SetI8Item( lMsgId, &lI8, 1 );
					sprintf( szMsg, "       INT8 %d: error=%d", lI8, nReturn );
					m_lstbxMsg.AddString( szMsg );
					nU1 = VALUE_U1;  
					nReturn = m_XComPro.SetU1Item( lMsgId, &nU1, 1 );
					sprintf( szMsg, "       UINT1 %u: error=%d", nU1, nReturn );
					m_lstbxMsg.AddString( szMsg );
					nU2 = VALUE_U2;  
					nReturn = m_XComPro.SetU2Item( lMsgId, &nU2, 1 );
					sprintf( szMsg, "       UINT2 %u: error=%d", nU2, nReturn );
					m_lstbxMsg.AddString( szMsg );
					nU4 = VALUE_U4;    
					nReturn = m_XComPro.SetU4Item( lMsgId, &nU4, 1 );
					sprintf( szMsg, "       UINT4 %u: error=%d", (UINT)nU4, nReturn );
					m_lstbxMsg.AddString( szMsg );
					nU8 = VALUE_U8;  
					nReturn = m_XComPro.SetU8Item( lMsgId, &nU8, 1 );
					sprintf( szMsg, "       UINT8 %u: error=%d", nU8, nReturn );
					m_lstbxMsg.AddString( szMsg );
					rF4 = VALUE_F4;   
					nReturn = m_XComPro.SetF4Item( lMsgId, &rF4, 1 );
					sprintf( szMsg, "       FLOAT4 %f: error=%d", (float)rF4, nReturn );
					m_lstbxMsg.AddString( szMsg );
					rF8 = VALUE_F8;     
					nReturn = m_XComPro.SetF8Item( lMsgId, &rF8, 1 );
					sprintf( szMsg, "       FLOAT8 %f: error=%d", (double)rF8, nReturn );
					m_lstbxMsg.AddString( szMsg );
				nReturn = m_XComPro.SetListItem( lMsgId, 4 );    //  L 4
				sprintf( szMsg, "LIST %d: error=%d", 4, nReturn );
				m_lstbxMsg.AddString( szMsg );
					sAscii = VALUE_STRING;
					sJis8 = VALUE_JIS8;
					nBinary = VALUE_BINARY; 
					nBool = VALUE_BOOL; 

					nReturn = m_XComPro.SetAsciiItem( lMsgId, sAscii.GetBuffer(), sAscii.GetLength() );
					sprintf( szMsg, "       ASCII %s: error=%d", sAscii, nReturn );
					m_lstbxMsg.AddString( szMsg );
					nReturn = m_XComPro.SetJis8Item( lMsgId, sJis8.GetBuffer(), sJis8.GetLength() ); 
					sprintf( szMsg, "       JIS8 %s: error=%d", sJis8, nReturn );
					m_lstbxMsg.AddString( szMsg );
					nReturn = m_XComPro.SetBinaryItem( lMsgId, &nBinary, 1 ); 
					sprintf( szMsg, "       BINARY %d: error=%d", nBinary, nReturn );
					m_lstbxMsg.AddString( szMsg );
					nReturn = m_XComPro.SetBoolItem( lMsgId, &nBool, 1 );
					sprintf( szMsg, "       BOOL %d: error=%d", nBool, nReturn );
					m_lstbxMsg.AddString( szMsg );
			nReturn = m_XComPro.Send( lMsgId );
			if( nReturn == 0 ) {
				m_lstbxMsg.AddString( "Send S2F33 successfully" );
			}
			else {
				sprintf( szMsg, "Fail to send S2F33 (%d)", nReturn );
				m_lstbxMsg.AddString( szMsg );
			}
		}
		else if( m_cmbMsg =="S5F23" ) { //  Array test
			char    szTemp[32];
			// Getting Device ID
			nDeviceID = atoi( m_cmbDevice.GetBuffer(2) );
			// Send S5F23
			nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDeviceID, 5, 23, 0 );
            if (nReturn < 0)
            {
				sprintf( szMsg, "MakeSecsMsg failed: error=%d", nReturn );
				m_lstbxMsg.AddString( szMsg );
                return;
            } 
			// Setting values
			nReturn = m_XComPro.SetListItem(lMsgId, 12);
			sprintf( szMsg, "LIST %d: error=%d", 12, nReturn );
			m_lstbxMsg.AddString( szMsg );			
				nReturn = m_XComPro.SetBoolItem(lMsgId, VALUE_BOOL_ARR, 7);
				sprintf( szMsg, "   BOOL " );
				for (i = 0; i < 7; i++){
					sprintf(szTemp, "%d ", VALUE_BOOL_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ":error=%d ", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				nReturn = m_XComPro.SetBinaryItem(lMsgId, VALUE_BINARY_ARR, 7);
				sprintf( szMsg, "   BINARY " );
				for (i = 0; i < 7; i++){
					sprintf(szTemp, "%d ", VALUE_BINARY_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ":error=%d ", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				nReturn = m_XComPro.SetU1Item(lMsgId, VALUE_U1_ARR, 7);
				sprintf( szMsg, "   UINT1 " );
				for (i = 0; i < 7; i++){
					sprintf(szTemp, "%u ", VALUE_U1_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ":error=%d ", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				nReturn = m_XComPro.SetU2Item(lMsgId, VALUE_U2_ARR, 7);
				sprintf( szMsg, "   UINT2 " );
				for ( i = 0; i < 7; i++){
					sprintf(szTemp, "%u ", VALUE_U2_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ":error=%d ", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				nReturn = m_XComPro.SetU4Item(lMsgId, VALUE_U4_ARR, 7);
				sprintf( szMsg, "   UINT4 " );
				for ( i = 0; i < 7; i++){
					sprintf(szTemp, "%u ", VALUE_U4_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ":error=%d ", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				nReturn = m_XComPro.SetU8Item(lMsgId, VALUE_U8_ARR, 7);
				sprintf( szMsg, "   UINT8 " );
				for (i = 0; i < 7; i++){
					sprintf(szTemp, "%.u ", VALUE_U8_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ":error=%d ", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				nReturn = m_XComPro.SetI1Item(lMsgId, VALUE_I1_ARR, 7);
				sprintf( szMsg, "   INT1 " );
				for ( i = 0; i < 7; i++){
					sprintf(szTemp, "%d ", VALUE_I1_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ":error=%d ", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				
				nReturn = m_XComPro.SetI2Item(lMsgId, VALUE_I2_ARR, 7);
				sprintf( szMsg, "   INT2 " );
				for (i = 0; i < 7; i++){
					sprintf(szTemp, "%d ", VALUE_I2_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ":error=%d ", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				nReturn = m_XComPro.SetI4Item(lMsgId, VALUE_I4_ARR, 7);
				sprintf( szMsg, "   INT4 " );
				for (i = 0; i < 7; i++){
					sprintf(szTemp, "%d ", VALUE_I4_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ":error=%d ", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				nReturn = m_XComPro.SetI8Item(lMsgId, VALUE_I8_ARR, 7);
				sprintf( szMsg, "   INT8 " );
				for (i = 0; i < 7; i++){
					sprintf(szTemp, "%d ", VALUE_I8_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ":error=%d ", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				nReturn = m_XComPro.SetF4Item(lMsgId, VALUE_F4_ARR, 7);
				sprintf( szMsg, "   FLOAT4 " );
				for (i = 0; i < 7; i++){
					sprintf(szTemp, "%f ", VALUE_F4_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ":error=%d ", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				nReturn = m_XComPro.SetF8Item(lMsgId, VALUE_F8_ARR, 7);
				sprintf( szMsg, "   FLOAT8 " );
				for (i = 0; i < 7; i++){
					sprintf(szTemp, "%f ", VALUE_F8_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ":error=%d ", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
			nReturn = m_XComPro.Send(lMsgId);
			// Send message
			if( nReturn == 0 ) {
				m_lstbxMsg.AddString( "Send S5F23 successfully" );
			}
			else {
				sprintf( szMsg, "Fail to send S5F23 (%d)", nReturn );
				m_lstbxMsg.AddString( szMsg );
			}
		}
		//////////////////////////////Edu Test//////////////////////////////////
		else if( m_cmbMsg =="S5F1"){		
			sprintf( szMsg, "------------------------------------------------------------------------------------------------------------");				m_lstbxMsg.AddString( szMsg );
			SendS5F1();
		}		
		else if( m_cmbMsg =="S6F11"){			
			sprintf( szMsg, "------------------------------------------------------------------------------------------------------------");				m_lstbxMsg.AddString( szMsg );
			SendS6F11(eTeaching);
		}
		else if( m_cmbMsg == "S14F1"){			//Edu Test
			sprintf( szMsg, "------------------------------------------------------------------------------------------------------------");				m_lstbxMsg.AddString( szMsg );
			SendS14F1();
		}
		//////////////////////////////Edu Test//////////////////////////////////
		else {
			sprintf( szMsg, "Undefined Message ");
			m_lstbxMsg.AddString( szMsg );
		}
	}
    while( m_lstbxMsg.GetCount() > 200 ) { m_lstbxMsg.DeleteString( 0 ); }	
}



BEGIN_EVENTSINK_MAP(CEqSampleDlg, CDialogEx)
	//ON_EVENT(CEqSampleDlg, IDC_XCOMPROCTRL1, 1, CEqSampleDlg::SecsEventXcomproctrl1, VTS_I2 VTS_I4)
	//ON_EVENT(CEqSampleDlg, IDC_XCOMPROCTRL1, 2, CEqSampleDlg::SecsMsgXcomproctrl1, VTS_NONE)
END_EVENTSINK_MAP()



void CEqSampleDlg::OnSecsEvent (void *lpParam, short nEventId, long lParam)
{
	CEqSampleDlg *dlg = (CEqSampleDlg*)lpParam;
	dlg->OnSecsEvent(nEventId,lParam);
}

void CEqSampleDlg::OnSecsEvent (short nEventId, long lParam)
{
		// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	char    szMsg[256];

    if( nEventId == 203 ) { //  T3 timeout...
        m_lstbxMsg.AddString( "[ALARM] T3 timeout alarm occurs" );
    }
    else if( nEventId == 102 ) {    //  NOT_SELECTED...
		m_SECSCommunicationOK = false;
        m_lstbxMsg.AddString( "[EVENT] HSMS not selected event happens" );
    }
    else if( nEventId == 101 ) {    //  NOT_CONNECTED...
		m_SECSCommunicationOK = false;
        m_lstbxMsg.AddString( "[EVENT] HSMS not connected event happens" );
    }
    else if( nEventId == 103 ) {    //  SELECTED...
		m_SECSCommunicationOK = true;
        m_lstbxMsg.AddString( "[EVENT] HSMS selected event happens" );
    }
    else {
        sprintf( szMsg, "[EVENT] Event Code = %d, Parameter = %d", nEventId, lParam );
        m_lstbxMsg.AddString( szMsg );
    }
}

void CEqSampleDlg::OnSecsMsg(void *lpParam)
{
	CEqSampleDlg* dlg = (CEqSampleDlg*)lpParam;
	dlg->OnSecsMsg();
}

void CEqSampleDlg::OnSecsMsg()
{
	printf("fire to OnSecsMsg\n");
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	char    szMsg[255], szTemp[32];
	short   nStrm, nFunc, nWbit, nDevId;
	long    lMsgId, lSysByte, lSize;
	int     nReturn, i;
	long	nItems = 0;
	BYTE	nBinary = 0;
	BYTE	nBool = 0;
	char	nI1 = 0;
	short   nI2 = 0;
	long	nI4 = 0;
	LONGLONG nI8 = 0;
	BYTE    nU1 = 0;
	WORD    nU2 = 0;
	ULONG   nU4 = 0;
	ULONGLONG nU8 = 0;
	long    lCnt;
	float   rF4;
	double  rF8;
	CString sAscii, sJis8;
	char    szString[255], szJis8[255];
	

	  while( m_XComPro.LoadSecsMsg( &lMsgId, &nDevId, &nStrm, &nFunc, &lSysByte, &nWbit ) >= 0 ) {
		  sprintf( szMsg, "------------------------------------------------------------------------------------------------------------");	
		  m_lstbxMsg.AddString( szMsg );
	      sprintf( szMsg, "Received S%dF%d", nStrm, nFunc );	      m_lstbxMsg.AddString( szMsg );

	      if( (nStrm == 1) && (nFunc == 1) ) {
	          m_XComPro.CloseSecsMsg( lMsgId );
	
	          nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDevId, 1, 2, lSysByte );
	          nReturn = m_XComPro.SetListItem( lMsgId, 2 );
	              sAscii = "XComV2";
	              nReturn = m_XComPro.SetAsciiItem( lMsgId, sAscii.GetBuffer(), sAscii.GetLength() );
	              sAscii = "V2.0.0";
	              nReturn = m_XComPro.SetAsciiItem( lMsgId, sAscii.GetBuffer(), sAscii.GetLength() );
	          if( (nReturn = m_XComPro.Send( lMsgId )) == 0 ) {
	              m_lstbxMsg.AddString( "Reply S1F2 successfully" );
	          }
	          else {
	              sprintf( szMsg, "Fail to reply S1F2 (%d)", nReturn );
	              m_lstbxMsg.AddString( szMsg );
	          }
	      }
	      else if( (nStrm == 1) && (nFunc == 13) ) {
	          // Check the type of S1F13 message
	          nReturn = m_XComPro.GetListItem( lMsgId, &nItems );
	          sprintf( szMsg, "LIST %d: next=%d", nItems, nReturn );
	          m_lstbxMsg.AddString( szMsg );
	
	          if( nItems == 0 ) {
	              m_XComPro.CloseSecsMsg( lMsgId );
	
	
	              nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDevId, 1, 14, lSysByte );
	              nReturn = m_XComPro.SetListItem( lMsgId, 2 );
	                  nBinary = 0;    nReturn = m_XComPro.SetBinaryItem( lMsgId, &nBinary, 1 );
	                  nReturn = m_XComPro.SetListItem( lMsgId, 0 );
	              if( (nReturn = m_XComPro.Send( lMsgId )) == 0 ) {
	                  m_lstbxMsg.AddString( "Reply S1F14 successfully" );
	              }
	              else {
	                  sprintf( szMsg, "Fail to reply S1F14 (%d)", nReturn );
	                  m_lstbxMsg.AddString( szMsg );
	              }
	
	          }
	          else {
	              // Read data
				nReturn = m_XComPro.GetAsciiItem( lMsgId, szString, &lSize, sizeof(szString));
	              sprintf( szMsg, "     ASCII %s: next=%d", szString, nReturn );
	              m_lstbxMsg.AddString( szMsg );
	
	              nReturn = m_XComPro.GetAsciiItem( lMsgId, szString, &lSize, sizeof(szString));
	              sprintf( szMsg, "     ASCII %s: next=%d", szString, nReturn );
	              m_lstbxMsg.AddString( szMsg );
	              m_XComPro.CloseSecsMsg( lMsgId );
	
	              nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDevId, 1, 14, lSysByte );
	              nReturn = m_XComPro.SetListItem( lMsgId, 2 );
	                  nBinary = 0;    nReturn = m_XComPro.SetBinaryItem( lMsgId, &nBinary, 1 );
	                  nReturn = m_XComPro.SetListItem( lMsgId, 2 );
	                      sAscii = "XComV2";
						nReturn = m_XComPro.SetAsciiItem( lMsgId, sAscii.GetBuffer(), sAscii.GetLength());
	                      sAscii = "V2.0.0";
	                      nReturn = m_XComPro.SetAsciiItem( lMsgId, sAscii.GetBuffer(), sAscii.GetLength());

	              if( (nReturn = m_XComPro.Send( lMsgId )) == 0 ) {
	                  m_lstbxMsg.AddString( "Reply S1F14 successfully" );
	              }
	              else {
	                  sprintf( szMsg, "Fail to reply S1F14 (%d)", nReturn );
	                  m_lstbxMsg.AddString( szMsg );
	              }
	          }
	      }
	      else if( (nStrm == 2) && (nFunc == 13) ) {
	          WORD    lReceived[5];
	          // Read list count for L n
	          nReturn = m_XComPro.GetListItem( lMsgId, &nItems );
	          sprintf( szMsg, "LIST %d: next=%d", nItems, nReturn );
	          m_lstbxMsg.AddString( szMsg );
	          // Read data
	          for( i = 0; i < nItems; i++ ) {
	              nReturn = m_XComPro.GetU2Item( lMsgId, &nU2, &lCnt, 1 );
	              lReceived[i] = nU2;
	              sprintf( szMsg, "   UINT2 %u: next=%d", nU2, nReturn );
	              m_lstbxMsg.AddString( szMsg );
	          }
	          m_XComPro.CloseSecsMsg( lMsgId );
	
	          nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDevId, 2, 14, lSysByte );
	          nReturn = m_XComPro.SetListItem( lMsgId, 2 );
	              nBinary = 0;    nReturn = m_XComPro.SetBinaryItem( lMsgId, &nBinary, 1 );
	              nReturn = m_XComPro.SetListItem( lMsgId, nItems );
	          for( i = 0; i < nItems; i++ ) {
	              nReturn = m_XComPro.SetU2Item( lMsgId, &lReceived[i], 1 );
	          }
	          if( (nReturn = m_XComPro.Send( lMsgId )) == 0 ) {
	              m_lstbxMsg.AddString( "Reply S2F14 successfully" );
	          }
	          else {
	              sprintf( szMsg, "Fail to reply S2F14 (%d)", nReturn );
	              m_lstbxMsg.AddString( szMsg );
	          }
	      }
	      else if( (nStrm == 2) && (nFunc == 33) ) {
	          //  Get data of the received message.
	          nReturn = m_XComPro.GetListItem( lMsgId, &nItems );
	          sprintf( szMsg, "LIST %d: next=%d", nItems, nReturn );
	          m_lstbxMsg.AddString( szMsg );
	          nReturn = m_XComPro.GetListItem( lMsgId, &nItems );
	          sprintf( szMsg, "   LIST %d: next=%d", nItems, nReturn );
	          m_lstbxMsg.AddString( szMsg );
	          // Read I1 value
	          nReturn = m_XComPro.GetI1Item( lMsgId, &nI1, &lCnt, 1 );
	          sprintf( szMsg, "       INT1 %d: next=%d", nI1 , nReturn);
	          m_lstbxMsg.AddString( szMsg );
	          // Read I2 value
	          nReturn = m_XComPro.GetI2Item( lMsgId, &nI2, &lCnt, 1 );
	          sprintf( szMsg, "       INT2 %d: next=%d", nI2 , nReturn);
	          m_lstbxMsg.AddString( szMsg );
	          // Read I4 value
	          nReturn = m_XComPro.GetI4Item( lMsgId, &nI4, &lCnt, 1 );
	          sprintf( szMsg, "       INT4 %d: next=%d", nI4 , nReturn);
	          m_lstbxMsg.AddString( szMsg );
	          // Read I8 value
	          nReturn = m_XComPro.GetI8Item( lMsgId, &nI8, &lCnt, 1 );
	          sprintf( szMsg, "       INT8 %d: next=%d", nI8 , nReturn);
	          m_lstbxMsg.AddString( szMsg );
	          // Read U1 value
	          nReturn = m_XComPro.GetU1Item( lMsgId, &nU1, &lCnt, 1 );
	          sprintf( szMsg, "       UINT1 %u: next=%d", nU1 , nReturn);
	          m_lstbxMsg.AddString( szMsg );
	          // Read U2 value
	          nReturn = m_XComPro.GetU2Item( lMsgId, &nU2, &lCnt, 1 );
	          sprintf( szMsg, "       UINT2 %u: next=%d", nU2 , nReturn);
	          m_lstbxMsg.AddString( szMsg );
	          // Read U4 value
			nReturn = m_XComPro.GetU4Item( lMsgId, &nU4, &lCnt, 1 );
	          sprintf( szMsg, "       UINT4 %u: next=%d", (UINT)nU4 , nReturn);
	          m_lstbxMsg.AddString( szMsg );
	          // Read U8 value
	          nReturn = m_XComPro.GetU8Item( lMsgId, &nU8, &lCnt, 1 );
	          sprintf( szMsg, "       UINT8 %.0f: next=%d", (double)nU8 , nReturn);
	          m_lstbxMsg.AddString( szMsg );
	          // Read F4 value
	          nReturn = m_XComPro.GetF4Item( lMsgId, &rF4, &lCnt, 1 );
	          sprintf( szMsg, "       FLOAT4 %f: next=%d", (float)rF4 , nReturn);
	          m_lstbxMsg.AddString( szMsg );
	          // Read F8 value
	          nReturn = m_XComPro.GetF8Item( lMsgId, &rF8, &lCnt, 1 );
	          sprintf( szMsg, "       FLOAT8 %f: next=%d", (double)rF8 , nReturn);
	          m_lstbxMsg.AddString( szMsg );
	          // Read List Count
	          nReturn = m_XComPro.GetListItem( lMsgId, &nItems );
	          sprintf( szMsg, "   LIST %d: next=%d", nItems , nReturn);
	          m_lstbxMsg.AddString( szMsg );
	          // Read String value
	          nReturn = m_XComPro.GetAsciiItem( lMsgId, szString, &lSize, sizeof(szString) );
	          sprintf( szMsg, "       ASCII %s: next=%d", szString , nReturn);
	          m_lstbxMsg.AddString( szMsg );
	          // Read JIS8 value
	          nReturn = m_XComPro.GetJis8Item( lMsgId, szJis8, &lSize, sizeof(szString) );
	          sprintf( szMsg, "       JIS8 %s: next=%d", szJis8 , nReturn);
	          m_lstbxMsg.AddString( szMsg );
	          // Read Binary value
	          nReturn = m_XComPro.GetBinaryItem( lMsgId, &nBinary, &lCnt, 1  );
	          sprintf( szMsg, "       BINARY %d: next=%d", nBinary, nReturn );
	          m_lstbxMsg.AddString( szMsg );
	          // Read Bool value
	          nReturn = m_XComPro.GetBoolItem( lMsgId, &nBool, &lCnt, 1  );
	          sprintf( szMsg, "       BOOL %d: next=%d", nBool, nReturn );
	          m_lstbxMsg.AddString( szMsg );
	          m_XComPro.CloseSecsMsg( lMsgId );
	
	          nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDevId, 2, 34, lSysByte );
	          nBinary = 0;    nReturn = m_XComPro.SetBinaryItem( lMsgId, &nBinary, 1 );
	          if( (nReturn = m_XComPro.Send( lMsgId )) == 0 ) {
	              m_lstbxMsg.AddString( "Reply S2F34 successfully" );
	          }
	          else {
	              sprintf( szMsg, "Fail to reply S2F34 (%d)", nReturn );
	              m_lstbxMsg.AddString( szMsg );
	          }
	      }
	      else if( (nStrm == 5) && (nFunc == 23) ) {
	          //  Get data of the received message.
	          nReturn = m_XComPro.GetListItem(lMsgId, &nItems);
				sprintf( szMsg, "LIST %d: next=%d", nItems, nReturn );
				m_lstbxMsg.AddString( szMsg );
				sprintf( szMsg, "   BOOL " );
				nReturn = m_XComPro.GetBoolItem(lMsgId, VALUE_BOOL_ARR, &lCnt, 7);
				for (i = 0; i < lCnt; i++){
					sprintf(szTemp, "%d ", VALUE_BOOL_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ": next=%d", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				sprintf( szMsg, "   BINARY " );
	
				nReturn = m_XComPro.GetBinaryItem(lMsgId, VALUE_BINARY_ARR, &lCnt, 7);
				for (i = 0; i < lCnt; i++){
					sprintf(szTemp, "%d ", VALUE_BINARY_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ": next=%d", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				sprintf( szMsg, "   UINT1 " );
	
				nReturn = m_XComPro.GetU1Item(lMsgId, VALUE_U1_ARR, &lCnt, 7);
				for (i = 0; i < lCnt; i++){
					sprintf(szTemp, "%u ", VALUE_U1_ARR[i]);
					strcat(szMsg, szTemp);
				}
							sprintf(szTemp, ": next=%d", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				sprintf( szMsg, "   UINT2 " );
	
				nReturn = m_XComPro.GetU2Item(lMsgId, VALUE_U2_ARR, &lCnt, 7);
				for (i = 0; i < lCnt; i++){
					sprintf(szTemp, "%u ", VALUE_U2_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ": next=%d", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				sprintf( szMsg, "   UINT4 " );
	
				nReturn = m_XComPro.GetU4Item(lMsgId, VALUE_U4_ARR, &lCnt, 7);
				for (i = 0; i < lCnt; i++){
					sprintf(szTemp, "%u ", (UINT)VALUE_U4_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ": next=%d", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				sprintf( szMsg, "   UINT8 " );
				nReturn = m_XComPro.GetU8Item(lMsgId, VALUE_U8_ARR, &lCnt, 7);
				for (i = 0; i < lCnt; i++){
					sprintf(szTemp, "%.0f ", VALUE_U8_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ": next=%d", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				sprintf( szMsg, "   INT1 " );
				nReturn = m_XComPro.GetI1Item(lMsgId, VALUE_I1_ARR, &lCnt, 7);
				for (i = 0; i < lCnt; i++){
					sprintf(szTemp, "%d ", VALUE_I1_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ": next=%d", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				sprintf( szMsg, "   INT2 " );
				nReturn = m_XComPro.GetI2Item(lMsgId, VALUE_I2_ARR, &lCnt, 7);
				for (i = 0; i < lCnt; i++){
					sprintf(szTemp, "%d ", VALUE_I2_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ": next=%d", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				sprintf( szMsg, "   INT4 " );
				nReturn = m_XComPro.GetI4Item(lMsgId, VALUE_I4_ARR, &lCnt, 7);
				for (i = 0; i < lCnt; i++){
					sprintf(szTemp, "%d ", VALUE_I4_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ": next=%d", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				sprintf( szMsg, "   INT8 " );
				nReturn = m_XComPro.GetI8Item(lMsgId, VALUE_I8_ARR, &lCnt, 7);
				for (i = 0; i < lCnt; i++){
					sprintf(szTemp, "%d ", VALUE_I8_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ": next=%d", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				sprintf( szMsg, "   FLOAT4 " );
	
				nReturn = m_XComPro.GetF4Item(lMsgId, VALUE_F4_ARR, &lCnt, 7);
				for (i = 0; i < lCnt; i++){
					sprintf(szTemp, "%f ", VALUE_F4_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ": next=%d", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
				sprintf( szMsg, "   FLOAT8 " );
	
				nReturn = m_XComPro.GetF8Item(lMsgId, VALUE_F8_ARR, &lCnt, 7);
				for (i = 0; i < lCnt; i++){
					sprintf(szTemp, "%f ", VALUE_F8_ARR[i]);
					strcat(szMsg, szTemp);
				}
				sprintf(szTemp, ": next=%d", nReturn);
				strcat(szMsg, szTemp);
				m_lstbxMsg.AddString( szMsg );
	
	          m_XComPro.CloseSecsMsg( lMsgId );
	
	          nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDevId, 5, 24, lSysByte );
	          nU1 = 1;
	          nReturn = m_XComPro.SetU1Item(lMsgId, &nU1, 1);
	          if( (nReturn = m_XComPro.Send(lMsgId)) == 0 ) {
	              m_lstbxMsg.AddString( "Reply S5F24 successfully" );
	          }
	          else {
	              sprintf( szMsg, "Fail to reply S5F24 (%d)", nReturn );
	              m_lstbxMsg.AddString( szMsg );
	          }
	      }
	      else if( (nStrm == 5) && (nFunc == 24) ) {
	          // Read U1 value
	          nReturn = m_XComPro.GetU1Item(lMsgId, &nU1, &lCnt, 1);
	          sprintf( szMsg, "UINT1 %d: next=%d", nU1, nReturn );
	          m_lstbxMsg.AddString( szMsg );
	          m_XComPro.CloseSecsMsg( lMsgId );
	      }
	      else if( (nStrm == 1) && (nFunc == 2) ) {
	          m_XComPro.CloseSecsMsg( lMsgId );
	      }
	      else if( (nStrm == 1) && (nFunc == 14) ) {
	          m_XComPro.CloseSecsMsg( lMsgId );
	      }
	      else if( (nStrm == 2) && (nFunc == 14) ) {
	          m_XComPro.CloseSecsMsg( lMsgId );
	      }
	      else if( (nStrm == 2) && (nFunc == 34) ) {
	          m_XComPro.CloseSecsMsg( lMsgId );
	      }
		  ///////////////////////Education Test///////////////////////////////
		  else if( (nStrm == 1) && (nFunc == 3) ) {		//Test #4
			  ReceiveS1F3(lMsgId);
			  sprintf( szMsg, "------------------------------------------------------------------------------------------------------------");				m_lstbxMsg.AddString( szMsg );
			  ReplyS1F4(lMsgId,lSysByte);
		  }
		  else if( (nStrm == 2) && (nFunc == 41) ) {		//Test #3
			  ReceiveS2F41(lMsgId);
			  sprintf( szMsg, "------------------------------------------------------------------------------------------------------------");				m_lstbxMsg.AddString( szMsg );
			  ReplyS2F42(lMsgId,lSysByte);

			  if(strcmp(VALUE_ASCII_ARR[0], "PAUSE")==0)
				  sprintf( szMsg, "------------------------------------------------------------------------------------------------------------");				m_lstbxMsg.AddString( szMsg );
				  SendS6F11(eLock);
		  }
		  else if( (nStrm == 5) && (nFunc == 2) ) {		//Test #1
			  ReceiveS5F2(lMsgId);
		  }
		  else if( (nStrm == 6) && (nFunc == 12) ) {		//Test #2,3,5
			  ReceiveS6F12(lMsgId);
		  }
		  else if( (nStrm == 10) && (nFunc == 3) ) {		//Test #4
			  ReceiveS10F3(lMsgId);
			  sprintf( szMsg, "------------------------------------------------------------------------------------------------------------");				m_lstbxMsg.AddString( szMsg );
			  ReplyS10F4(lMsgId,lSysByte);
		  }
		  else if( (nStrm == 14) && (nFunc == 2) ) {		//Test #5
			  ReceiveS14F2(lMsgId);
			  sprintf( szMsg, "------------------------------------------------------------------------------------------------------------");				m_lstbxMsg.AddString( szMsg );
			  SendS6F11(eMapData);
		  }
		   ///////////////////////Education Test///////////////////////////////
	      else {
	          sprintf( szMsg, "Undefined message received (S%dF%d)", nStrm, nFunc);
	          m_lstbxMsg.AddString( szMsg );
	          m_XComPro.CloseSecsMsg( lMsgId );
	      }
	  }
	
	  while( m_lstbxMsg.GetCount() > 200 ){
	      m_lstbxMsg.DeleteString( 0 ); 
	  }
}

void CEqSampleDlg::OnLbnDblclkLstMsg()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_lstbxMsg.ResetContent();
}



void CEqSampleDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	long nEventType = 0;
	long lParam = 0;
	short nEventId = 0;
	int nRet = 0;

	switch(nIDEvent)
	{
		case 1:
			nRet = m_XComPro.PopEvent(&nEventType,&nEventId,&lParam);
			if( nRet >= 0) 
			{
				if(nEventType == SECS_EVENT_TYPE)
				{
					OnSecsEvent(nEventId,lParam);
				}
				else if(nEventType == SECS_MSG_TYPE)
				{
					OnSecsMsg();
				}
			}
			break;
		default:
			break;
	}
}

void CEqSampleDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	SetTimer(1,1000,NULL);
}


void CEqSampleDlg::OnBnClickedBtnInit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString     strFile;
    char        szMsg[256];
    int         nReturn;

	//SetEventHandlerMode(SecsMessage 수신방식 설정)을 안하고 Initialize시에는 
	//default값(Event방식)으로 초기화 하게 되는데 초기화 전에 꼭 Event를 
	//등록 하시고 Initialize를 하셔야 합니다.
	 
	CButton *pButton1 = (CButton*)GetDlgItem(IDC_EVENT);
	CButton *pButton2 = (CButton*)GetDlgItem(IDC_POLLING);
	
	if(pButton1->GetCheck())	//EVENT
	{
		m_XComPro.SetSecsEventHandler(this, OnSecsEvent); 
		m_XComPro.SetSecsMsgEventHandler(this, OnSecsMsg); 
		m_XComPro.SetEventHandlerMode(1);
	}
	else if(pButton2->GetCheck())	//POLLING
	{
		m_XComPro.SetEventHandlerMode(0);
		SetTimer(1,10,NULL);
	}
	else
	{
		AfxMessageBox("Please check RcvMode radiobutton");
		return;
	}

    //  Initialize the XCom control.
    strFile = "EqSample.cfg";

    if( (nReturn = m_XComPro.Initialize( strFile )) == 0 ) {
        m_lstbxMsg.AddString( "m_XComPro initialized successfully" );
		GetDlgItem(IDC_BTN_INIT)->EnableWindow(false);
		GetDlgItem(IDC_BTN_Close)->EnableWindow(true);
		GetDlgItem(IDC_BTN_START)->EnableWindow(true);
    }
    else {
        sprintf( szMsg, "Fail to initialize m_XComPro (%d)", nReturn );
        m_lstbxMsg.AddString( szMsg );
    }

    // Initialize Combobox 
    m_cmbMsg = "S1F1";
    m_cmbDevice = "1";

    // Initializing array value
    for (int i = 0; i < MAX_ARRAY; i++){
        VALUE_I1_ARR[i] = (short)(i + 1);
        VALUE_I2_ARR[i] = (short)(i + 1);
        VALUE_I4_ARR[i] = i + 1;
        VALUE_I8_ARR[i] = i + 1;
        VALUE_U1_ARR[i] = (short)(i + 1);
        VALUE_U2_ARR[i] = i + 1;
        VALUE_U4_ARR[i] = i + 1;
        VALUE_U8_ARR[i] = i + 1;
        VALUE_F4_ARR[i] = (float)(i + 1);
        VALUE_F8_ARR[i] = i + 1;
        VALUE_BOOL_ARR[i] = 1;
        VALUE_BINARY_ARR[i] = 1;
    }
	m_SECSCommunicationOK = false;
    UpdateData(false);
}


void CEqSampleDlg::OnBnClickedBtnClose()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if(0 == m_XComPro.Close())
	{
		GetDlgItem(IDC_BTN_INIT)->EnableWindow(true);
		GetDlgItem(IDC_BTN_Close)->EnableWindow(false);
		KillTimer(1);
	}
}

LRESULT CEqSampleDlg::ReceiveS1F3(long lMsgId)
{
	/////////////////////////////////////////////////////////////////////
	//        TechWing SECS basic education Test - by YSP
	//
	//			Edu Test - #4
	//			SVID = 2
	//
	//		<S1F3 P Selected Equipment Status Request(SSR)
	//				<LIST n 
	//					<UINT4 1 SVID>
	//				>
	//		>
	//////////////////////////////////////////////////////////////////////
	long		nItems = 0;
	char    szMsg[255], szTemp[32];
	int		nReturn = 0;
	long    lCnt;

	
	//  Get data of the received message.
	m_XComPro.GetListItem(lMsgId, &nItems);
	sprintf( szMsg, "LIST %d" , nItems);		m_lstbxMsg.AddString( szMsg );
	{
		m_XComPro.GetU4Item(lMsgId, VALUE_U4_ARR, &lCnt, MAX_ARRAY);
		sprintf( szMsg, "    UINT4 <SVID "  );		
		for (int i = 0; i < lCnt; i++){
			sprintf(szTemp, "%u >", VALUE_U4_ARR[i]);
			strcat(szMsg, szTemp);
		}
		m_lstbxMsg.AddString( szMsg );
	}
	
	m_XComPro.CloseSecsMsg( lMsgId );
	
	return 0L;
}

BOOL CEqSampleDlg::ReplyS1F4(long lMsgId, long lSysByte)
{
	/////////////////////////////////////////////////////////////////////
	//        TechWing SECS basic education Test - by YSP
	//
	//			Edu Test - #4
	//			SVID = 2, SV=83.8
	//
	//		<S1F4 S Selected Equipment Status Data(SDD)
	//				<LIST n 
	//					<ASCII n SV>
	//				>
	//		>
	//////////////////////////////////////////////////////////////////////
	int		nReturn = 0;
	char    szMsg[255];
	short   nDeviceID;

	short	nStream = 1;
	short	nFunc = 4;
	int		 nListCnt ;
	int		 nItems = 1;


	nDeviceID = atoi( m_cmbDevice.GetBuffer(2) );
	nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDeviceID, nStream, nFunc, lSysByte );

	if (nReturn < 0)
	{
		sprintf( szMsg, "MakeSecsMsg failed: error=%d", nReturn );		m_lstbxMsg.AddString( szMsg );
		return FALSE;
	} 
	else
	{
		sprintf( szMsg, "SecsMsg S%dF%d", nStream, nFunc  );		m_lstbxMsg.AddString( szMsg );
	}

	nListCnt = 1;
	m_XComPro.SetListItem( lMsgId, nListCnt );	sprintf( szMsg, "  LIST %d", nListCnt );	m_lstbxMsg.AddString( szMsg );
	{
		CString strSV = _T("83.8");
		for( int i = 0; i < nItems; i++ ) {
			m_XComPro.SetAsciiItem( lMsgId, strSV.GetBuffer(), strSV.GetLength() );
			sprintf( szMsg, "       ASCII <SV %s>", strSV );			m_lstbxMsg.AddString( szMsg );
		}
	}
	
	if( (nReturn = m_XComPro.Send(lMsgId)) == 0 ) {
		m_lstbxMsg.AddString( "Reply S1F4 successfully" );
	}
	else {
		sprintf( szMsg, "Fail to reply S1F4 (%d)", nReturn );		m_lstbxMsg.AddString( szMsg );
	}

	return 0L;
}

LRESULT CEqSampleDlg::ReceiveS2F41(long lMsgId)
{
	/////////////////////////////////////////////////////////////////////
	//        TechWing SECS basic education Test - by YSP
	//
	//			Edu Test - #3
	//
	//
	//		<S2F41 P Host Command Send (HCS) 
	//			<LIST 2 
	//				<ASCII 40 RCMD >
	//				<LIST 0 # of parameters>
	//			>
	//		>
	/////////////////////////////////////////////////////////////////////

	long	nItems = 0;
	char    szMsg[255];
	int		nReturn = 0;
	long    lCnt;
	char	szValue[16];
	
	//  Get data of the received message.
	m_XComPro.GetListItem(lMsgId, &nItems);
	sprintf( szMsg, "LIST %d ", nItems );	m_lstbxMsg.AddString( szMsg );
	{
		m_XComPro.GetAsciiItem(lMsgId, szValue, &lCnt, sizeof(szValue));
		sprintf( szMsg, "    ACSII <RCMD %s>", szValue);	m_lstbxMsg.AddString( szMsg );
	}
	
	m_XComPro.CloseSecsMsg( lMsgId );

	if(strcmp(szValue,"PAUSE") == 0)
	{
		sprintf(VALUE_ASCII_ARR[0], szValue);
	}
	
	return 0L;
}

BOOL CEqSampleDlg::ReplyS2F42(long lMsgId, long lSysByte)
{
	/////////////////////////////////////////////////////////////////////
	//        TechWing SECS basic education Test - by YSP
	//
	//			Edu Test - #3
	//			HCACK = 0
	//
	//		<S2F42 S Host Command Acknowledge (HCA) 
	//			<LIST 2 
	//				<BINARY 1 HCACK>
	//				<LIST 0 >
	//			>
	//		>
	//////////////////////////////////////////////////////////////////////

	int		nReturn = 0;
	char    szMsg[255];
	short   nDeviceID;

	short	nStream = 2;
	short	nFunc = 42;
	int		nListCnt = 2;
	int		nItems = 1;
	
	BYTE nBinary = 0;

	nDeviceID = atoi( m_cmbDevice.GetBuffer(2) );
	nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDeviceID, nStream, nFunc, lSysByte );
	
	if (nReturn < 0)	{
		sprintf( szMsg, "MakeSecsMsg failed: error=%d", nReturn );		m_lstbxMsg.AddString( szMsg );
		return FALSE;
	} 
	else	{
		sprintf( szMsg,"SecsMsg S%dF%d", nStream, nFunc  );		m_lstbxMsg.AddString( szMsg );
	}

	m_XComPro.SetListItem( lMsgId, nListCnt );
	sprintf( szMsg, "  LIST %d", nListCnt );	m_lstbxMsg.AddString( szMsg );
	{
		m_XComPro.SetBinaryItem( lMsgId, &nBinary, 1 );
		sprintf( szMsg, "       BINARY <HCACK %d> ", nBinary);		m_lstbxMsg.AddString( szMsg );
		nListCnt = 0;
		m_XComPro.SetListItem( lMsgId, nListCnt );
		sprintf( szMsg, "       LIST %d ", 0);		m_lstbxMsg.AddString( szMsg );
	}

	if( (nReturn = m_XComPro.Send(lMsgId)) == 0 ) {
		m_lstbxMsg.AddString( "Reply S2F42 successfully" );
	}
	else {
		sprintf( szMsg, "Fail to reply S2F42 (%d)", nReturn );		m_lstbxMsg.AddString( szMsg );
	}
	

	return TRUE;
}

BOOL CEqSampleDlg::SendS5F1()
{
	/////////////////////////////////////////////////////////////////////
	//        TechWing SECS basic education Test - by YSP
	//
	//			Edu Test - #1
	//			ALCD = 2
	//			ALID=21511
	//			ALTX=Load_PP::Hand's 1-1 Vacuum Error 
	//
	// 			<S5F1 P Alarm Report Send (ARS)
	// 				<LIST 3 
	// 				<BINARY 1 ALCD>
	// 				<UINT4 1 ALID>
	// 				<ASCII n ALTX>
	// 				>
	// 			>
	// 			<S5F2 S Alarm Report Acknowledge (ARA)
	// 			<BINARY 1 ACKC5>
	// 			>
	//////////////////////////////////////////////////////////////////////
	char    szMsg[256];
	long    lMsgId;
	int       nDeviceID, nReturn;

	short	nStream = 5;
	short	nFunc = 1;

	nDeviceID = atoi( m_cmbDevice.GetBuffer(2) );
	nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDeviceID, nStream, nFunc, 0 );
	
	if (nReturn < 0)
	{
		sprintf( szMsg, "MakeSecsMsg failed: error=%d", nReturn );		m_lstbxMsg.AddString( szMsg );
		return FALSE;
	} 
	else
	{
		sprintf( szMsg, "SecsMsg S%dF%d", nStream, nFunc  );		m_lstbxMsg.AddString( szMsg );
	}

	////////////////////////////////////////////////////////////////////////
	// Setting values
	int nListCnt = 3;
	m_XComPro.SetListItem( lMsgId, nListCnt );
	sprintf( szMsg, "  LIST %d", nListCnt );		m_lstbxMsg.AddString( szMsg );
	{
		BYTE nALCD = 2;
		m_XComPro.SetBinaryItem( lMsgId, &nALCD, 1 ); 
		sprintf( szMsg, "       BINARY		<ALCD %d> ", nALCD);		m_lstbxMsg.AddString( szMsg );

		ULONG nALID = 21411;  
		m_XComPro.SetU4Item( lMsgId, &nALID, 1 );
		sprintf( szMsg, "       UINT4		<ALID %u>", nALID );		m_lstbxMsg.AddString( szMsg );

		CString sALTX = _T("Load_PP::Hand's 1-1 Vacuum Error");
		m_XComPro.SetAsciiItem( lMsgId, sALTX.GetBuffer(), sALTX.GetLength() );
		sprintf( szMsg, "       ASCII			<ALTX %s>", sALTX );		m_lstbxMsg.AddString( szMsg );
	}

	nReturn = m_XComPro.Send( lMsgId );
	if( nReturn == 0 ) {
		m_lstbxMsg.AddString( "Send S5F1 successfully" );
	}
	else {
		sprintf( szMsg, "Fail to send S5F1 (%d)", nReturn );
		return FALSE;
	}

	return TRUE;
}

LRESULT CEqSampleDlg::ReceiveS5F2(long lMsgId)
{
	//////////////////////////////////////////////////////////////////////
	//        TechWing SECS basic education Test - by YSP
	//
	//		Edu Test - #1
	//		ACKC5=0
	//
	//		<S5F2 S Alarm Report Acknowledge (ARA)
	//			<BINARY 1 ACKC5>
	//		>
	//////////////////////////////////////////////////////////////////////

	long	nItems = 0;
	char    szMsg[255];
	int		nReturn = 0;
	long    lCnt;
	BYTE nBinary = 0;

	nReturn = m_XComPro.GetBinaryItem(lMsgId, &nBinary, &lCnt,1);
	sprintf( szMsg, "    BINARY <ACKC5 %d>", (UINT)nBinary);		m_lstbxMsg.AddString( szMsg );
	
	return 0L;
}

BOOL CEqSampleDlg::SendS6F11(int nKind)
{
	/////////////////////////////////////////////////////////////////////
	//        TechWing SECS basic education Test - by YSP
	//
	//			Edu Test - #2
	//			DATAID =1, 	CEID=1201,	RPTID=1
	//			DVVAL1=Operator ID,	DVVAL2=Motor Name, DVVAL3=Old Value, DVVAL4=New Value   
	//
	// 	<S6F11 P Event Report Send (ERS) 
	// 		<LIST 3 
	// 			<UINT4 1 DATAID>
	// 			<UINT4 1 CEID>
	// 			<LIST 1 
	// 				<LIST 2 
	// 					<UINT4 1 RPTID(=1)>
	// 					<LIST n 
	// 						<ASCII n >
	// 					>
	// 				>
	// 			>
	// 		>
	// 	>
	//////////////////////////////////////////////////////////////////////

	char    szMsg[4096];
	long    lMsgId;
	int       nDeviceID, nReturn;

	short	nStream = 6;
	short	nFunc = 11;

	nDeviceID = atoi( m_cmbDevice.GetBuffer(2) );
	nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDeviceID, nStream, nFunc, 0 );
	
	if (nReturn < 0)	{
		sprintf( szMsg, "MakeSecsMsg failed: error=%d", nReturn );		m_lstbxMsg.AddString( szMsg );
		return FALSE;
	} 
	else	{
		sprintf( szMsg, "SecsMsg S%dF%d", nStream, nFunc );		m_lstbxMsg.AddString( szMsg );
	}

	ULONG nDataID, nCEID, nRPTID;
	CString strDataTmp[7] = {0,};
	CString strData = _T("");

	int nListCntData;  
	////////////////////////////////////////////////////////////////////////
	// Setting values

	if(nKind == eTeaching)
	{
		nCEID = 1201;  
		nRPTID = 1;  
		nListCntData = 4;
		strDataTmp[0] = _T("OPERATOR_ID=202030");
		strDataTmp[1] = _T("LOCATION=LOAD_PP1,TABLE1,Y");
		strDataTmp[2] = _T("ORIGINAL=380.30");
		strDataTmp[3] = _T("NEW=399.9");
	}
	else if(nKind == eLock)
	{
		nCEID = 1500;  
		nRPTID = 2;  
		nListCntData = 2;
		strDataTmp[0] = _T("MDLN=T7-0097");
		strDataTmp[1] = _T("STATUS=LOCK");
	}
	else if(nKind == eMapData)
	{
		nCEID = 1501;  
		nRPTID = 40;  
		nListCntData = 4;
		strDataTmp[0] = _T("CTRAYID=C-tray0001");
		strDataTmp[1] = _T("LOTID=LOTNAMEAA001");
		strDataTmp[2] = _T("LOCATIONID=UNLOAD_SETPLATE4");
		//strDataTmp[3] = _T("MAPDATA= xxxx.xml");
	}
	
	int nListCnt = 3;
	m_XComPro.SetListItem( lMsgId, nListCnt );
	sprintf( szMsg, "  LIST %d", nListCnt );		m_lstbxMsg.AddString( szMsg );
	{
		nDataID = 1;  
		m_XComPro.SetU4Item( lMsgId, &nDataID, 1 );
		sprintf( szMsg, "    UINT4 <DATAID %u>", nDataID );		m_lstbxMsg.AddString( szMsg );
			
		m_XComPro.SetU4Item( lMsgId, &nCEID, 1 );
		sprintf( szMsg, "    UINT4 <CEID %u>", nCEID );		m_lstbxMsg.AddString( szMsg );

		nListCnt = 1;
		m_XComPro.SetListItem( lMsgId, nListCnt );
		sprintf( szMsg, "    LIST %d", nListCnt );		m_lstbxMsg.AddString( szMsg );
		{
			nListCnt = 2;
			m_XComPro.SetListItem( lMsgId, nListCnt );
			sprintf( szMsg, "      LIST %d", nListCnt );		m_lstbxMsg.AddString( szMsg );
			{
				m_XComPro.SetU4Item( lMsgId, &nRPTID, 1 );
				sprintf( szMsg, "        UINT4 <RPTID %u>", nRPTID );		m_lstbxMsg.AddString( szMsg );

				m_XComPro.SetListItem( lMsgId, nListCntData );
				sprintf( szMsg, "        LIST %d", nListCntData );		m_lstbxMsg.AddString( szMsg );
				{
					for(int i=0; i<nListCntData;i++)
					{
						if( nKind == eMapData && i == 3){
							strData = SetMapData();
						}						
						else{
							strData = strDataTmp[i];
						}
						m_XComPro.SetAsciiItem( lMsgId, strData.GetBuffer(), strData.GetLength() );
						sprintf( szMsg, "          ASCII  <%s>", strData );				m_lstbxMsg.AddString( szMsg );
					}
				}
			}
		}
	}

	nReturn = m_XComPro.Send( lMsgId );

	if( nReturn == 0 ) {
		m_lstbxMsg.AddString( "Send S6F11 successfully" );
	}
	else {
		sprintf( szMsg, "Fail to send S6F11 (%d)", nReturn );
		m_lstbxMsg.AddString( szMsg );

		return FALSE;
	}

	return TRUE;
}

LRESULT CEqSampleDlg::ReceiveS6F12(long lMsgId)
{
	/////////////////////////////////////////////////////////////////////
	//        TechWing SECS basic education Test - by YSP
	//
	//			Edu Test - #2
	//			ACKC6=0
	//<S6F12 S 
	//	<BINARY 1 ACKC6>
	//>
	/////////////////////////////////////////////////////////////////////
	long	nItems = 0;
	char    szMsg[255];
	int		nReturn = 0;
	long    lCnt;
	BYTE nBinary = 0;

	//  Get data of the received message.
	 nReturn = m_XComPro.GetBinaryItem(lMsgId, &nBinary, &lCnt,1);
	sprintf( szMsg, "  BINARY <ACKC6 %d>", (UINT)nBinary);		m_lstbxMsg.AddString( szMsg );

	m_XComPro.CloseSecsMsg( lMsgId );

	return 0L;
}

LRESULT	CEqSampleDlg::ReceiveS10F3(long lMsgId)
{
	/////////////////////////////////////////////////////////////////////
	//        TechWing SECS basic education Test - by YSP
	//
	//			Edu Test - #4
	//			TID=TID001
	//			TEXT=Please check the TESTUP1 RTD sensor. 
	//
	//			<S10F3 P Terminal Display, Single (VTN)
	//				<LIST 2 
	//				<BINARY 1 TID>
	//				<ASCII 80 TEXT>
	//				>
	//			>
	//////////////////////////////////////////////////////////////////////
	long	nItems = 0;
	char    szMsg[255];
	int		nReturn = 0;
	long    lCnt;
	char	szValue[80];
	BYTE nBinary = 0;

	//  Get data of the received message.
	m_XComPro.GetListItem(lMsgId, &nItems);
	sprintf( szMsg, "LIST %d ", nItems );	m_lstbxMsg.AddString( szMsg );
	{
		m_XComPro.GetBinaryItem(lMsgId, &nBinary, &lCnt,1);
		sprintf( szMsg, "       BINARY <TID %d>", nBinary);		m_lstbxMsg.AddString( szMsg );
		m_XComPro.GetAsciiItem(lMsgId, szValue, &lCnt, sizeof(szValue));
		sprintf( szMsg, "       ACSII  <TEXT %s>", szValue);	m_lstbxMsg.AddString( szMsg );
	}

	m_XComPro.CloseSecsMsg( lMsgId );

	return 0L;
}

BOOL CEqSampleDlg::ReplyS10F4(long lMsgId, long lSysByte)
{
	/////////////////////////////////////////////////////////////////////
	//        TechWing SECS basic education Test - by YSP
	//
	//			Edu Test - #4
	//			ACKC10 = 0
	//
	//			<S10F4 S Terminal Display, Single Acknowledge (VTA)
	//				<BINARY 1 ACKC10>
	//			>
	////////////////////////////////////////////////////////////////////////
	int		nReturn = 0;
	char    szMsg[255];
	short   nDeviceID;

	short	nStream = 10;
	short	nFunc = 4;
	int		nListCnt = 2;
	int		nItems = 1;

	BYTE nBinary = 0;

	nDeviceID = atoi( m_cmbDevice.GetBuffer(2) );
	nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDeviceID, nStream, nFunc,lSysByte );
	
	if (nReturn < 0)	{
		sprintf( szMsg, "MakeSecsMsg failed: error=%d", nReturn );		m_lstbxMsg.AddString( szMsg );
		return FALSE;
	} 
	else	{
		sprintf( szMsg,"SecsMsg S%dF%d", nStream, nFunc  );		m_lstbxMsg.AddString( szMsg );
		
	}
	m_XComPro.SetBinaryItem( lMsgId, &nBinary, 1 );
	sprintf( szMsg, "       BINARY <ACKC10 %d> ", nBinary);		m_lstbxMsg.AddString( szMsg );

	if( (nReturn = m_XComPro.Send(lMsgId)) == 0 ) {
		m_lstbxMsg.AddString( "Reply S10F4 successfully" );
	}
	else {
		sprintf( szMsg, "Fail to reply S10F4 (%d)", nReturn );		m_lstbxMsg.AddString( szMsg );
	}
	

	return TRUE;
}

BOOL CEqSampleDlg::SendS14F1()
{
	/////////////////////////////////////////////////////////////////////
	//        TechWing SECS basic education Test - by YSP
	//			Edu Test - #5
	//			OBJSPEC=EQ,	OBJTYPE=MAPDATA,	OBJID=C-Tray0001
	//
	// 			<S14F1 P GetAttr Request
	// 				<LIST 5 
	// 						<ASCII n OBJSPEC>
	// 						<ASCII n OBJTYPE>
	// 						<LIST n 
	// 							<ASCII n OBJID>
	// 						>
	// 						<LIST n 
	// 							<LIST 3 
	// 								<ASCII n ATTRID>
	// 								<ASCII n ATTRDATA>
	// 								<UINT1 1 ATTRRELN>
	// 							>
	// 						>
	// 						<LIST n 
	// 							<ASCII n ATTRID>
	// 						>
	// 					>
	// 			>
	////////////////////////////////////////////////////////////////////////
	char    szMsg[256];
	long    lMsgId;
	int       nDeviceID, nReturn;
	CString strData = _T("");
	short	nStream = 14;
	short	nFunc = 1;

	nDeviceID = atoi( m_cmbDevice.GetBuffer(2) );
	nReturn = m_XComPro.MakeSecsMsg( &lMsgId, nDeviceID, nStream, nFunc, 0 );
		
	if (nReturn < 0)	{
		sprintf( szMsg, "MakeSecsMsg failed: error=%d", nReturn );		m_lstbxMsg.AddString( szMsg );
		return FALSE;
	} 
	else	{
		sprintf( szMsg,"SecsMsg S%dF%d", nStream, nFunc );		m_lstbxMsg.AddString( szMsg );
	}

	CString strOBJSPEC	 = "EQ";
	CString strOBJTYPE	 = "MAPDATA";
	CString strOBJID		 = "C-TRAY0001";
	////////////////////////////////////////////////////////////////////////
	// Setting values
	int nListCnt = 5;
	m_XComPro.SetListItem( lMsgId, nListCnt );
	sprintf( szMsg, "  LIST %d", nListCnt ); 	m_lstbxMsg.AddString( szMsg );
	{
		strData = strOBJSPEC ;
		m_XComPro.SetAsciiItem( lMsgId, strData.GetBuffer(), strData.GetLength() );
		sprintf( szMsg, "        ASCII		<OBJSPEC=%s>", strData );				m_lstbxMsg.AddString( szMsg );
		strData = strOBJTYPE;
		m_XComPro.SetAsciiItem( lMsgId, strData.GetBuffer(), strData.GetLength() );
		sprintf( szMsg, "        ASCII		<OBJTYPE=%s>", strData );				m_lstbxMsg.AddString( szMsg );

		nListCnt = 1;
		m_XComPro.SetListItem( lMsgId, nListCnt );
		sprintf( szMsg, "        LIST %d", nListCnt );		m_lstbxMsg.AddString( szMsg );
		{
				strData = strOBJID;
				m_XComPro.SetAsciiItem( lMsgId, strData.GetBuffer(), strData.GetLength() );
				sprintf( szMsg, "                ASCII		<OBJID=%s>", strData );				m_lstbxMsg.AddString( szMsg );
		}
		nListCnt = 0;
		m_XComPro.SetListItem( lMsgId, nListCnt );
		sprintf( szMsg, "        LIST %d", nListCnt ); 	m_lstbxMsg.AddString( szMsg );
		m_XComPro.SetListItem( lMsgId, nListCnt );
		sprintf( szMsg, "        LIST %d", nListCnt ); 	m_lstbxMsg.AddString( szMsg );
	}
	
	nReturn = m_XComPro.Send( lMsgId );
	
	if( nReturn == 0 ) {
		m_lstbxMsg.AddString( "Send S14F1 successfully" );
	}
	else {
		sprintf( szMsg, "Fail to send S14F1 (%d)", nReturn );		m_lstbxMsg.AddString( szMsg );
		return FALSE;
	}
	return TRUE;
}

LRESULT CEqSampleDlg::ReceiveS14F2(long lMsgId)
{
	/////////////////////////////////////////////////////////////////////
	//        TechWing SECS basic education Test - by YSP
	//			Edu Test - #5
	//			OBJSPEC=EQ,	OBJTYPE=MAPDATA,	OBJID=C-Tray0001
	//
	//			<S14F2 S GetAttr Data(GAD)
	//				<LIST 2 
	//					<LIST n number of objects
	//						<LIST 2 
	//							<ASCII n ObjID >
	//							<LIST n 
	//								<LIST 2 number of attrubutes
	//									<ASCII n ATTRID>
	//									<ASCII n ATTRDATA>
	//								>
	//							>
	//						>
	//					>
	//					<LIST 2 
	//						<UINT1 1 OBJACK >
	//						<LIST n number of errors reported
	//							<LIST 2 
	//								<UINT1 n ERRCODE>
	//								<ASCII n ERRTEXT>
	//							>
	//						>
	//					>
	//				>
	//			>
	////////////////////////////////////////////////////////////////////////
	long	nItems , nItems2, nItems3, nItems4, nItems5;
	char    szMsg[4096];
	int		nReturn = 0;
	long    lSize;
	char	szValue[4096];
	BYTE nBinary = 0;

	int i,j;

	//  Get data of the received message.
	m_XComPro.GetListItem(lMsgId, &nItems);
	sprintf( szMsg, "LIST %d ", nItems );	m_lstbxMsg.AddString( szMsg );	//2
	{
		m_XComPro.GetListItem(lMsgId, &nItems2);
		sprintf( szMsg, "  LIST %d ", nItems2 );	m_lstbxMsg.AddString( szMsg );	//n
		{
			for( i=0;i<nItems2;i++)
			{
				m_XComPro.GetListItem(lMsgId, &nItems3);
				sprintf( szMsg, "    LIST	<%d> ", nItems3 );	m_lstbxMsg.AddString( szMsg );	//2
				{
					m_XComPro.GetAsciiItem(lMsgId, szValue, &lSize, sizeof(szValue));
					sprintf( szMsg, "      ACSII		<ObjID %s>", szValue);	m_lstbxMsg.AddString( szMsg );
					m_XComPro.GetListItem(lMsgId, &nItems4);
					sprintf( szMsg, "      LIST		<%d> ", nItems4);	m_lstbxMsg.AddString( szMsg );	//n
					for( j=0;j<nItems4;j++)
					{
						m_XComPro.GetListItem(lMsgId, &nItems5);
						sprintf( szMsg, "        LIST		<%d> ", nItems5 );	m_lstbxMsg.AddString( szMsg );	//2
						{
							m_XComPro.GetAsciiItem(lMsgId, szValue, &lSize, sizeof(szValue));
							sprintf( szMsg, "          ACSII		<ATTRID %s>", szValue);	m_lstbxMsg.AddString( szMsg );
							m_XComPro.GetAsciiItem(lMsgId,szValue, &lSize, sizeof(szValue));
							sprintf( szMsg, "          ACSII		<ATTRDATA %s>", szValue);	m_lstbxMsg.AddString( szMsg );
						}
					}
				}
			}
		}
	}

	m_XComPro.CloseSecsMsg( lMsgId );

	return 0L;
}

CString  CEqSampleDlg::SetMapData()
{
	CString strData = _T("");
	strData+=_T( "<?xml version=\"1.0\" encoding=\"utf-8\"?>");
	strData+=_T( "<MapData>																																																																											");
	strData+=_T( "	<Layouts>																																																																										");
	strData+=_T( "		<Layout LayoutId=\"JEDEC TRAY\" DefaultUnits=\"mm\" TopLevel=\"true\">																																								");
	strData+=_T( "			<Dimension X=\"1\" Y=\"1\" />																																																														");
	strData+=_T( "			<ChildLayouts>																																																																					    ");
	strData+=_T( "				<ChildLayouts LayoutId=\"7.5x11.2mm 10x21=210\" />																																																	");
	strData+=_T( "			</ChildLayouts>																																																																					");
	strData+=_T( "		</Layout>																																																																									");
	strData+=_T( "		<Layout LayoutId=\"7.5x11.2mm 10x21=210\" DefaultUnits=\"mm\" TopLevel=\"false\">																																		");
	strData+=_T( "			<Dimension X=\"21\" Y=\"10\" />																																																													");
	strData+=_T( "		</Layout>																																																																									");
	strData+=_T( "	</Layouts>																																																																										");
	strData+=_T( "	<Substrates> 																																																																								    ");
	strData+=_T( "		<Substrate SubstrateType=\"JEDEC TRAY\" SubstrateId=\"0066731025\"/>																																									");
	strData+=_T( "	</Substrates>																																																																								");
	strData+=_T( "	<SubstrateMaps>																																																																							");
	strData+=_T( "		<SubstrateMap SubstrateType=\"JEDEC TRAY\" SubstrateId=\"0066731025\" LayoutSpecifier=\"JEDEC TRAY/7.5x11.2mm 10x21=210\" Orientation=\"0\">	    ");
	strData+=_T( "			<Overlay MapName=\"DeviceBinMap\" MapVersion=\"1.0\">																																														");
	strData+=_T( "				<BinCodeMap BinType=\"ASCII\" NullBin=\"0\" MapType=\"2DArray\"> 																																								");
	strData+=_T( "					<BinDefinitions>  																																																																			");
	strData+=_T( "						<BinDefinition BinCode=\".\" BinCount=\"30\" BinDescription=\"Empty\" /> 																																				");
	strData+=_T( "						<BinDefinition BinCode=\"1\" BinCount=\"180\" BinDescription=\"Good Bin 1\" /> 																																	");
	strData+=_T( "					</BinDefinitions>																																																																			");
	strData+=_T( "					<BinCode>...111111111111111111</BinCode>																																																				");
	strData+=_T( "					<BinCode>...111111111111111111</BinCode>																																																				");
	strData+=_T( "					<BinCode>...111111111111111111</BinCode>																																																				");
	strData+=_T( "					<BinCode>...111111111111111111</BinCode>																																																				");
	strData+=_T( "					<BinCode>...111111111111111111</BinCode>																																																				");
	strData+=_T( "					<BinCode>...111111111111111111</BinCode>																																																				");
	strData+=_T( "					<BinCode>...111111111111111111</BinCode>																																																				");
	strData+=_T( "					<BinCode>...111111111111111111</BinCode>																																																				");
	strData+=_T( "					<BinCode>...111111111111111111</BinCode>																																																				");
	strData+=_T( "					<BinCode>...111111111111111111</BinCode>																																																				");
	strData+=_T( "				</BinCodeMap>																																																																				");
	strData+=_T( "			</Overlay>																																																																								");
	strData+=_T( "		</SubstrateMap>																																																																						");
	strData+=_T( "	</SubstrateMaps>																																																																						");
	strData+=_T( "</MapData>																																																																										");

	return strData;
}
