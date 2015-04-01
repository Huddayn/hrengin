/*
 * Copyright (C) 2014  absurdworlds
 *
 * License LGPLv3-only:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef _hrengin_CollisionObject_
#define _hrengin_CollisionObject_

#include <btBulletDynamicsCommon.h>
#include <btBulletCollisionCommon.h>

#include <hrengin/physics/CollisionObject.h>

namespace hrengin {
namespace physics {

// internal implementation details

class CollisionObject::Details {
public:
	Details(btCollisionObject* Object) : obj(Object)
	{

	}
	Details(btRigidBody* Body) : obj(Body)
	{

	}

	btCollisionObject* obj;

};


} // namespace physics
} // namespace hrengin
#endif//_hrengin_CollisionObject_