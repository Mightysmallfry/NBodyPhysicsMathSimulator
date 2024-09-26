#pragma once
#include "CVector.h"

#include <iostream>
#include <string>

#include "BodyType.h"

namespace Comet
{



    class CBody
    {
    public:

        CBody() = default;

        CBody(std::string name) : name_(name) {}

        CBody(std::string name, float mass, CVector position)
            : name_(name), mass_(mass), position_(position) {}


        std::string ToString() const;

    private:

        std::string name_{ "Ophiuchus" };
        BodyType bodyType_{ BodyType::Singularity };


        double mass_{ 1.0f };

        CVector position_{ZERO_VECTOR};
        CVector netForce_{ZERO_VECTOR};
    };
}
