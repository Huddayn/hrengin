/*
   Copyright (C) 2014  absurdworlds

   License LGPLv3-only:
   GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
   This is free software: you are free to change and redistribute it.
   There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef _hrengin_models_
#define _hrengin_models_

#include <hrengin/common/compiler_setup.h>
#include <hrengin/common/types.h>
#include <hrengin/common/Vector3d.h>

namespace hrengin {
//! Enumeration of primitive shapes
enum Shape {
	SHAPE_EMPTY,
	SHAPE_PLANE,
	SHAPE_SPHERE,
	SHAPE_BOX,
	SHAPE_CAPSULE,
	SHAPE_CYLINDER,
	SHAPE_CONE
};

//! Axis alignment for primitive shapes
enum Axis {
	AXIS_X,
	AXIS_Y,
	AXIS_Z
};

//! Represents a geometric primitive
struct Primitive {
	Shape shape;
	Axis axis;
	f32 dimensions[3];
	f32 offset[3];
	f32 rotation[4];

	Primitive () : shape(SHAPE_EMPTY), axis(AXIS_Y), dimensions(), offset(), rotation()
	{

	}
};

struct SMesh {
	f32* verts;
};


} // namespace hrengin

#endif//_hrengin_models_