#pragma once
#include <string>
#include <iostream>

class Vector3D
{
    private:
        float y;
        float x;
        float z;
    public:
        Vector3D();
        Vector3D(float x, float y, float z);
        Vector3D(const Vector3D &v);

        const float get_x();
        const float get_y();
        const float get_z();

        void set_x(float x);
        void set_y(float y);
        void set_z(float z);

        Vector3D& operator=(const Vector3D &v);
        Vector3D operator+(const Vector3D &v);
        Vector3D operator-(const Vector3D &v);
        Vector3D operator*(const float &value);
        Vector3D operator/(const float &value);
        bool operator==(const Vector3D &other);

};

class Segment
{
    public:
        Vector3D start;
        Vector3D end;

        Segment();
        Segment(Vector3D start, Vector3D end);

};

float scalar_product(Vector3D a, Vector3D b);

Vector3D intersec(Segment a, Segment b);