// Cadd1.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "Cadd1.h"
#include <locale>//用于修改文件不能输入中文的问题--117
#include"Cadd_warn.h"//提示界面
#include"Cstudent.h"
Cstudent stu;
// Cadd1 对话框
IMPLEMENT_DYNAMIC(Cadd1, CDialogEx)

Cadd1::Cadd1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADD, pParent)
	, m_num(_T(""))
	, m_name(_T(""))
	, m_class(_T(""))
	, m_age(_T(""))
	, m_math(_T(""))
	, m_sex(-1)
	, m_cpp(_T(""))
	, m_english(_T(""))
{

}

Cadd1::~Cadd1()
{
}

void Cadd1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_num);
	DDX_Text(pDX, IDC_EDIT4, m_name);
	DDX_Text(pDX, IDC_EDIT5, m_class);
	DDX_Text(pDX, IDC_EDIT3, m_age);
	DDX_Text(pDX, IDC_EDIT1, m_math);
	DDX_Radio(pDX, IDC_RADIO1, m_sex);
	DDX_Text(pDX, IDC_EDIT6, m_cpp);
	DDX_Text(pDX, IDC_EDIT7, m_english);
}


BEGIN_MESSAGE_MAP(Cadd1, CDialogEx)
	ON_BN_CLICKED(IDOK, &Cadd1::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO1, &Cadd1::OnBnClickedRadio1)
END_MESSAGE_MAP()


// Cadd1 消息处理程序


void Cadd1::OnBnClickedOk()
{
	CString sex;
	Cadd_warn add_warn1;
	UpdateData(true);
	//strcpy(stu.name,m_name);
	if (m_num.IsEmpty())
	{
		MessageBox(_T("输入的学号不能为空"));
		return;
	}
	if (m_num.GetLength() >= 20)
	{
		MessageBox(_T("请输入正确的学号"));
		m_num = "";
		return;
	}
	
	if (m_name.IsEmpty())
	{
		MessageBox(_T("输入的名字不能为空"));
		return;
	}
	if (m_name.GetLength() >= 20)
	{
		MessageBox(_T("请输入正确的姓名"));
		return;
	}
	if (m_class.IsEmpty())
	{
		MessageBox(_T("输入的专业年级不能为空"));
		return;
	}
	if (m_class.GetLength() >= 20)
	{
		MessageBox(_T("请输入正确的专业班级"));
		return;
	}
	if (m_age.IsEmpty())
	{
		MessageBox(_T("输入的年龄不能为空"));
		return;
	}
	if (m_age.GetLength() >= 20)
	{
		MessageBox(_T("请输入正确的年龄"));
		return;
	}
	if (m_sex==-1)
	{
		MessageBox(_T("请选择一个性别"));
		return;
	}
	if (m_math.IsEmpty())
	{
		MessageBox(_T("输入的高数成绩不能为空"));
		return;
	}
	if (m_math.GetLength() >= 5)
	{
		MessageBox(_T("请输入正确的高数成绩"));
		return;
	}
	if (m_cpp.IsEmpty())
	{
		MessageBox(_T("输入的实训成绩不能为空"));
		return;
	}

	if (m_cpp.GetLength() >= 5)
	{
		MessageBox(_T("请输入正确的实训成绩"));
		return;
	}
	if (m_english.IsEmpty())
	{
		MessageBox(_T("输入的英语成绩不能为空"));
		return;
	}
	if (m_english.GetLength() >= 5)
	{
		MessageBox(_T("请输入正确的英语成绩"));
		return;
	}
	//if (m_sex == 0)
	//	sex = _T("男");
	//if(m_sex == 1)
	//	sex = _T("女");
	LPSTR str;//将CString 转换为char 
	USES_CONVERSION;
	str = T2A(m_name);
	strcpy_s(stu.name, str);
	str = T2A(m_age);
	strcpy_s(stu.age, str);
	str = T2A(m_math);
	strcpy_s(stu.Math, str);
	str = T2A(m_english);
	strcpy_s(stu.English, str);
	str = T2A(m_num);
	strcpy_s(stu.num, str);
	str = T2A(m_class);
	strcpy_s(stu.Class, str);
	str = T2A(m_cpp);
	strcpy_s(stu.CPP, str);
	stu.sex = m_sex;
	CStdioFile myfile;
	CString FileString = _T("学生信息管理表.txt");
	if (myfile.Open(FileString, CFile::typeText | CFile::modeWrite | CFile::modeCreate | CFile::modeNoTruncate))
	{
		myfile.SeekToEnd();//文件指针指向文件末尾
		myfile.Write(&stu, sizeof(stu));
		if (add_warn1.DoModal() == IDOK)
		{
			m_num = "";
			m_name = "";
			m_math = "";
			m_class = "";
			m_age = "";
			m_sex = -1;
			m_cpp = "";
			m_english = "";
			UpdateData(FALSE);
		}
		else
			CDialogEx::OnOK();
		myfile.Close();
	}
	else
		MessageBox(_T("出现了一个文件打开失败的错误!"));
	
	// TODO: 在此添加控件通知处理程序代码*/
}


void Cadd1::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
}
