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
    //���[�J���̊p�x
    lAngle += radian;
    Matrix33 mat;
    //�O���[�o���p�x�̍s��
    mat.Rotate(GetAngle());
    gPos = mat * lPos;
    gPos.Add(parent->GetPos());
    //�S�Ă̎q�̃O���[�o���p�x�A���W���X�V
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
    printf("���[�J�����W X:%0.2f, Y:%0.2f\n", lPos.x, lPos.y);
    printf("�O���[�o�����W X:%0.2f, Y:%0.2f\n", gPos.x, gPos.y);
    printf("���[�J���p�x:%0.0f\n", calc.Degrees(lAngle));
    printf("�O���[�o���p�x:%0.0f\n", calc.Degrees(gAngle));
    
}
