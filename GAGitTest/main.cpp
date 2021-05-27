#include <DxLib.h> 
#include <cmath>
#include "Geometry.h"

bool IsHit(const Rect& rcA, const Rect& rcB)
{
    // 重なっているときに true 重なっていないときに false を返す
    // ①中心点同士の差分を計算
    // ②X方向の差分とA,Bのの幅の合計を比較
    // ③幅の合計（差分ならば当たっていないのでfalse）
    // ④Y方向の同じこと
    // ⑤高さの合計（差分ならば当たっていないのでfalse）
    // ⑥ここまで return されていない時点であたりなので true

    int sighX = rcB.center.x - rcA.center.x;
    int sighY = rcB.center.y - rcA.center.y;
    sighX /= abs(sighX);
    sighY /= abs(sighY);

    // auto DifX2 = abs(rcB.center.x -rcA.center.x))
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
    //円と縁の当たり判定を行う
    //円A
    //円B
    //true：あたり/false：はずれ
    //
    //①円Aと円Bの中心点同士の距離を測る
    //　（ピタゴラスの定理で測る）
    //② ①で求めた距離と円Aの半径＋円Bの半径を比較する
    //③ ①で求めた距離 <= ②の合計ならあたっているのでtrueを返す
    //  そうでなければfalseを返す
    //
    // もし、sqrtやhypot関数を使用したい場合は
    // #include<cmath>をインクルードすること

    auto DifX = (cB.center.x - cA.center.x);
    auto DifY = (cB.center.y - cA.center.y);

    auto disD = hypot(DifX, DifY);

    if (disD <= cA.radius + cB.radius)
    {
        return true;
    }

    //auto totalRAD = cA.radius + cB.radius;
    //return totalRAD = 

    return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

    SetGraphMode(1024, 768, 32);
    ChangeWindowMode(true);
    SetWindowText(L"矩形当たり判定 2016002_伊勢拓晟");


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
