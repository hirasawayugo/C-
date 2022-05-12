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
    //ローカルの角度
    lAngle += radian;
    Matrix33 mat;
    //グローバル角度の行列
    mat.Rotate(GetAngle());
    if (inverse) gPos = mat.inverse() * lPos;
    else gPos = mat * lPos;
    gPos.Add(parent->GetPos());
    //全ての子のグローバル角度、座標を更新
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
    printf("ローカル座標 X:%0.2f, Y:%0.2f\n", lPos.x, lPos.y);
    printf("グローバル座標 X:%0.2f, Y:%0.2f\n", gPos.x, gPos.y);
    printf("ローカル角度:%0.0f\n", calc.Degrees(lAngle));
    printf("グローバル角度:%0.0f\n", calc.Degrees(gAngle));
    
}
