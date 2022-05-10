#include "Base.h"

Base::Base()
{
}

Base::~Base()
{
}

void Base::AddChild(Base* base)
{
    children.push_back(base);
}

void Base::ShowChildren()
{
    std::list<Base*>::iterator iter;
    

    for (iter = children.begin(); iter != children.end(); ++iter) {
        Base* child = *iter;
        child->Log();
    }
}
