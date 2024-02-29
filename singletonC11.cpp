/*
    c++11之后保证了static局部变量是线程安全你的
*/

#include <iostream>

class Singleton
{
public:
	// 注意返回的是引用
	static Singleton& getInstance()
	{
		static Singleton value;  //静态局部变量
		return value;
	}

private:
	Singleton() = default;
	Singleton(const Singleton& other) = delete; //禁止使用拷贝构造函数
	Singleton& operator=(const Singleton&) = delete; //禁止使用拷贝赋值运算符
};

int main()
{
	Singleton& s1 = Singleton::getInstance();
	std::cout << &s1 << std::endl;

	Singleton& s2 = Singleton::getInstance();
	std::cout << &s2 << std::endl;

    //auto s3 = s2;
    //auto s4 = Singleton();
    //auto s5 = Singleton(s2);
	return 0;
}


