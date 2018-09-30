#pragma once
#include <vector>
#include <iostream>
#include "stdafx.h"

struct Vertex
{
	int vertex_X;
	int vertex_Y;
	Vertex(int x, int y);
	int getMiddleCoordinate(int a, char coordinate);
};

void generateFractal(const int WIDTH, const int HEIGHT, const int ITERATION_NUMBER, int& currentX, int& currentY, std::vector<Vertex>& vertices);