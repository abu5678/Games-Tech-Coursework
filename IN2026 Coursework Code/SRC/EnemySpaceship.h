#ifndef __EnemySpaceship_H__
#define __EnemySpaceship_H__

#include "GameUtil.h"

#include "GameObject.h"
#include "GameObjectType.h"
#include "EnemyListener.h"
#include "IGameWorldListener.h"

class EnemySpaceship : public IGameWorldListener
{
public:
	EnemySpaceship() {}
	virtual ~EnemySpaceship() {}

	void OnWorldUpdated(GameWorld* world) {
		shooting();
	}
	void OnObjectAdded(GameWorld* world, shared_ptr<GameObject> object) {}

	void OnObjectRemoved(GameWorld* world, shared_ptr<GameObject> object)
	{
	}

	void AddListener(shared_ptr<EnemyListener> listener)
	{
		mListeners.push_back(listener);
	}
	void shooting()
	{
		// Send message to all listeners
		for (EnemySpaceshipListenerList::iterator lit = mListeners.begin(); lit != mListeners.end(); ++lit) {
			(*lit)->ShootInterval();
		}
	}

private:

	typedef std::list< shared_ptr<EnemyListener> > EnemySpaceshipListenerList;

	EnemySpaceshipListenerList mListeners;
};

#endif
