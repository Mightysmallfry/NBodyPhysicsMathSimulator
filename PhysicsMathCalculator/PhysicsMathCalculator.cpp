// PhysicsMathCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CConstants.h"
#include "CBody.h"

using namespace Comet;

void main()
{

    CBody objectO("Ophiuchus", 1.0, CVector(0.0 , 0.0, 1000));

    std::cout << objectO.ToString();

}
