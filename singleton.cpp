#include <iostream>
#define EHAN   1

#if EHAN
/*饿汉式：线程安全，注意一定要在合适的地方去delete它
饿汉模式是线程安全的。 这是因为饿汉模式在类加载时就将实例初始化，]
并且永远只有一个实例。 由于实例在类加载时就创建，所以不存在多线程竞争的情况，因此饿汉模式是线程安全的。
*/
class Singleton
{
public:
    static Singleton* getInstance();
private:
    Singleton(){}                                    //构造函数私有
    Singleton(const Singleton&) = delete;            //明确拒绝
    Singleton& operator=(const Singleton&) = delete; //明确拒绝

    static Singleton* m_pSingleton;
};

Singleton* Singleton::m_pSingleton = new Singleton();

Singleton* Singleton::getInstance()
{
    return m_pSingleton;
}
#else
/*
    懒汉在获取实例的时候才会去new出对象
*/
#include <mutex>
std::mutex mt;

class Singleton
{
public:
    static Singleton* getInstance();
private:
    Singleton(){}                                    //构造函数私有
    Singleton(const Singleton&) = delete;            //明确拒绝
    Singleton& operator=(const Singleton&) = delete; //明确拒绝

    static Singleton* m_pSingleton;

};
Singleton* Singleton::m_pSingleton = NULL;

Singleton* Singleton::getInstance()
{
    if(m_pSingleton == NULL)
    {
        
        mt.lock();
        if(m_pSingleton == NULL)
        {
            m_pSingleton = new Singleton();
        }
        mt.unlock();
    }
    return m_pSingleton;
}


#endif


int main()
{
    auto singlev = Singleton::getInstance();
    //auto singlev2 = *singlev; 赋值的操作是delete掉的
    
    return 0;
}