#pragma once
#include "CBody.h"
#include "CVector.h"
#include "CForces.h"
#include "CConstants.h"

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
        void SnapShot();
        void UpdatePositions();
        void UpdateDistances();
        void UpdateForces();

    private:

        double simStart{ 0.0 };
        double deltaTime{ 1.0 };
        double simDuration{ 20.0 };



        std::unordered_map<std::string, CBody> bodyRegistry_;

        //Uses the pair of bodies as the Id
        std::unordered_map<std::pair<CBody, CBody>, double, pair_hash> distanceRegistry_;


    };
}

