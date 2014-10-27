#include "Block_NM1.h"


Block_NM1::Block_NM1(void) : AbstractBlock()
{
	KN.SetIsOn(false); 
	NKN.SetIsOn(false); 
	AKN.SetIsOn(false); 
	VP.SetIsOn(false); 
	VKM.SetIsOn(false); 
	MP.SetIsOn(false);

	butt = false;
	butV = false;
}

void Block_NM1::GetOutRelays(bool KM, bool S, bool N, bool Z, bool buttonLeft, bool buttonRight, bool buttonVar)
{
	OutKM.SetIsOn(KM); 
	OutS.SetIsOn(S); 
	OutN.SetIsOn(N);
	OutZ.SetIsOn(Z);
	butt = buttonLeft;
	butV = buttonVar;
}

Block_NM1::~Block_NM1(void)
{
}

block_ret_value Block_NM1::f1()
{
	block_ret_value ret;
	//левая половина
	ret.leftSideRet = BLOCK_RETURN_FAIL;
	if(KN.IsOn() || AKN.IsOn())
	{
		ret.leftSideRet = BLOCK_RETURN_MINUS;
	}
	else
	if(AKN.IsOn() && !NKN.IsOn() && !VP.IsOn() && butt)
	{
		ret.leftSideRet = BLOCK_RETURN_MINUS;
	}


	//правая половина
	ret.rightSideRet = BLOCK_RETURN_FAIL;
	if(KN.IsOn() || AKN.IsOn())
	{
	//	ret.rightSideRet = BLOCK_RETURN_MINUS;
	}
	//else
		//if(AKN.IsOn() && !NKN.IsOn() && !VP.IsOn() && butL)
		{
		//	ret.rightSideRet = BLOCK_RETURN_MINUS;
		}

	return ret;
}

block_ret_value Block_NM1::f2()
{
	block_ret_value ret;

	ret.leftSideRet = BLOCK_RETURN_FAIL;
	ret.rightSideRet = BLOCK_RETURN_FAIL;

	if (!KN.IsOn() && !NKN.IsOn() ||
		KN.IsOn() && NKN.IsOn() && AKN.IsOn())
	{
		ret.leftSideRet = BLOCK_RETURN_PASS;
		ret.rightSideRet = BLOCK_RETURN_PASS;
	}
	else
	{
		if (KN.IsOn() && !AKN.IsOn() && (VKM.IsOn() || VP.IsOn()))
		{
			ret.leftSideRet = BLOCK_RETURN_MINUS;
		}
		if (NKN.IsOn() && !AKN.IsOn() && (MP.IsOn() || VP.IsOn()))
		{
			ret.rightSideRet = BLOCK_RETURN_PLUS;
		}
	}

	return ret;
}

block_ret_value Block_NM1::f3()
{
	block_ret_value ret;

	if (VKM.IsOn() || VP.IsOn())
	{
		ret.leftSideRet = BLOCK_RETURN_MINUS;
	}
	if (MP.IsOn() || VP.IsOn())
	{
		ret.rightSideRet = BLOCK_RETURN_PLUS;
	}

	return ret;
}

block_ret_value Block_NM1::f4()
{
	block_ret_value ret;

	if (!VKM.IsOn() && !MP.IsOn())
	{
		ret.leftSideRet = BLOCK_RETURN_PASS;
		ret.rightSideRet = BLOCK_RETURN_PASS;
	}
	else
	{
		ret.leftSideRet = BLOCK_RETURN_FAIL;
		ret.rightSideRet = BLOCK_RETURN_FAIL;

		if (VKM.IsOn())
		{
			ret.leftSideRet = BLOCK_RETURN_MINUS;
		}
		if(MP.IsOn() && !NKN.IsOn() && OutZ.IsOn())
		{
			ret.rightSideRet = BLOCK_RETURN_PLUS;
		}
	}

	return ret;
}

void Block_NM1::g1(bool isGoodLeft, bool isGoodRight)
{
	if(isGoodLeft)
	{
		KN.SetIsOn(true);
	}
	else
	{
		KN.SetIsOn(false);
	}

	if(isGoodRight)
	{
		NKN.SetIsOn(true);
	}
	else
	{
		NKN.SetIsOn(false);
	}
}

void Block_NM1::g2(bool isGood)
{
	if(isGood)
	{
		AKN.SetIsOn(true);
	}
	else
	{
		AKN.SetIsOn(false);
	}
}

void Block_NM1::g3()
{
	//VOID
}

void Block_NM1::g4(bool isGood)
{

}
