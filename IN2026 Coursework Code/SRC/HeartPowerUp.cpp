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

// PUBLIC INSTANCE METHODS ////////////////////////////////////////////////////

/** Update HeartPowerUp, removing it from game world if necessary. */
void HeartPowerUp::Update(int t)
{
	// Update position/velocity
	GameObject::Update(t);

	if (mSprite.get() == NULL) return;

}

bool HeartPowerUp::CollisionTest(shared_ptr<GameObject> o)
{
	if (o->GetType() != GameObjectType("Bullet")) return false;
	//if (GetType() == o->GetType()) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void HeartPowerUp::OnCollision(const GameObjectList& objects)
{
	mWorld->FlagForRemoval(GetThisPtr());
}