#include <iostream>

#include "matrix_lib.hpp"
#include <math.h>
// #include <cmath>

using namespace std;
// using namespace Math;
// using Matrix;

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

    Matrix Matrix::transpose(){

      int n = 9;

      Matrix transpose;

      for(int row = 0; row < 3; row++)
      {
        for(int clm = 0; clm < 3; clm++)
        {
          int entry = clm + row*3;
          transpose.entries_[entry] = entries_[entry + (clm - row)*2];
        }
      }

      return transpose;

    }

    Matrix Matrix::inverse(){

      Matrix result;

      Matrix guassian;
      guassian.entries_ = entries_;

      int n = 3;
      vector<float> inverse;
      inverse.push_back(1);
      inverse.push_back(0);
      inverse.push_back(0);
      inverse.push_back(0);
      inverse.push_back(1);
      inverse.push_back(0);
      inverse.push_back(0);
      inverse.push_back(0);
      inverse.push_back(1);

      bool invalid = false;

      for(int row = 0; row < n; row++)
      {
        // getting the pivot. only gets the diagnonals
        float diag_focus = guassian.entries_[row + n*row];

        if( diag_focus == 0){
          for(int swap_row = row; swap_row < n; swap_row++){
            if(guassian.entries_[row + n*swap_row] != 0){
              diag_focus = guassian.entries_[row + n*swap_row];
              //switching row
              for(int clm = 0; clm < n; clm++){
                float g_swap = guassian.entries_[clm + n*row];
                guassian.entries_[clm + n*row] = guassian.entries_[clm + n*swap_row];
                guassian.entries_[clm + n*swap_row] = g_swap;

                float i_swap = inverse[clm + n*row];
                inverse[clm + n*row] = inverse[clm + n*swap_row];
                inverse[clm + n*swap_row] = i_swap;
              }
            }
            if(swap_row == n-1){

            }
          }
        }

        if (invalid == true){
          break;
        }

        // row = row/diag_focus
        // redusing the focus pivot to 1 eg [3,1,4] becomes [1,1/3,4/3]
        for (int clm = 0; clm < n; clm++)
        {
          guassian.entries_[clm + n*row] = guassian.entries_[clm + n*row]/diag_focus;
          inverse[clm + n*row] = inverse[clm + n*row]/diag_focus;
        }

        // reduce_row = reduce_row - x*row
        // reducing all entries of the column to which we got diag_focus to 0
        for (int reduce_row = 0; reduce_row < n; reduce_row++)
        {
          if (reduce_row != row)
          {
            // diagnonal pivot entry - reducing all entries of the column to 0.
            float first_entry = guassian.entries_[row + n*reduce_row];

            for(int clm = 0; clm < n; clm++)
            {
              guassian.entries_[clm + n*reduce_row] = guassian.entries_[clm + n*reduce_row] - guassian.entries_[clm + n*row]*first_entry;
              inverse[clm + n*reduce_row] = inverse[clm + n*reduce_row] - inverse[clm + n*row]*first_entry;
            }
          }
          // cout << guassian.entries_[0] << ' ' << guassian.entries_[1] << ' ' << guassian.entries_[2] << '\n' <<
          //    guassian.entries_[3] << ' ' << guassian.entries_[4] << ' ' << guassian.entries_[5] << '\n' << 
          //    guassian.entries_[6] << ' ' << guassian.entries_[7] << ' ' << guassian.entries_[8];
          // cout << '\n';
          // cout << '\n';
        }
      }


      if (!invalid){
        result.set_matrix(inverse);
      }

      return result;

    }

    Matrix Matrix::operator+(const Matrix &other){ //why cannot use the namespace Matrix:: here?

      Matrix result;

      vector<float> result_v;
      result_v.push_back(entries_[0] + other.entries_[0]);
      result_v.push_back(entries_[1] + other.entries_[1]);
      result_v.push_back(entries_[2] + other.entries_[2]);
      result_v.push_back(entries_[3] + other.entries_[3]);
      result_v.push_back(entries_[4] + other.entries_[4]);
      result_v.push_back(entries_[5] + other.entries_[5]);
      result_v.push_back(entries_[6] + other.entries_[6]);
      result_v.push_back(entries_[7] + other.entries_[7]);
      result_v.push_back(entries_[8] + other.entries_[8]);
      result.set_matrix(result_v);

      return result;

    };

    Matrix Matrix::operator - (const Matrix &other){

      Matrix result;

      vector<float> result_v;
      result_v.push_back(entries_[0] - other.entries_[0]);
      result_v.push_back(entries_[1] - other.entries_[1]);
      result_v.push_back(entries_[2] - other.entries_[2]);
      result_v.push_back(entries_[3] - other.entries_[3]);
      result_v.push_back(entries_[4] - other.entries_[4]);
      result_v.push_back(entries_[5] - other.entries_[5]);
      result_v.push_back(entries_[6] - other.entries_[6]);
      result_v.push_back(entries_[7] - other.entries_[7]);
      result_v.push_back(entries_[8] - other.entries_[8]);
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
          entry_result = entry_result + entries_[j + 3*floor(entry/3)]*other.entries_[3*j + entry % 3];
        }

        result_v.push_back(entry_result);

      }

      // the for loop is wrong above. Please fix it as soon as you are back.

      result.set_matrix(result_v);

      return result;
    }

    // Matrix Matrix::operator*(const vector<float> &entries)
    // {
    //   return 
    // }

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