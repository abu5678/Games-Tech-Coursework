#ifndef __ExtraBulletsPowerUp_H__
#define __ExtraBulletsPowerUp_H__

#include "GameUtil.h"
#include "GameObject.h"

class ExtraBulletsPowerUp : public GameObject
{
public:
	ExtraBulletsPowerUp();
	ExtraBulletsPowerUp(GLVector3f p, GLVector3f v, GLfloat h, GLfloat r);
	ExtraBulletsPowerUp(const ExtraBulletsPowerUp& e);
	virtual ~ExtraBulletsPowerUp(void);

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);
};

#endif
#pragma once
#pragma once
