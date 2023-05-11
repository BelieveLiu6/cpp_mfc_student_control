// Cmodify.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "Cmodify.h"
#include "resource.h"
// Cmodify 对话框
IMPLEMENT_DYNAMIC(Cmodify, CDialogEx)

Cmodify::Cmodify(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MODIFY, pParent)
	, m_modify_num(_T(""))
	, m_modify_name(_T(""))
	, m_modify_class(_T(""))
	, m_modify_age(_T(""))
	, m_modify_math(_T(""))
	, m_modify_sex(-1)
	, m_modify_cpp(_T(""))
	, m_modify_english(_T(""))
{

}

Cmodify::~Cmodify()
{
}

void Cmodify::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_modify_num);
	DDX_Text(pDX, IDC_EDIT4, m_modify_name);
	DDX_Text(pDX, IDC_EDIT5, m_modify_class);
	DDX_Text(pDX, IDC_EDIT3, m_modify_age);
	DDX_Text(pDX, IDC_EDIT1, m_modify_math);
	DDX_Radio(pDX, IDC_RADIO1, m_modify_sex);
	DDX_Text(pDX, IDC_EDIT6, m_modify_cpp);
	DDX_Text(pDX, IDC_EDIT7, m_modify_english);
}


BEGIN_MESSAGE_MAP(Cmodify, CDialogEx)
	ON_BN_CLICKED(IDOK, &Cmodify::OnBnClickedOk)
END_MESSAGE_MAP()


// Cmodify 消息处理程序


BOOL Cmodify::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Cmodify::OnBnClickedOk()
{
	UpdateData(true);
	if (m_modify_num.IsEmpty())
	{
		MessageBox(_T("输入的学号不能为空"));
		return;
	}

	if (m_modify_name.IsEmpty())
	{
		MessageBox(_T("输入的名字不能为空"));
		return;
	}

	if (m_modify_class.IsEmpty())
	{
		MessageBox(_T("输入的专业年级不能为空"));
		return;
	}
	if (m_modify_age.IsEmpty())
	{
		MessageBox(_T("输入的年龄不能为空"));
		return;
	}
	if (m_modify_sex == -1)
	{
		MessageBox(_T("请选择一个性别"));
		return;
	}
	if (m_modify_math.IsEmpty())
	{
		MessageBox(_T("输入的高数成绩不能为空"));
		return;
	}
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
