#pragma once

//�G�̃x�[�X���N���X�G�̓����`�֌W�Ȃ��̕���
//�S�G�l�~�[���ʕ���

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

