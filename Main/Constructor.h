#ifndef _CONSTRUCTOR_H
#define _CONSTRUCTOR_H

#include <iostream>
#define LOG(txt) std::cout << __func__ << ": " << txt << '\n';

class Foo
{
public:
    ///@brief Default Constructor
    Foo()
    {
        LOG("Default Constructor") return;
    }
    ///@brief Copy Constructor
    Foo(const Foo&)
    { 
        LOG("Copy Constructor") return;
    }
    ///@brief
    Foo(const Foo&&) noexcept
    {
        LOG("Move Constructor") return;
    }
    ///@brief
    Foo& operator=(const Foo&)
    {
        LOG("Assign Operator") return *this;
    }
public:
    ///@brief Custom Constructor
    Foo(int foo_int, float foo_float):
        foo_int(foo_int),
        foo_float(foo_float)
    {
        LOG("Custom Constructor") return;
    }
public:
    ///@brief Destructor
    ~Foo()
    {
        LOG("Destructor") return;
    }
public:
    void print() const
    {
        std::cout << "- foo_int: " << this->foo_int << '\n';
        std::cout << "- foo_double: " << this->foo_float << '\n';
        return;
    }
private:
    int foo_int = 0;
    float foo_float = 0.f;
};

#endif // !_CONSTRUCTOR_H
