//
//  Onda.cpp
//  
//
//  Created by Nicolas Felipe Vergara Duran on 26/04/18.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
using namespace std;
#define PI (3.141592653589793)
double* linspace(double in, double end, int size){
    double* vector = new double[size];
    double h=(end-in)/(size-1);
    double point=in;
    for(int i=0;i<size;i++){
        vector[i]=point;
        point+=h;
    }
    return vector;
}
void EcuacionOnda(){
    double delta_t=0.1;
    double T=40;
    double rho=10;
    double C=pow(T/rho,1/2);
    double time=200;
    double delta_x=0.1;
    double L=100;
    double k=pow((C*delta_t)/delta_x,2);
    int size_x=(L/delta_x)+1;
    int size_t=(time/delta_t)+1;
    double* x=linspace(0,L,size_x);
    double* t=linspace(0,time,size_t);
    double* Solucion_old = new double[size_x];
    double* Solucion_new = new double[size_x];
    double* Solucion_reallyOld = new double[size_x];
    //se crea la condición inicial
    
    for(int i=0; i<size_x;i++){
        if(x[i]<=0.8*L){
        Solucion_old[i]=(1.25/L)*x[i];
        Solucion_reallyOld[i]=(1.25/L)*x[i];
        cout<<t[0]<<" "<<x[i]<<" "<<Solucion_old[i]<<endl;
        }
        else{
            Solucion_old[i]=5-((5/L)*x[i]);
            Solucion_reallyOld[i]=5-((5/L)*x[i]);
            cout<<t[0]<<" "<<x[i]<<" "<<Solucion_old[i]<<endl;
        }
    }
    int i=1;
    for(int i=1;i<size_t;i++){
        for(int j=0; j<size_x;j++){
            if(j!=0 && j!=size_x-1){
                Solucion_new[j]=2*Solucion_old[j]-Solucion_reallyOld[j]+(k*(Solucion_old[j+1]-2*Solucion_old[j]+Solucion_old[j-1]));
            }
            cout<<t[i]<<" "<<x[j]<<" "<<Solucion_new[j]<<endl;
        }
        for(int j=0; j<size_x;j++){
            Solucion_reallyOld[j]=Solucion_old[j];
            Solucion_old[j]=Solucion_new[j];
        }
    }
    
}
int main(){
    EcuacionOnda();
    return 0;
}
