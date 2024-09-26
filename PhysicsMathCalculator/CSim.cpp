#include "CSim.h"
#include <sstream>


namespace Comet
{
    std::string CSim::ToString()
    {
        std::stringstream ss;

        ss << "==== Sim Registry =====\n";

        for (std::pair<std::string, CBody> entry : bodyRegistry_)
        {
            ss << entry.second.ToString() << "\n";
        }

        return ss.str();
    }

    void CSim::AddBody(CBody& cbody)
    {
        bodyRegistry_.insert({ cbody.GetId(), cbody });
    }

    void CSim::RemoveBody(CBody& cbody)
    {
        if (bodyRegistry_.contains(cbody.GetId()))
        {
            bodyRegistry_.erase(cbody.GetId());
        }
    }

    void CSim::Update()
    {
        //Update Body positions
        UpdatePositions();

        //Update the distances between bodies
        UpdateDistances();

        //Update forces
        UpdateForces();
    }

    void CSim::UpdatePositions()
    {

    }

    void CSim::UpdateDistances()
    {
        for (std::pair<std::string, CBody> bodyOne : bodyRegistry_)
        {
            for (std::pair<std::string, CBody> bodyTwo : bodyRegistry_)
            {
                if (bodyOne.second != bodyTwo.second && !distanceRegistry_.contains(std::make_pair(bodyOne.second, bodyTwo.second))
                    && !distanceRegistry_.contains(std::make_pair(bodyTwo.second, bodyOne.second)))
                {
                    double distanceBetweenBodies = Distance(bodyOne.second.GetPosition(), bodyTwo.second.GetPosition());
                    distanceRegistry_.insert({ { bodyOne.second, bodyTwo.second }, distanceBetweenBodies });
                }
            }
        }


    }

    void CSim::UpdateForces()
    {



    }
}
    