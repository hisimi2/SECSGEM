
// EqSampleDlg.h : 헤더 파일
//


#pragma once
#include "XComProApi.h"
#include "afxwin.h"

#define MAX_ARRAY	7
// CEqSampleDlg 대화 상자
class CEqSampleDlg : public CDialogEx
{
// 생성입니다.
public:
	CEqSampleDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_EQSAMPLE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedOk();
	CString m_cmbDevice;
	CString m_cmbMsg;
	CListBox m_lstbxMsg;

// Implementation
private:
    // Variable for array
    char VALUE_I1_ARR[MAX_ARRAY];
    short VALUE_I2_ARR[MAX_ARRAY];
    long VALUE_I4_ARR[MAX_ARRAY];
    LONGLONG VALUE_I8_ARR[MAX_ARRAY];
    BYTE VALUE_U1_ARR[MAX_ARRAY];
    WORD VALUE_U2_ARR[MAX_ARRAY];
    ULONG VALUE_U4_ARR[MAX_ARRAY];
    ULONGLONG VALUE_U8_ARR[MAX_ARRAY];
    float VALUE_F4_ARR[MAX_ARRAY];
    double VALUE_F8_ARR[MAX_ARRAY];
    BYTE VALUE_BOOL_ARR[MAX_ARRAY];
    BYTE VALUE_BINARY_ARR[MAX_ARRAY];
	char VALUE_ASCII_ARR[MAX_ARRAY][16];
	bool m_SECSCommunicationOK;

public:
	
	XComPro m_XComPro;

	afx_msg void OnBnClickedBtnStart();
	afx_msg void OnBnClickedBtnStop();
	afx_msg void OnBnClickedBtnSendMsg();
	afx_msg void OnLbnDblclkLstMsg();
	afx_msg void SendS5F23();
	afx_msg void SecsEventPoll(short nEventId, long lParam);
	DECLARE_EVENTSINK_MAP()


	void OnSecsEvent(short nEventId, long lParam);
	void OnSecsMsg();

	static void OnSecsEvent(void *lpParam, short nEventID, long lParam);
	static void OnSecsMsg(void *lpParam);
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedBtnInit();
	CButton rbEvent;
	afx_msg void OnBnClickedBtnClose();

	enum eERS{eTeaching=0, eLock=1,eMapData=2};

	LRESULT	ReceiveS1F3(long lMsgId);
	BOOL			ReplyS1F4(long lMsgId, long lSysByte);
	LRESULT	ReceiveS2F41(long lMsgId);
	BOOL			ReplyS2F42(long lMsgId, long lSysByte);

	BOOL			SendS5F1();
	LRESULT	ReceiveS5F2(long lMsgId);
	BOOL			SendS6F11(int nKind=eTeaching);
	LRESULT	ReceiveS6F12(long lMsgId);
	LRESULT	ReceiveS10F3(long lMsgId);
	BOOL			ReplyS10F4(long lMsgId, long lSysByte);
	BOOL			SendS14F1();
	LRESULT	ReceiveS14F2(long lMsgId);

	CString		SetMapData();

	
};
