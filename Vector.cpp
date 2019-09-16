// A class interface for Euclidean 3-Space vector objects. Written for more
//  general case currently. Test against a specially written Vector3D class if
//  use cases for other dimensions is stagnent.
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
        Vector<T, n>() :
          components(n, 0), x{ components[0] }, y{ components[1] }, z{components[2]} {
            
        }

        T& operator[](int i) {
            return components[i];
        }

    private:
        std::vector<T> components;

    public:
        T& x;
        T& y;
        T& z;
        
};

using Vector3D = Vector<double, 3>;

}; // End of namespace dey::math

int main(int argc, char** argv) {
    dey::math::Vector3D testVec{};

    testVec.y = 1;
    testVec.z = 2;

    for (int i = 0; i < 3; i++) {
        std::cout << testVec[i] << " ";
    } std::cout << std::endl;

    return 0;
}