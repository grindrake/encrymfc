
// encrmfc.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CencrmfcApp:
// О реализации данного класса см. encrmfc.cpp
//

class CencrmfcApp : public CWinApp
{
public:
	CencrmfcApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CencrmfcApp theApp;