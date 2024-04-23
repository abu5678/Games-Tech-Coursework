#include "GameWorld.h"
#include "BoundingSphere.h"
#include "ShieldPowerUp.h"
#include <stdlib.h>
#include "BoundingShape.h"

/** Constructor. */
ShieldPowerUp::ShieldPowerUp() : GameObject("ShieldPowerUp") {}

/** Construct a new ShieldPowerUp with given position, velocity, angle and rotation. */
ShieldPowerUp::ShieldPowerUp(GLVector3f p, GLVector3f v, GLfloat h, GLfloat r)
	: GameObject("ShieldPowerUp", p, v, GLVector3f(), h, r) {}

/** Copy constructor. */
ShieldPowerUp::ShieldPowerUp(const ShieldPowerUp& e) : GameObject(e) {}

/** Destructor. */
ShieldPowerUp::~ShieldPowerUp(void) {}

// PUBLIC INSTANCE METHODS ////////////////////////////////////////////////////


bool ShieldPowerUp::CollisionTest(shared_ptr<GameObject> o)
{
	if (o->GetType() != GameObjectType("Bullet")) return false;
	//if (GetType() == o->GetType()) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void ShieldPowerUp::OnCollision(const GameObjectList& objects)
{
	mWorld->FlagForRemoval(GetThisPtr());
}