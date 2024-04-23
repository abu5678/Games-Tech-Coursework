#ifndef __POWERUP_H__
#define __POWERUP_H__

#include "GameUtil.h"

#include "GameObject.h"
#include "GameObjectType.h"
#include "PowerUpListener.h"
#include "IGameWorldListener.h"

class PowerUp : public IGameWorldListener
{
public:
	PowerUp() {}
	virtual ~PowerUp() {}

	void OnWorldUpdated(GameWorld* world) {}
	void OnObjectAdded(GameWorld* world, shared_ptr<GameObject> object) {}

	void OnObjectRemoved(GameWorld* world, shared_ptr<GameObject> object)
	{
		if (object->GetType() == GameObjectType("ExtraBulletsPowerUp")) {
			FireExtraBulletsPickedUp();
		}
	}

	void AddListener(shared_ptr<PowerUpListener> listener)
	{
		mListeners.push_back(listener);
	}
	void FireExtraBulletsPickedUp()
	{
		// Send message to all listeners
		for (PowerUpListenerList::iterator lit = mListeners.begin(); lit != mListeners.end(); ++lit) {
			(*lit)->OnExtraBulletsPowerUpCollected();
		}
	}

private:

	typedef std::list< shared_ptr<PowerUpListener> > PowerUpListenerList;

	PowerUpListenerList mListeners;
};

#endif
