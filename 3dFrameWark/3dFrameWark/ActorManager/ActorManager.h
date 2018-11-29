#ifndef _ACTOR_MANAGER_H_
#define _ACTOR_MANAGER_H_

#include "../Actor/Actor.h"
#include "../Actor/ActorPtr.h"

#include <list>
#include <functional>

class ActorManager
{
public:
	ActorManager() = default;

	void add(const ActorPtr& actor);

	void update(float deltaTime);

	void draw()const;

	void collide();

	void collide(Actor& other);

	void collide(ActorManager& other);

	void remove();

	ActorPtr find_actor(const std::string& l_name)const;

	unsigned int get_count()const;

	void each_actor(std::function<void(const ActorPtr&)>fn)const;

	void handle_message(EventMessage message, void*param);

	void clear();

	ActorManager(const ActorManager& other) = delete;
	ActorManager& operator=(const ActorManager& other) = delete;

private:

	using ActorList = std::list<ActorPtr>;
	ActorList actors_;
};

#endif