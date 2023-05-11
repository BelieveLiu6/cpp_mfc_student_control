#pragma once
#include "afxdialogex.h"


// Cstatistic 对话框

class Cstatistic : public CDialogEx
{
	DECLARE_DYNAMIC(Cstatistic)

public:
	Cstatistic(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Cstatistic();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_statistic };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_picture;
};
