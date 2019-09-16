#include <iostream>
#include <cmath>

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

    Vector3D &operator *=(float s) {
        x *= s;
        y *= s;
        z *= s;
        return (*this);
    }

    Vector3D &operator /=(float s) {
        s = 1.0 / s;
        x *= s;
        y *= s;
        z *= s;
        return (*this);
    }

    Vector3D &operator +=(const Vector3D& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return (*this);
    }

    Vector3D &operator -=(const Vector3D& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return (*this);
    }
};

inline Vector3D operator *(const Vector3D &v, float s) {
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator /(const Vector3D &v, float s) {
    s = 1.0 / s;
    return (Vector3D(v.x * s, v.y * s, v.z * s));
}

inline Vector3D operator -(const Vector3D &v) {
    return (Vector3D(-v.x, -v.y, -v.z));
}

inline float Magnitude(const Vector3D &v) {
    return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline float MagnitudeSquared(const Vector3D &v) {
    return (v.x * v.x + v.y * v.y + v.z * v.z);
}

inline Vector3D Normalize(const Vector3D &v) {
    return (v / Magnitude(v));
}

inline Vector3D operator +(const Vector3D& a, const Vector3D& b) {
    return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline Vector3D operator -(const Vector3D& a, const Vector3D& b) {
    return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}

int main() {
    Vector3D testVector(3.4, 5.3, 2.6);

    Vector3D tV2(3, 5, 2);

    for (int i = 0; i < 3; i++) {
        std::cout << testVector[i] << " ";
    } std::cout << std::endl;

    Vector3D minusVector = testVector - tV2;

    for (int i = 0; i < 3; i++) {
        std::cout << minusVector[i] << " ";
    } std::cout << std::endl;

    return 0;
}