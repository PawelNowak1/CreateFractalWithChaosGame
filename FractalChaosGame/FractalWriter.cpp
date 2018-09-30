#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

void writePixelsToFile(std::vector<std::string>& pixels, const int WIDTH, const int HEIGHT, const int WHITE_PIXEL_VALUE)
{
	std::string filename;

	std::cout << "What would you like to name the file of the PGM image? Please include .pgm at the end of your name.\n";
	std::cin >> filename;

	std::ofstream fileOut(filename.c_str(), std::ios_base::out
		| std::ios_base::binary
		| std::ios_base::trunc
	);

	if (fileOut.is_open() && fileOut.good())
	{
		// https://en.wikipedia.org/wiki/Netpbm_format#PGM_example
		fileOut << "P2" << " " << WIDTH << " " << HEIGHT << " " << WHITE_PIXEL_VALUE << "\n";

		for (int i = 0; i < HEIGHT; i++)
		{
			fileOut << pixels[i];
			fileOut << "\n";
		}
		fileOut.close();
	}
	else
	{
		std::cout << "Something went wrong\n";
	}
}