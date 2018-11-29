#include "ActorManager.h"

void ActorManager::add(const ActorPtr & actor)
{
	actors_.push_front(actor);
}

void ActorManager::update(float deltaTime)
{
	for (const auto& actor : actors_)
		actor->update(deltaTime);
}

void ActorManager::draw() const
{
	for (const auto& actor : actors_)
		actor->draw();
}

void ActorManager::collide()
{
	for (auto i = actors_.begin(); i != actors_.end(); ++i)
		for (auto j = std::next(i); j != actors_.end(); ++j)
			(*i)->collide(**j);
}

void ActorManager::collide(Actor & other)
{
	for (const auto& actor : actors_)
		other.collide(*actor);
}

void ActorManager::collide(ActorManager & other)
{
	for (const auto& actor : actors_)
		other.collide(*actor);
}

void ActorManager::remove()
{
	actors_.remove_if([](const ActorPtr& actor) {return actor->is_dead(); });
}

ActorPtr ActorManager::find_actor(const std::string & l_name) const
{
	for (const auto& actor : actors_)
		if (actor->get_name() == l_name)
			return actor;
}

unsigned int ActorManager::get_count() const
{
	return actors_.size();
}

void ActorManager::each_actor(std::function<void(const ActorPtr&)> fn) const
{
	for (const auto& actor : actors_)
		fn(actor);
}

void ActorManager::handle_message(EventMessage message, void * param)
{
	for (const auto& actor : actors_)
		actor->handle_message(message, param);
}

void ActorManager::clear()
{
	actors_.clear();
}
