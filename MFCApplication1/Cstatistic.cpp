// Cstatistic.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "Cstatistic.h"
#include "resource.h"


// Cstatistic 对话框

IMPLEMENT_DYNAMIC(Cstatistic, CDialogEx)

Cstatistic::Cstatistic(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_statistic, pParent)
{

}

Cstatistic::~Cstatistic()
{
}

void Cstatistic::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDCANCEL, m_picture);
}


BEGIN_MESSAGE_MAP(Cstatistic, CDialogEx)
END_MESSAGE_MAP()


// Cstatistic 消息处理程序
