#pragma once
#include "afxdialogex.h"


// Csearch 对话框

class Csearch : public CDialogEx
{
	DECLARE_DYNAMIC(Csearch)

public:
	Csearch(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Csearch();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_list2;
	afx_msg void OnCbnSelchangeCombo1();
	CString m_search;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult);
	void readfile();
	CComboBox m_combo;
	int m_group;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnCbnSelendokCombo1();

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedRadio2();
};
