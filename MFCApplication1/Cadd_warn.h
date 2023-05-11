#pragma once
#include "afxdialogex.h"


// Cadd_warn 对话框

class Cadd_warn : public CDialogEx
{
	DECLARE_DYNAMIC(Cadd_warn)

public:
	Cadd_warn(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Cadd_warn();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD_WARN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
