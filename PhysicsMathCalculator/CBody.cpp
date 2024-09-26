#include "CBody.h"

#include <sstream>


namespace Comet
{
    std::string CBody::ToString() const
    {
        std::stringstream ss;

        ss << "()" << name_ << "()\n";
        ss << "BodyType: " << BodyTypeToString(bodyType_)  << "\n";
        ss << "Position: " << position_.ToString() << "\n";
        ss << "NetForce: " << netForce_.ToString() << "\n";

        return ss.str();
    }
}
