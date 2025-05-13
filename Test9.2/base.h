#ifndef DATE_H
#define DATE_H

class Base
{
protected:
    std::string name;
public:
    Base(const std::string& n) : name(n) {};
    virtual ~Base() = default;
};

class Derived : public Base
{
public:
    using Base::name;
    Derived(const std::string& n) : Base(n) {};
};

class Center {
public:
    Center() = default;
    Base* base;
    void calc() const
    {
        std::cout << dynamic_cast<Derived*>(base)->name;
    }
};

#endif //DATE_H
