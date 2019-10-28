#include <iostream>
#include <vector>

using namespace std;

// namespace Math{

    class Matrix{

        public:

            Matrix(vector<float> entries);

            void set_matrix(const vector<float> entries);

            Matrix get_matrix();

            Matrix operator+(const Matrix &other);

            Matrix operator-(const Matrix &other);

            Matrix operator*(const Matrix &other);

            Matrix operator*(const vector<float> &entries); // matrix * vector

            Matrix inverse(const Matrix &other);

            Matrix transpose(); //keep in mind that traspose DOES NOT update the matrix. If you would like to update it store it on a new matrix.

            Matrix inverse();

            Matrix operator = (const vector<float> entries); // storing the entries of a given matrix as a vector format.

            Matrix operator = (const Matrix matrix); //storing the matrix

            friend std::ostream& operator<<(std::ostream& out, const Matrix &matrix);

        public:

            Matrix() : entries_({0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}) {  }
            //{0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0}
            vector<float> entries_;

    };
        
// };

