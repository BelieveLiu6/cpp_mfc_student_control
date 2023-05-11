#pragma once
#include "afxdialogex.h"
#include"Cstudent.h"

// Cmune 对话框

class Cmune : public CDialogEx
{
	DECLARE_DYNAMIC(Cmune)

public:
	Cmune(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Cmune();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MUNE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	CListCtrl m_list1;
	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	void  ReadStringCharToUnicode(CString& str);
	void SaveFile();
	void FlashList();
//	afx_msg void OnNMClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	// 排序
	CComboBox m_combo1;
	int m_radio1;
	afx_msg void OnCbnSelendokCombo2();
	afx_msg void OnBnClickedButton2();
	void sort_up(int x);
	void sort_down(int x);
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnLvnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCbnSelendokCombo1();
	afx_msg void OnBnClickedButton8();
	CComboBox m_combo2;
};
