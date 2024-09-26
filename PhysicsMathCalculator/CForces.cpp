#include "CForces.h"

#include "CConstants.h"

namespace Comet
{
    double CForces::Gravitational(CBody& bodyOne, CBody& bodyTwo)
    {
        double force = UNIVERSAL_GRAVITATIONAL_CONSTANT * bodyOne.GetMass() * bodyTwo.GetMass();
        force = force / DistanceSquared(bodyOne.GetPosition(), bodyTwo.GetPosition());

        return force;
    }
}
