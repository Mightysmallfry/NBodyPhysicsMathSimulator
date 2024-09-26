#include "BodyType.h"


namespace Comet
{
    std::string BodyTypeToString(BodyType bodyType)
    {
        switch (bodyType)
        {
        case BodyType::Planet:
            return "Planet";
        case BodyType::Moon:
            return "Moon:";
        case BodyType::Star:
            return "Star";
        case BodyType::Singularity:
            return "Singularity";
        }
    }

    std::ostream& operator<<(std::ostream& os, BodyType bodyType) {
        switch (bodyType)
        {
        case BodyType::Planet:
            return os << "Planet";
        case BodyType::Moon: return os << "Moon:";
        case BodyType::Star:
            return os << "Star";
        case BodyType::Singularity:
            return os << "Singularity";
        }
    }
}
