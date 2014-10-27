#ifndef KEA_CONSTANTS
#define KEA_CONSTANTS


enum BLOCK_RETURN
{
	BLOCK_RETURN_NONE = 16,
	BLOCK_RETURN_MINUS = 8,
	BLOCK_RETURN_PLUS = 4,
	BLOCK_RETURN_PASS = 2,
	BLOCK_RETURN_FAIL = 1
};



struct block_ret_value
{
	BLOCK_RETURN leftSideRet; //справа у блока
	BLOCK_RETURN rightSideRet; //слева у блока
	block_ret_value()
	{
		leftSideRet = BLOCK_RETURN_NONE;
		rightSideRet = BLOCK_RETURN_NONE;
	}
};

#endif