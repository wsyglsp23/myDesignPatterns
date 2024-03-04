#include<iostream>
/*
    个人理解:利用了虚函数和多态，每个对象都有对应的生产工厂，降低了耦合

*/
typedef enum
{
    product1,
    product2
}ProductType;

class Product
{
public:
    virtual std::string getType() = 0;
};


class Product1:public Product
{

public:
    std::string getType()
    {
        std::cout << "type:1" << std::endl;
        std::string type = "type1";
        return type;
    }
};


class Product2:public Product
{

public:
    std::string getType()
    {
        std::cout << "type:2" << std::endl;
        std::string type = "type2";
        return type;
    }
};


class FactoryProductor
{
public:
    virtual Product* createProduct() = 0;
};

class Factorproduct1:public FactoryProductor
{

    Product * createProduct()
    {
        return new Product1;
    }
};


class Factorproduct2:public FactoryProductor
{

    Product * createProduct()
    {
        return new Product2;
    }
};


int main()
{

    FactoryProductor* fp1 = new Factorproduct1();
    Product * p1 = fp1->createProduct();
    p1->getType();

    FactoryProductor* fp2 = new Factorproduct2();
    Product * p2 = fp2->createProduct();
    p2->getType();
    return 0;
}