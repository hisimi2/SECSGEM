
// EqSample.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CEqSampleApp:
// �� Ŭ������ ������ ���ؼ��� EqSample.cpp�� �����Ͻʽÿ�.
//

class CEqSampleApp : public CWinApp
{
public:
	CEqSampleApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CEqSampleApp theApp;