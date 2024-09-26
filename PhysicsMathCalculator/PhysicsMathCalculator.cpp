// PhysicsMathCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CConstants.h"
#include "CSim.h"

using namespace Comet;

void main()
{

    CBody object0("Ophiuchus", BodyType::Singularity, 100.0, CVector(0.0 , 0.0, 1000));
    CBody object1("Apophis", BodyType::Star, 10.0);
    CBody object3("Jormungandr");
    CBody object5("Quetzalcoatl");
    CBody object2("Caduceus");
    CBody object4("Asclepius");
    CBody object6("Glycon");
    CBody object7("Leviathan");
    CBody object8("Echidna", BodyType::Moon);

    CSim Genesis;

    Genesis.AddBody(object0);
    Genesis.AddBody(object1);
    Genesis.AddBody(object2);
    Genesis.AddBody(object3);
    Genesis.AddBody(object4);
    Genesis.AddBody(object5);
    Genesis.AddBody(object6);
    Genesis.AddBody(object7);
    Genesis.AddBody(object8);

    std::cout << Genesis.ToString() << "\n";


    Genesis.RemoveBody(object3);
    Genesis.RemoveBody(object4);
    Genesis.RemoveBody(object5);

    std::cout << Genesis.ToString();


    
}
