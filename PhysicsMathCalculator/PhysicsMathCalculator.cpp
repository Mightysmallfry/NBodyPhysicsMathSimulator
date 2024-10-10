// PhysicsMathCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CConstants.h"
#include "CSim.h"

using namespace Comet;

int main()
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

    CSim LunaSystem;

    LunaSystem.AddBody(object0);
    LunaSystem.AddBody(object1);
    LunaSystem.AddBody(object2);
    LunaSystem.AddBody(object3);
    LunaSystem.AddBody(object4);
    LunaSystem.AddBody(object5);
    LunaSystem.AddBody(object6);
    LunaSystem.AddBody(object7);
    LunaSystem.AddBody(object8);

    std::cout << LunaSystem.ToString() << "\n";

    LunaSystem.RemoveBody(object3);
    LunaSystem.RemoveBody(object4);
    LunaSystem.RemoveBody(object5);

    std::cout << LunaSystem.ToString();


    
}
