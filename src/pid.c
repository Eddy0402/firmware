
#include "pid.h"

float runPID(pid_context_t * p,float setpoint,float input){

    float error;
    float deriv;

    error = setpoint - input;
    //use input instead of error to avoid derivative kick
    deriv = (input - p->prev_in) / p->dt;

    p->integral += error * p->dt;

    p->prev_in = input;
    return error*p->kp + p->integral*p->ki + deriv*p->kd;
}
