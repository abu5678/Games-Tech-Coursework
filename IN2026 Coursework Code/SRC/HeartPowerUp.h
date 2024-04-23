#ifndef __HeartPowerUp_H__
#define __HeartPowerUp_H__

#include "GameUtil.h"
#include "GameObject.h"

class HeartPowerUp : public GameObject
{
public:
	HeartPowerUp();
	HeartPowerUp(GLVector3f p, GLVector3f v, GLfloat h, GLfloat r);
	HeartPowerUp(const HeartPowerUp& e);
	virtual ~HeartPowerUp(void);

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);
};

#endif
#pragma once
