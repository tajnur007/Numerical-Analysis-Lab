Euler Method for solving differential equation
Given a differential equation dy/dx = f(x, y) with initial condition y(x0) = y0. Find its approximate solution using Euler method.

Euler Method :
In mathematics and computational science, the Euler method (also called forward
Euler method) is a first-order numerical procedurefor solving ordinary differential
equations (ODEs) with a given initial value.
Consider a differential equation dy/dx = f(x, y) with initialcondition y(x0)=y0
then succesive approximation of this equation can be given by:

y(n+1) = y(n) + h * f(x(n), y(n))

where h = (x(n) – x(0)) / n
h indicates step size. Choosing smaller
values of h leads to more accurate results
and more computation time.



Example :


    Consider below differential equation
            dy/dx = (x + y + xy)
    with initial condition y(0) = 1 
    and step size h = 0.025.
    Find y(0.1).
   
    Solution:
    f(x, y) = (x + y + xy)
    x0 = 0, y0 = 1, h = 0.025
    Now we can calculate y1 using Euler formula
    y1 = y0 + h * f(x0, y0)
    y1 = 1 + 0.025 *(0 + 1 + 0 * 1)
    y1 = 1.025
    y(0.025) = 1.025.
    Similarly we can calculate y(0.050), y(0.075), ....y(0.1).
    y(0.1) = 1.11167
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
filter_none
edit
play_arrow

brightness_4
/* CPP  Program to find approximation 
   of a ordinary differential equation 
   using euler method.*/
#include <iostream> 
using namespace std; 
  
// Consider a differential equation 
// dy/dx=(x + y + xy) 
float func(float x, float y) 
{ 
    return (x + y + x * y); 
} 
  
// Function for Euler formula 
void euler(float x0, float y, float h, float x) 
{ 
    float temp = -0; 
  
    // Iterating till the point at which we 
    // need approximation 
    while (x0 < x) { 
        temp = y; 
        y = y + h * func(x0, y); 
        x0 = x0 + h; 
    } 
  
    // Printing approximation 
    cout << "Approximate solution at x = "
         << x << "  is  " << y << endl; 
} 
  
// Driver program 
int main() 
{ 
    // Initial Values 
    float x0 = 0; 
    float y0 = 1; 
    float h = 0.025; 
  
    // Value of x at which we need approximation 
    float x = 0.1; 
  
    euler(x0, y0, h, x); 
    return 0; 
} 

Output :
Approximate solution at x = 0.1  is  1.11167