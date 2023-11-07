#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double fun(double x, double y)                      // task function
{
   return 3*pow(x, 3)*y;
}

double fun_analit(double x)                        //function for calculating the analytical value
{
   double xx = 3*pow(x, 4)/4;
   return exp(xx);
}

double* El_X(double a, double b, int n)            //computing by the Euler method
{
   double h = (b-a)/n;
   auto* x= new double [n];
   x[0] = a;
   for(int i = 1; i <= n; i++){
       x[i] = a + i*h;
   }
   return x;
}

double* El_Y(double a, double b, int n, double* x)  //calculation by the Euler method
{
   double h = (b-a)/n;
   auto* y = new double [n];
   y[0] = 1;                                        // given y = 1
   for(int i = 1; i <= n; i++){
       x[i] = a + i*h;
       y[i] = y[i-1]+h*fun(x[i-1], y[i-1]);
   }
   return y;
}

void print_(double* x, double* y, int n)          //output of the table
{
   for(int i = 0; i < n; i++){
       cout << setprecision(5) << fixed << x[i] << setw(10) << y[i] <<
setw(10);
       cout << fun_analit(x[i]) << setw(10) << abs(fun_analit(x[i]) -
y[i])<< endl;
   }
}

int main()
{
   int n = 448;
   double a = 0, b = pow(4/3, 1/4);
   double* x = El_X(a, b, n);
   double* y = El_Y(a, b, n, x);
   print_(x, y, n);


   return 0;
}
