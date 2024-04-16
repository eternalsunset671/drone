#define _USE_MATH_DEFINES
#include <iostream>
#include <random>
#include <cmath>
#include <math.h>
#include <string>

class Vector {
private:
    double a, b, c;
public:
    Vector();
    Vector(double, double, double);
    Vector operator + (Vector); //векторная сумма
    Vector operator ^ (Vector); //векторное произведение
    double operator * (Vector);  //скалярное произведение
    Vector operator * (double);  //произведение вектора на число
    double mod();
};



Vector::Vector() {
    a = 0;
    b = 0;
    c = 0;
}

Vector::Vector(double in1, double in2, double in3) {
    a = in1;
    b = in2;
    c = in3;
}



Vector Vector :: operator + (Vector other) {
    Vector tmp;
    tmp.a = a + other.a;
    tmp.b = b + other.b;
    tmp.c = c + other.c;
    return tmp;
}

Vector Vector::operator ^ (Vector other) {
    Vector tmp;
    tmp.a = b * other.c - other.b * c;
    tmp.b = other.a * c - a * other.c;
    tmp.c = a * other.b - other.a * b;
    return tmp;
}

double Vector::operator * (Vector other) {
    double s;
    s = a * other.a + b * other.b + c * other.c;
    return s;
}

Vector Vector :: operator * (double s) {
    Vector tmp;
    tmp.a = a * s;
    tmp.b = b * s;
    tmp.c = c * s;
    return tmp;
}

double Vector::mod() {
    return sqrt(a * a + b * b + c * c);
}

class Point {
private:
    double a, b, c;
public:
    Point();
    Point(double, double, double);
    Vector operator - (Point);
    void show();
};

Point::Point() {
    a = 0;
    b = 0;
    c = 0;
}

Point::Point(double in1, double in2, double in3) {
    a = in1;
    b = in2;
    c = in3;
}

Vector Point :: operator - (Point other) {
    a = a - other.a;
    b = b - other.b;
    c = c - other.c;
    Vector tmp(a, b, c);
    return tmp;
}

void Point::show() {
    std::cout << "(" << a << "; " << b << "; " << c << ")";
}

std::string testWayPoint(Point A, Vector forvard, Vector n);

std::string testWayPoint(Point A, Vector forvard, Vector n) {
    Point O(0, 0, 0);
    Vector s;
    s = A - O;

    double fi = acos(s * forvard / (s.mod() * forvard.mod()));
    double r;
    r = s.mod();
    std::cout << " fi = " << int(fi * 180 / M_PI) << " r = " << r << " ";
    if (r < 10 && fi < M_PI / 6) {

        if ((s ^ n) * forvard < 0) {
            return "Right";
        }
        if ((s ^ n) * forvard == 0) {
            return "Ahead";
        }
        else {
            return "Left";
        }
    }
    else {
        return "REJECTED";
    }

}


int main() {
    srand(time(0));

    Vector forvard(1, 0, 0);
    Vector n(0, 0, -1);
    int i = 0;
    while (i < 100) {

        Point point(rand() % 8, rand() % 17 - 8, rand() % 16 - 8);
        point.show();
        std::cout << " " << testWayPoint(point, forvard, n) << "\n";
        i++;

    }
    return 0;
}
