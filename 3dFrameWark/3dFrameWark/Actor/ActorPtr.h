#ifndef _ACTOR_PTR_H_
#define _ACTOR_PTR_H_

#include <memory>

class Actor;
using ActorPtr = std::shared_ptr<Actor>;

template<class T,class... Args>
inline ActorPtr new_actor(Args&&... args)
{
	return std::make_shared<T>(args...);
}

#endif