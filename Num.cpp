#include "stdafx.h"

CNum::CNum()
{
}
CNum::~CNum()
{

}

void CNum::Update(float dt, int i,int j,int k, int l,int q)
{
	//m_pNum->SetPos()
	m_pNum->SetNumber(i);
	m_pSNum->SetNumber(j);
	m_pENum->SetNumber(k);
	m_pCNum->SetNumber(l);
	m_pRNum->SetNumber(q);
}
void CNum::Enable(stEMVec3 Vec)
{

}
void CNum::Disable()
{

}
void CNum::CreateObj(CRootScene* pScene)
{
	//m_pAnimation = NULL;	
	m_pNum = new CEMNumber(10);
	m_pNum->SetTexture(pScene, 10,
		"Data/Image/UI/0.png",
		"Data/Image/UI/1.png",
		"Data/Image/UI/2.png",
		"Data/Image/UI/3.png",
		"Data/Image/UI/4.png",
		"Data/Image/UI/5.png",
		"Data/Image/UI/6.png",
		"Data/Image/UI/7.png",
		"Data/Image/UI/8.png",
		"Data/Image/UI/9.png",
		GL_REPEAT, GL_NEAREST);
	m_pNum->SetOrtho2D(true);
	m_pNum->SetPos(1190.0f, 110, 0.0f);
	m_pNum->SetStyle(E_NUMSTYLE_OFFSET_RIGHT);
	m_pNum->SetSize(1.0f, 1.0f);
	m_pNum->SetBlend(TRUE);
	m_pNum->SetBoundingBoxCalc(false);
	m_pNum->SetFrstumCullingFlag(FALSE);

	m_pCNum = new CEMNumber(10);
	m_pCNum->SetTexture(pScene, 10,
		"Data/Image/UI/0.png",
		"Data/Image/UI/1.png",
		"Data/Image/UI/2.png",
		"Data/Image/UI/3.png",
		"Data/Image/UI/4.png",
		"Data/Image/UI/5.png",
		"Data/Image/UI/6.png",
		"Data/Image/UI/7.png",
		"Data/Image/UI/8.png",
		"Data/Image/UI/9.png",
		GL_REPEAT, GL_NEAREST);
	m_pCNum->SetOrtho2D(true);
	m_pCNum->SetPos(130.0f, 100, 0.0f);
	m_pCNum->SetSize(1.0f, 1.0f);
	m_pCNum->SetBlend(TRUE);
	m_pCNum->SetBoundingBoxCalc(false);
	m_pCNum->SetFrstumCullingFlag(FALSE);

	m_pENum = new CEMNumber(10);
	m_pENum->SetTexture(pScene, 10,
		"Data/Image/UI/0.png",
		"Data/Image/UI/1.png",
		"Data/Image/UI/2.png",
		"Data/Image/UI/3.png",
		"Data/Image/UI/4.png",
		"Data/Image/UI/5.png",
		"Data/Image/UI/6.png",
		"Data/Image/UI/7.png",
		"Data/Image/UI/8.png",	
		"Data/Image/UI/9.png",
		GL_REPEAT, GL_NEAREST);
	m_pENum->SetOrtho2D(true);
	m_pENum->SetPos(1190.0f, 50.0f, 0.0f);
	m_pENum->SetSize(1.0f, 1.0f);
	m_pENum->SetStyle(E_NUMSTYLE_OFFSET_RIGHT);
	m_pENum->SetBlend(TRUE);
	m_pENum->SetBoundingBoxCalc(false);
	m_pENum->SetFrstumCullingFlag(FALSE);

	m_pSNum = new CEMNumber(10);
	m_pSNum->SetTexture(pScene, 10,
		"Data/Image/UI/스테이지 0.png",
		"Data/Image/UI/스테이지 1.png",
		"Data/Image/UI/스테이지 2.png",
		"Data/Image/UI/스테이지 3.png",
		"Data/Image/UI/스테이지 4.png",
		"Data/Image/UI/스테이지 5.png",
		"Data/Image/UI/스테이지 6.png",
		"Data/Image/UI/스테이지 7.png",
		"Data/Image/UI/스테이지 8.png",
		"Data/Image/UI/스테이지 9.png",
		GL_REPEAT, GL_NEAREST);
	m_pSNum->SetOrtho2D(true);
	m_pSNum->SetPos(590.0f, 60, 0.0f);
	m_pSNum->SetSize(1.0f, 1.0f);
	m_pSNum->SetBlend(TRUE);
	m_pSNum->SetBoundingBoxCalc(false);
	m_pSNum->SetFrstumCullingFlag(FALSE);

	m_pRNum = new CEMNumber(10);
	m_pRNum->SetTexture(pScene, 10,
		"Data/Image/UI/스테이지 0.png",
		"Data/Image/UI/스테이지 1.png",
		"Data/Image/UI/스테이지 2.png",
		"Data/Image/UI/스테이지 3.png",
		"Data/Image/UI/스테이지 4.png",
		"Data/Image/UI/스테이지 5.png",
		"Data/Image/UI/스테이지 6.png",
		"Data/Image/UI/스테이지 7.png",
		"Data/Image/UI/스테이지 8.png",
		"Data/Image/UI/스테이지 9.png",
		GL_REPEAT, GL_NEAREST);
	m_pRNum->SetOrtho2D(true);
	m_pRNum->SetPos(650.0f, 60, 0.0f);
	m_pRNum->SetSize(1.0f, 1.0f);
	m_pRNum->SetBlend(TRUE);
	m_pRNum->SetBoundingBoxCalc(false);
	m_pRNum->SetFrstumCullingFlag(FALSE);

	pScene->Commit(-1, "SNum", m_pSNum);
	pScene->Commit(-1, "CNum", m_pCNum);
	pScene->Commit(-1, "ENum", m_pENum);
	pScene->Commit(-1, "RNum", m_pRNum);
	pScene->Commit(-1, "Num", m_pNum);
}