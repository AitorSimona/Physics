#include "PhysBody3D.h"
#include "glmath.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// TODO 4: Fill in PhysBody methods. Remember to use 
// get/setOpenGLMatrix methods

// ---------------------------------------------------------
PhysBody3D::PhysBody3D(btRigidBody* body) : body(body)
{
	body->setUserPointer(this);
}

// ---------------------------------------------------------
PhysBody3D::~PhysBody3D()
{
	delete body;
}

// ---------------------------------------------------------
void PhysBody3D::GetTransform(float* matrix) const
{
	this->body->getWorldTransform().getOpenGLMatrix(matrix);
}

// ---------------------------------------------------------
void PhysBody3D::SetTransform(const float* matrix) const
{
	this->body->getWorldTransform().setFromOpenGLMatrix(matrix);
}

// ---------------------------------------------------------
void PhysBody3D::SetPos(float x, float y, float z)
{
	btTransform t = body->getWorldTransform();
	t.setOrigin(btVector3(x, y, z));
	body->setWorldTransform(t);
}
