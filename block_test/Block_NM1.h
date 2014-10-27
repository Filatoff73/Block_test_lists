#ifndef KEA_BLOCK_NM1
#define KEA_BLOCK_NM1

//////////////////////////////////////////////////////////////////////////
// ���� ��1 - ��������� ���������� �������� � ������
// 6 ����: ��, ���, ���, ��, ���, ��
// ������� ����: ��, � - � �������������� �����, �, ������ ��������� � ���������� ������.
//////////////////////////////////////////////////////////////////////////

#include "AbstractBlock.h"

class Block_NM1 : public AbstractBlock
{
public:
	Block_NM1(void);
	~Block_NM1(void);

	//���������� ������� ����
	void GetOutRelays(bool KM, bool S, bool N, bool Z, bool buttonLeft, bool buttonRight, bool buttonVar);

	//������ ������
	block_ret_value f1();
	block_ret_value f2();
	block_ret_value f3();
	block_ret_value f4();

	//������ ���������� ����
	void g1(bool isGoodLeft, bool isGoodRight);
	void g2(bool isGood);
	void g3();
	void g4(bool isGood);

	//������ ��� �����
	//block_ret_value f__();

	void setKN(bool b)
	{
		KN.SetIsOn(b);
	}
	bool IsKN()
	{
		return KN.IsOn();
	}

	void setNKN(bool b)
	{
		NKN.SetIsOn(b);
	}
	bool IsNKN()
	{
		return NKN.IsOn();
	}

	void setAKN(bool b)
	{
		AKN.SetIsOn(b);
	}
	bool IsAKN()
	{
		return AKN.IsOn();
	}

	void setVP(bool b)
	{
		VP.SetIsOn(b);
	}
	bool IsVP()
	{
		return VP.IsOn();
	}

	void setVKM(bool b)
	{
		VKM.SetIsOn(b);
	}
	bool IsVKM()
	{
		return VKM.IsOn();
	}

	void setMP(bool b)
	{
		MP.SetIsOn(b);
	}
	bool IsMP()
	{
		return MP.IsOn();
	}

	void setOutKM(bool b)
	{
		OutKM.SetIsOn(b);
	}
	bool IsOutKM()
	{
		return OutKM.IsOn();
	}

	void setOutS(bool b)
	{
		OutS.SetIsOn(b);
	}
	bool IsOutS()
	{
		return OutS.IsOn();
	}

	void setOutN(bool b)
	{
		OutN.SetIsOn(b);
	}
	bool IsOutN()
	{
		return OutN.IsOn();
	}

	void setOutZ(bool b)
	{
		OutZ.SetIsOn(b);
	}
	bool IsOutZ()
	{
		return OutZ.IsOn();
	}
private:
	Relay KN, NKN, AKN, VP, VKM, MP;
	Relay OutKM, OutS, OutN, OutZ;

	//������
	bool butt;
	bool butV;
};

#endif

