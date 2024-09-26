#ifndef COMET_CONSTANTS_H
#define COMET_CONSTANTS_H

#include <cfloat>
#include "CVector.h"

namespace Comet
{
	class CVector;

	//--- MATH CONSTANTS
	static constexpr double TOLERANCE{DBL_EPSILON};
	static constexpr double PI{3.14159265358979323846};

	//--- PHYSICS CONSTANTS
	// Ref. Engineers' Practical Databook 1st Ed. Jay Smith
	// Ref. Nasa Planetary Fact Sheet(2023)
	

	static constexpr double EARTH_GRAVITY{9.80665}; // Standard gravity of Earth in m/s² 9.81 (32.2 ft/s²)
	static const CVector EARTH_GRAVITY_VECTOR{0.0, -EARTH_GRAVITY, 0.0};
	static constexpr double EARTH_MASS{5.9722e24}; //Mass in 10^24 kg
	static constexpr double EARTH_RADIUS{6371000}; //Radius in m


	static constexpr double SPEED_OF_LIGHT{300'000'000.0}; // Speed of light in a vacuum in m/s 299792458
	static constexpr double UNIVERSAL_GRAVITATIONAL_CONSTANT{.00000000006673};
	//Gravitational constant: 6.67384 * 10^-11 Nm^2/kg^2





	// Rigid-Body Dynamics
	static constexpr double MIN_RIGID_BODY_TWO_AREA = 0.01 * 0.01; //m^2
	static constexpr double MAX_RIGID_BODY_TWO_AREA = 64.0 * 64.0; //m^2

	// Material Density
	static constexpr double MIN_DENSITY = 500; // kg/m^3 - Lithium ~ Half of Water
	static constexpr double MAX_DENSITY = 1'000'000'000'000'000'000.0; // kg/m^3 - BlackHole

	// Celestial Body Categorization

	static constexpr double MIN_STAR_TEMPERATURE = 1'100'273.15; // kelvin
	


}
#endif // COMET_CONSTANTS_H
