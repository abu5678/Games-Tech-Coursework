#ifndef __LaserPowerUp_H__
#define __LaserPowerUp_H__

#include "GameUtil.h"
#include "GameObject.h"

class LaserPowerUp : public GameObject
{
public:
	LaserPowerUp();
	LaserPowerUp(GLVector3f p, GLVector3f v, GLfloat h, GLfloat r);
	LaserPowerUp(const LaserPowerUp& e);
	virtual ~LaserPowerUp(void);

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);
};

#endif
#pragma once
#pragma once
