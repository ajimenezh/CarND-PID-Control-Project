#include "PID.h"
#include <iostream>
#include "math.h"
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double _Kp, double _Ki, double _Kd) {

    params = {_Kp, _Ki, _Kd};

    i_error = 0;
    last_cte = 0;

    dp = {0.0, 0.0, 0.0};


    for (int i=0; i<3; i++) dp[i] = params[i]/10.0;

    params[0] += dp[0];

    idx_opt = 0;

    best_err = 100.0;
}

void PID::UpdateError(double cte) {

    p_error = cte;
    d_error = (cte - last_cte);
    i_error += cte;


    last_cte = cte;

    double err = fabs(TotalError());

    if (err < best_err) {

        best_err = err;

        params[idx_opt%3] *= 1.1;
    }
    else {
        if (idx_opt < 3)
            params[idx_opt%3] -= dp[idx_opt%3];
        else
            params[idx_opt%3] += dp[idx_opt%3];

        dp[idx_opt%3] *= 0.9;
    }

    cout<<fabs(TotalError())<<endl;

    idx_opt = (idx_opt + 1)%6;

    if (idx_opt < 3)
        params[idx_opt%3] += dp[idx_opt%3];
    else
        params[idx_opt%3] -= dp[idx_opt%3];

    for (int i=0; i<3; i++) std::cout<<params[i]<<" "; std::cout<<"\n";
    for (int i=0; i<3; i++) std::cout<<dp[i]<<" "; std::cout<<"\n";



}

double PID::TotalError() {

    cout<<p_error<<" "<<d_error<<" "<<i_error<<endl;

    return - params[0]*p_error - params[1]*d_error - params[2]*i_error;

}

