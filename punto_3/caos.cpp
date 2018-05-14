//
//  caos.cpp
//
//
//  Created by Nicolas Felipe Vergara Duran on 14/05/18.
//

#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
double dp1(double t,double q1,double q2,double epsilon){
    return((-2.0)*q1*pow(pow(2*q1,2.0)+pow(epsilon,2.0),-3.0/2.0));
}
double dp2(double t,double q1,double q2,double epsilon){
    return(((q1-q2)*pow(pow(q1-q2,2.0)+pow(epsilon/2,2.0),-3.0/2.0))-((q1+q2)*pow(pow(q1+q2,2.0)+pow(epsilon/2,2.0),-3.0/2.0)));
}
double dq1(double t,double p1,double p2){
    return(p1);
}
double dq2(double t,double p1,double p2){
    return(p2);
}
void rk4(double *t, double *q1, double *q2,double *p1, double *p2, double h,double epsilon){
    double t_in, q1_in, q2_in, p1_in,p2_in;
    double kq1_1, kq1_2, kq1_3, kq1_4;
    double kq2_1, kq2_2, kq2_3, kq2_4;
    double kp1_1, kp1_2, kp1_3, kp1_4;
    double kp2_1, kp2_2, kp2_3, kp2_4;
    
    t_in = *t;
    q1_in = *q1;
    q2_in = *q2;
    p1_in = *p1;
    p2_in = *p2;
    
    kp1_1 = dp1(t_in, q1_in, q2_in,epsilon);
    kp2_1 = dp2(t_in, q1_in, q2_in,epsilon);
    kq1_1 = dq1(t_in, p1_in, p2_in);
    kq2_1 = dq2(t_in, p1_in, p2_in);
    
    kp1_2= dp1(t_in + (h/2.0), q1_in + kq1_1 * (h/2.0), q2_in+ kq2_1 * (h/2.0),epsilon);
    kp2_2= dp2(t_in + (h/2.0), q1_in + kq1_1 * (h/2.0), q2_in+ kq2_1 * (h/2.0),epsilon);
    kq1_2 = dq1(t_in + (h/2.0), p1_in + kp1_1 * (h/2.0), p2_in+ kp2_1 * (h/2.0));
    kq2_2 = dq2(t_in + (h/2.0), p1_in + kp1_1 * (h/2.0), p2_in+ kp2_1 * (h/2.0));
    
    kp1_3= dp1(t_in + (h/2.0), q1_in + kq1_2 * (h/2.0), q2_in+ kq2_2 * (h/2.0),epsilon);
    kp2_3= dp2(t_in + (h/2.0), q1_in + kq1_2 * (h/2.0), q2_in+ kq2_2 * (h/2.0),epsilon);
    kq1_3 = dq1(t_in + (h/2.0), p1_in + kp1_2 * (h/2.0), p2_in+ kp2_2 * (h/2.0));
    kq2_3 = dq2(t_in + (h/2.0), p1_in + kp1_2 * (h/2.0), p2_in+ kp2_2 * (h/2.0));
    
    kp1_4= dp1(t_in + h, q1_in + kq1_3 * h, q2_in+ + kq2_3 * h,epsilon);
    kp2_4= dp2(t_in + h, q1_in + kq1_3 * h, q2_in+ + kq2_3 * h,epsilon);
    kq1_4 = dq1(t_in + h, p1_in + kp1_3 * h, p2_in+ kp2_3 * h);
    kq2_4 = dq2(t_in + h, p1_in + kp1_3 * h, p2_in+ kp2_3 * h);
    
    t_in = t_in + h;
    q1_in = q1_in + h * (kq1_1 + 2.0*kq1_2 + 2.0*kq1_3 + kq1_4)/6.0;
    q2_in = q2_in + h * (kq2_1 + 2.0*kq2_2 + 2.0*kq2_3 + kq2_4)/6.0;
    p1_in = p1_in + h * (kp1_1 + 2.0*kp1_2 + 2.0*kp1_3 + kp1_4)/6.0;
    p2_in = p2_in + h * (kp2_1 + 2.0*kp2_2 + 2.0*kp2_3 + kp2_4)/6.0;
    
    *t = t_in;
    *p1 = p1_in;
    *p2 = p2_in;
    *q1 = q1_in;
    *q2 = q2_in;
}
int main(){
    double h=0.006;
    double epsilon=1E-3;
    double a=1.0/(2.0*pow(2.0,1.0/2.0));
    double t=0.0;
    double q1 = a;
    double q1_old=a;
    double q2 = -a;
    double p1 = 0.0;
    double p2 = 0.0;
    
    while(t<3000){
        rk4(&t, &q1, &q2, &p1, &p2,h,epsilon);
        if(q1/q1_old<0){
        cout << q2<<" "<< p2 << endl;
        }
        q1_old=q1;
        
    }
    
    return 0;
}
