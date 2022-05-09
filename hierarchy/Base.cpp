#include "Base.h"

Base::Base()
{
}

Base::~Base()
{
}

void Base::AddChild(Base base)
{
    children.push_back(base);
}

void Base::ShowChild()
{
    std::list<Base> child;
    for (auto child = children.begin(); child != children.end(); ++child) {
        child->Log();
    }
}
