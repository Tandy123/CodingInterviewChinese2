#include <iostream>
#include <memory>
using namespace std;
//single thread
class Singleton1
{
public:
	static Singleton1  *Instance() 
	{
		if (instance == NULL)
		{
			instance = new Singleton1();
		}
		return instance;
	}

private:
	Singleton1(void) 
	{
		cout << "Create a Singleton1.\n" << endl;
	}
	virtual ~Singleton1() 
	{
		cout << "Destroy a Singleton1.\n" << endl;
	}
	static Singleton1 *instance;
};
Singleton1* Singleton1::instance = NULL;

//智能指针
class Singleton2
{
public:
	static Singleton2  *Instance()
	{
		if (instance.get() == 0)
		{
			instance.reset(new Singleton2);
		}
		return instance.get();
	}

private:
	Singleton2(void)
	{
		cout << "Create a Singleton2.\n" << endl;
	}
	virtual ~Singleton2() 
	{
		cout << "Destroy a Singleton2.\n" << endl;
	}
	friend class auto_ptr<Singleton2>;
	//这里声明class auto_ptr<Singleton>为类Singleton的友元类就是为了在class auto_ptr<Singleton>类里能调用类Singleton的保护类型的析构函数
	static auto_ptr<Singleton2> instance;
};
auto_ptr<Singleton2> Singleton2::instance;

int main() {
	Singleton1 *singleton1_1 = Singleton1::Instance();
	Singleton1 *singleton1_2 = Singleton1::Instance();

	Singleton2 *singleton2_1 = Singleton2::Instance();
	Singleton2 *singleton2_2 = Singleton2::Instance();
	return 0;
}