// Cdelete_warn.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "Cdelete_warn.h"


// Cdelete_warn 对话框

IMPLEMENT_DYNAMIC(Cdelete_warn, CDialogEx)

Cdelete_warn::Cdelete_warn(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Delete_warn, pParent)
{

}

Cdelete_warn::~Cdelete_warn()
{
}

void Cdelete_warn::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cdelete_warn, CDialogEx)
END_MESSAGE_MAP()


// Cdelete_warn 消息处理程序
