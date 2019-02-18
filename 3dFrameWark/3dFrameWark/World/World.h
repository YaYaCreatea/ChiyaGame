#ifndef _WORLD_H_
#define _WORLD_H_

#include "IWorld.h"
#include "../ActorGroupManager/ActorGroupManager.h"

#include "../CollisionMesh/CollisionMesh.h"
#include "../SkyBox/SkyBox.h"

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

	void draw2()const;

	void draw3()const;

	void draw4()const;

	void handle_message(EventMessage message, void* param);

	void add_event_message_listener(EventMessageListener listener);

	void add_camera(const ActorPtr& camera, const ActorPtr& camera1);

	void add_camera(const ActorPtr& camera, const ActorPtr& camera1, const ActorPtr& camera2, const ActorPtr& camera3);

	void add_light(const ActorPtr& light);

	void clear();

	virtual void add_actor(ActorGroup group, const ActorPtr& actor)override;

	virtual ActorPtr find_actor(ActorGroup group, const std::string& l_name)const override;

	virtual void add_camera_chiya(const ActorPtr& camera)override;

	virtual void add_camera_rize(const ActorPtr& camera)override;

	virtual void add_camera_syaro(const ActorPtr& camera)override;

	virtual void add_camera_cocoa(const ActorPtr& camera) override;

	virtual ActorPtr get_camera_chiya() const override;

	virtual ActorPtr get_camera_rize() const override;

	virtual ActorPtr get_camera_syaro() const override;

	virtual ActorPtr get_camera_cocoa() const override;

	virtual unsigned int get_count_actor(ActorGroup group)const override;

	virtual void each_actor(ActorGroup group, std::function<void(const ActorPtr&)>fn)const override;

	virtual void send_message(EventMessage message, void* param = nullptr)override;

	World(const World& other) = delete;
	World& operator=(const World& other) = delete;

private:
	ActorGroupManager actors_;
	ActorPtr cameraChiya_;
	ActorPtr cameraRize_;
	ActorPtr cameraSyaro_;
	ActorPtr cameraCocoa_;
	EventMessageListener listener_{ [](EventMessage,void*) {} };

	bool m_chiyaAlready;
	bool m_rizeAlready;
	bool m_syaroAlready;
	bool m_cocoaAlready;
};

#endif