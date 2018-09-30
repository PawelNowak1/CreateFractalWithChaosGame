// FractalChaosGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UserInput.h"
#include <iostream>

int main()
{
	bool applicationStatus = true;

	while (applicationStatus)
	{
		applicationStatus = getUserInput();
	}

	return 0;
}