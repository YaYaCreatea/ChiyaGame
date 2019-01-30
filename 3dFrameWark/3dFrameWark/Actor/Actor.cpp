#include "Actor.h"

void Actor::update(float deltaTime)
{
}

void Actor::draw() const
{
}

void Actor::react(Actor & other)
{
}

void Actor::collide(Actor & other)
{
	if (is_collide(other))
	{
		react(other);
		other.react(*this);
	}

	if (is_collide_capsule(other))
	{		
		react(other);
		other.react(*this);
	}
}

void Actor::set_IsDown(bool l_isDown)
{
	m_isDown = l_isDown;
}

void Actor::die()
{
	m_isdead = true;
}

bool Actor::get_IsDown() const
{
	return m_isDown;
}

bool Actor::is_dead() const
{
	return m_isdead;
}

bool Actor::is_collide(const Actor & other) const
{
	return get_body().intersects(other.get_body());
}

bool Actor::is_collide_capsule(const Actor & other) const
{
	return get_bodyCapsule().intersects(other.get_bodyCapsule());
}

const std::string & Actor::get_name() const
{
	return m_name;
}

Vector3 Actor::get_position() const
{
	return m_position;
}

Vector3 Actor::get_velocity() const
{
	return m_velocity;
}

Matrix Actor::get_pose() const
{
	return Matrix(m_rotation).Translation(m_position);
}

BoundingSphere Actor::get_body() const
{
	return body_.transform(get_pose());
}

BoundingCapsule Actor::get_bodyCapsule() const
{
	return bodyCapsule_.transform(get_pose());
}

void Actor::handle_message(EventMessage message, void * param)
{
}
