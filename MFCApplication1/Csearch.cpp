// Csearch.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "Csearch.h"
#include"resource.h"
#include<vector>
#include"Cstudent.h"
using namespace std;
Cstudent stu_search;
vector<Cstudent>V1;
// Csearch 对话框
IMPLEMENT_DYNAMIC(Csearch, CDialogEx)

Csearch::Csearch(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SEARCH, pParent)
	, m_search(_T(""))
	, m_group(-1)
{

}

Csearch::~Csearch()
{
}

void Csearch::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list2);
	DDX_Text(pDX, IDC_EDIT2, m_search);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Radio(pDX, IDC_RADIO2, m_group);
}


BEGIN_MESSAGE_MAP(Csearch, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Csearch::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &Csearch::OnBnClickedButton1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &Csearch::OnLvnItemchangedList2)
	ON_EN_CHANGE(IDC_EDIT2, &Csearch::OnEnChangeEdit2)
	ON_CBN_SELENDOK(IDC_COMBO1, &Csearch::OnCbnSelendokCombo1)
	ON_BN_CLICKED(IDOK, &Csearch::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO2, &Csearch::OnBnClickedRadio2)
END_MESSAGE_MAP()


// Csearch 消息处理程序


BOOL Csearch::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect rect1;
	m_list2.GetClientRect(&rect1);
	m_list2.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	// TODO:  在此添加额外的初始化
	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_list2.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_list2.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加三列   
	m_list2.InsertColumn(0, _T("学号"), LVCFMT_CENTER, rect.Width() / 5, 0);
	m_list2.InsertColumn(1, _T("性别"), LVCFMT_CENTER, rect.Width() / 9, 1);
	m_list2.InsertColumn(2, _T("名字"), LVCFMT_CENTER, rect.Width() / 8, 2);
	m_list2.InsertColumn(3, _T("年龄"), LVCFMT_CENTER, rect.Width() / 9, 3);
	m_list2.InsertColumn(4, _T("专业班级"), LVCFMT_CENTER, rect.Width() / 6, 4);
	m_list2.InsertColumn(5, _T("高数成绩"), LVCFMT_CENTER, rect.Width() / 7, 5);
	m_list2.InsertColumn(6, _T("实训成绩"), LVCFMT_CENTER, rect.Width() / 7, 6);
	m_list2.InsertColumn(7, _T("英语成绩"), LVCFMT_CENTER, rect.Width() / 7, 7);
	m_combo.InsertString(0, _T("学号"));
	m_combo.InsertString(1, _T("名字"));
	m_combo.InsertString(2, _T("专业班级"));
	m_combo.InsertString(3, _T("高数成绩"));
	m_combo.InsertString(4, _T("实训成绩"));
	m_combo.InsertString(5, _T("英语成绩"));
	readfile();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
void Csearch::readfile()//将数据读取到V1容器里
{
	CStdioFile readfile;
	if (!readfile.Open(_T("学生信息管理表.txt"), CFile::typeText | CFile::modeRead))
	{
		MessageBox(_T("打开文件失败"));
	    return;
    }
	while (readfile.Read(&stu_search, sizeof(stu_search)) == sizeof(stu_search))//自动将文件内容读取完整
	{
		V1.push_back(stu_search);
	}
	readfile.Close();
}

