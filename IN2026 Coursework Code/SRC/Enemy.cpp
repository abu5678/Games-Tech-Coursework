#include "GameUtil.h"
#include "GameWorld.h"
#include "EnemyBullet.h"
#include "Enemy.h"
#include "BoundingSphere.h"


using namespace std;

// PUBLIC INSTANCE CONSTRUCTORS ///////////////////////////////////////////////

/**  Default constructor. */
Enemy::Enemy() : GameObject("Enemy"), mThrust(0)
{
}

/** Construct a Enemy with given position, velocity, acceleration, angle, and rotation. */
Enemy::Enemy(GLVector3f p, GLVector3f v, GLVector3f a, GLfloat h, GLfloat r)
	: GameObject("Enemy", p, v, a, h, r), mThrust(0)
{
}

/** Copy constructor. */
Enemy::Enemy(const Enemy& s)
	: GameObject(s), mThrust(0)
{
}

/** Destructor. */
Enemy::~Enemy(void)
{
}

// PUBLIC INSTANCE METHODS ////////////////////////////////////////////////////

/** Update this Enemy. */
void Enemy::Update(int t)
{
	// Call parent update function
	GameObject::Update(t);
}

/** Render this Enemy. */
void Enemy::Render(void)
{
	if (mEnemyShape.get() != NULL) mEnemyShape->Render();

	// If ship is thrusting
	if ((mThrust > 0) && (mThrusterShape.get() != NULL)) {
		mThrusterShape->Render();
	}

	GameObject::Render();
}

/** Fire the rockets. */
void Enemy::Thrust(float t)
{
	mThrust = t;
	// Increase acceleration in the direction of ship
	mAcceleration.x = mThrust * cos(DEG2RAD * mAngle);
	mAcceleration.y = mThrust * sin(DEG2RAD * mAngle);
}

/** Set the rotation. */
void Enemy::Rotate(float r)
{
	mRotation = r;
}

/** Shoot a bullet. */
void Enemy::Shoot(void)
{
	// Check the world exists
	if (!mWorld) return;
	// Construct a unit length vector in the direction the Enemy is headed
	GLVector3f Enemy_heading(cos(DEG2RAD * (mAngle-90)), sin(DEG2RAD * (mAngle-90)), 0);
	Enemy_heading.normalize();
	// Calculate the point at the node of the Enemy from position and heading
	GLVector3f bullet_position = mPosition + (Enemy_heading * 4);
	// Calculate how fast the bullet should travel
	float bullet_speed = 30;
	// Construct a vector for the bullet's velocity
	GLVector3f bullet_velocity = mVelocity + Enemy_heading * bullet_speed;
	// Construct a new bullet
	shared_ptr<GameObject> bullet
	(new EnemyBullet(bullet_position, bullet_velocity, mAcceleration, mAngle, 0, 2000));
	bullet->SetBoundingShape(make_shared<BoundingSphere>(bullet->GetThisPtr(), 2.0f));
	bullet->SetShape(mBulletShape);
	// Add the new bullet to the game world
	mWorld->AddObject(bullet);

}


bool Enemy::CollisionTest(shared_ptr<GameObject> o)
{
	if (GetType() != GameObjectType("Bullet")) return false;
	if (mBoundingShape.get() == NULL) return false;
	if (o->GetBoundingShape().get() == NULL) return false;
	return mBoundingShape->CollisionTest(o->GetBoundingShape());
}

void Enemy::OnCollision(const GameObjectList& objects)
{
	mWorld->FlagForRemoval(GetThisPtr());
}
