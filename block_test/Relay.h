#pragma once
class Relay
{
public:
	Relay(void);
	~Relay(void);
	void SetIsOn(bool b)
	{
		//���� �� ����� �������� ��������
		isOn = b;
	}
	bool IsOn()
	{
		return isOn;
	}
private:
	bool isOn;
	int onDelay;
	int offDelay;
};

