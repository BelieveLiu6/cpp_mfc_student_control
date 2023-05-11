#pragma once
#include "afxdialogex.h"


// Cdelete_warn 对话框

class Cdelete_warn : public CDialogEx
{
	DECLARE_DYNAMIC(Cdelete_warn)

public:
	Cdelete_warn(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Cdelete_warn();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Delete_warn };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
