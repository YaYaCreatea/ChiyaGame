#include "World.h"

#include "../ActorGroupManager/ActorGroup.h"
#include "../Actor/Actor.h"

World::World()
{
	initialize();
}

void World::initialize()
{
	clear();
	actors_.add(ActorGroup::Player);
	actors_.add(ActorGroup::PlayerAction);
	actors_.add(ActorGroup::Enemy);
	actors_.add(ActorGroup::EnemyAction);
	actors_.add(ActorGroup::Neutral);
}

void World::update(float deltaTime)
{
	actors_.update(deltaTime);

	actors_.collide(ActorGroup::Player, ActorGroup::Enemy);
	actors_.collide(ActorGroup::Player, ActorGroup::EnemyAction);
	actors_.collide(ActorGroup::PlayerAction, ActorGroup::Enemy);

	actors_.remove();

	camera0_->update(deltaTime);
	camera1_->update(deltaTime);
}

void World::draw() const
{	
	camera0_->draw();
	actors_.draw();	
}

void World::draw2() const
{
	camera1_->draw();
	actors_.draw();
}

void World::handle_message(EventMessage message, void * param)
{
	listener_(message, param);

	camera0_->handle_message(message, param);
	actors_.handle_message(message, param);
	
	actors_.handle_message(message, param);	
}

void World::add_event_message_listener(EventMessageListener listener)
{
	listener_ = listener;
}

void World::add_camera(const ActorPtr & camera, const ActorPtr& camera1)
{
	camera0_ = camera;
	camera1_ = camera1;
}

void World::add_light(const ActorPtr & light)
{
}

void World::clear()
{
	actors_.clear();
}

void World::add_actor(ActorGroup group, const ActorPtr & actor)
{
	actors_.add(group, actor);
}

ActorPtr World::find_actor(ActorGroup group, const std::string & l_name) const
{
	return actors_.find_actor(group, l_name);
}

ActorPtr World::get_camera0() const
{
	return camera0_;
}

ActorPtr World::get_camera1() const
{
	return camera1_;
}

unsigned int World::get_count_actor(ActorGroup group) const
{
	return actors_.get_count(group);
}

void World::each_actor(ActorGroup group, std::function<void(const ActorPtr&)> fn) const
{
	actors_.each_actor(group, fn);
}

void World::send_message(EventMessage message, void * param)
{
	handle_message(message, param);
}
