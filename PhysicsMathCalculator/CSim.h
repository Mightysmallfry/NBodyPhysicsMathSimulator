#pragma once
#include "CBody.h"
#include "CVector.h"
#include "CForces.h"

#include <string>
#include <iostream>
#include <unordered_map>

namespace Comet
{

    class CSim
    {
    public:

        CSim() = default;


        std::string ToString();

        void AddBody(CBody& cbody);
        void RemoveBody(CBody& cbody);

        


    private:

        std::unordered_map<std::string, CBody> bodyRegistry_;
        

    };
}

