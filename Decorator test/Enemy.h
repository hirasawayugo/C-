#pragma once

//敵のベース情報クラス敵の動き形関係なしの部分
//全エネミー共通部分

class Enemy
{
public:
    Enemy(const int& life, const int& power);
    virtual ~Enemy() {}

    virtual void move() = 0;

    int getLife() const;
    int getPower() const;
protected:
    int mLife;
    int mPower;
private:
    Enemy();
    Enemy(const Enemy& rhs);
    Enemy& operator=(const Enemy& rhs);
};

