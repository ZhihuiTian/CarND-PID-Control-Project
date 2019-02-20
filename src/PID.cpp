#include "PID.h"
#include <limits>
#include <algorithm>
using namespace std;
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {
}

PID::~PID() {
}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
  // re-initalization of error terms
  p_error = 0;
  i_error = 0;
  d_error = 0;

  // assignation of PID controller gains
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  // python:
  // diff_cte = cte - prev_cte
  // prev_cte = cte
  // int_cte += cte
  d_error = cte - p_error;
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  // python: steer = -tau_p * cte - tau_d * diff_cte - tau_i * int_cte
  double totalError = -(Kp * p_error) - (Kd * d_error) - (Ki * i_error);
  if (totalError > 1) {
    totalError = 1.0;
  } else if (totalError < -1) {
    totalError = -1.0;
  }
  return totalError;  // TODO: Add your total error calc here!
}
