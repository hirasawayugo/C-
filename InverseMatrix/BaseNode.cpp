#include "BaseNode.h"
#include "Matrix33.h"
#include "Calculator.h"

BaseNode::BaseNode()
{
    lAngle = 0;
    gAngle = 0;
    parent = nullptr;
}

BaseNode::~BaseNode()
{
}

void BaseNode::AddChild(BaseNode* base)
{
    children.push_back(base);
    base->parent = this;
    gPos = GetPos();
    base->gPos = base->GetPos();
}

void BaseNode::Foward( const Vector2D& vec)
{
    lPos.Add(vec);
    Matrix33 mat;
    mat.Rotate(GetAngle());
    gPos = mat * lPos;
    if (parent != nullptr) {
        gPos.Add(parent->GetPos());
    }
}

void BaseNode::Rotate(const double& radian, bool inverse )
{
    //���[�J���̊p�x
    lAngle += radian;
    Matrix33 mat;
    //�O���[�o���p�x�̍s��
    mat.Rotate(GetAngle());
    if (inverse) gPos = mat.inverse() * lPos;
    else gPos = mat * lPos;
    gPos.Add(parent->GetPos());
    //�S�Ă̎q�̃O���[�o���p�x�A���W���X�V
    std::list<BaseNode*>::iterator iter;
    for (iter = children.begin(); iter != children.end(); ++iter) {
        BaseNode* child = *iter;
        child->Rotate(0, false);
    }
}

Vector2D BaseNode::GetPos()
{
    Matrix33 mat;
    mat.Rotate(GetAngle());
    Vector2D pos = mat * lPos;
    if (parent != nullptr) {
       pos.Add(parent->GetPos());
    }
    return pos;
}

double BaseNode::GetAngle()
{
    double pAngle = 0;
    if (parent != nullptr) {
        pAngle = parent->GetAngle();
    }
    gAngle = lAngle + pAngle;
    return gAngle;
}

void BaseNode::Log()
{
    Calculator calc;
    printf("���[�J�����W X:%0.2f, Y:%0.2f\n", lPos.x, lPos.y);
    printf("�O���[�o�����W X:%0.2f, Y:%0.2f\n", gPos.x, gPos.y);
    printf("���[�J���p�x:%0.0f\n", calc.Degrees(lAngle));
    printf("�O���[�o���p�x:%0.0f\n", calc.Degrees(gAngle));
    
}
