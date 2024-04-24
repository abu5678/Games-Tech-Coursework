#ifndef __Enemy_H__
#define __Enemy_H__

#include "GameUtil.h"
#include "GameObject.h"
#include "Shape.h"

class Enemy : public GameObject
{
public:
	Enemy();
	Enemy(GLVector3f p, GLVector3f v, GLVector3f a, GLfloat h, GLfloat r);
	Enemy(const Enemy& s);
	virtual ~Enemy(void);

	virtual void Update(int t);
	virtual void Render(void);

	virtual void Thrust(float t);
	virtual void Rotate(float r);
	virtual void Shoot(void);

	void SetEnemyShape(shared_ptr<Shape> Enemy_shape) { mEnemyShape = Enemy_shape; }
	void SetThrusterShape(shared_ptr<Shape> thruster_shape) { mThrusterShape = thruster_shape; }
	void SetBulletShape(shared_ptr<Shape> bullet_shape) { mBulletShape = bullet_shape; }

	bool CollisionTest(shared_ptr<GameObject> o);
	void OnCollision(const GameObjectList& objects);

private:
	float mThrust;

	shared_ptr<Shape> mEnemyShape;
	shared_ptr<Shape> mThrusterShape;
	shared_ptr<Shape> mBulletShape;
};

#endif