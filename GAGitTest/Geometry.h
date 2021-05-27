#pragma once

/// <summary>
/// ベクトル構造体
/// </summary>

struct Vector2
{
	float x, y;
};

using Position2 = Vector2;

// 注釈：用途に合わせて構造体のつくり方を変える
// 
// 格闘ゲームでは地面の高さが同じ
// 地面とキャラの足元に頻繁に当たり判定が発生する
// なので、格ゲーキャラの矩形の判定、その中心点は
// 中央下、地面と接する場所にある

// 矩形構造体
struct Rect
{
	Position2 center;
	float w, h;
	float Left() const;
	float Top() const;
	float Right() const;
	float Bottom() const;
	float Whide() const;
	float Hight() const;
};


// 円の構造体
struct Circle
{
	Position2 center;	// 中心点
	float radius;		// 半径
};
