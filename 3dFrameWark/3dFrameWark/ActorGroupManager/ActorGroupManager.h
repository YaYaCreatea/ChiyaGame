#ifndef _ACTOR_GROUP_MANAGER_H_
#define _ACTOR_GROUP_MANAGER_H_

#include "../ActorManager/ActorManager.h"

#include <map>

enum class ActorGroup;

class ActorGroupManager
{
public:
	ActorGroupManager() = default;

	void add(ActorGroup group);

	void add(ActorGroup group, const ActorPtr& actor);

	void update(float deltaTime);

	void draw()const;

	void draw(ActorGroup group)const;

	void clear();

	ActorPtr find_actor(ActorGroup group, const std::string& l_name)const;

	unsigned int get_count(ActorGroup group)const;

	void each_actor(ActorGroup group, std::function<void(const ActorPtr&)>fn)const;

	void collide(ActorGroup group_1, ActorGroup group_2);

	void handle_message(EventMessage message, void* param);

	void remove();

	ActorGroupManager(const ActorGroupManager& other) = delete;
	ActorGroupManager& operator=(const ActorGroupManager& other) = delete;

private:
	using ActorGroupMap = std::map<ActorGroup, ActorManager>;
	ActorGroupMap actor_group_map_;
};

#endif
