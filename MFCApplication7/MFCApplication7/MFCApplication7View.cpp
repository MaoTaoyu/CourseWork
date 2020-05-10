
// MFCApplication7View.cpp : CMFCApplication7View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication7.h"
#endif

#include "MFCApplication7Doc.h"
#include "MFCApplication7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication7View

IMPLEMENT_DYNCREATE(CMFCApplication7View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication7View, CView)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication7View 构造/析构

CMFCApplication7View::CMFCApplication7View()
{
	// TODO: 在此处添加构造代码

}

CMFCApplication7View::~CMFCApplication7View()
{
}

BOOL CMFCApplication7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication7View 绘制

void CMFCApplication7View::OnDraw(CDC* /*pDC*/)
{
	CMFCApplication7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CMFCApplication7View 诊断

#ifdef _DEBUG
void CMFCApplication7View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication7Doc* CMFCApplication7View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication7Doc)));
	return (CMFCApplication7Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication7View 消息处理程序


void CMFCApplication7View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMFCApplication7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	pDoc->count++;
	CView::OnLButtonDown(nFlags, point);
}


void CMFCApplication7View::OnRButtonDown(UINT nFlags, CPoint point)
{
	CMFCApplication7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	pDoc->s.Format(_T("%d"), pDoc->count);
	dc.TextOut(200, 200, pDoc->s);
	CView::OnRButtonDown(nFlags, point);
}
