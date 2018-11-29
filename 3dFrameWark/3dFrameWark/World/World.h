#ifndef _WORLD_H_
#define _WORLD_H_

#include "IWorld.h"
#include "../ActorGroupManager/ActorGroupManager.h"

#include <functional>

enum class EventMessage;

class World :public IWorld
{
public:
	using EventMessageListener = std::function<void(EventMessage, void*)>;

public:
	World();

	void initialize();

	void update(float deltaTime);

	void draw()const;

	void handle_message(EventMessage message, void* param);

	void add_event_message_listener(EventMessageListener listener);

	void add_camera(const ActorPtr& camera);

	void add_light(const ActorPtr& light);

	void clear();

	virtual void add_actor(ActorGroup group, const ActorPtr& actor)override;

	virtual ActorPtr find_actor(ActorGroup group, const std::string& l_name)const override;

	virtual unsigned int get_count_actor(ActorGroup group)const override;

	virtual void each_actor(ActorGroup group, std::function<void(const ActorPtr&)>fn)const override;

	virtual void send_message(EventMessage message, void* param = nullptr)override;

	World(const World& other) = delete;
	World& operator=(const World& other) = delete;

private:
	ActorGroupManager actors_;
	ActorPtr camera_;
	EventMessageListener listener_{ [](EventMessage,void*) {} };
};

#endif