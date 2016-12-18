// Exaple44Dlg.h : header file
//

#pragma once
CString GetTimeIng(void);
struct threadInfo
{
	UINT nMilliSecond;
	UINT Id;
};
UINT ThreadFunc(LPVOID lpParam);
// CExaple44Dlg dialog
class CExaple44Dlg : public CDialog
{
// Construction
public:
	CExaple44Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_EXAPLE44_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;
	int m_nData1;   
	int m_nData2;
	CString str; //获取系统时间 
	CTime tm;
	CWinThread* pThread;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT nTimerID);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
CString CExaple44Dlg::GetTimeIng(void);
};
