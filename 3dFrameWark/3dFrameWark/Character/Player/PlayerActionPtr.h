#ifndef _PLAYER_ACTION_PTR_H_
#define _PLAYER_ACTION_PTR_H_

#include <memory>

class PlayerActionBase;
using PlayerActionPtr = std::shared_ptr<PlayerActionBase>;

// ƒAƒNƒVƒ‡ƒ“‚Ì’Ç‰Á
template<class T, class... Args>
inline PlayerActionPtr new_action(Args&&... args)
{
	return std::make_shared<T>(args...);
}

#endif