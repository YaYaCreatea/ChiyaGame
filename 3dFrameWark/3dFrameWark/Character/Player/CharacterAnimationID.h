#ifndef _CHARACTER_ANIMATION_ID_H_
#define _CHARACTER_ANIMATION_ID_H_

enum class ChiyaAnmID
{
	Idle,
	Combo1,
	Move,
	Combo2 = 8,
	JumpReady,
	Jump,
	Landing,
	Damage,
	Break,
	DamageBreak,
	Down,
	DownIdle,
};

enum class RizeAnmID
{
	Idle,
	Move,
	Combo1,
	Combo2,
	JumpReady,
	Jump,
	Landing,
	Damage,
	DamageBreak,
	Down,
	DownIdle,
	BreakReady,
	BreakCharge,
	BreakChargeMax,
	Break,
};

#endif