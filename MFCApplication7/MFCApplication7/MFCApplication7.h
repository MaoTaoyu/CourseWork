
// MFCApplication7.h : MFCApplication7 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMFCApplication7App:
// �йش����ʵ�֣������ MFCApplication7.cpp
//

class CMFCApplication7App : public CWinApp
{
public:
	CMFCApplication7App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication7App theApp;
