#pragma once
#include "afxdialogex.h"


// Cadd 对话框

class Cadd : public CDialogEx
{
	DECLARE_DYNAMIC(Cadd)

public:
	Cadd(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Cadd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedOk();
	CString num;
	CString name;
	CString age;
	CString grade;
	CString score;
	afx_msg void OnBnClickedRadio2();
	BOOL m_boy;
	BOOL m_girl;
};
