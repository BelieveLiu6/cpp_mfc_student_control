// Cmune.cpp: 实现文件
//
#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "Cmune.h"
#include"Cadd1.h"
#include"Cdelete_warn.h"
#include<vector>
#include"Cmodify.h"
#include"Csearch.h"
#include"Cstudent.h"
#include<algorithm>
#include"Cstatistic.h"
using namespace std;
vector<Cstudent>V0;
Cstudent stu1,stu2,temp;
// Cmune 对话框
IMPLEMENT_DYNAMIC(Cmune, CDialogEx)
Cmune::Cmune(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_radio1(-1)
{

}

Cmune::~Cmune()
{
}
void Cmune::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_COMBO2, m_combo1);
	DDX_Radio(pDX, IDC_RADIO1, m_radio1);
	DDX_Control(pDX, IDC_COMBO1, m_combo2);
}


BEGIN_MESSAGE_MAP(Cmune, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &Cmune::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &Cmune::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &Cmune::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &Cmune::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &Cmune::OnBnClickedOk)
//	ON_NOTIFY(NM_CLICK, IDC_LIST1, &Cmune::OnNMClickList1)
ON_NOTIFY(NM_CLICK, IDC_LIST1, &Cmune::OnClickList1)
ON_CBN_SELENDOK(IDC_COMBO2, &Cmune::OnCbnSelendokCombo2)
ON_BN_CLICKED(IDC_BUTTON2, &Cmune::OnBnClickedButton2)
ON_CBN_SELCHANGE(IDC_COMBO2, &Cmune::OnCbnSelchangeCombo2)
ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST1, &Cmune::OnLvnColumnclickList1)
ON_CBN_SELENDOK(IDC_COMBO1, &Cmune::OnCbnSelendokCombo1)
ON_BN_CLICKED(IDC_BUTTON8, &Cmune::OnBnClickedButton8)
END_MESSAGE_MAP()


// Cmune 消息处理程序


void Cmune::OnBnClickedButton5()//修改按钮
{
	POSITION pos;
	pos=m_list1.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(_T("请选择要修改的数据"), _T("警告"));
			return;
	}
	int position;
	position = m_list1.GetNextSelectedItem(pos);
	Cmodify modify;
	int i;
	CString nu, se, na, ag, cl, ma,cp,en;
	modify.m_modify_num = m_list1.GetItemText(position, 0);
	if (m_list1.GetItemText(position, 1) == _T("男"))
		modify.m_modify_sex = 0;
	else
		modify.m_modify_sex = 1;
	modify.m_modify_name = m_list1.GetItemText(position, 2);
	modify.m_modify_age = m_list1.GetItemText(position, 3);
	modify.m_modify_class = m_list1.GetItemText(position, 4);
	modify.m_modify_math = m_list1.GetItemText(position, 5);
	modify.m_modify_cpp = m_list1.GetItemText(position, 6);
	modify.m_modify_english= m_list1.GetItemText(position, 7);
	i = modify.DoModal();
	if(i==IDOK)
	
	{
	  nu = modify.m_modify_num;
	  if (modify.m_modify_sex == 0)
		se = _T("男");
	  else
		se = _T("女");
	na = modify.m_modify_name;
	ag = modify.m_modify_age;
	cl = modify.m_modify_class;
	ma = modify.m_modify_math;
	cp = modify.m_modify_cpp;
	en= modify.m_modify_english;
	m_list1.SetItemText(position,0, nu);
	m_list1.SetItemText(position, 1, se);
	m_list1.SetItemText(position, 2, na);
	m_list1.SetItemText(position,3, ag);
	m_list1.SetItemText(position, 4, cl);
	m_list1.SetItemText(position, 5, ma);
	m_list1.SetItemText(position, 6, cp);
	m_list1.SetItemText(position, 7, en);
	SaveFile();
	FlashList();
	}
	/*
	CWnd* cwnd;
	cwnd = modify.GetDlgItem(IDC_EDIT2);
	cwnd->SetWindowText(str);*/ //bug
	/*temp.temp_num = m_list1.GetItemText(position, 0);
	UpdateData(FALSE);*/
	if (i == IDCANCEL)
		return;

	// TODO: 在此添加控件通知处理程序代码
}


