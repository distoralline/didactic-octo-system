#include <iostream>

struct Vector3D {
    double x, y, z;
    
    Vector3D() = default;
    Vector3D(double a, double b, double c) {
        x = a;
        y = b;
        z = c;
    }

    double& operator [](int i) {
        return ((&x)[i]);
    }

    const double& operator [](int i) const {
        return ((&x) [i]);
    }
};

int main() {
    Vector3D testVector(3.4, 5.3, 2.6);

    for (int i = 0; i < 3; i++) {
        std::cout << testVector[i] << " ";
    } std::cout << std::endl;

    return 0;
}