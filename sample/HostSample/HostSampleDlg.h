
// HostSampleDlg.h : 헤더 파일
//

#pragma once
#include "XComProApi.h"

#define MAX_ARRAY	7
// CHostSampleDlg 대화 상자
class CHostSampleDlg : public CDialogEx
{
// 생성입니다.
public:
	CHostSampleDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_HOSTSAMPLE_DIALOG };

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
	afx_msg void OnBnClickedBtnStart();
	CString m_cmbDevice;
	CString m_cmbMsg;
	CListBox m_lstbxMsg;
	DECLARE_EVENTSINK_MAP()
	

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
	bool m_SECSCommunicationOK;
public:
	XComPro m_XComPro;

	afx_msg void OnBnClickedBtnStop();
	afx_msg void OnBnClickedBtnSendMsg();
	afx_msg void OnLbnDblclkLstMsg();

	void OnSecsEvent(short nEventId, long lParam);
	void OnSecsMsg();

	static void OnSecsEvent(void *lpParam, short nEventID, long lParam);
	static void OnSecsMsg(void *lpParam);

	afx_msg void OnBnClickedBtnInit();
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	
	BOOL			SendS1F3();
	LRESULT	ReceiveS1F4(long lMsgId);
	BOOL			SendS2F41();
	LRESULT	ReceiveS2F42(long lMsgId);
	LRESULT	ReceiveS5F1(long lMsgId);
	BOOL			ReplyS5F2(long lMsgId, long lSysByte);
	LRESULT	RecevieS6F11(long lMsgId);
	LRESULT	ReplyS6F12(long lMsgId, long lSysByte);
	BOOL			SendS10F3();
	LRESULT	ReceiveS10F4(long lMsgId);
	BOOL			ReceiveS14F1(long lMsgId);
	LRESULT	ReplyS14F2(long lMsgId, long lSysByte);

	CString		GetMapData();
};
