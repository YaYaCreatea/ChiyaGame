#ifndef _ACTOR_H_
#define _ACTOR_H_

#include <string>

#include "../Utility/Vector3/Vector3.h"
#include "../Utility/Matrix/Matrix.h"

#include "../CollisionDetection/BoundingSphere/BoundingSphere.h"
#include "../CollisionDetection/BoundingCapsule/BoundingCapsule.h"

class IWorld;
enum class EventMessage;

class Actor
{
public:
	Actor() = default;

	virtual ~Actor() {}

	virtual void update(float deltaTime);

	virtual void draw()const;

	virtual void react(Actor& other);

	void collide(Actor& other);

	void die();

	bool is_dead()const;

	bool is_collide(const Actor& other)const;

	bool is_collide_capsule(const Actor& other)const;

	const std::string& get_name()const;

	Vector3 get_position()const;

	Vector3 get_velocity()const;

	Matrix get_pose()const;

	BoundingSphere get_body()const;

	BoundingCapsule get_bodyCapsule()const;

	virtual void handle_message(EventMessage message, void* param = nullptr);

	Actor(const Actor& other) = delete;
	Actor& operator=(const Actor& other) = delete;

protected:
	IWorld* world_{ nullptr };

	std::string m_name{};

	Vector3 m_position{ Vector3::Zero };
	Vector3 m_velocity{ Vector3::Zero };
	Vector3 m_prevposition{ Vector3::Zero };

	Matrix m_rotation{ Matrix::Identity };

	BoundingSphere body_{};

	BoundingCapsule bodyCapsule_{};

	bool m_isdead{ false };
};

#endif