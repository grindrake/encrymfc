
// encrmfc.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CencrmfcApp:
// � ���������� ������� ������ ��. encrmfc.cpp
//

class CencrmfcApp : public CWinApp
{
public:
	CencrmfcApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CencrmfcApp theApp;