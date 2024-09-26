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

        CBody(std::string name, BodyType bodyType)
            : name_(name), bodyType_(bodyType) {}

        CBody(std::string name, BodyType bodyType, double mass)
            : name_(name), bodyType_(bodyType), mass_(mass) {}

        CBody(std::string name, BodyType bodyType, double mass, CVector position)
            : name_(name), bodyType_(bodyType), mass_(mass), position_(position) {}


        std::string ToString() const;

        bool operator==(const CBody other) const;

        inline std::string GetId() const { return name_; }


    private:

        std::string name_{ "Ophiuchus" };
        BodyType bodyType_{ BodyType::Planet };


        double mass_{ 1.0f };

        CVector position_{ZERO_VECTOR};
        CVector netForce_{ZERO_VECTOR};
    };


}
