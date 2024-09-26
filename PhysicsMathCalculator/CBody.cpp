#include "CBody.h"

#include <sstream>


namespace Comet
{
    std::string CBody::ToString() const
    {
        std::stringstream ss;

        ss << "()" << name_ << "()\n";
        ss << "BodyType: " << BodyTypeToString(bodyType_)  << "\n";
        ss << "Mass:" << mass_ << "\n";
        ss << "Position: " << position_.ToString() << "\n";
        ss << "NetForce: " << netForce_.ToString() << "\n";

        return ss.str();
    }

    //If they're named the same then they should be the same, this means it is case sensitive
    bool CBody::operator==(const CBody other) const
    {
        return (GetId() == other.GetId());
    }
}
