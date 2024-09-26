#include "CVector.h"

#include <cmath>
#include <sstream>
#include <stdexcept>

#include "CConstants.h"


namespace Comet
{
  CVector::CVector()
    : X(0.0), Y(0.0), Z(0.0) {}

  CVector::CVector(const double x, const double y)
    : X(x), Y(y), Z(0.0) {}

  CVector::CVector(const double x, const double y, const double z)
    : X(x), Y(y), Z(z) {}

  // copy-constructor
  CVector::CVector(const CVector& other)
  {
    X = other.X;
    Y = other.Y;
    Z = other.Z;
  }

  // copy-assignment
  CVector& CVector::operator=(const CVector& other)
  {
    if (this != &other) // prevent self-assignment
    {
      X = other.X;
      Y = other.Y;
      Z = other.Z;
    }
    return *this;
  }

  // Add two vectors.
  CVector CVector::operator+(const CVector& other) const
  {
    return {(X + other.X), (Y + other.Y), (Z + other.Z)};
  }

  // Add two vectors.
  CVector& CVector::operator+=(const CVector& other)
  {
    X += other.X;
    Y += other.Y;
    Z += other.Z;
    return *this;
  }

  // Subtract two vectors.
  CVector CVector::operator-(const CVector& other) const
  {
    return {(X - other.X), (Y - other.Y), (Z - other.Z)};
  }

  // Subtract two vectors.
  CVector& CVector::operator-=(const CVector& other)
  {
    X -= other.X;
    Y -= other.Y;
    Z -= other.Z;
    return *this;
  }

  // Multiply a vector by a scalar.
  CVector CVector::operator*(const double scalar) const
  {
    return {(X * scalar), (Y * scalar), (Z * scalar)};
  }

  // Multiply a vector by a scalar.
  CVector& CVector::operator*=(const double scalar)
  {
    X *= scalar;
    Y *= scalar;
    Z *= scalar;
    return *this;
  }

  // Divide a vector by a scalar.
  CVector CVector::operator/(const double scalar) const
  {
    if (scalar == 0.0)
      throw (std::logic_error("Divide by zero."));

    return {(X / scalar), (Y / scalar), (Z / scalar)};
  }

  // Divide a vector by a scalar.
  CVector& CVector::operator/=(const double scalar)
  {
    if (scalar == 0.0f)
      throw std::logic_error("Divide by zero.");

    X /= scalar;
    Y /= scalar;
    Z /= scalar;
    return *this;
  }

  // Reverse the vector direction.
  CVector CVector::operator-() const
  {
    return {-X, -Y, -Z};
  }

  // Reverse the vector direction.
  void CVector::Reverse()
  {
    X = -X;
    Y = -Y;
    Z = -Z;
  }

  // Near-equal a.k.a. fuzzy equality 
  bool CVector::operator==(const CVector& other) const
  {
    return (
      (RelDiff(X, other.X) < TOLERANCE) &&
      (RelDiff(Y, other.Y) < TOLERANCE) &&
      (RelDiff(Z, other.Z) < TOLERANCE));
  }

  bool CVector::operator!=(const CVector& other) const
  {
    return !operator==(other);
  }

  // Returns the squared magnitude or length of a vector.
  double CVector::LengthSquared() const
  {
    return X * X + Y * Y + Z * Z;
  }

  // Returns the magnitude or length of a vector.
  double CVector::Length() const
  {
    return std::sqrt(X * X + Y * Y + Z * Z);
  }

  // Turns a vector into a unit vector.
  // Divides each component by the vector magnitude.
  void CVector::Normalize()
  {
    double magnitude = Length();

    if (magnitude <= TOLERANCE)
      magnitude = 1.0;

    X /= magnitude;
    Y /= magnitude;
    Z /= magnitude;
  }

CVector NormalizedVector(const CVector& vector)
  {
      CVector normalizedVector = vector;
      normalizedVector.Normalize();
      return normalizedVector;
  }

  // Vector Dot Product - operator*
  double CVector::Dot(const CVector& other) const
  {
    return (X * other.X) + (Y * other.Y) + (Z * other.Z);
  }

  bool CVector::IsOrthogonalTo(const CVector& other) const
  {
      return this->Dot(other) == 0;
  }

  // Vector Cross Product - operator^
  CVector CVector::Cross(const CVector& other) const
  {
    return {
      (Y * other.Z - Z * other.Y),
      (Z * other.X - X * other.Z),
      (X * other.Y - Y * other.X)
    };
  }

  // Return a string with a vector formatted as (X, Y, Z)
  std::string CVector::ToString() const
  {
    std::stringstream ss;

    ss << "[" << X << ", " << Y << ", " << Z << "]";
    return ss.str();
  }

  //========================================================================
  // FREE METHODS - Do not belong to a class per se.

  // Inserts a formatted vector into an output stream.
  std::ostream& operator<<(std::ostream& os, const CVector& vector)
  {
    os << "Vector: " << vector.ToString();
    return os;
  }

  // Creates a vector based on two points, from start to end.
  CVector CreateVector(const CVector& start, const CVector& end)
  {
    return end - start;
  }

  // Returns the squared distance between two points.
  double DistanceSquared(const CVector& vector1, const CVector& vector2)
  {
    const double dx = vector1.X - vector2.X;
    const double dy = vector1.Y - vector2.Y;
    const double dz = vector1.Z - vector2.Z;
    return (dx * dx) + (dy * dy) + (dz * dz);
  }

  // Returns the distance between two points.
  double Distance(const CVector& vector1, const CVector& vector2)
  {
    const double dx = vector1.X - vector2.X;
    const double dy = vector1.Y - vector2.Y;
    const double dz = vector1.Z - vector2.Z;
    return std::sqrt((dx * dx) + (dy * dy) + (dz * dz));
  }

  //========================================================================
  // PROTECTED METHODS

  // Relative Difference
  // Used to determine floating-point 'fuzzy' equality.
  // Use: if RelDiff(a, b) < TOLERANCE...
  // Ref. Knuth Sec. 4.2.2 pp. 217-8 
  double CVector::RelDiff(const double a, const double b) const
  {
    const double diff = std::max(std::abs(a), std::abs(b));
    return (diff == 0.0 ? 0.0 : std::abs(a - b) / diff);
  }

  CVector operator*(double scalar, const CVector vector)
  {
      return vector * scalar;
  }
}
