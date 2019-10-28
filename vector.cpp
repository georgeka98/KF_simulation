#include <iostream>

#include "vector.hpp"
#include <math.h>
// #include <cmath>

using namespace std;
// using namespace Math;
// using Matrix;

// namespace Math{

    Vector::Vector(vector<float> entries){  

      set_vector(entries);

    };

    Vector Vector::get_vector(){
      
      return entries_;

    };
        
    void Vector::set_vector(const vector<float> entries){
      
      entries_ = entries; 

    }

    Vector Vector::operator+(const Vector &other){ //why cannot use the namespace Matrix:: here?

      Vector result;

      vector<float> result_v;
      result_v.push_back(entries_[0] + other.entries_[0]);
      result_v.push_back(entries_[1] + other.entries_[1]);
      result_v.push_back(entries_[2] + other.entries_[2]);
      result.set_vector(result_v);

      return result;

    };

    Vector Vector::operator - (const Vector &other){

      Vector result;

      vector<float> result_v;
      result_v.push_back(entries_[0] - other.entries_[0]);
      result_v.push_back(entries_[1] - other.entries_[1]);
      result_v.push_back(entries_[2] - other.entries_[2]);
      result.set_vector(result_v);

      return result;
    }

    float Vector::operator * (const Vector &other){

      Vector result;
      int dimention = result.n_;
      float dot_product = 0;

      for(int entry = 0; entry < dimention; entry++){

        dot_product += entries_[entry]*other.entries_[entry];

      }

      return dot_product;
    }

    // Matrix Matrix::operator*(const vector<float> &entries)
    // {
    //   return 
    // }

    Vector Vector::operator = (const vector<float> &entries)
    {
      set_vector(entries);

      return *this;
    }

    Vector Vector::operator=(const Vector &vector)
    {
      set_vector(vector.entries_);

      return *this;
    } 

    std::ostream& operator<<(std::ostream& out, const Vector &vector)
    {
      out << vector.entries_[0] << ' ' << vector.entries_[1] << ' ' << vector.entries_[2] << '\n';

      // TODO How about convert the abobe int oa for loop? Have a look at concatination with chars and strings.

      return out;
    }