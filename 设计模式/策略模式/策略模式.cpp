#include <iostream>
#include <exception>  
#include <stdlib.h>

using namespace std;

/*�����㷨��*/
class Strategy
{
public:
	virtual void AlgorithmInterface() = 0;
};

class ConcreteStrategyA: public Strategy
{
public:
	virtual void AlgorithmInterface()
	{
		cout<< "�㷨A��ʵ��" <<endl;
	}
};

class ConcreteStrategyB: public Strategy
{
public:
	virtual void AlgorithmInterface()
	{
		cout<< "�㷨B��ʵ��" <<endl;
	}
};

class ConcreteStrategyC: public Strategy
{
public:
	virtual void AlgorithmInterface()
	{
		cout<< "�㷨C��ʵ��" <<endl;
	}
};

/*������*/
class Context
{
public:
	Context(Strategy *strategy)       /*��ʼ��ʱ�������Ľӿ�*/
	{
		this->_strategy = strategy;
	}
public:
	void ContexInterface()			/*���ݾ���Ķ���������㷨����*/
	{
		this->_strategy->AlgorithmInterface();
	}
private:
	Strategy *_strategy;
};


/*
int main(void)
{
	Context context(new ConcreteStrategyA());
	context.ContexInterface();

	Context context2(new ConcreteStrategyB());
	context2.ContexInterface();

	Context context3(new ConcreteStrategyC());
	context3.ContexInterface();

	system("PAUSE");
	return 0;
}
*/