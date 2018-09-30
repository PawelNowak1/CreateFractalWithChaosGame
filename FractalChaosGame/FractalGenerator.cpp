#include "stdafx.h"
#include <iostream>
#include "FractalGenerator.h"
#include "FractalWriter.h"
#include <vector>
#include <iomanip>
#include <string>

Vertex::Vertex(int x, int y)
{
	vertex_X = x;
	vertex_Y = y;
}

int Vertex::getMiddleCoordinate(int a, char coordinate)
{
	if (coordinate == 'x')
		return (vertex_X + a) / 2;
	return (vertex_Y + a) / 2;
}

void initStringVectorWithBlackPixels(std::vector<std::string>& pixels, int blackPixel, int width, int height);

void generateWhitePixels(std::vector<std::string>& pixels, int numberOfIterations, std::vector<Vertex>& vertices, int &currentX, int &currentY, int whitePixel);

void generateFractal(const int WIDTH, const int HEIGHT, const int NUMBER_OF_ITERATIONS, int& currentX, 
	int& currentY, std::vector<Vertex>& vertices)
{
	const int BLACK_PIXEL_VALUE = 0;
	const int WHITE_PIXEL_VALUE = 1;

	std::vector<std::string> pixels;

	initStringVectorWithBlackPixels (pixels, BLACK_PIXEL_VALUE, WIDTH, HEIGHT);
	generateWhitePixels(pixels, NUMBER_OF_ITERATIONS, vertices, currentX, currentY, WHITE_PIXEL_VALUE);
	writePixelsToFile(pixels, WIDTH, HEIGHT, WHITE_PIXEL_VALUE);
}

void initStringVectorWithBlackPixels(std::vector<std::string>& pixels, int blackPixel, int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		std::string a = "";
		for (int j = 0; j < width; j++)
			a = a + std::to_string(blackPixel) + " ";
		pixels.push_back(a);
	}
}

void generateWhitePixels(std::vector<std::string>& pixels, int numberOfIterations, std::vector<Vertex>& vertices, int &currentX, int &currentY, int whitePixel)
{
	srand(time(NULL));
	int randVertex;
	int numberOfVertices = vertices.size();
	for (int i = 0; i < numberOfIterations; i++)
	{
		randVertex = std::rand() % numberOfVertices;
		currentX = vertices[randVertex].getMiddleCoordinate(currentX, 'x');
		currentY = vertices[randVertex].getMiddleCoordinate(currentY, 'y');
		pixels[currentY].replace(currentX * 2, 1, std::to_string(whitePixel));
	}
}