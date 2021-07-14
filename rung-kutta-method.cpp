Runge-Kutta 4th Order Method to Solve Differential Equation
Given following inputs,

An ordinary differential equation that defines value of dy/dx in the form x and y.
Initial value of y, i.e., y(0)
Thus we are given below.


 \frac{\mathrm{dx} }{\mathrm{d} y} = f(x, y),y(0)= y_o 

The task is to find value of unknown function y at a given point x.



The Runge-Kutta method finds approximate value of y for a given x. Only first order ordinary differential equations can be solved by using the Runge Kutta 4th order method.

Below is the formula used to compute next value yn+1 from previous value yn. The value of n are 0, 1, 2, 3, ….(x – x0)/h. Here h is step height and xn+1 = x0 + h

. Lower step size means more accuracy.

  K_1 = hf(x_n, y_n)  K_2 = hf(x_n+\frac{h}{2}, y_n+\frac{k_1}{2})  K_3 = hf(x_n+\frac{h}{2}, y_n+\frac{k_2}{2})  K_4 = hf(x_n+h, y_n+k_3)  y_n_+_1 = y_n + k_1/6 + k_2/3 + k_3/3 + k_4/6 + O(h^{5})  
The formula basically computes next value yn+1 using current yn plus weighted average of four increments.

k1 is the increment based on the slope at the beginning of the interval, using y
k2 is the increment based on the slope at the midpoint of the interval, using y + hk1/2.
k3 is again the increment based on the slope at the midpoint, using using y + hk2/2.
k4 is the increment based on the slope at the end of the interval, using y + hk3.
The method is a fourth-order method, meaning that the local truncation error is on the order of O(h5), while the total accumulated error is order O(h4).

Source: https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods

Below is implementation for the above formula.
filter_none
edit
play_arrow

brightness_4
// C program to implement Runge Kutta method 
#include<stdio.h> 
  
// A sample differential equation "dy/dx = (x - y)/2" 
float dydx(float x, float y) 
{ 
    return((x - y)/2); 
} 
  
// Finds value of y for a given x using step size h 
// and initial value y0 at x0. 
float rungeKutta(float x0, float y0, float x, float h) 
{ 
    // Count number of iterations using step size or 
    // step height h 
    int n = (int)((x - x0) / h); 
  
    float k1, k2, k3, k4, k5; 
  
    // Iterate for number of iterations 
    float y = y0; 
    for (int i=1; i<=n; i++) 
    { 
        // Apply Runge Kutta Formulas to find 
        // next value of y 
        k1 = h*dydx(x0, y); 
        k2 = h*dydx(x0 + 0.5*h, y + 0.5*k1); 
        k3 = h*dydx(x0 + 0.5*h, y + 0.5*k2); 
        k4 = h*dydx(x0 + h, y + k3); 
  
        // Update next value of y 
        y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);; 
  
        // Update next value of x 
        x0 = x0 + h; 
    } 
  
    return y; 
} 
  
// Driver method 
int main() 
{ 
    float x0 = 0, y = 1, x = 2, h = 0.2; 
    printf("\nThe value of y at x is : %f", 
            rungeKutta(x0, y, x, h)); 
    return 0; 
} 
Output:

The value of y at x is : 1.103639