#ifndef __ShieldPowerUp_H__
#define __ShieldPowerUp_H__

#include "GameUtil.h"
#include "GameObject.h"

class ShieldPowerUp : public GameObject
{
public:
	ShieldPowerUp();
	ShieldPowerUp(GLVector3f p, GLVector3f v, GLfloat h, GLfloat r);
	ShieldPowerUp(const ShieldPowerUp& e);
	virtual ~ShieldPowerUp(void);

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);
};

#endif
#pragma once
#pragma once
