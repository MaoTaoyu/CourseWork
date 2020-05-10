
// MFCApplication4View.cpp : CMFCApplication4View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "MFCApplication4.h"
#endif

#include "MFCApplication4Doc.h"
#include "MFCApplication4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication4View

IMPLEMENT_DYNCREATE(CMFCApplication4View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication4View, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCApplication4View ����/����

CMFCApplication4View::CMFCApplication4View()
{
	// TODO: �ڴ˴���ӹ������
	count = 0;
}

CMFCApplication4View::~CMFCApplication4View()
{
}

BOOL CMFCApplication4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMFCApplication4View ����

void CMFCApplication4View::OnDraw(CDC* pDC)
{
	CMFCApplication4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	for (int i = 0; i < count ; i++ ) {
		pDC->Ellipse(p[i].x - rac[i], p[i].y - rac[i], p[i].x + rac[i], p[i].y + rac[i]);
	}
}


// CMFCApplication4View ���

#ifdef _DEBUG
void CMFCApplication4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication4Doc* CMFCApplication4View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication4Doc)));
	return (CMFCApplication4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication4View ��Ϣ�������


void CMFCApplication4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int a = 3;
	int b = 10;
	CClientDC dc(this);
	int r = (rand() % (b - a) + a)*3;
	dc.Ellipse(point.x - r,point.y - r,point.x + r,point.y + r);
	rac[count] = r;
	p[count].SetPoint(point.x, point.y);
	count++;
	CView::OnLButtonDown(nFlags, point);
}
