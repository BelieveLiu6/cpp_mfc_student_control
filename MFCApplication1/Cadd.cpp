// Cadd.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "Cadd.h"


// Cadd 对话框
IMPLEMENT_DYNAMIC(Cadd, CDialogEx)

Cadd::Cadd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD, pParent)
	, num(_T(""))
	, sex(_T(""))
	, name(_T(""))
	, age(_T(""))
	, grade(_T(""))
	, score(_T(""))
	, m_boy(FALSE)
	, m_girl(FALSE)
	
{

}

Cadd::~Cadd()
{
}

void Cadd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, num);
	DDX_Text(pDX, IDC_EDIT5, age);
	DDX_Text(pDX, IDC_EDIT4, grade);
	DDX_Text(pDX, IDC_EDIT6, score);
	DDX_Radio(pDX, IDC_RADIO1, m_boy);
	DDX_Radio(pDX, IDC_RADIO2, m_girl);
	DDX_Text(pDX, IDC_EDIT1, name);
}


BEGIN_MESSAGE_MAP(Cadd, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &Cadd::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &Cadd::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &Cadd::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &Cadd::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO2, &Cadd::OnBnClickedRadio2)
END_MESSAGE_MAP()


// Cadd 消息处理程序


void Cadd::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void Cadd::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cadd::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void Cadd::OnBnClickedOk()
{
	
	// TODO: 在此添加控件通知处理程序代码
}


void Cadd::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
}
