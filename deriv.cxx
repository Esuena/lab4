#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx, const double xmin){
   for(int i=0; i<N; i++)
    cout << i*dx + xmin << "\t" << p[i] << endl;     
}

void exp(double* p, const int N, const double dx, const double xmin){
  for(int i=0; i<N; i++)
    p[i]=exp(-pow(i*dx+xmin,2));
}

void derivative(double* p, const int N, const double dx, const double xmin){
  double a;//Puffer
  double b=p[0];
  p[0]=p[1]/(2*dx);//lower boundary
  for(int i=1; i<(N-1); i++){
    a=p[i];
    p[i]=(p[i+1]-b)/(2*dx);//problem: in dem wert p[i-1] steht schon die vorherige Ableitung drin!
    b=a; //b wird der aktuelle Wert von a zugewiesen!
  }
    p[N-1]=-p[N-2]/(2*dx);//upper boundary
}
  

int main(){
  const int N = 100;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);

  // call to function which fills array p here
  exp(p,N,dx,xmin);
  // call to function which calculates the derivative
  derivative(p,N,dx,xmin);
  
  print(p,N,dx,xmin);

  return 0;
}