void Cmune::OnBnClickedButton4()//查询按钮
{
	Csearch search;
	search.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void Cmune::OnBnClickedButton3()//增添按钮
{
	Cadd1 add;
	int X= add.DoModal();
	if (X == IDCANCEL || X == IDOK)
	{
		FlashList();
	}//调用刷新函数
	// TODO: 在此添加控件通知处理程序代码
}


void Cmune::OnBnClickedButton1()//删除功能
{
	
	POSITION pos = m_list1.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(_T("请选择要删除的数据"), _T("警告"));
		return;
	}
	Cdelete_warn Cdelete;
    if (Cdelete.DoModal() != IDOK)
		return;
	else
	{
		int n = m_list1.GetNextSelectedItem(pos);
		m_list1.DeleteItem(n);
		SaveFile();
		MessageBox(_T("删除成功"));
		FlashList();
	}
	// TODO: 在此添加控件通知处理程序代码
}


void Cmune::OnBnClickedOk()
{
	
	SaveFile();
	 // TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}



void Cmune::OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


BOOL Cmune::OnInitDialog()//初始化
{
	CDialogEx::OnInitDialog();
	
	CRect rect;
	
	
	m_list1.GetClientRect(&rect);// 获取编程语言列表视图控件的位置和大小   

	  
	m_list1.SetExtendedStyle( LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);// 为列表视图控件添加全行选中和栅格风格 

	// 为列表视图控件添加三列   
	m_list1.InsertColumn(0, _T("学号"), LVCFMT_CENTER, rect.Width() / 5, 0);
	m_list1.InsertColumn(1, _T("性别"), LVCFMT_CENTER, rect.Width() / 9, 1);
	m_list1.InsertColumn(2, _T("名字"), LVCFMT_CENTER, rect.Width() / 8, 2);
	m_list1.InsertColumn(3, _T("年龄"), LVCFMT_CENTER, rect.Width() / 9, 3);
	m_list1.InsertColumn(4, _T("专业班级"), LVCFMT_CENTER, rect.Width() / 6, 4);
	m_list1.InsertColumn(5, _T("高数成绩"), LVCFMT_CENTER, rect.Width() / 7, 5);
	m_list1.InsertColumn(6, _T("实训成绩"), LVCFMT_CENTER, rect.Width() / 7, 6);
	m_list1.InsertColumn(7, _T("英语成绩"), LVCFMT_CENTER, rect.Width() / 7, 7);

	// 在列表视图控件中插入列表项，并设置列表子项文本  
	FlashList();
	m_combo1.InsertString(0, _T("学号"));
	m_combo1.InsertString(1, _T("性别"));
	m_combo1.InsertString(2, _T("名字"));
	m_combo1.InsertString(3, _T("年龄"));
	m_combo1.InsertString(4, _T("专业班级"));
	m_combo1.InsertString(5, _T("高数成绩"));
	m_combo1.InsertString(6, _T("实训成绩"));
	m_combo1.InsertString(7, _T("英语成绩"));



	m_combo2.InsertString(0, _T("高数成绩"));
	m_combo2.InsertString(1, _T("实训成绩"));
	m_combo2.InsertString(2, _T("英语成绩"));
	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void Cmune::SaveFile()
{
	CStdioFile writefile;
	if (writefile.Open(_T("学生信息管理表.txt"), CFile::typeText | CFile::modeWrite | CFile::modeCreate))
	{
		for (int i = 0; i < m_list1.GetItemCount(); i++)
		{
			LPSTR str;
			CString SEX;
			int sex;
			USES_CONVERSION;
			str = T2A(m_list1.GetItemText(i, 0));//将CString 转换为LOSTR 再使用strcpy 将LOSTR的值赋给char
			strcpy_s(stu2.num, str);
			SEX=m_list1.GetItemText(i, 1);
			if (SEX == "男")
				sex = 0;
			else
				sex = 1;
			stu2.sex = sex;
			str = T2A(m_list1.GetItemText(i, 2));
			strcpy_s(stu2.name, str);
			str = T2A(m_list1.GetItemText(i, 3));
			strcpy_s(stu2.age, str);
			str = T2A(m_list1.GetItemText(i, 4));
			strcpy_s(stu2.Class, str);
			str = T2A(m_list1.GetItemText(i, 5));
			strcpy_s(stu2.Math, str);
			str = T2A(m_list1.GetItemText(i, 6));
			strcpy_s(stu2.CPP, str);
			str = T2A(m_list1.GetItemText(i, 7));
			strcpy_s(stu2.English, str);
			writefile.SeekToEnd();
			writefile.Write(&stu2,sizeof(stu2));
		}
		writefile.Close();
	}
}   
void Cmune::FlashList()
{
	m_list1.DeleteAllItems();
	CString str;
	CStdioFile infile;
	if (infile.Open(_T("学生信息管理表.txt"), CFile::typeText | CFile::modeRead | CFile::modeCreate | CFile::modeNoTruncate))
	{
		int i = 0;
		while (infile.Read(&stu1, sizeof(stu1)) == sizeof(stu1))//文件数据读取到stu1中,直到文件末尾，跳出循环
		{
			CString sex;
			m_list1.InsertItem(i, (CString)stu1.num);
			if (stu1.sex == 0)
				sex = "男";
			else
				sex = "女";
			m_list1.SetItemText(i, 1, sex);
			m_list1.SetItemText(i, 2, (CString)stu1.name);
			m_list1.SetItemText(i, 3, (CString)stu1.age);
			m_list1.SetItemText(i, 4, (CString)stu1.Class);
			m_list1.SetItemText(i, 5, (CString)stu1.Math);
			m_list1.SetItemText(i, 6, (CString)stu1.CPP);
			m_list1.SetItemText(i, 7, (CString)stu1.English);
			i++;
		}
		infile.Close();
	}
}//刷新列表


//void Cmune::OnNMClickList1(NMHDR* pNMHDR, LRESULT* pResult)
//{
//
//
//
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
//	*pResult = 0;
//}


void Cmune::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult)//单击事件
{

	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void Cmune::OnCbnSelendokCombo2()//确认选择combo事件
{
	CEdit* radio1 = (CEdit*)GetDlgItem(IDC_RADIO1);
	radio1->EnableWindow(true);
	CEdit* radio2 = (CEdit*)GetDlgItem(IDC_RADIO2);
	radio2->EnableWindow(true);
	CEdit* button2 = (CEdit*)GetDlgItem(IDC_BUTTON2);//获取句柄 以便后面ShowWindow or EnableWindow的使用
	button2->EnableWindow(true);
	m_radio1 = -1;
	UpdateData(false);
	int nIndex = m_combo1.GetCurSel();//获取选择的位置
	CString str;
	m_combo1.GetLBText(nIndex, str);

	// TODO: 在此添加控件通知处理程序代码
}


void Cmune::OnBnClickedButton2()//排序按钮
{
	UpdateData(true);
	if (m_radio1 == -1)
	{
		MessageBox(_T("请选择排序方式"));
		return;
	}
	if (m_radio1 == 0)
	{
		int x;
		x = m_combo1.GetCurSel();
		sort_up(x);
	}
	if (m_radio1 == 1)
	{
		int x;
		x = m_combo1.GetCurSel();
		sort_down(x);
	}
	SaveFile();
	// TODO: 在此添加控件通知处理程序代码
}
BOOL sort_num(Cstudent a, Cstudent b)
{     
	float temp1, temp2;
	temp1 = atof(a.num);
	temp2 = atof(b.num);
	return temp1 < temp2;
}
BOOL sort_sex(Cstudent a, Cstudent b)
{
	return a.sex < b.sex;
}
BOOL sort_name(Cstudent a, Cstudent b)
{
	int x = strcmp(a.name, b.name);
	return x < 0;
}
BOOL sort_age(Cstudent a, Cstudent b)
{
	float temp1, temp2;
	temp1 = atof(a.age);
	temp2 = atof(b.age);
	return temp1 < temp2;
}
BOOL sort_class(Cstudent a, Cstudent b)
{
	int x = strcmp(a.Class, b.Class);
	return x < 0;
}
BOOL sort_math(Cstudent a, Cstudent b)
{
	float temp1, temp2;
	temp1 = atof(a.Math);
	temp2 = atof(b.Math);
	return temp1 < temp2;
}
BOOL sort_cpp(Cstudent a, Cstudent b)
{
	float temp1, temp2;
	temp1 = atof(a.CPP);
	temp2 = atof(b.CPP);
	return temp1 < temp2;
}
BOOL sort_english(Cstudent a, Cstudent b)
{
	float temp1, temp2;
	temp1 = atof(a.English);
	temp2 = atof(b.English);
	return temp1 < temp2;
}
void Cmune::sort_up(int x)
{
	for (int i = 0; i < m_list1.GetItemCount(); i++)
	{
		LPSTR str;
		CString SEX;
		int sex;
		USES_CONVERSION;
		str = T2A(m_list1.GetItemText(i, 0));//将CString 转换为LOSTR 再使用strcpy 将LOSTR的值赋给char
		strcpy_s(temp.num, str);
		SEX = m_list1.GetItemText(i, 1);
		if (SEX == "男")
			sex = 0;
		else
			sex = 1;
		temp.sex = sex;
		str = T2A(m_list1.GetItemText(i, 2));
		strcpy_s(temp.name, str);
		str = T2A(m_list1.GetItemText(i, 3));
		strcpy_s(temp.age, str);
		str = T2A(m_list1.GetItemText(i, 4));
		strcpy_s(temp.Class, str);
		str = T2A(m_list1.GetItemText(i, 5));
		strcpy_s(temp.Math, str);
		str = T2A(m_list1.GetItemText(i, 6));
		strcpy_s(temp.CPP, str);
		str = T2A(m_list1.GetItemText(i, 7));
		strcpy_s(temp.English, str);
		V0.push_back(temp);
	}
	if (x == 0)
	sort(V0.begin(), V0.end(), sort_num);
	if (x == 1)
		sort(V0.begin(), V0.end(), sort_sex);
	if (x == 2)
		sort(V0.begin(), V0.end(), sort_name);
	if (x == 3)
		sort(V0.begin(), V0.end(), sort_age);
	if (x == 4)
		sort(V0.begin(), V0.end(), sort_class);
	if (x == 5)
		sort(V0.begin(), V0.end(), sort_math);
	if (x == 6)
		sort(V0.begin(), V0.end(), sort_cpp);
	if (x == 7)
		sort(V0.begin(), V0.end(), sort_english); 
	m_list1.DeleteAllItems();
	for (int i = 0; i < V0.size(); i++)
	{

		CString sex;
		m_list1.InsertItem(i, (CString)V0[i].num);
		if (V0[i].sex == 0)
			sex = "男";
		else
			sex = "女";
		m_list1.SetItemText(i, 1, sex);
		m_list1.SetItemText(i, 2, (CString)V0[i].name);
		m_list1.SetItemText(i, 3, (CString)V0[i].age);
		m_list1.SetItemText(i, 4, (CString)V0[i].Class);
		m_list1.SetItemText(i, 5, (CString)V0[i].Math);
		m_list1.SetItemText(i, 6, (CString)V0[i].CPP);
		m_list1.SetItemText(i, 7, (CString)V0[i].English);
	}
	V0.clear();
};
BOOL sort_num1(Cstudent a, Cstudent b)
{
	float temp1, temp2;
	temp1 = atof(a.num);
	temp2 = atof(b.num);
	return temp1 > temp2;
}
BOOL sort_sex1(Cstudent a, Cstudent b)
{
	return a.sex > b.sex;
}
BOOL sort_name1(Cstudent a, Cstudent b)
{
	int x = strcmp(a.name, b.name);
	return x > 0;
}
BOOL sort_age1(Cstudent a, Cstudent b)
{
	float temp1, temp2;
	temp1 = atof(a.age);
	temp2 = atof(b.age);
	return temp1 > temp2;
}
BOOL sort_class1(Cstudent a, Cstudent b)
{
	int x = strcmp(a.Class, b.Class);
	return x > 0;
}
BOOL sort_math1(Cstudent a, Cstudent b)
{
	float temp1, temp2;
	temp1 = atof(a.Math);
	temp2 = atof(b.Math);
	return temp1 > temp2;
}
BOOL sort_cpp1(Cstudent a, Cstudent b)
{
	float temp1, temp2;
	temp1 = atof(a.CPP);
	temp2 = atof(b.CPP);
	return temp1 > temp2;
}
BOOL sort_english1(Cstudent a, Cstudent b)
{
	float temp1, temp2;
	temp1 = atof(a.English);
	temp2 = atof(b.English);
	return temp1 > temp2;
}
void Cmune::sort_down(int x)
{
	for (int i = 0; i < m_list1.GetItemCount(); i++)
	{
		LPSTR str;//
		CString SEX;
		int sex;
		USES_CONVERSION;
		str = T2A(m_list1.GetItemText(i, 0));//将CString 转换为LOSTR 再使用strcpy 将LOSTR的值赋给char
		strcpy_s(temp.num, str);
		SEX = m_list1.GetItemText(i, 1);
		if (SEX == "男")
			sex = 0;
		else
			sex = 1;
		temp.sex = sex;
		str = T2A(m_list1.GetItemText(i, 2));
		strcpy_s(temp.name, str);
		str = T2A(m_list1.GetItemText(i, 3));
		strcpy_s(temp.age, str);
		str = T2A(m_list1.GetItemText(i, 4));
		strcpy_s(temp.Class, str);
		str = T2A(m_list1.GetItemText(i, 5));
		strcpy_s(temp.Math, str);
		str = T2A(m_list1.GetItemText(i, 6));
		strcpy_s(temp.CPP, str);
		str = T2A(m_list1.GetItemText(i, 7));
		strcpy_s(temp.English, str);
		V0.push_back(temp);
	}
	if (x == 0)
		sort(V0.begin(), V0.end(), sort_num1);
	if (x == 1)
		sort(V0.begin(), V0.end(), sort_sex1);
	if (x == 2)
		sort(V0.begin(), V0.end(), sort_name1);
	if (x == 3)
		sort(V0.begin(), V0.end(), sort_age1);
	if (x == 4)
		sort(V0.begin(), V0.end(), sort_class1);
	if (x == 5)
		sort(V0.begin(), V0.end(), sort_math1);
	if (x == 6)
		sort(V0.begin(), V0.end(), sort_cpp1);
	if (x == 7)
		sort(V0.begin(), V0.end(), sort_english1);
	m_list1.DeleteAllItems();
	for (int i = 0; i < V0.size(); i++)
	{

		CString sex;
		m_list1.InsertItem(i, (CString)V0[i].num);
		if (V0[i].sex == 0)
			sex = "男";
		else
			sex = "女";
		m_list1.SetItemText(i, 1, sex);
		m_list1.SetItemText(i, 2, (CString)V0[i].name);
		m_list1.SetItemText(i, 3, (CString)V0[i].age);
		m_list1.SetItemText(i, 4, (CString)V0[i].Class);
		m_list1.SetItemText(i, 5, (CString)V0[i].Math);
		m_list1.SetItemText(i, 6, (CString)V0[i].CPP);
		m_list1.SetItemText(i, 7, (CString)V0[i].English);
	}
	V0.clear();
}
void Cmune::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void Cmune::OnLvnColumnclickList1(NMHDR* pNMHDR, LRESULT* pResult)//点击表头相应按钮
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码



	*pResult = 0;
}


void Cmune::OnCbnSelendokCombo1()
{
	CEdit* button2 = (CEdit*)GetDlgItem(IDC_BUTTON8);//获取句柄 以便后面ShowWindow or EnableWindow的使用
	button2->EnableWindow(true);
	// TODO: 在此添加控件通知处理程序代码
}


void Cmune::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
}
