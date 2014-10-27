#pragma once
class Polus
{
public:
	Polus(void);
	~Polus(void);


	static bool IsPolusPB (){return isPolusPB; }
	static bool IsPolusPK (){return isPolusPK; }
	static bool IsPolusPG (){return isPolusPG; }
	static bool IsPolusPN (){return isPolusPN; }
	static bool IsPolusMG (){return isPolusMG; }
	static bool IsPolusMI (){return isPolusMI; }
	static bool IsPolusP  (){return isPolusP;  }
	static bool IsPolusM  (){return true;  }
	static bool IsPolusPTD(){return isPolusPTD;}
	static bool IsPolusSH (){return isPolusSH; }


	static void SetPolusPB (bool b) {isPolusPB; }
	static void SetPolusPK (bool b) {isPolusPK; }
	static void SetPolusPG (bool b) {isPolusPG; }
	static void SetPolusPN (bool b) {isPolusPN; }
	static void SetPolusMG (bool b) {isPolusMG; }
	static void SetPolusMI (bool b) {isPolusMI; }
	static void SetPolusP  (bool b) {isPolusP;  }
	static void SetPolusM  (bool b) {isPolusM;  }
	static void SetPolusPTD(bool b) {isPolusPTD;}
	static void SetPolusSH (bool b) {isPolusSH; }

private:


	static bool isPolusPB; 
	static bool isPolusPK;
	static bool isPolusPG;
	static bool isPolusPN;
	static bool isPolusMG;
	static bool isPolusMI;
	static bool isPolusP;
	static bool isPolusM;
	static bool isPolusPTD;
	static bool isPolusSH;
};

