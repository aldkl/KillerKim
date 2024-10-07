#pragma once
class CMonster : public CUnit
{
public:
	int m_nNum;
public:
	CMonster();
	~CMonster();
public:
	void Die();
};