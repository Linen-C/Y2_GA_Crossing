#include <DxLib.h> 
#include <cmath>
#include "Geometry.h"

bool IsHit(const Rect& rcA, const Rect& rcB)
{
    // �d�Ȃ��Ă���Ƃ��� true �d�Ȃ��Ă��Ȃ��Ƃ��� false ��Ԃ�
    // �@���S�_���m�̍������v�Z
    // �AX�����̍�����A,B�̂̕��̍��v���r
    // �B���̍��v�i�����Ȃ�Γ������Ă��Ȃ��̂�false�j
    // �CY�����̓�������
    // �D�����̍��v�i�����Ȃ�Γ������Ă��Ȃ��̂�false�j
    // �E�����܂� return ����Ă��Ȃ����_�ł�����Ȃ̂� true

    int sighX = rcB.center.x - rcA.center.x;
    int sighY = rcB.center.y - rcA.center.y;
    sighX /= abs(sighX);
    sighY /= abs(sighY);

    int DifX = rcB.center.x - rcA.center.x;
    int DifY = rcB.center.y - rcA.center.y;

    //if (abs(DifX) < (rcA.w + rcB.w))
    //{
    //    DifX *= 0.5;
    //    rcA.center.x -= sighX * DifX;
    //    rcB.center.x += sighX * DifX;
    //}
    //else
    //{
    //    DifX *= 0.5;
    //    rcA.center.x -= sighX * DifX;
    //    rcB.center.x += sighX * DifX;
    //}
    //    if (abs(DifY) < (rcA.h + rcB.h))
    //    {
    //        return true;
    //    }
    //}

    if (abs(DifX) < (rcA.w + rcB.w))
    {
        if (abs(DifY) < (rcA.h + rcB.h))
        {
            return true;
        }
    }

    return false;
}

bool IsHit(const Circle& cA, const Circle& cB)
{
    //�~�Ɖ��̓����蔻����s��
    //�~A
    //�~B
    //true�F������/false�F�͂���
    //
    //�@�~A�Ɖ~B�̒��S�_���m�̋����𑪂�
    //�@�i�s�^�S���X�̒藝�ő���j
    //�A �@�ŋ��߂������Ɖ~A�̔��a�{�~B�̔��a���r����
    //�B �@�ŋ��߂����� <= �A�̍��v�Ȃ炠�����Ă���̂�true��Ԃ�
    //  �����łȂ����false��Ԃ�
    //
    // �����Asqrt��hypot�֐����g�p�������ꍇ��
    // #include<cmath>���C���N���[�h���邱��

    auto DifX = (cB.center.x - cA.center.x);
    auto DifY = (cB.center.y - cA.center.y);

    auto disD = hypot(DifX, DifY);

    if (disD <= cA.radius + cB.radius)
    {
        return true;
    }

    return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

    SetGraphMode(1024, 768, 32);
    ChangeWindowMode(true);
    SetWindowText(L"��������");


    //Rect RcA{ 100,100,50,50 };
    //Rect RcB{ 400,300,50,100 };
    Circle cA{ 100,500,50 };
    Circle cB{ 600,500,100 };

    char keyState[256];


    if (DxLib_Init()) {
        return -1;
    }

    SetDrawScreen(DX_SCREEN_BACK);

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {
        ClsDrawScreen();

        GetHitKeyStateAll(keyState);

        constexpr float speed = 6;
        unsigned int coller = 0xffffff;

        //if (keyState[KEY_INPUT_LEFT])
        //{
        //    RcA.center.x -= speed;
        //}
        //if (keyState[KEY_INPUT_UP])
        //{
        //    RcA.center.y -= speed;
        //}
        //if (keyState[KEY_INPUT_RIGHT])
        //{
        //    RcA.center.x += speed;
        //}
        //if (keyState[KEY_INPUT_DOWN])
        //{
        //    RcA.center.y += speed;
        //}

        if (keyState[KEY_INPUT_LEFT])
        {
            cA.center.x -= speed;
        }
        if (keyState[KEY_INPUT_UP])
        {
            cA.center.y -= speed;
        }
        if (keyState[KEY_INPUT_RIGHT])
        {
            cA.center.x += speed;
        }
        if (keyState[KEY_INPUT_DOWN])
        {
            cA.center.y += speed;
        }

        //if (IsHit(RcA, RcB))
        //{
        //    coller = 0xffaaaa;
        //}

        if (IsHit(cA, cB))
        {
            coller = 0xffaaaa;
        }

        //DrawBox(RcA.Left(), RcA.Top(), RcA.Right(), RcA.Bottom(), coller, true);
        //DrawBox(RcB.Left(), RcB.Top(), RcB.Right(), RcB.Bottom(), coller, true);
        DrawCircleAA(cA.center.x, cA.center.y, cA.radius, 32, coller, true);
        DrawCircleAA(cB.center.x, cB.center.y, cB.radius, 32, coller, true);

        ScreenFlip();
    }

    DxLib_End();
    return 0;
}
