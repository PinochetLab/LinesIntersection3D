#include "vect.hpp"

Vector3D::Vector3D(){}
Vector3D::Vector3D(float x, float y, float z):x(x), y(y), z(z){}
Vector3D::Vector3D(const Vector3D &v): x(v.x), y(v.y), z(v.z){}

const float Vector3D::get_x(){return x;}
const float Vector3D::get_y(){return y;}
const float Vector3D::get_z(){return z;}

void Vector3D::set_x(float x){this->x = x;}
void Vector3D::set_y(float y){this->y = y;}
void Vector3D::set_z(float z){this->z = z;}

Vector3D& Vector3D::operator=(const Vector3D &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D &v)
{
    return Vector3D(x+v.x, y+v.y, z+v.z);
}

Vector3D Vector3D::operator-(const Vector3D &v)
{
    return Vector3D(x-v.x, y-v.y, z-v.z);
}

Vector3D Vector3D::operator*(const float &value)
{
    return Vector3D(x*value, y*value, z*value);
}

Vector3D Vector3D::operator/(const float &value)
{
    return Vector3D(x/value, y/value, z/value);
}

bool Vector3D::operator==(const Vector3D &other)
{
    return (this->get_x() == other.x && this->get_y() == other.y && this->get_z() == other.z);
}

Segment::Segment(){};
Segment::Segment(Vector3D start, Vector3D end): start(start), end(end){}

float scalar_product(Vector3D a, Vector3D b)
{
    return (a.get_x()*b.get_x() + a.get_y()*b.get_y() + a.get_z()*b.get_z());
}

Vector3D intersec(Segment a, Segment b)
{
    Segment seg;
    float t1 = 0, t2 = 0, t = 0;
    t1+= scalar_product(a.start-b.start, b.end-b.start)*scalar_product(b.end-b.start, a.end-a.start);
    t1-= scalar_product(a.start-b.start, a.end-a.start)*scalar_product(b.end-b.start, b.end-b.start);
    t2+= scalar_product(a.end-a.start, a.end-a.start)*scalar_product(b.end-b.start, b.end-b.start);
    t2-= scalar_product(a.end-a.start, b.end-b.start)*scalar_product(b.end-b.start, a.end-a.start);
    t = t1/t2;
//    std::cout<< t1 << " " << t2 << std::endl;
    
    float u1 = 0, u2 = 0;
    u1+= (scalar_product(a.start-b.start, b.end-b.start));
    u1+= t*scalar_product(a.end-a.start, b.end-b.start);
    u2 = scalar_product(b.end-b.start, b.end-b.start);
//    std::cout<< u1 << " " << u2 << std::endl;
    
    seg.end = a.start + (a.end - a.start)*t;
    seg.start = b.start + (b.end - b.start)*u1/u2;
    Vector3D tmp = seg.end - seg.start;
    Vector3D close_point = (seg.end + seg.start) / 2;

    try
    {
        if (t2 == 0 || u2 == 0)
            throw std::string("input segments are the same");
        if (scalar_product(close_point - a.start, a.end - a.start) < 0 ||
            scalar_product(close_point - a.end, a.start - a.end) < 0)
            throw std::string("point outside first segment bound");
        if (scalar_product(close_point - b.start, b.end - b.start) < 0 ||
            scalar_product(close_point - b.end, b.start - b.end) < 0)
            throw std::string("point outside second segment boundaries");
        if ((scalar_product(tmp, tmp) - 0.001) > 0)
            throw std::string("no intersection point");
    }
    catch(const std::string& ex)
    {
        std::cerr << ex << '\n';
        exit(1);
    }
    
    return close_point;
}

