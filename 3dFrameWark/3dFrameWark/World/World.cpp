#include "World.h"

#include "../ActorGroupManager/ActorGroup.h"
#include "../Actor/Actor.h"

#include "../assetsID/AssetsID.h"

#include <EffekseerForDXLib.h>
#include "../Effect/Effect.h"


World::World()
{
	initialize();
}

void World::initialize()
{
	clear();
	actors_.add(ActorGroup::Chiya);
	actors_.add(ActorGroup::ChiyaAction);
	actors_.add(ActorGroup::Rize);
	actors_.add(ActorGroup::RizeAction);
	actors_.add(ActorGroup::Syaro);
	actors_.add(ActorGroup::SyaroAction);
	actors_.add(ActorGroup::Cocoa);
	actors_.add(ActorGroup::CocoaAction);
	actors_.add(ActorGroup::Boss);
	actors_.add(ActorGroup::BossBody);
	actors_.add(ActorGroup::Neutral);
	actors_.add(ActorGroup::Effect);

	m_chiyaAlready = false;
	m_rizeAlready = false;
	m_syaroAlready = false;
	m_cocoaAlready = false;
}

void World::update(float deltaTime)
{
	actors_.update(deltaTime);

	actors_.collide(ActorGroup::Chiya, ActorGroup::Rize);
	actors_.collide(ActorGroup::Chiya, ActorGroup::Syaro);
	actors_.collide(ActorGroup::Chiya, ActorGroup::Cocoa);
	actors_.collide(ActorGroup::Chiya, ActorGroup::Boss);
	actors_.collide(ActorGroup::Rize, ActorGroup::Syaro);
	actors_.collide(ActorGroup::Rize, ActorGroup::Cocoa);
	actors_.collide(ActorGroup::Rize, ActorGroup::Boss);
	actors_.collide(ActorGroup::Syaro, ActorGroup::Cocoa);
	actors_.collide(ActorGroup::Syaro, ActorGroup::Boss);
	actors_.collide(ActorGroup::Cocoa, ActorGroup::Boss);

	actors_.collide(ActorGroup::Chiya, ActorGroup::RizeAction);
	actors_.collide(ActorGroup::Chiya, ActorGroup::SyaroAction);
	actors_.collide(ActorGroup::Chiya, ActorGroup::CocoaAction);
	actors_.collide(ActorGroup::Rize, ActorGroup::ChiyaAction);
	actors_.collide(ActorGroup::Rize, ActorGroup::SyaroAction);
	actors_.collide(ActorGroup::Rize, ActorGroup::CocoaAction);
	actors_.collide(ActorGroup::Syaro, ActorGroup::ChiyaAction);
	actors_.collide(ActorGroup::Syaro, ActorGroup::RizeAction);
	actors_.collide(ActorGroup::Syaro, ActorGroup::CocoaAction);
	actors_.collide(ActorGroup::Cocoa, ActorGroup::ChiyaAction);
	actors_.collide(ActorGroup::Cocoa, ActorGroup::RizeAction);
	actors_.collide(ActorGroup::Cocoa, ActorGroup::SyaroAction);
	actors_.collide(ActorGroup::Boss, ActorGroup::ChiyaAction);
	actors_.collide(ActorGroup::Boss, ActorGroup::RizeAction);
	actors_.collide(ActorGroup::Boss, ActorGroup::SyaroAction);
	actors_.collide(ActorGroup::Boss, ActorGroup::CocoaAction);
	actors_.collide(ActorGroup::BossBody, ActorGroup::ChiyaAction);
	actors_.collide(ActorGroup::BossBody, ActorGroup::RizeAction);
	actors_.collide(ActorGroup::BossBody, ActorGroup::SyaroAction);
	actors_.collide(ActorGroup::BossBody, ActorGroup::CocoaAction);

	actors_.remove();

	if (cameraChiya_ != nullptr)
		cameraChiya_->update(deltaTime);
	if (cameraRize_ != nullptr)
		cameraRize_->update(deltaTime);

	if (cameraSyaro_ != nullptr)
		cameraSyaro_->update(deltaTime);
	if (cameraCocoa_ != nullptr)
		cameraCocoa_->update(deltaTime);
}

void World::draw()const
{
	cameraChiya_->draw();
	SkyBox::draw();
	CollisionMesh::draw();
	actors_.draw();
}

void World::draw2() const
{
	cameraRize_->draw();
	SkyBox::draw();
	CollisionMesh::draw();
	actors_.draw();
}

void World::draw3() const
{
	cameraSyaro_->draw();
	SkyBox::draw();
	CollisionMesh::draw();
	actors_.draw();
}

void World::draw4() const
{
	cameraCocoa_->draw();
	SkyBox::draw();
	CollisionMesh::draw();
	actors_.draw();
}

void World::handle_message(EventMessage message, void * param)
{
	listener_(message, param);

	cameraChiya_->handle_message(message, param);
	actors_.handle_message(message, param);

	actors_.handle_message(message, param);
}

void World::add_event_message_listener(EventMessageListener listener)
{
	listener_ = listener;
}

void World::add_camera(const ActorPtr & camera, const ActorPtr& camera1)
{
	cameraChiya_ = camera;
	cameraRize_ = camera1;
}

void World::add_camera(const ActorPtr & camera, const ActorPtr & camera1, const ActorPtr & camera2, const ActorPtr & camera3)
{
	cameraChiya_ = camera;
	cameraRize_ = camera1;
	cameraSyaro_ = camera2;
	cameraCocoa_ = camera3;
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

void World::add_camera_chiya(const ActorPtr & camera)
{
	cameraChiya_ = camera;
}

void World::add_camera_rize(const ActorPtr & camera)
{
	cameraRize_ = camera;
}

void World::add_camera_syaro(const ActorPtr & camera)
{
	cameraSyaro_ = camera;
}

void World::add_camera_cocoa(const ActorPtr & camera)
{
	cameraCocoa_ = camera;
}

ActorPtr World::get_camera_chiya() const
{
	return cameraChiya_;
}

ActorPtr World::get_camera_rize() const
{
	return cameraRize_;
}

ActorPtr World::get_camera_syaro() const
{
	return cameraSyaro_;
}

ActorPtr World::get_camera_cocoa() const
{
	return cameraCocoa_;
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
