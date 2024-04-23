#include "GameWorld.h"
#include "BoundingSphere.h"
#include "LaserPowerUp.h"
#include <stdlib.h>
#include "BoundingShape.h"

/** Constructor. */
LaserPowerUp::LaserPowerUp() : GameObject("LaserPowerUp") {}

/** Construct a new LaserPowerUp with given position, velocity, angle and rotation. */
LaserPowerUp::LaserPowerUp(GLVector3f p, GLVector3f v, GLfloat h, GLfloat r)
	: GameObject("LaserPowerUp", p, v, GLVector3f(), h, r) {}

/** Copy constructor. */
LaserPowerUp::LaserPowerUp(const LaserPowerUp& e) : GameObject(e) {}

/** Destructor. */
LaserPowerUp::~LaserPowerUp(void) {}

// PUBLIC INSTANCE METHODS ////////////////////////////////////////////////////


bool LaserPowerUp::CollisionTest(shared_ptr<GameObject> o)
{
	if (o->GetType() != GameObjectType("Bullet")) return false;
	//if (GetType() == o->GetType()) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void LaserPowerUp::OnCollision(const GameObjectList& objects)
{
	mWorld->FlagForRemoval(GetThisPtr());
}