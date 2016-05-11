#include <iostream>
#include <exception>  
#include <stdlib.h>

using namespace std;

/************************************************************************/
/*  ��ԭ�������㷨�Ļ����ϣ�����㷨���ǩ�������ڱ����ڹ����ʱ��¶
/*  �㷨����                                                            */
/************************************************************************/

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
enum AI {CSA, CSB, CSC}; /*��ǩ*/
class Context
{
public:
	Context(enum AI ai)       /*��ʼ��ʱ����ѡ��*/
	{
		switch (ai)
		{
		case CSA:
			this->_strategy = new ConcreteStrategyA();
			break;
		case CSB:
			this->_strategy = new ConcreteStrategyB();
			break;
		case CSC:
			this->_strategy = new ConcreteStrategyC();
			break;
		default:
			this->_strategy = NULL;
			break;
		}
	}
	~Context()
	{
		if (!_strategy)
		{
			delete _strategy;
			_strategy = NULL;
		}
	}
public:
	void ContexInterface()			/*���ݾ���Ķ���������㷨����*/
	{
		this->_strategy->AlgorithmInterface();
	}
private:
	Strategy *_strategy;
};



int main(void)
{
	/*
	Context context(CSA);
	context.ContexInterface();

	Context context2(CSB);
	context2.ContexInterface();

	Context context3(CSC);
	context3.ContexInterface();
	*/

	Context *context = NULL;
	context = new Context(CSA);
	context->ContexInterface();

	context = new Context(CSB);
	context->ContexInterface();

	context = new Context(CSC);
	context->ContexInterface();


	system("PAUSE");
	return 0;
}
