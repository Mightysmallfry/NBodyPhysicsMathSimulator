#ifndef COMET_VECTOR_H
#define COMET_VECTOR_H

#include <iostream>
#include <string>

namespace Comet
{
    class CVector;


    //Use this function in order to get a unit vector of the parameter without changing the parameter
    CVector NormalizedVector(const CVector& vector);

    
    class CVector
    {
    public:
        double X;
        double Y;
        double Z;

        CVector();

        CVector(double x, double y);

        CVector(double x, double y, double z);

        CVector(const CVector& other);

        CVector& operator=(const CVector& other);

        CVector operator+(const CVector& other) const;
        CVector& operator+=(const CVector& other);

        CVector operator-(const CVector& other) const;
        CVector& operator-=(const CVector& other);

        CVector operator*(double scalar) const;
        friend CVector operator*(double scalar, const CVector vector);
        CVector& operator*=(double scalar);

        CVector operator/(double scalar) const;
        CVector& operator/=(double scalar);

        CVector operator-() const;
        void Reverse();

        bool operator==(const CVector& other) const;
        bool operator!=(const CVector& other) const;


        // Unary functions
        double LengthSquared() const;
        double Length() const;
        void Normalize();

        double Dot(const CVector& other) const;

        bool IsOrthogonalTo(const CVector& other) const;

        // finds a third dimension magnitude, that is equal to the shape made by the two vectors
        //TODO:Double Check Cross to see if correct input is occurring.
        CVector Cross(const CVector& other) const; //returns single double 

        std::string ToString() const;

    protected:
        double RelDiff(double a, double b) const;
    };

    static const CVector ZERO_VECTOR{0.0, 0.0, 0.0};
    static const CVector UNIT_VECTOR{1.0, 1.0, 1.0};

    //--- Free methods
    std::ostream& operator<<(std::ostream& os, const CVector& vector);

    CVector CreateVector(const CVector& start, const CVector& end);
    double DistanceSquared(const CVector& vector1, const CVector& vector2);
    double Distance(const CVector& vector1, const CVector& vector2);
}
#endif // COMET_VECTOR_H
