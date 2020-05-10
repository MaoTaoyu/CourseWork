
// MFCApplication5View.cpp : CMFCApplication5View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication5.h"
#endif

#include "MFCApplication5Doc.h"
#include "MFCApplication5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication5View

IMPLEMENT_DYNCREATE(CMFCApplication5View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication5View, CView)
END_MESSAGE_MAP()

// CMFCApplication5View 构造/析构

CMFCApplication5View::CMFCApplication5View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication5View::~CMFCApplication5View()
{
}

BOOL CMFCApplication5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication5View 绘制

void CMFCApplication5View::OnDraw(CDC* pDC)
{
	CMFCApplication5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int red = 0, green = 0, blue = 0;
	int color = RGB(red, green, blue);
	CBrush newBrush(color);
	CBrush*oldBrush = pDC->SelectObject(&newBrush);
	int rac1, rac2;
	CRect rc;
	GetClientRect(&rc);
	rac1 = (rc.left + rc.right) / 2;
	rac2 = (rc.top + rc.bottom) / 2;
	pDC->Ellipse(rac1 - rac1, rac2 - rac2, rac1 + rac1, rac2 + rac2);
	pDC->SelectObject(oldBrush);
}


// CMFCApplication5View 诊断

#ifdef _DEBUG
void CMFCApplication5View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication5Doc* CMFCApplication5View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication5Doc)));
	return (CMFCApplication5Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication5View 消息处理程序
