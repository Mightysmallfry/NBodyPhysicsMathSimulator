#pragma once
#include "CBody.h"
#include "CVector.h"
#include "CForces.h"

#include <string>
#include <iostream>
#include <unordered_map>

namespace Comet
{

    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& pair) const {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };


    class CSim
    {
    public:

        CSim() = default;


        std::string ToString();

        void AddBody(CBody& cbody);
        void RemoveBody(CBody& cbody);


        //A good way of updating might be a graph/dikstra's method
        void Update();
        void UpdatePositions();
        void UpdateDistances();
        void UpdateForces();

    private:

        std::unordered_map<std::string, CBody> bodyRegistry_;

        //Uses the pair of bodies as the Id
        std::unordered_map<std::pair<CBody, CBody>, double, pair_hash> distanceRegistry_;


        //In an adjacency list, they would all be adjacent unless the distance is small enough (SOI)
        //So, have a 

    };
}

