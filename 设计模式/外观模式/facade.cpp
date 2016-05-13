#include <iostream>

using namespace std;


class SubSystenmOne
{
public:
	void MethodOne()
	{
		cout << "��ϵͳ����һ" << endl;
	}
};

class SubSystemTwo
{
public:
	void MethodTwo()
	{
		cout << "��ϵͳ������" << endl;
	}
};

class SubSystemThree
{
public:
	void MethodThree()
	{
		cout << "��ϵͳ������" << endl;
	}
};

class SubSystemFour
{
public:
	void MethodFour()
	{
		cout << "��ϵͳ������" << endl;
	}
};

class Facade
{
private:
	SubSystenmOne	*one;
	SubSystemTwo	*two;
	SubSystemThree  *three;
	SubSystemFour	*four;

public:

	Facade()
	{
		one		= new SubSystenmOne();
		two		= new SubSystemTwo();
		three	= new SubSystemThree();
		four	= new SubSystemFour();
	}
	~Facade()
	{
		delete one;
		delete two;
		delete three;
		delete four;
	}

public:
	void MethodA()
	{
		cout << "������A��" << endl;
		one->MethodOne();
		two->MethodTwo();
		three->MethodThree();

	}
	void MethodB()
	{
		cout << "������B��" << endl;
		four->MethodFour();
		two->MethodTwo();
	}

};

int main(void)
{
	Facade *facade = new Facade();

	facade->MethodA();
	facade->MethodB();

	system("PAUSE");
	return 0;
}