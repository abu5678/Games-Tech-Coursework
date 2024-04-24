#ifndef __EnemyBullet_H__
#define __EnemyBullet_H__

#include "GameUtil.h"
#include "GameObject.h"

class EnemyBullet : public GameObject
{
public:
	EnemyBullet();
	EnemyBullet(GLVector3f p, GLVector3f v, GLVector3f a, GLfloat h, GLfloat r, int ttl);
	EnemyBullet(const EnemyBullet& b);
	virtual ~EnemyBullet(void);

	virtual void Update(int t);

	void SetTimeToLive(int ttl) { mTimeToLive = ttl; }
	int GetTimeToLive(void) { return mTimeToLive; }

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);

protected:
	int mTimeToLive;
};

#endif