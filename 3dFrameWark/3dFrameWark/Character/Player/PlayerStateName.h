#ifndef _PLAYER_STATE_NAME_H_
#define _PLAYER_STATE_NAME_H_

enum class PlayerStateName
{
	Idle,
	Move,
	Attack,
	Break,
	Damage,
	DamageBreak,
	Jump,
	Down,
	DownIdle,
	Dash,
};

enum
{
	MotionIdle = 1,
	MotionForwardWalk = 2,
	MotionBackardWalk = 3,
	MotionLeftWalk = 4,
	MotionRightWalk = 5,
	MotionFire = 11,
	MotionDamage = 14,
	MotionJump = 17
};


#endif