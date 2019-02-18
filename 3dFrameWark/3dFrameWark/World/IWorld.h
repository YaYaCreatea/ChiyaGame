#ifndef _IWORLD_H_
#define _IWORLD_H_

#include "../Actor/ActorPtr.h"
#include <string>
#include <functional>

enum class ActorGroup;
enum class EventMessage;

class IWorld
{
public:
	virtual ~IWorld() {}

	virtual void add_actor(ActorGroup group, const ActorPtr& actor) = 0;

	virtual ActorPtr find_actor(ActorGroup group, const std::string& name) const = 0;

	virtual void add_camera_chiya(const ActorPtr& camera) = 0;

	virtual void add_camera_rize(const ActorPtr& camera) = 0;

	virtual void add_camera_syaro(const ActorPtr& camera) = 0;

	virtual void add_camera_cocoa(const ActorPtr& camera) = 0;

	virtual ActorPtr get_camera_chiya() const = 0;

	virtual ActorPtr get_camera_rize() const = 0;

	virtual ActorPtr get_camera_syaro() const = 0;

	virtual ActorPtr get_camera_cocoa() const = 0;

	virtual unsigned int get_count_actor(ActorGroup group)const = 0;

	virtual void each_actor(ActorGroup group, std::function<void(const ActorPtr&)>fn)const = 0;

	virtual void send_message(EventMessage message, void* param = nullptr) = 0;
};

#endif