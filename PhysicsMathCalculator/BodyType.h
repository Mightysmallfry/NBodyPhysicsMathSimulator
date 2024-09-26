#pragma once
#include <string>
#include <iostream>

namespace Comet
{
    enum class BodyType

    {
        Planet,
        Moon,
        Star,
        Singularity
    };


    std::string BodyTypeToString(BodyType bodyType);

    std::ostream& operator<<(std::ostream& os, BodyType bodyType);




}

