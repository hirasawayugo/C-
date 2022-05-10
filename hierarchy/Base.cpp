#include "Base.h"
#include "Matrix33.h"
#include "Calculator.h"

Base::Base()
{
    lAngle = 0;
    gAngle = 0;
    parent = nullptr;
}

Base::~Base()
{
}

void Base::AddChild(Base* base)
{
    children.push_back(base);
    base->parent = this;
}

void Base::ShowChildren()
{
    std::list<Base*>::iterator iter;
    for (iter = children.begin(); iter != children.end(); ++iter) {
        Base* child = *iter;
        child->Log();
    }
}

void Base::Foward( const Vector2D& vec)
{
    lPos.Add(vec);
    Matrix33 mat;
    mat.Rotate(GetAngle());
    gPos = mat * lPos;
    if (parent != nullptr) {
        gPos.Add(parent->GetPos());
    }
}

void Base::Rotate(const double& radian)
{
    //ローカルの角度
    lAngle += radian;
    Matrix33 mat;
    //グローバル角度の行列
    mat.Rotate(GetAngle());
    gPos = mat * lPos;
    gPos.Add(parent->GetPos());
    //全ての子のグローバル角度、座標を更新
    std::list<Base*>::iterator iter;
    for (iter = children.begin(); iter != children.end(); ++iter) {
        Base* child = *iter;
        child->Rotate(0);
    }
}

Vector2D Base::GetPos()
{
    Matrix33 mat;
    mat.Rotate(GetAngle());
    Vector2D pos = mat * lPos;
    if (parent != nullptr) {
       pos.Add(parent->GetPos());
    }
    return pos;
}

double Base::GetAngle()
{
    double pAngle = 0;
    if (parent != nullptr) {
        pAngle = parent->GetAngle();
    }
    gAngle = lAngle + pAngle;
    return gAngle;
}

void Base::Log()
{
    Calculator calc;
    printf("ローカル座標 X:%0.2f, Y:%0.2f\n", lPos.x, lPos.y);
    printf("グローバル座標 X:%0.2f, Y:%0.2f\n", gPos.x, gPos.y);
    printf("ローカル角度:%0.0f\n", calc.Degrees(lAngle));
    printf("グローバル角度:%0.0f\n", calc.Degrees(gAngle));
    
}
