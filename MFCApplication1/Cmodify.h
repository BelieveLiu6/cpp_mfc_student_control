#pragma once
#include "afxdialogex.h"


// Cmodify 对话框

class Cmodify : public CDialogEx
{
	DECLARE_DYNAMIC(Cmodify)

public:
	Cmodify(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Cmodify();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MODIFY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_modify_num;
	CString m_modify_name;
	CString m_modify_class;
	CString m_modify_age;
	CString m_modify_math;
	int m_modify_sex;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	CString m_modify_cpp;
	CString m_modify_english;
};