void Csearch::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Csearch::OnBnClickedButton1()
{
	UpdateData(true);
	if (m_search == "")
	{
		MessageBox(_T("请输入查找信息"));
		return;
	}
	m_list2.DeleteAllItems();
	int nIndex = m_combo.GetCurSel();//获取选择的位置
	CString str;
	int x = 0;
	m_combo.GetLBText(nIndex, str);
	if (str == "")
	{
		MessageBox(_T("请选择查询方式"));
		return;
	}// TODO: 在此添加控件通知处理程序代码
	if (str == "姓名")
	{
		if(m_search=="")
		{
			MessageBox(_T("请输入想要查询学生的名字"));
			return;
		}
		for (int i = 0; i < V1.size(); i++)
		{
			if (m_search == V1[i].name)
			{
				CString sex;
				m_list2.InsertItem(x, (CString)V1[i].num);
				if (V1[i].sex == 0)
					sex = "男";
				else
					sex = "女";
				m_list2.SetItemText(x, 1,sex );
				m_list2.SetItemText(x, 2, (CString)V1[i].name);
				m_list2.SetItemText(x, 3, (CString)V1[i].age);
				m_list2.SetItemText(x, 4, (CString)V1[i].Class);
				m_list2.SetItemText(x, 5, (CString)V1[i].Math);
				m_list2.SetItemText(x, 6, (CString)V1[i].CPP);
				m_list2.SetItemText(x, 7, (CString)V1[i].English);
				x++;
			}
	    }
		if (x == 0)
		{
			MessageBox(_T("查无此人！"));
			return;
		}
		else
		{
			MessageBox(_T("查找成功！"));
			return;
		}
	}
	x = 0;
	if (str == "学号")
	{
		if (m_search == "")
		{
			MessageBox(_T("请输入想要查询学生的学号"));
			return;
		}
		for (int i = 0; i < V1.size(); i++)
		{
			if (m_search == V1[i].num)
			{
				CString sex;
				m_list2.InsertItem(x, (CString)V1[i].num);
				if (V1[i].sex == 0)
					sex = "男";
				else
					sex = "女";
				m_list2.SetItemText(x, 1, sex);
				m_list2.SetItemText(x, 2, (CString)V1[i].name);
				m_list2.SetItemText(x, 3, (CString)V1[i].age);
				m_list2.SetItemText(x, 4, (CString)V1[i].Class);
				m_list2.SetItemText(x, 5, (CString)V1[i].Math);
				m_list2.SetItemText(x, 6, (CString)V1[i].CPP);
				m_list2.SetItemText(x, 7, (CString)V1[i].English);
				x++;
			}
		}
		if (x == 0)
		{
			MessageBox(_T("查无此人！"));
			return;
		}
		else
		{
			MessageBox(_T("查找成功！"));
			return;
		}
	}
	x = 0;
	if (str == "专业班级")
	{
		if (m_search == "")
		{
			MessageBox(_T("请输入想要查询学生的专业班级"));
			return;
		}
		for (int i = 0; i < V1.size(); i++)
		{
			if (m_search == V1[i].Class)
			{
				CString sex;
				m_list2.InsertItem(x, (CString)V1[i].num);
				if (V1[i].sex == 0)
					sex = "男";
				else
					sex = "女";
				m_list2.SetItemText(x, 1, sex);
				m_list2.SetItemText(x, 2, (CString)V1[i].name);
				m_list2.SetItemText(x, 3, (CString)V1[i].age);
				m_list2.SetItemText(x, 4, (CString)V1[i].Class);
				m_list2.SetItemText(x, 5, (CString)V1[i].Math);
				m_list2.SetItemText(x, 6, (CString)V1[i].CPP);
				m_list2.SetItemText(x, 7, (CString)V1[i].English);
				x++;
			}
		}
		if (x == 0)
		{
			MessageBox(_T("查无此人！"));
			return;
		}
		else
		{
			MessageBox(_T("查找成功！"));
			return;
		}
	}
	x = 0;
	if (str == "高数成绩")
	{
		if (m_search == "")
		{
			MessageBox(_T("请输入想要查询科目的成绩或者范围"));
			return;
		}
		if (m_group == -1)
		{
	
			for (int i = 0; i < V1.size(); i++)
			{
				if (m_search == V1[i].Math)
				{
					CString sex;
					m_list2.InsertItem(x, (CString)V1[i].num);
					if (V1[i].sex == 0)
						sex = "男";
					else
						sex = "女";
					m_list2.SetItemText(x, 1, sex);
					m_list2.SetItemText(x, 2, (CString)V1[i].name);
					m_list2.SetItemText(x, 3, (CString)V1[i].age);
					m_list2.SetItemText(x, 4, (CString)V1[i].Class);
					m_list2.SetItemText(x, 5, (CString)V1[i].Math);
					m_list2.SetItemText(x, 6, (CString)V1[i].CPP);
					m_list2.SetItemText(x, 7, (CString)V1[i].English);
					x++;
				}
			}
	    }
		if (m_group == 0)
		{
			LPSTR str;
			USES_CONVERSION;
			str = T2A(m_search);//CString ->LPSTR 与Char比较方法
			for (int i = 0; i < V1.size(); i++)
			{
				float temp1, temp2;
				temp1 = atof(str);
				temp2 = atof(V1[i].Math);
				if (temp2 >= temp1)
				{
					CString sex;
					m_list2.InsertItem(x, (CString)V1[i].num);
					if (V1[i].sex == 0)
						sex = "男";
					else
						sex = "女";
					m_list2.SetItemText(x, 1, sex);
					m_list2.SetItemText(x, 2, (CString)V1[i].name);
					m_list2.SetItemText(x, 3, (CString)V1[i].age);
					m_list2.SetItemText(x, 4, (CString)V1[i].Class);
					m_list2.SetItemText(x, 5, (CString)V1[i].Math);
					m_list2.SetItemText(x, 6, (CString)V1[i].CPP);
					m_list2.SetItemText(x, 7, (CString)V1[i].English);
					x++;
				}
			}
		}
		if (m_group == 1)
		{
			LPSTR str;
			USES_CONVERSION;
			str = T2A(m_search);//CString ->LPSTR 与Char比较方法
			for (int i = 0; i < V1.size(); i++)
			{
				float temp1, temp2;
				temp1 = atof(str);
				temp2 = atof(V1[i].Math);
				if (temp2 < temp1)
				{
					CString sex;
					m_list2.InsertItem(x, (CString)V1[i].num);
					if (V1[i].sex == 0)
						sex = "男";
					else
						sex = "女";
					m_list2.SetItemText(x, 1, sex);
					m_list2.SetItemText(x, 2, (CString)V1[i].name);
					m_list2.SetItemText(x, 3, (CString)V1[i].age);
					m_list2.SetItemText(x, 4, (CString)V1[i].Class);
					m_list2.SetItemText(x, 5, (CString)V1[i].Math);
					m_list2.SetItemText(x, 6, (CString)V1[i].CPP);
					m_list2.SetItemText(x, 7, (CString)V1[i].English);
					x++;
				}
			}
		}
		if (x == 0)
		{
			MessageBox(_T("查无此人！"));
			return;
		}
		else
		{
			MessageBox(_T("查找成功！"));
			return;
		}
	}
	x = 0;
	if (str == "实训成绩")
	{
		if (m_search == "")
		{
			MessageBox(_T("请输入想要查询科目的成绩或者范围"));
			return;
		}
		if (m_group == -1)
		{

			for (int i = 0; i < V1.size(); i++)
			{
				if (m_search == V1[i].CPP)
				{
					CString sex;
					m_list2.InsertItem(x, (CString)V1[i].num);
					if (V1[i].sex == 0)
						sex = "男";
					else
						sex = "女";
					m_list2.SetItemText(x, 1, sex);
					m_list2.SetItemText(x, 2, (CString)V1[i].name);
					m_list2.SetItemText(x, 3, (CString)V1[i].age);
					m_list2.SetItemText(x, 4, (CString)V1[i].Class);
					m_list2.SetItemText(x, 5, (CString)V1[i].Math);
					m_list2.SetItemText(x, 6, (CString)V1[i].CPP);
					m_list2.SetItemText(x, 7, (CString)V1[i].English);
					x++;
				}
			}
		}
		if (m_group == 0)
		{
			LPSTR str;
			USES_CONVERSION;
			str = T2A(m_search);//CString ->LPSTR 与Char比较方法
			for (int i = 0; i < V1.size(); i++)
			{
				float temp1, temp2;
				temp1 = atof(str);
				temp2 = atof(V1[i].CPP);
				if (temp2 >= temp1)
				{
					CString sex;
					m_list2.InsertItem(x, (CString)V1[i].num);
					if (V1[i].sex == 0)
						sex = "男";
					else
						sex = "女";
					m_list2.SetItemText(x, 1, sex);
					m_list2.SetItemText(x, 2, (CString)V1[i].name);
					m_list2.SetItemText(x, 3, (CString)V1[i].age);
					m_list2.SetItemText(x, 4, (CString)V1[i].Class);
					m_list2.SetItemText(x, 5, (CString)V1[i].Math);
					m_list2.SetItemText(x, 6, (CString)V1[i].CPP);
					m_list2.SetItemText(x, 7, (CString)V1[i].English);
					x++;
				}
			}
		}
		if (m_group == 1)
		{
			LPSTR str;
			USES_CONVERSION;  
			str = T2A(m_search);//CString ->LPSTR 与Char比较方法
			for (int i = 0; i < V1.size(); i++)
			{
				float temp1, temp2;
				temp1 = atof(str);
				temp2 = atof(V1[i].CPP);
				if (temp2 < temp1)
				{
					CString sex;
					m_list2.InsertItem(x, (CString)V1[i].num);
					if (V1[i].sex == 0)
						sex = "男";
					else
						sex = "女";
					m_list2.SetItemText(x, 1, sex);
					m_list2.SetItemText(x, 2, (CString)V1[i].name);
					m_list2.SetItemText(x, 3, (CString)V1[i].age);
					m_list2.SetItemText(x, 4, (CString)V1[i].Class);
					m_list2.SetItemText(x, 5, (CString)V1[i].Math);
					m_list2.SetItemText(x, 6, (CString)V1[i].CPP);
					m_list2.SetItemText(x, 7, (CString)V1[i].English);
					x++;
				}
			}
		}
		if (x == 0)
		{
			MessageBox(_T("查无此人！"));
			return;
		}
		else
		{
			MessageBox(_T("查找成功！"));
			return;
		}
	}
	x = 0;

	if (str == "英语成绩")
	{
		if (m_search == "")
		{
			MessageBox(_T("请输入想要查询科目的成绩或者范围"));
			return;
		}
		if (m_group == -1)
		{

			for (int i = 0; i < V1.size(); i++)
			{
				if (m_search == V1[i].English)
				{
					CString sex;
					m_list2.InsertItem(x, (CString)V1[i].num);
					if (V1[i].sex == 0)
						sex = "男";
					else
						sex = "女";
					m_list2.SetItemText(x, 1, sex);
					m_list2.SetItemText(x, 2, (CString)V1[i].name);
					m_list2.SetItemText(x, 3, (CString)V1[i].age);
					m_list2.SetItemText(x, 4, (CString)V1[i].Class);
					m_list2.SetItemText(x, 5, (CString)V1[i].Math);
					m_list2.SetItemText(x, 6, (CString)V1[i].CPP);
					m_list2.SetItemText(x, 7, (CString)V1[i].English);
					x++;
				}
			}
		}
		if (m_group == 0)
		{
			LPSTR str;
			USES_CONVERSION;
			str = T2A(m_search);//CString ->LPSTR 与Char比较方法
			for (int i = 0; i < V1.size(); i++)
			{
				float temp1, temp2;
				temp1 = atof(str);
				temp2 = atof(V1[i].English);
				if (temp2 >= temp1)
				{
					CString sex;
					m_list2.InsertItem(x, (CString)V1[i].num);
					if (V1[i].sex == 0)
						sex = "男";
					else
						sex = "女";
					m_list2.SetItemText(x, 1, sex);
					m_list2.SetItemText(x, 2, (CString)V1[i].name);
					m_list2.SetItemText(x, 3, (CString)V1[i].age);
					m_list2.SetItemText(x, 4, (CString)V1[i].Class);
					m_list2.SetItemText(x, 5, (CString)V1[i].Math);
					m_list2.SetItemText(x, 6, (CString)V1[i].CPP);
					m_list2.SetItemText(x, 7, (CString)V1[i].English);
					x++;
				}
			}
		}
		if (m_group == 1)
		{
			LPSTR str;
			USES_CONVERSION;
			str = T2A(m_search);//CString ->LPSTR 与Char比较方法
			for (int i = 0; i < V1.size(); i++)
			{
				float temp1, temp2;
				temp1 = atof(str);
				temp2 = atof(V1[i].English);
				if (temp2 < temp1)
				{
					CString sex;
					m_list2.InsertItem(x, (CString)V1[i].num);
					if (V1[i].sex == 0)
						sex = "男";
					else
						sex = "女";
					m_list2.SetItemText(x, 1, sex);
					m_list2.SetItemText(x, 2, (CString)V1[i].name);
					m_list2.SetItemText(x, 3, (CString)V1[i].age);
					m_list2.SetItemText(x, 4, (CString)V1[i].Class);
					m_list2.SetItemText(x, 5, (CString)V1[i].Math);
					m_list2.SetItemText(x, 6, (CString)V1[i].CPP);
					m_list2.SetItemText(x, 7, (CString)V1[i].English);
					x++;
				}
			}
		}
		if (x == 0)
		{
			MessageBox(_T("查无此人！"));
			return;
		}
		else
		{
			MessageBox(_T("查找成功！"));
			return;
		}
	}
	x = 0;
}


