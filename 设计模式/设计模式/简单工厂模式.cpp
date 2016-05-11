#include <iostream>
#include <exception>  

using namespace std;

/*����*/
class Operation
{
public:
	int _numA;
	int _numB;
public:
	virtual  double GetResult()
	{
		return 0;
	}
};

/*��*/
class OperationAdd: public Operation
{
public:
	virtual double GetResult()
	{
		return _numA + _numB;
	}
};

/*��*/
class OperationSub: public Operation
{
public:
	virtual double GetResult()
	{
		return _numA - _numB;
	}
};

/*��*/
class OperationMul: public Operation
{
public:
	virtual double GetResult()
	{
		return _numA * _numB;
	}
};

/*��*/
class OperationDiv: public Operation
{
public:
	virtual double GetResult()
	{
		return _numA / _numB;
	}
};

/*����*/
class OperationFactory
{
public:
	static Operation* CreateOperation(char operate)
	{
		Operation *oper = NULL;
		switch(operate)
		{
		case  '+':
			oper = new OperationAdd();
			break;
		case '-':
			oper = new OperationSub();
			break;
		case '*':
			oper = new OperationMul();
			break;
		case '/':
			oper = new OperationDiv();
			break;
		default :
			break;
		}
		return oper;
	}
};


int main(void)
{
	Operation *oper = NULL;
	int numA = 0;
	int numB = 0;
	char operate ='0';

	cout<< "��������A�� ";
	cin >> numA;

	cout<< "�������������";
	cin >> operate;

	cout<< "��������B�� ";
	cin >> numB;

	oper = OperationFactory::CreateOperation(operate);

	try
	{
		oper->_numA = numA;
		oper->_numB = numB;

		cout << numA << operate << numB << "=" << oper->GetResult() << endl;

	}
	catch (exception& e)
	{
		cout << "�����쳣" << e.what() <<endl;
	}

	system("PAUSE");
	return 0;
}