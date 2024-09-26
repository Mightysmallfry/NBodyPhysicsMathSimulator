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
        bodyRegistry_.insert(std::make_pair(cbody.GetId(), cbody));
    }

    void CSim::RemoveBody(CBody& cbody)
    {
        if (bodyRegistry_.contains(cbody.GetId()))
        {
            bodyRegistry_.erase(cbody.GetId());
        }
    }
}
    