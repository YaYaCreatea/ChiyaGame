#ifndef _INPUT_STATE_H_
#define _INPUT_STATE_H_

class InputState
{
public:
	InputState();
	~InputState();

	void initialize(int l_inputType);

	void update();

	bool Stay(int button)const;

	bool Trigger(int button)const;

	bool Release(int button)const;

	void Vibration(int l_power, int l_time);

	int Get_Type()const;

private:
	int m_inputType;
	int m_currentState;
	int m_previousState;
};

#endif