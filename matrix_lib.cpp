#include <iostream>

// #include "matrix_lib.hpp"
#include <math.h>

using namespace std;
// using namespace Math;

// namespace Math{

    Matrix m;

    Matrix::Matrix(vector<float> entries){  

      set_matrix(entries);

    };

    Matrix Matrix::get_matrix(){
      
      return entries_;

    };
        
    void Matrix::set_matrix(const vector<float> entries){
      
      entries_ = entries; 

    }

    Matrix operator+(const Matrix &other){ //why cannot use the namespace Matrix:: here?

      Matrix result;

      vector<float> result_v;
      result_v.push_back(m.entries_[0] + other.entries_[0]);
      result_v.push_back(m.entries_[1] + other.entries_[1]);
      result_v.push_back(m.entries_[2] + other.entries_[2]);
      result_v.push_back(m.entries_[3] + other.entries_[3]);
      result_v.push_back(m.entries_[4] + other.entries_[4]);
      result_v.push_back(m.entries_[5] + other.entries_[5]);
      result_v.push_back(m.entries_[6] + other.entries_[6]);
      result_v.push_back(m.entries_[7] + other.entries_[7]);
      result_v.push_back(m.entries_[8] + other.entries_[8]);
      result.set_matrix(result_v);

      return result;

    };

    Matrix Matrix::operator - (const Matrix &other){

      Matrix result;

      vector<float> result_v;
      result_v.push_back(m.entries_[0] - other.entries_[0]);
      result_v.push_back(m.entries_[1] - other.entries_[1]);
      result_v.push_back(m.entries_[2] - other.entries_[2]);
      result_v.push_back(m.entries_[3] - other.entries_[3]);
      result_v.push_back(m.entries_[4] - other.entries_[4]);
      result_v.push_back(m.entries_[5] - other.entries_[5]);
      result_v.push_back(m.entries_[6] - other.entries_[6]);
      result_v.push_back(m.entries_[7] - other.entries_[7]);
      result_v.push_back(m.entries_[8] - other.entries_[8]);
      result.set_matrix(result_v);

      return result;
    }

    Matrix Matrix::operator * (const Matrix &other){

      Matrix result;

      vector<float> result_v;

      int n = sqrt(9);

      for(int entry = 0; entry < 9; entry++){

        int entry_result = 0;

        for(int j = 0; j < 3; j++){
          entry_result = entry_result + m.entries_[j + floor(entry/3)]*other.entries_[j+3];

          cout << other.entries_[j+3];
          cout << ' ';
          cout << floor(entry/3);
          cout << '\n';
        }

        // result_v[0] = entry_result;

        result_v.push_back(entry_result);

      }

      // the for loop is wrong above. Please fix it as soon as you are back.

      result.set_matrix(result_v);

      return result;
    }

    Matrix Matrix::operator = (const vector<float> entries)
    {
      set_matrix(entries);

      return *this;
    }

    Matrix Matrix::operator = (const Matrix matrix)
    {
      set_matrix(matrix.entries_);

      return *this;
    } 

    std::ostream& operator<<(std::ostream& out, const Matrix &matrix)
    {
      out << matrix.entries_[0] << ' ' << matrix.entries_[1] << ' ' << matrix.entries_[2] << '\n' <<
             matrix.entries_[3] << ' ' << matrix.entries_[4] << ' ' << matrix.entries_[5] << '\n' << 
             matrix.entries_[6] << ' ' << matrix.entries_[7] << ' ' << matrix.entries_[8];

      // TODO How about convert the abobe int oa for loop? Have a look at concatination with chars and strings.

      return out;
    }

// }