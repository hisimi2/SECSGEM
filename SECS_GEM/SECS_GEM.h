
// SECS_GEM.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSECS_GEMApp:
// �� Ŭ������ ������ ���ؼ��� SECS_GEM.cpp�� �����Ͻʽÿ�.
//

class CSECS_GEMApp : public CWinApp
{
public:
	CSECS_GEMApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSECS_GEMApp theApp;