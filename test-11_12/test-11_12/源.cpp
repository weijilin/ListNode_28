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


// class默认继承权限---private
// struct默认继承权限---public
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

// 赋值兼容规则---public

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
public继承方式: 基类中成员在派生类中访问权限不会发生改变
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

// 如果是public的继承方式，子类与基类的关系： is-a
// is-a: 可以将子类对象看成是一个基类对象
//      函数调用(在类外)：在类外所有用到基类对象的位置，都可以使用派生类对象代替
//      对象模型：对象中各个成员变量在内存中的布局方式


// 1. 可以将子类对象直接赋值给基类对象
// 2. 可以让基类的指针或者引用直接指向子类的对象
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
