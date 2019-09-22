// A class interface for Euclidean 3-Space vector objects. Written for more
//  general case currently. Test against a specially written Vector3D class if
//  use cases for other dimensions is stagnent.

// Page 845 for parallel programming
#include <vector>

#include <iostream>

namespace dey::math {

template<typename T, int n>
class Vector {
    public:
    // Issue, assumes n greater than or equal to 3 passed to template,
    //  how to paramterize for a natural x,y or x,y,z,w, is solution to make a more
    //  awkward member extension outside of class if possible?
    //  or must a separate class be written with much code repetition.
    //  Perhaps an extension with a strange inheritence/encapsulation?
        Vector<T, n>() : components(n, 0) {
            
        }

        Vector<T, n>(const Vector<T, n> &src) = default;

        T& operator[](int i) {
            return components[i];
        }

    protected:
        std::vector<T> components;
};

template<typename T>
class Vector2D : public Vector<T, 2>{
    public:
        Vector2D<T>() :
          x{ components[0] }, y{ components[1] } {}

        Vector2D<T>(const Vector2D<T> &src) :
          Vector<T, 2>(src), x{ components[0] }, y{ components[1] } {}

        T& x;
        T& y;
};

template<typename T>
class Vector3D : public Vector<T, 3>{
    public:
        Vector3D<T>() :
          x{ components[0] }, y{ components[1] }, z{ components[2] } {}

        Vector3D<T>(const Vector3D<T> &src) :
          Vector<T, 3>(src), x{ components[0] },
          y{ components[1] }, z{ components[2] } {}


        T& x;
        T& y;
        T& z;
};

template<typename T>
class Vector4D : public Vector<T, 4>{
    public:
        Vector4D<T>() :
          x{ components[0] }, y{ components[1] },
            z{ components[2] }, w{ components[3] } {}

        Vector4D<T>(const Vector4D<T> &src) :
          Vector<T, 4>(src), x{ components[0] },
          y{ components[1] }, z{ components[2] }, w{ components[3] } {}
        
        T& x;
        T& y;
        T& z;
        T& w;
};

}; // End of namespace dey::math

int main(int argc, char** argv) {
    dey::math::Vector3D<double> testVec{};
    testVec.x = 77;
    dey::math::Vector3D<double> testCopy(testVec);

    /*
    dey::math::Vector<double, 3> testVec{};
    testVec[0] = 77;
    dey::math::Vector<double, 3> testCopy(testVec);
    */

    dey::math::Vector3D<float> testerVec{};

    testVec.y = 1;
    testVec.z = 2;

    //testVec[1] = 1;
    //testVec[2] = 2;

    testerVec.y = 1;
    testerVec.z = 2;

    testCopy.z = 7;

    //testCopy[2] = 7;

    for (int i = 0; i < 3; i++) {
        std::cout << testVec[i] << " ";
        std::cout << testCopy[i] << " ";
    } std::cout << std::endl;

    return 0;
}