#include <iostream>
#include "kalman_filter.hpp"
// #include "matrix_lib.hpp"

namespace KalmanFilter{

    void KalmanFilter::init(Vector x, Matrix A, Matrix P, Matrix Q, Matrix H, Matrix R){
        x_ = x;
        A_ = A;
        P_ = P;
        Q_ = Q;
        H_ = H;
        R_ = R;
        I_ = {  1,0,0,
                0,1,0,
                0,0,1};
    }

    KalmanFilter::KalmanFilter(uint8_t n, uint8_t m, uint8_t k)
        : n_(n)
        , m_(m)
        , k_(0){
    }

    void KalmanFilter::set_initial(Vector init){
        x_ =  init;
    }

    Vector KalmanFilter::get_state(){
        return x_;
    }

    Matrix KalmanFilter::get_covariance(){
        return P_;
    }

    Vector KalmanFilter::get_measurement(){

        return z_;
    }

    void KalmanFilter::update_sensor_noise(Matrix R){

        //some sort of calclulation takes place here.

        R_ = R;
    }

    void KalmanFilter::filter(float dt, Vector s, Vector z){
        KalmanFilter::update_state_transition(dt);

        KalmanFilter::predict_state();
        KalmanFilter::predict_covariance();

        Matrix K = KalmanFilter::kalman_gain();

        // KalmanFilter::get_data(); // manipulate sensor data and set measurement vector

        KalmanFilter::estimate_state(K,z);
        KalmanFilter::estimate_covariance(K);
    }

    void KalmanFilter::predict_state(){
        x_ = A_ * x_;
    }

    void KalmanFilter::predict_covariance(){
        P_ = A_ * P_ * A_.transpose() + Q_;
    }

    Matrix KalmanFilter::kalman_gain(){
        Matrix K = (P_ * H_.transpose()) * (H_ * P_ * H_.transpose() + R_).inverse();
        return K;
    }

    void KalmanFilter::estimate_state(Matrix K, Vector z){
        x_ = x_ + K * (z - H_ * x_);
    }

    void KalmanFilter::estimate_covariance(Matrix K){
        P_ = (I_ - K * H_) * P_;
    }

    void KalmanFilter::update_state_transition(float dt){
        Matrix A;

        // for(int i = 0; i < n_; i++){

        // }
        A = {1.0, dt, (dt*dt)/2,
            0.0, 1.0, dt,
            0.0, 0.0, 1.0};

        // A_ = A;
        A_ = A;
    }

    // VectorXf KalmanFilter::get_data(){

    //     Eigen::Vector3f z(0.0,0.0,0.0); // placeholder

    //     // read data from sensor
    //     // manipulate data - make any calculations needed
    //     // store data in a VectorXf format

    //     // output data
    //     set_measurement(z);

    //     return z;
    // }

    void KalmanFilter::set_measurement(Vector z){
        z_ = z;
    }

}




// #endif  // KALMAN_FILTER_HPP