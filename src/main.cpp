#include "vect.hpp"

void output_vector(Vector3D &vec)
{
  std::cout << vec.get_x() << ", " << vec.get_y() << ", " << vec.get_z() << std::endl; 
}

int main()
{   
    Vector3D res = intersec(Segment(Vector3D(0, 0, 0), Vector3D(11, 11, 0)), Segment(Vector3D(10, 10, 0), Vector3D(0, 10, 0)));
    output_vector(res);
    res = intersec(Segment(Vector3D(0, 0, 0), Vector3D(11, 11, 0)), Segment(Vector3D(0, 0, 0), Vector3D(11, 11, 0)));
    output_vector(res);
    return 0;
}
