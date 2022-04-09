#include "vector.h"

#include <iostream>
#include <sstream>
#include <cassert>
#include <cmath>

using std::cout;
using std::endl;
using std::stringstream;

// A Function to test if two doubles are "equal"
bool DoubleEquals(double a, double b, double epsilon = 1e-6);

int main(int argc, char* argv[]) {
    // Testing empty vector (Comment to test card vec_6
    Vector a(0);
    assert(!a.IsValid());
    cout << "Is Valid passed" << endl;

    // Testing a vector in 2D (Comment to test card vec_6
    Vector b(2);
    assert(b.Dimensions() == 2);

    // ---------------------------------------
    // Why do we need to use this function????
    // DoubleEquals(a,b)
    // Testing default setting of components of 2D Vector
    // Testing operator[] overload
    assert(DoubleEquals(b[0], 0.0));
    assert(DoubleEquals(b[1], 0.0));
//    assert(b[0] == 0.0);
//    assert(b[1] == 0.0);
    // Testing write-to operator[] overload
    b[0] = 1.5;
    b[1] = -1.5;
    assert(DoubleEquals(b[0], 1.5));
    assert(DoubleEquals(b[1], -1.5));
//    assert(b[0] == 1.5);
//    assert(b[1] == -1.5);
    // Testing IO with streams
    // It would be nice to overload << and >>
    stringstream stream;
    b.Write(stream);
    assert(stream.str() == "2 1.5 -1.5");
    stream.clear();
    stream.str("2 4.0 0.0");
    b.Read(stream);
    assert(b.Dimensions() == 2);
    assert(DoubleEquals(b[0], 4.0));
    assert(DoubleEquals(b[1], 0.0));
//    assert(b[0] == 4.0);
//    assert(b[1] == 0.0);
    stream.clear();

    // Testing constructors that take in an array
    double data1[] = {1, 2, 3};
    double data2[] = {-1, 2, 1};
    Vector c(3, data1);
    assert(c.Dimensions() == 3);
    assert(DoubleEquals(c[0], 1.0));
    assert(DoubleEquals(c[1], 2.0));
    assert(DoubleEquals(c[2], 3.0));
//    assert(c[0] == 1.0);
//    assert(c[1] == 2.0);
//    assert(c[2] == 3.0);

    Vector d(3, data2);
    assert(d.Dimensions() == 3);
    assert(DoubleEquals(d[0], -1.0));
    assert(DoubleEquals(d[1], 2.0));
    assert(DoubleEquals(d[2], 1.0));
//    assert(d[0] == -1.0);
//    assert(d[1] == 2.0);
//    assert(d[2] == 1.0);

    Vector e(d);
    assert(e.Dimensions() == 3);
    assert(DoubleEquals(e[0], -1.0));
    assert(DoubleEquals(e[1], 2.0));
    assert(DoubleEquals(e[2], 1.0));
//    assert(e[0] == -1.0);
//    assert(e[1] == 2.0);
//    assert(e[2] == 1.0);

    assert(e == d);
    assert(e != c);

    Vector f(0);
    f = c;
    assert(f.Dimensions() == 3);
    assert(DoubleEquals(f[0], 1.0));
    assert(DoubleEquals(f[1], 2.0));
    assert(DoubleEquals(f[2], 3.0));
//    assert(f[0] == 1.0);
//    assert(f[1] == 2.0);
//    assert(f[2] == 3.0);

    Vector g(3);
    Vector h(3);
    Vector i(3);
    g[0] = 2.5;
    g[1] = 1.2;
    g[2] = 0.0;
    h[0] = -0.5;
    h[1] = 0.3;
    h[2] = 4.0;
    i = g + h;
    assert(i.IsValid());
    assert(DoubleEquals(i[0], 2.0));
    assert(DoubleEquals(i[1], 1.5));
    assert(DoubleEquals(i[2], 4.0));
//    assert(i[0] == 2.0);
//    assert(i[1] == 1.5);
//    assert(i[2] == 4.0);

    i = g - h;
    assert(i.IsValid());
    assert(DoubleEquals(i[0], 3.0));
    assert(DoubleEquals(i[1], 0.9));
    assert(DoubleEquals(i[2], -4.0));
//    assert(i[0] == 3.0);
//    assert(i[1] == 0.9);
//    assert(i[2] == -4.0);

    DoubleEquals(g.EuclidianDistance(h), sqrt(25.81));
    DoubleEquals(g.EuclidianDistance(g), 0);
//    assert(g.EuclidianDistance(h) == sqrt(25.81));
//    assert(g.EuclidianDistance(g) == 0);


    // Testing operator-()const
    double signFlipData1[] = {2, 4, 6, 8};
    double signFlipData2[] = {4, 6, 5, 4};
    double signFlipData3[] = {10, 2, 7, 4};
    Vector testerSignFlip1(4, signFlipData1);
    Vector flippedSign1 = -testerSignFlip1;
    assert((flippedSign1[0] == -2) && (flippedSign1[1] == -4) && (flippedSign1[2] == -6) && (flippedSign1[3] == -8));

    Vector testerSignFlip2(4, signFlipData2);
    Vector flippedSign2 = -testerSignFlip2;
    assert((flippedSign2[0] == -4) && (flippedSign2[1] == -6) && (flippedSign2[2] == -5) && (flippedSign2[3] == -4));

    Vector testerSignFlip3(4, signFlipData3);
    Vector flippedSign3 = -testerSignFlip3;
    assert((flippedSign3[0] == -10) && (flippedSign3[1] == -2) && (flippedSign3[2] == -7) && (flippedSign3[3] == -4));

    // Testing operator*()const
    double multiData1[] = {2, 4, 6, 8};
    double multiData2[] = {4, 6, 5, 4};
    double multiData3[] = {10, 2, 7, 4};
    Vector multiTester1(4, multiData1);
    Vector multiTransf1 = multiTester1 * 3;
    assert((multiTransf1[0] == 6) && (multiTransf1[1] == 12) && (multiTransf1[2] == 18) && (multiTransf1[3] == 24));

    Vector multiTester2(4, multiData2);
    Vector multiTransf2 = multiTester2 * 3;
    assert((multiTransf2[0] == 12) && (multiTransf2[1] == 18) && (multiTransf2[2] == 15) && (multiTransf2[3] == 12));

    Vector multiTester3(4, multiData3);
    Vector multiTransf3 = multiTester3 * 4;
    assert((multiTransf3[0] == 40) && (multiTransf3[1] == 8) && (multiTransf3[2] == 28) && (multiTransf3[3] == 16));



    cout << "All unit tests passed" << endl;

    return 0;
}
bool DoubleEquals(double a, double b, double epsilon){
    return abs(a - b) < epsilon;
}
