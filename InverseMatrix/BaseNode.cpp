#include "BaseNode.h"
#include "Matrix33.h"
#include "Calculator.h"

BaseNode::BaseNode()
{
    lAngle = 0;
    parent = nullptr;
}

BaseNode::~BaseNode()
{
}

void BaseNode::AddChild(BaseNode* base)
{
    children.push_back(base);
    base->parent = this;
}

void BaseNode::Foward( const Vector2D& vec)
{
    lPos.Add(vec);
    
}

void BaseNode::Rotate(const double& radian, bool inverse )
{
    //���[�J���̊p�x
    lAngle += radian;
    //�O���[�o���p�x�̍s��
    mat.Rotate(lAngle);
    if (inverse) mat = mat.inverse();
}

Vector2D BaseNode::GetPos()
{
    Vector2D gPos = mat* lPos;
    if (parent != nullptr) {
        gPos = parent->GetMatrix() * gPos;
        gPos.Add(parent->GetPos());
    }
    return gPos;
}

Matrix33 BaseNode::GetMatrix()
{
    Matrix33 gMat = mat;
    if (parent != nullptr) {
        gMat = parent->GetMatrix() * gMat;
    }
    return gMat;
}

void BaseNode::Log()
{
    Calculator calc;
    printf("���[�J�����W X:%0.2f, Y:%0.2f\n", lPos.x, lPos.y);
    printf("���[�J���p�x:%0.0f\n", calc.Degrees(lAngle));
    
}
