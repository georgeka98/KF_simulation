// #include "eigen-git-mirror/Eigen/Core"
// #include <iostream>

// using namespace std;
// using namespace Eigen;

// int main () {
//     cout << "Eigen version: " << EIGEN_MAJOR_VERSION << "."
//         << EIGEN_MINOR_VERSION << endl ;

//     double Dt = 0.05;

//     // Noiseless connection matrix from Current estimation state to sensor reading.
//     Matrix3f H;
//     H << 1.0, 0.0, 0.0,
//         0.0, 1.0, 0.0,
//         0.0, 0.0, 1.0;

//     Matrix3f I;
//     I << 1.0, 0.0, 0.0,
//         0.0, 1.0, 0.0,
//         0.0, 0.0, 1.0;

//     // Random enviromental uncertainty
//     MatrixXf Q(3,3);
//     Q << 0.02, 0.02, 0.02,
//         0.02, 0.02, 0.02,
//         0.02, 0.02, 0.02;

//     //Estimation covariance uncertainty matrix (assuming Guassina Distributed)
//     MatrixXf Pkk(3,3);
//     Pkk << 0.5, 0.5, 0.5,
//         0.5, 0.5, 0.5,
//         0.5, 0.5, 0.5;

//     // Sensor random error noise
//     MatrixXf R(3,3);
//     R << 0.005, 0.005, 0.005,
//         0.005, 0.005, 0.005,
//         0.005, 0.005, 0.005;

//     // transition matrix
//     MatrixXf A(3,3);
//     A << 1.0, Dt, (Dt*Dt)/2,
//         0.0, 1.0, Dt,
//         0.0, 0.0, 1.0;

//     MatrixXf A_t(3,3);
//     A << 1.0, 0.0, 0.0,
//         Dt, 1.0, 0.0,
//         (Dt*Dt)/2, Dt, 1.0;


//     Vector3f sk_1k_1(0.0,0.0,0.0);

//     while(/* TODO pod is not stationary */){
//         MatrixXf skk_1(3,3) ;
//         skk_1 = sk_1k_1 + A*sk_1k_1;

//         MatrixXf Pkk_1(3,3);
//         Pkk_1 = A*Pkk*A_t + Q;

//         //kalman gain
//         MatrixXf K(3,3);
//         K = H*Pkk_1*H.transpose()*((H*Pkk_1*H.transpose()).inverse() + R);

//         float a = 7.0;
//         Vector3f zkk_1(0.0, 0.0, a); //get measurement 

//         // Current state measurement
//         Vector3f skk(0.0,0.0,0.0);
//         skk = skk_1 + K*(zkk_1 - H*skk_1);

//         // Current state measurement uncertainty covariance.
//         MatrixXf K(3,3);
//         Pkk = (I - K*H)*Pkk_1;


//         std::cout << "next estimated state =\n" << skk_1  << std::endl;
//         std::cout << "next Estimated uncertainty =\n" << Pkk_1 << std::endl;
//         std::cout << "Kalman Gain =\n" << K << std::endl;
//         std::cout << "Current state measurement =\n" << skk << std::endl;
//         std::cout << "Current state measurement uncertainty covariance =\n" << Pkk << std::endl;
//     }

// }

// #include "matrix_lib.cpp"
#include "kalman_filter.hpp"
// #include "vector.cpp"
#include <iostream>
#include <cmath>
#include <math.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// #define M_PI;
// using namespace KalmanFilter;

int main(){

     Matrix H(3,3);
     H = {1,0,0,
          0,1,0,
          0,0,1};

     Matrix I(3,3);
     I = {1,0,0,
          0,1,0,
          0,0,1,
          0,0,0};

     Matrix A(3,3);
     A = {1, 0.5, 0.125,
          0, 1  , 0.5,
          0, 0  , 1     };

     Matrix R(3,3);
     R = {0.0051, 0.00225, 0.005431,
          0.0012, 0.0034, 0.00353,
          0.00566, 0.00541, 0.005};

     Matrix P(3,3);
     P = {0.5, 0.55, 0.5444,
          0.53, 0.41, 0.122,
          0.6, 0.3, 0.23};

     Matrix Q(3,3);
     Q = {0.021, 0.022, 0.0243,
          0.0242, 0.05322, 0.0214,
          0.0132, 0.021, 0.023};

     Vector s(3);
     s = {0,0,0};

     Vector s_p(3);
     s_p = {0,0,0};

     Vector z(3);
     z = {1.3,3.2,0.443, 0.2};

     KalmanFilter::KalmanFilter KF = KalmanFilter::KalmanFilter(3,1,0);
     KF.init(s, A, P, Q, H, R);

     std::cout << "state: \n";
     std::cout << KF.get_state();
     KF.filter(0.05,s,z);
     std::cout << "next state: \n";
     std::cout << KF.get_state();


     // srand(time(0));

    // double fx1 = ((double) rand() / (RAND_MAX));
    // double fx2 = ((double) rand() / (RAND_MAX));

    // double mu = 0.0;
    // double variance = 1.0;
    // double epsilon = std::numeric_limits<double>::epsilon();
    // double PI = M_PI;

    // if (fx1 == 0){
    //     cout << 0;
    // }

    // // cout << "random f(x): \n";
    // // cout << fx1; //((float )((int)(fx1* 10))) / 10;
    // // cout << "\nepsilon: \n";
    // // cout << epsilon;
    // // cout << '\n';

    // // while(fx1 <= epsilon){
    //     double z1;

    //     z1 = mu + variance * sqrt(-2*log(fx1)) * cos(2 * PI);

    //     cout << "random x generated: \n";
    //     cout << z1;
    // // }
    return 0;

}