#include <iostream>
#include <string>

using namespace std;

/************************************************************************/
/* װ��ģʽ��                                                                     */
/************************************************************************/

/*����*/
class Person
{
public:
	Person(){}
	Person(string name)
	{
		this->_name = name;
	}
private:
	string _name;
public:
	virtual void Show()			/*��ʾװ��*/
	{
		cout<< " װ���" << _name <<endl;
	}
};

/*������*/
class Finery: public Person
{
protected:
	Person *_component;
public:
	void Decorate(Person *component)
	{
		this->_component = component;
	}
	virtual void Show()
	{
		if (_component != NULL)
		{
			_component->Show();
		}
	}
};

/*���������*/
class TShirts: public Finery
{
public:
	virtual void Show()
	{
		cout<< " ����T�� ";
		Finery::Show();
	}
};

class BigTrouser: public Finery
{
	virtual void Show()
	{
		cout<< " ��� ";
		Finery::Show();
	}
};

class Shoes: public Finery
{
	virtual void Show()
	{
		cout<< " ����Ь ";
		Finery::Show();
	}
};

class Shuit: public Finery
{
	virtual void Show()
	{
		cout<< " ��װ ";
		Finery::Show();
	}
};

class Tie: public Finery
{
	virtual void Show()
	{
		cout<< " ��� ";
		Finery::Show();
	}
};



int main(void)
{
	Person *kong = new Person("kong");

	cout<< "\n��һ��װ��: " << endl;

	Tie		   *tie		  = new Tie();
	BigTrouser *bigtrouser = new BigTrouser();
	TShirts	   *tshirt     = new TShirts();

	tie->Decorate(kong);
	bigtrouser->Decorate(tie);
	tshirt->Decorate(bigtrouser);

	tshirt->Show();

	delete tie;
	delete bigtrouser;
	delete tshirt;
	delete kong;

	system("PAUSE");

	return 0;
}