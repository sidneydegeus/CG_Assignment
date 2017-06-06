#include "ShapeGenerator.h"
#include "Vertex.h"
#include "ShapeData.h"

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#define PI 3.14159265359
using glm::vec3;
using glm::mat4;
using glm::mat3;
#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a)

glm::vec3 randomColor()
{
	glm::vec3 ret;
	ret.x = rand() / (float)RAND_MAX;
	ret.y = rand() / (float)RAND_MAX;
	ret.z = rand() / (float)RAND_MAX;
	return ret;
}

ShapeData ShapeGenerator::makePlaneVerts(uint dimensions)
{
	ShapeData ret;
	ret.numVertices = dimensions * dimensions;
	int half = dimensions / 2;
	ret.vertices = new Vertex[ret.numVertices];
	for (int i = 0; i < dimensions; i++)
	{
		for (int j = 0; j < dimensions; j++)
		{
			Vertex& thisVert = ret.vertices[i * dimensions + j];
			thisVert.position.x = j - half;
			thisVert.position.z = i - half;
			thisVert.position.y = 0;
			thisVert.normal = glm::vec3(0.0f, 1.0f, 0.0f);
			thisVert.color = randomColor();
		}
	}
	return ret;
}

ShapeData ShapeGenerator::makePlaneIndices(uint dimensions)
{
	ShapeData ret;
	ret.numIndices = (dimensions - 1) * (dimensions - 1) * 2 * 3; // 2 triangles per square, 3 indices per triangle
	ret.indices = new unsigned short[ret.numIndices];
	int runner = 0;
	for (int row = 0; row < dimensions - 1; row++)
	{
		for (int col = 0; col < dimensions - 1; col++)
		{
			ret.indices[runner++] = dimensions * row + col;
			ret.indices[runner++] = dimensions * row + col + dimensions;
			ret.indices[runner++] = dimensions * row + col + dimensions + 1;

			ret.indices[runner++] = dimensions * row + col;
			ret.indices[runner++] = dimensions * row + col + dimensions + 1;
			ret.indices[runner++] = dimensions * row + col + 1;
		}
	}
	assert(runner = ret.numIndices);
	return ret;
}

ShapeData ShapeGenerator::makePlaneUnseamedIndices(uint tesselation)
{
	ShapeData ret;
	uint dimensions = tesselation * tesselation;
	ret.numIndices = dimensions * 2 * 3; // 2 triangles per square, 3 indices per triangle
	ret.indices = new unsigned short[ret.numIndices];
	int runner = 0;
	for (int row = 0; row < tesselation; row++)
	{
		// This code is crap but works, and I'm not in the mood right now to clean it up
		for (int col = 0; col < tesselation; col++)
		{
			// Bottom left triangle
			ret.indices[runner++] = tesselation * row + col;
			// One row down unless it's the bottom row, 
			ret.indices[runner++] = (row + 1 == tesselation ? 0 : tesselation * row + tesselation) + col;
			// Move to vert right of this one unless it's the last vert,
			// which we connect to the first vert in the row
			// the % dimensions at the end accounts for the last row hooking to the first row
			ret.indices[runner++] = (tesselation * row + col + tesselation + (col + 1 == tesselation ? -tesselation + 1 : 1)) % dimensions;

			// Upper right triangle
			ret.indices[runner++] = tesselation * row + col;
			if (col + 1 == tesselation && row + 1 == tesselation)
			{
				// Very last vert
				ret.indices[runner++] = 0;
			}
			else if (col + 1 == tesselation)
			{
				// Last vert on this row
				// Check if we need to connect it to zeroeth row or the next row
				if (row + 1 == tesselation)
				{
					// Tie to zeroeth row
					ret.indices[runner++] = col + 1;
				}
				else
				{
					// Tie to next row
					ret.indices[runner++] = tesselation * row + col + 1;
				}
			}
			else
			{
				// Regular interior vert
				// the % dimensions at the end accounts for the last row hooking to the first row
				ret.indices[runner++] = (tesselation * row + col + tesselation + 1) % dimensions;
			}
			ret.indices[runner++] = tesselation * row + col + (col + 1 == tesselation ? -col : 1);
		}
	}
	return ret;
}

ShapeData ShapeGenerator::makePlane(uint dimensions)
{
	ShapeData ret = makePlaneVerts(dimensions);
	ShapeData ret2 = makePlaneIndices(dimensions);
	ret.numIndices = ret2.numIndices;
	ret.indices = ret2.indices;
	return ret;
}