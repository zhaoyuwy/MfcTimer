// Exaple44Dlg.cpp : implementation file
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Exaple44.h"
#include "Exaple44Dlg.h"
#include <io.h>//Rain  �������������Ϣ
#include <fcntl.h>//Rain
#include "afx.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExaple44Dlg dialog


void InitConsoleWindow()//Rain

{

	int nCrt = 0;

	FILE* fp;

	AllocConsole();

	nCrt = _open_osfhandle((long)GetStdHandle(STD_OUTPUT_HANDLE), _O_TEXT);

	fp = _fdopen(nCrt, "w");

	*stdout = *fp;

	setvbuf(stdout, NULL, _IONBF, 0);

}
threadInfo Info; 
CExaple44Dlg::CExaple44Dlg(CWnd* pParent /*=NULL*/)
: CDialog(CExaple44Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nData1 = 0;   
	m_nData2 = 0;  
	tm=CTime::GetCurrentTime(); 
	str=tm.Format("����ʱ����%Y��%m��%d�� %X");
}

void CExaple44Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExaple44Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CExaple44Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CExaple44Dlg message handlers

BOOL CExaple44Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	InitConsoleWindow();//Rain
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CExaple44Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CExaple44Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CExaple44Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	SetTimer(1, 1000, NULL);   
	// ����IDΪ2�Ķ�ʱ������ʱʱ��Ϊ2��   
	SetTimer(2, 2000, NULL);  
	Info.Id=1;
	Info.nMilliSecond =100;
	pThread=AfxBeginThread(ThreadFunc,  &Info);    //����MFC�߳�
	//OnOK();
}
UINT ThreadFunc(LPVOID lpParam)
{
	threadInfo* pInfo=(threadInfo*)lpParam;
	static int j = 0;
	for(int i=0;i<100;i++)
	{
		int nTemp=pInfo->nMilliSecond;

		Sleep(nTemp);
		printf("====i:%d\n",i);
	}
	CString tm= GetTimeIng();
	printf("====pInfo:%d\n",pInfo->Id);
	printf("====pInfo:%d\n",pInfo->Id);
	return 0;
}

void CExaple44Dlg::OnTimer(UINT_PTR nIDEvent)      
{      
	// TODO: Add your message handler code here and/or call default      
	// TODO: Add your message handler code here and/or call default   
	switch (nIDEvent)   
	{   
	case 1:  
		{// ���m_nData1�Ѿ��ﵽ10��������IDΪ1�Ķ�ʱ��   
		/*		if (10 == m_nData1)   
		{   
		KillTimer(1);   
		break;   
		} */  
		//KillTimer(1); 
		// ˢ�±༭��IDC_EDIT1����ʾ   
		SetDlgItemInt(IDC_EDIT1, ++m_nData1);
		str = GetTimeIng();
		//wchar_t *pch =new wchar_t[str.GetLength()+1]; 
		//pch=str.GetBuffer(str.GetLength()+1);
		//str.ReleaseBuffer(); //����GetBuffer��һ��Ҫ����ReleaseBuffer 


//cout<< pch << endl;
		//cout<< (LPCTSTR)GetTimeIng() << endl;
		/*	using namespace std;*/
		//cout<<m_nData1;
//printf("now time is %s\n", pch);
//printf("now time is %s\n", str);
wprintf_s(L"%s\n",str);
//wprintf_s(L"%s\n",pch);
		}
		break;   
	case 2:   
		// ���m_nData2�Ѿ��ﵽ5��������IDΪ2�Ķ�ʱ��   
		/*	if (5 == m_nData2)   
		{   
		KillTimer(2);   
		break;   
		} */  
		//KillTimer(2);
		// ˢ�±༭��IDC_EDIT2����ʾ 
		{

			wprintf_s(L"Case2 : %s\n",GetTimeIng());
			SetDlgItemInt(IDC_EDIT2, ++m_nData2); 
		}  
	default:   
		break;   
	}   

	//CDialogEx::OnTimer(nIDEvent);  

	CWnd::OnTimer(nIDEvent);      
} 
CString GetTimeIng(void)
{
	CString str; //��ȡϵͳʱ�� ����

	CTime tm2; 
	//tm2=CTime::GetCurrentTime(); ����

	//str=tm2.Format("����ʱ����%Y��%m��%d�� %X");
	return str;
}
CString CExaple44Dlg::GetTimeIng(void)
{
	SYSTEMTIME st;
	CString str; //��ȡϵͳʱ�� ����
	GetLocalTime(&st);
	//str.Format("-:-:-",st.wHour,st.wMinute,st.wSecond);
	str.Format(_T("%d:%d:%d"),st.wHour,st.wMinute,st.wSecond);
	CTime tm2; 
	return str;
}
