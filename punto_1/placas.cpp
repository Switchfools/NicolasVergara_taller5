//
//  placas.cpp
//  
//
//  Created by Nicolas Felipe Vergara Duran on 2/05/18.
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
double** Laplace(){
    double L=5.0;
    double V_0=100;
    double N=2*pow(L/(5.0/512.0),2);
    double l=2;
    double d=1;
    int size=(L/(5.0/512.0))+1;
    double* x=linspace(-L/2,L/2,size);
    double* y=linspace(-L/2,L/2,size);
    double **Solucion_old= new double*[size];
    double** Solucion_new=new double*[size];
    //se inicializa la solucion para que se obedezca las condiciones de frontera.
    for(int i=0;i<size;i++){
        Solucion_old[i] = new double[size];
        Solucion_new[i] = new double[size];
    }
    for(int i=0; i<size;i++){
        for(int j=0;j<size;j++){
            if(i==0 || i==size-1 || j==0 || j==size-1 ){
                Solucion_old[i][j]=0;
                Solucion_new[i][j]=0;
            }
            else if((x[j]>=-l/2&&x[j]<=l/2)&&(y[i]<=(d/2)+(5.0/(512.0))&&y[i]>=(d/2)-(5.0/(512.0)))){
                Solucion_old[i][j]=V_0/2;
                Solucion_new[i][j]=V_0/2;
            }
            else if((x[j]>=-l/2&&x[j]<=l/2)&&(y[i]<=-(d/2)+(5.0/(512.0))&&y[i]>=-(d/2)-(5.0/(512.0)))){
                    Solucion_old[i][j]=-V_0/2;
                    Solucion_new[i][j]=-V_0/2;
            }
    }
   }
    for(int k=0;k<N;k++){
    for(int i=0; i<size;i++){
        for(int j=0;j<size;j++){
            if(i==0 || i==size-1 || j==0 || j==size-1 ){
                Solucion_new[i][j]=0;
            }
            else if((x[j]>=-l/2&&x[j]<=l/2)&&(y[i]<=(d/2)+(5.0/(512.0))&&y[i]>=(d/2)-(5.0/(512.0)))){
                Solucion_new[i][j]=V_0/2;
            }
            else if((x[j]>=-l/2&&x[j]<=l/2)&&(y[i]<=-(d/2)+(5.0/(512.0))&&y[i]>=-(d/2)-(5.0/(512.0)))){
                Solucion_new[i][j]=-V_0/2;
            }
            else{
            Solucion_new[i][j]=(1/4.0)*(Solucion_old[i+1][j]+Solucion_old[i-1][j]+Solucion_old[i][j+1]+Solucion_old[i][j-1]);
            Solucion_old[i][j]=Solucion_new[i][j];
            }
        }
    }
    }
    for(int i=0; i<size;i++){
        for(int j=0;j<size;j++){
            cout<<Solucion_new[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
    return Solucion_new;
}
void Campo(double **Potencial){
    double L=5.0;
    int size=(L/(5.0/512.0))+1;
    double** Campo_X=new double*[size];
    double** Campo_Y=new double*[size];
    for(int i=0;i<size;i++){
        Campo_X[i] = new double[size];
        Campo_Y[i] = new double[size];
    }
    for(int i=0; i<size;i++){
        for(int j=0;j<size;j++){
            if(i==0 || i==size-1 || j==0 || j==size-1 ){
                Campo_X[i][j]=0;
                Campo_Y[i][j]=0;
            }
            else{
                Campo_X[i][j]=-(Potencial[i+1][j]-Potencial[i-1][j])/(2*(5.0/512.0));
                Campo_Y[i][j]=-(Potencial[i][j+1]-Potencial[i][j-1])/(2*(5.0/512.0));
            }
        }
    }
    for(int i=0; i<size;i++){
        for(int j=0;j<size;j++){
            cout<<Campo_Y[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
    for(int i=0; i<size;i++){
        for(int j=0;j<size;j++){
            cout<<Campo_X[i][j]<<" ";
        }
        cout<<" "<<endl;
    }
}
int main(){
    Campo(Laplace());
    return 0;
}