void Csearch::OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void Csearch::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void Csearch::OnCbnSelendokCombo1()//确定选择事件
{
	
	CEdit* button1 = (CEdit*)GetDlgItem(IDC_BUTTON1);
	button1->EnableWindow(true);
	m_search = "";
	m_group = -1;
	UpdateData(false);
	int nIndex = m_combo.GetCurSel();
	CString str;
	int x = 0;
	m_combo.GetLBText(nIndex, str);
	if (str == "高数成绩" || str == "实训成绩" || str == "英语成绩")
	{
		m_group = -1;
		MessageBox(_T("在下方输入相应的成绩进行查询或勾选范围按钮进行范围查询"), _T("提示"));
		CEdit* radio2 = (CEdit*)GetDlgItem(IDC_RADIO2);
		radio2->ShowWindow(true);
		CEdit* radio3 = (CEdit*)GetDlgItem(IDC_RADIO3);
		radio3->ShowWindow(true);
	}
	else
	{
		CEdit* edit2 = (CEdit*)GetDlgItem(IDC_RADIO2);
		edit2->ShowWindow(false);
		CEdit* edit3 = (CEdit*)GetDlgItem(IDC_RADIO3);
		edit3->ShowWindow(false);
	}
	// TODO: 在此添加控件通知处理程序代码
}


void Csearch::OnBnClickedOk()
{
	V1.clear();
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void Csearch::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
}
