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
        SnapShot();

        //Update Body positions
        UpdatePositions();

        //Update forces
        UpdateForces();

    }

    void CSim::SnapShot()
    {
        
    }

    void CSim::UpdatePositions()
    {

    }

    void CSim::UpdateDistances()
    {

    }

    void CSim::UpdateForces()
    {
        //If the force is neglible, we can just remove the relationship, without applying the force.

        //Check each relationship's gravitational force, if large enough add the force
        //Regardless remove the relationship from the distance directory afterwards.



    }
}
    