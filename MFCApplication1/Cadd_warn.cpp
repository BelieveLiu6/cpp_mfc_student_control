// Cadd_warn.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "Cadd_warn.h"


// Cadd_warn 对话框

IMPLEMENT_DYNAMIC(Cadd_warn, CDialogEx)

Cadd_warn::Cadd_warn(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD_WARN, pParent)
{

}

Cadd_warn::~Cadd_warn()
{
}

void Cadd_warn::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cadd_warn, CDialogEx)
	ON_BN_CLICKED(IDOK, &Cadd_warn::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Cadd_warn::OnBnClickedCancel)
END_MESSAGE_MAP()


// Cadd_warn 消息处理程序


void Cadd_warn::OnBnClickedOk()
{   // TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void Cadd_warn::OnBnClickedCancel()
{
	
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
