#pragma once

/// <summary>
/// �x�N�g���\����
/// </summary>

struct Vector2
{
	float x, y;
};

using Position2 = Vector2;

// ���߁F�p�r�ɍ��킹�č\���̂̂������ς���
// 
// �i���Q�[���ł͒n�ʂ̍���������
// �n�ʂƃL�����̑����ɕp�ɂɓ����蔻�肪��������
// �Ȃ̂ŁA�i�Q�[�L�����̋�`�̔���A���̒��S�_��
// �������A�n�ʂƐڂ���ꏊ�ɂ���

// ��`�\����
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


// �~�̍\����
struct Circle
{
	Position2 center;	// ���S�_
	float radius;		// ���a
};
