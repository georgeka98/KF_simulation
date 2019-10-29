#include <iostream>

#include "vector.hpp"
#include <math.h>
// #include <cmath>

using namespace std;
// using namespace Math;
// using Matrix;

// namespace Math{

    Vector::Vector(int size){  

      set_size(size);

    };

    void Vector::set_vector(const vector<float> entries)
    {
      entries_ = entries; 
    }

    void Vector::set_size(int size)
    {
      size_ = size;
    }

    vector<float> Vector::get_vector()
    {
      return entries_;
    };

    Vector Vector::operator+(const Vector &other){ //why cannot use the namespace Matrix:: here?

      Vector result(size_);
      vector<float> result_v;

      for(int i = 0; i < size_; i++)
      {
        result_v.push_back(entries_[i] + other.entries_[i]);
      }

      result.set_vector(result_v);

      return result;

    };

    Vector Vector::operator - (const Vector &other){

      Vector result(size_);

      vector<float> result_v;

      for(int i = 0; i < size_; i++)
      {
        result_v.push_back(entries_[i] - other.entries_[i]);
      }

      result.set_vector(result_v);

      return result;
    }

    float Vector::operator * (const Vector &other){

      Vector result(size_);
      float dot_product = 0;

      //vectors havethe same size
      if (other.size_ == size_)
      {
        int dimention = result.size_;
        float dot_product = 0;

        std::cout << dimention;

        for(int entry = 0; entry < dimention; entry++){

          dot_product += entries_[entry]*other.entries_[entry];

        }
      }

      return dot_product;
    }

    Vector Vector::operator = (const vector<float> &entries)
    {
      set_vector(entries);

      return *this;
    }

    Vector Vector::operator=(const Vector &vector)
    {
      set_vector(vector.entries_);
      set_size(vector.size_);

      return *this;
    } 

    std::ostream& operator<<(std::ostream& out, const Vector &vector)
    {
      out << vector.entries_[0] << ' ' << vector.entries_[1] << ' ' << vector.entries_[2] << '\n';

      // TODO How about convert the abobe int oa for loop? Have a look at concatination with chars and strings.

      return out;
    }