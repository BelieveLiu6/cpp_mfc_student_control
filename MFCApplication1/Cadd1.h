#pragma once
#include "afxdialogex.h"


// Cadd1 对话框

class Cadd1 : public CDialogEx
{
	DECLARE_DYNAMIC(Cadd1)

public:
	Cadd1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Cadd1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_num;
	CString m_name;
	CString m_class;
	CString m_age;
	CString m_math;
	afx_msg void OnBnClickedRadio1();
	int m_sex;
	CString m_cpp;
	CString m_english;
};
