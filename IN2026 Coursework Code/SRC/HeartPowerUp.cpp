#include "GameWorld.h"
#include "BoundingSphere.h"
#include "HeartPowerUp.h"
#include <stdlib.h>
#include "BoundingShape.h"

/** Constructor. */
HeartPowerUp::HeartPowerUp() : GameObject("HeartPowerUp") {}

/** Construct a new HeartPowerUp with given position, velocity, angle and rotation. */
HeartPowerUp::HeartPowerUp(GLVector3f p, GLVector3f v, GLfloat h, GLfloat r)
	: GameObject("HeartPowerUp", p, v, GLVector3f(), h, r) {}

/** Copy constructor. */
HeartPowerUp::HeartPowerUp(const HeartPowerUp& e) : GameObject(e) {}

/** Destructor. */
HeartPowerUp::~HeartPowerUp(void) {}

bool HeartPowerUp::CollisionTest(shared_ptr<GameObject> o)
{
	if (o->GetType() != GameObjectType("Bullet")) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void HeartPowerUp::OnCollision(const GameObjectList& objects)
{
	mWorld->FlagForRemoval(GetThisPtr());
}