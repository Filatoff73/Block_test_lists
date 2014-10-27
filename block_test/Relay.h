#pragma once
class Relay
{
public:
	Relay(void);
	~Relay(void);
	void SetIsOn(bool b)
	{
		//—юда же потом задержки впишутс€
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

