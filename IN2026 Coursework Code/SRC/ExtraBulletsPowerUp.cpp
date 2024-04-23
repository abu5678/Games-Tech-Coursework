#include "GameWorld.h"
#include "BoundingSphere.h"
#include "ExtraBulletsPowerUp.h"
#include <stdlib.h>
#include "BoundingShape.h"

/** Constructor. */
ExtraBulletsPowerUp::ExtraBulletsPowerUp() : GameObject("ExtraBulletsPowerUp") {}

/** Construct a new ExtraBulletsPowerUp with given position, velocity, angle and rotation. */
ExtraBulletsPowerUp::ExtraBulletsPowerUp(GLVector3f p, GLVector3f v, GLfloat h, GLfloat r)
	: GameObject("ExtraBulletsPowerUp", p, v, GLVector3f(), h, r) {}

/** Copy constructor. */
ExtraBulletsPowerUp::ExtraBulletsPowerUp(const ExtraBulletsPowerUp& e) : GameObject(e) {}

/** Destructor. */
ExtraBulletsPowerUp::~ExtraBulletsPowerUp(void) {}

// PUBLIC INSTANCE METHODS ////////////////////////////////////////////////////

bool ExtraBulletsPowerUp::CollisionTest(shared_ptr<GameObject> o)
{
	if (o->GetType() != GameObjectType("Bullet")) return false;
	//if (GetType() == o->GetType()) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void ExtraBulletsPowerUp::OnCollision(const GameObjectList& objects)
{
	mWorld->FlagForRemoval(GetThisPtr());
}