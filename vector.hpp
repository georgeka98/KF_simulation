#include <iostream>
#include <vector>

using namespace std;

class Vector{

    public:

        Vector(vector<float> entries);

        void set_vector(const vector<float> entries);

        Vector get_vector();

        Vector operator+(const Vector &other);

        Vector operator-(const Vector &other);

        float operator*(const Vector &other); // dot product

        Vector operator=(const vector<float> &other); //storing new vector

        Vector operator=(const Vector &other); //storing Vector

        friend std::ostream& operator<<(std::ostream& out, const Vector &vector);

    public:

        Vector() : entries_({0.0,0.0,0.0}) {};

        vector<float> entries_;

        int n_ = 3; // dimention e.g 3 = 3x3 matrix
        int m_ = 9;

};