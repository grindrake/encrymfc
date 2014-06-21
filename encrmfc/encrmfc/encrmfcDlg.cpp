
// encrmfcDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "encrmfc.h"
#include "encrmfcDlg.h"
#include "afxdialogex.h"
//#include "blockspr.h"
#include "CryptoPP\pwdbased.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif




// ���������� ���� CAboutDlg ������������ ��� �������� �������� � ����������

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ������ ����������� ����
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

// ����������
protected:
	DECLARE_MESSAGE_MAP()
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


// ���������� ���� CencrmfcDlg




CencrmfcDlg::CencrmfcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CencrmfcDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CencrmfcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CencrmfcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CencrmfcDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ����������� ��������� CencrmfcDlg

BOOL CencrmfcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���������� ������ "� ���������..." � ��������� ����.

	// IDM_ABOUTBOX ������ ���� � �������� ��������� �������.
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

	// ������ ������ ��� ����� ����������� ����. ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

void CencrmfcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������. ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CencrmfcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CencrmfcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CencrmfcDlg::OnBnClickedOk()
{
	CString str;
	//CEdit* editBox = (CEdit*)GetDlgItem(IDC_EDIT4);
	//editBox->GetWindowText(str);
	//int l = str.GetLength();
	CListBox* listBox = (CListBox*)GetDlgItem(IDC_LIST1);
	//listBox->AddString(str);
	//for (int i=0, str[i]!='\0', i++)
	// TODO: �������� ���� ��� ����������� �����������
	
	static int inlen;
	byte *in, *out, *buf;
	int blocksize = 16;
	buf = new byte[blocksize-1];
	int outlen;
	CString empty ("");
	CString err ("Empty Stream");

	FILE* f;
	
	f = fopen ("../tex.txt","r");
	
	if (f) 
	{
		fseek (f, 0, SEEK_END);
		inlen = ftell (f);
		rewind (f);

		outlen  = inlen + (inlen+1)%16;
		in = new byte[inlen];
		out = new byte[outlen];

		fread (in, sizeof(char), 0, f);
		
		for (int i=0; i<inlen; i++)   // ��������� ����� � ���
		{
			fread(&(out[i]), sizeof(char), 1, f);
			//cout<<out[i];
			listBox->AddString(out[i]);
		}

		memset (out+inlen, '/0', outlen-inlen); // ��������� ��������� ���������

		//cout<<"\n"<<"\n";
		
		listBox->AddString(empty);
		listBox->AddString(empty);

		fclose (f);
	}
	else
	{
		//cout<<"Empty stream"<<"\n";
		listBox->AddString(err);
		listBox->AddString(empty);
	}

	for ( int k = 0; k<(outlen/blocksize); k++ )
	{
		memcpy(buf, out + k*blocksize, blocksize);
		

		for (int j = 0; j < blocksize; j++)
		{
			//cout<<buf[j];
			listBox->AddString(buf[j]);
		}
		//cout<<"\n";
		listBox->AddString(empty);
	}                    
	
}


