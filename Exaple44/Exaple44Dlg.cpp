// Exaple44Dlg.cpp : implementation file
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Exaple44.h"
#include "Exaple44Dlg.h"
#include <io.h>//Rain  用来输出调试信息
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
	str=tm.Format("现在时间是%Y年%m月%d日 %X");
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
	// 启动ID为2的定时器，定时时间为2秒   
	SetTimer(2, 2000, NULL);  
	Info.Id=1;
	Info.nMilliSecond =100;
	pThread=AfxBeginThread(ThreadFunc,  &Info);    //创建MFC线程
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
		{// 如果m_nData1已经达到10，则销毁ID为1的定时器   
		/*		if (10 == m_nData1)   
		{   
		KillTimer(1);   
		break;   
		} */  
		//KillTimer(1); 
		// 刷新编辑框IDC_EDIT1的显示   
		SetDlgItemInt(IDC_EDIT1, ++m_nData1);
		str = GetTimeIng();
		//wchar_t *pch =new wchar_t[str.GetLength()+1]; 
		//pch=str.GetBuffer(str.GetLength()+1);
		//str.ReleaseBuffer(); //调用GetBuffer后一定要调用ReleaseBuffer 


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
		// 如果m_nData2已经达到5，则销毁ID为2的定时器   
		/*	if (5 == m_nData2)   
		{   
		KillTimer(2);   
		break;   
		} */  
		//KillTimer(2);
		// 刷新编辑框IDC_EDIT2的显示 
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
	CString str; //获取系统时间 　　

	CTime tm2; 
	//tm2=CTime::GetCurrentTime(); 　　

	//str=tm2.Format("现在时间是%Y年%m月%d日 %X");
	return str;
}
CString CExaple44Dlg::GetTimeIng(void)
{
	SYSTEMTIME st;
	CString str; //获取系统时间 　　
	GetLocalTime(&st);
	//str.Format("-:-:-",st.wHour,st.wMinute,st.wSecond);
	str.Format(_T("%d:%d:%d"),st.wHour,st.wMinute,st.wSecond);
	CTime tm2; 
	return str;
}
