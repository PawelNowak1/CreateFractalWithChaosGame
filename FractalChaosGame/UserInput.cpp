#include "stdafx.h"
#include <iostream>
#include "UserInput.h"
#include "FractalGenerator.h"
#include <vector>

void getVerticesInput(std::vector<Vertex>& vertices, const int NUMBER_OF_VERTICES);

bool getExitInput();

bool getUserInput()
{
	int width, height, numberOfVertices, currentX, currentY, iterationNumber;
	
	std::cout << "Hi! Welcome to my program which enables you to\ndraw fractals using chaos game algorithm\n";
	std::cout << "Specify your data";
	
	std::cout << "\nWidth of image (in pixels): ";
	std::cin >> width;
	
	std::cout << "\nHeight of image (in pixels): ";
	std::cin >> height;

	std::cout << "\nNumber of vertices: ";
	std::cin >> numberOfVertices;

	std::cout << "\nStarting position X: ";
	std::cin >> currentX;
	
	std::cout << "\nStarting position Y: ";
	std::cin >> currentY;

	std::vector<Vertex> vertices;
	getVerticesInput(vertices, numberOfVertices);

	std::cout << "\nHow many times do you want to iterate chaos game?\n";
	std::cin >> iterationNumber;

	std::cout << "generating fractal, please wait...\n";

	generateFractal(width, height, iterationNumber, currentX, currentY, vertices);

	return getExitInput();
}

void getVerticesInput(std::vector<Vertex>& vertices, const int NUMBER_OF_VERTICES)
{
	for (int i = 0; i < NUMBER_OF_VERTICES; i++)
	{
		int x, y;
		std::cout << "\nVertex number " << i + 1 << ") X coordinate: " << std::endl;
		std::cin >> x;

		std::cout << "\nVertex number " << i + 1 << ") Y coordinate: " << std::endl;
		std::cin >> y;

		Vertex vertex(x, y);
		vertices.push_back(vertex);
	}
}

bool getExitInput()
{
	int exit;
	std::cout << "\nPress 1 to exit, pressing any other number will allow you to generate next fractal\n";
	std::cin >> exit;

	if (exit == 1)
		return false;
	return true;
}