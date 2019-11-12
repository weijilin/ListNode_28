#define _CRT_SECURE_NO_WARNINGS 1
#if 0
class Base
{
public:
	void SetBase(int pub, int pro, int pri)
	{
		_pub = pub;
		_pro = pro;
		_pri = pri;
	}

	void PrintBase()
	{
		cout << _pub << " " << _pro << " " << _pri << endl;
	}

public:
	int _pub;
protected:
	int _pro;
private:
	int _pri;
};


// classĬ�ϼ̳�Ȩ��---private
// structĬ�ϼ̳�Ȩ��---public
struct Derived : Base
{
public:
	void SetDerived(int pubD, int proD, int priD)
	{
		_pub = pubD;
		_pro = proD;

		//_pri = priD;
	}
};

class D : public Derived
{
public:
	void TestFunc()
	{
		_pub = 10;
		_pro = 20;
	}
};

int main()
{
	Derived d;
	d._pub = 10;
	return 0;
}
#endif

// ��ֵ���ݹ���---public

class Base
{
public:
	void SetBase(int b)
	{
		_b = b;
	}

	void PrintBase()
	{
		cout << _b << endl;
	}

protected:
	int _b;
};


/*
public�̳з�ʽ: �����г�Ա���������з���Ȩ�޲��ᷢ���ı�
*/
struct Derived : public Base
{
public:
	void SetDerived(int b, int d)
	{
		_b = b;
		_d = d;
	}


	int _d;
};

// �����public�ļ̳з�ʽ�����������Ĺ�ϵ�� is-a
// is-a: ���Խ�������󿴳���һ���������
//      ��������(������)�������������õ���������λ�ã�������ʹ��������������
//      ����ģ�ͣ������и�����Ա�������ڴ��еĲ��ַ�ʽ


// 1. ���Խ��������ֱ�Ӹ�ֵ���������
// 2. �����û����ָ���������ֱ��ָ������Ķ���
int main()
{
	Base b;
	b.SetBase(10);

	Derived d;
	d.SetDerived(20, 30);

	/*b.SetBase(40);
	b.PrintBase();*/

	d.SetBase(40);
	d.PrintBase();

	b = d;

	//d = b;

	Base* pb = &b;
	pb = &d;

	Base& rb = d;

	Derived* pd = &d;
	pd = (Derived*)&b;
	pd->_d = 30;
	return 0;
}
