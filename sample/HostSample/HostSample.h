
// HostSample.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CHostSampleApp:
// �� Ŭ������ ������ ���ؼ��� HostSample.cpp�� �����Ͻʽÿ�.
//

class CHostSampleApp : public CWinApp
{
public:
	CHostSampleApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CHostSampleApp theApp;