#include "stdafx.h"

CMonster::CMonster()
{
	m_fSpeed = 50;
	m_nNum = 4;
}
CMonster::~CMonster()
{

}

void CMonster::Die()
{
	m_nNum = 5;
}