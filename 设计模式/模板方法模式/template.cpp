#include <iostream>

using namespace std;


class AbstractClass
{
public:
	virtual void PrimitiOperation1() = 0;
	virtual void PrimitiOperation2() = 0;
public:
	void TemplateMethod() 
	{
		PrimitiOperation1();
		PrimitiOperation2();
		cout << " " << endl;
	}
};


class ConcreteClassA :  public AbstractClass
{
public:
	void PrimitiOperation1()
	{
		cout << "������A ����1ʵ��" << endl;
	}
	void PrimitiOperation2()
	{
		cout << "������A ����2ʵ��" << endl;
	}

};

class ConcreteClassB :  public AbstractClass
{
public:
	void PrimitiOperation1()
	{
		cout << "������B ����1ʵ��" << endl;
	}
	void PrimitiOperation2()
	{
		cout << "������B ����2ʵ��" << endl;
	}

};


int main(void)
{
	AbstractClass *p1;
	p1 = new ConcreteClassA();
	p1->TemplateMethod();

	delete p1;
	p1 = new ConcreteClassB();
	p1->TemplateMethod();

	system("PAUSE");
	return 0;
}