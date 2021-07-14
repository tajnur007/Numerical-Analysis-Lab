Program to implement Simpson’s 3/8 rule
Write a program to implement Simpson’s 3/8 rule.

The Simpsons’s 3/8 rule was developed by Thomas Simpson. This method is used for performing numerical integrations. This method is generally used for numerical approximation of definite integrals. Here, parabolas are used to approximate each part of curve.

Simpson’s 3/8 formula :



 \int_{a}^{b} f(x) dx  =  \frac{3h}{8} (  F(a) + 3F (   \frac{2a + b}{3} )  + 3F(   \frac{a + 2b}{3} )  + F(b) ) 

Here,
h is the interval size given by h = ( b – a ) / n
n is number of intervals or interval limit

Examples :

Input : lower_limit = 1, upper_limit = 10, 
        interval_limit = 10
Output : integration_result = 0.687927


Input : lower_limit = 1, upper_limit = 5, 
        interval_limit = 3
Output : integration_result = 0.605835
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
filter_none
edit
play_arrow

brightness_4
// CPP program to implement Simpson's rule 
#include<iostream> 
using namespace std; 
  
// Given function to be integrated 
float func( float x) 
{ 
    return (1 / ( 1 + x * x )); 
} 
  
// Function to perform calculations 
float calculate(float lower_limit, float upper_limit, 
                int interval_limit ) 
{ 
    float value; 
    float interval_size = (upper_limit - lower_limit) 
                          / interval_limit; 
    float sum = func(lower_limit) + func(upper_limit); 
  
    // Calculates value till integral limit 
    for (int i = 1 ; i < interval_limit ; i++) 
    { 
        if (i % 3 == 0) 
            sum = sum + 2 * func(lower_limit + i * interval_size); 
        else
            sum = sum + 3 * func(lower_limit + i * interval_size); 
    } 
    return ( 3 * interval_size / 8 ) * sum ; 
} 
  
// Driver Code 
int main() 
{ 
    int interval_limit = 10; 
    float lower_limit = 1; 
    float upper_limit = 10; 
    float integral_res = calculate(lower_limit, upper_limit, 
                                   interval_limit); 
  
    cout << integral_res; 
    return 0; 
} 

Output :
0.687927