#ifndef PLANE_H
#define PLANE_H

#include "ShapeData.h"

typedef unsigned int uint;

class ShapeGenerator
{
	static ShapeData makePlaneVerts(uint dimensions);
	static ShapeData makePlaneIndices(uint dimensions);
	static ShapeData makePlaneUnseamedIndices(uint tesselation);
public:
	static ShapeData makePlane(uint dimensions = 10);
};


#endif