Program to find root of an equations using secant method
The secant method is used to find the root of an equation f(x) = 0. It is started from two distinct estimates x1 and x2 for the root. It is an iterative procedure involving linear interpolation to a root. The iteration stops if the difference between two intermediate values is less than convergence factor.

Examples :

Input : equation = x3 + x - 1 
        x1 = 0, x2 = 1, E = 0.0001
Output : Root of the given equation = 0.682326
         No. of iteration=5
Algorithm



Initialize: x1, x2, E, n         // E = convergence indicator
calculate f(x1),f(x2)

if(f(x1) * f(x2) = E); //repeat the loop until the convergence
    print 'x0' //value of the root
    print 'n' //number of iteration
}
else
    print "can not found a root in the given interval"
Recommended: Please try your approach on {IDE} first, before moving on to the solution.
filter_none
edit
play_arrow

brightness_4
// C++ Program to find root of an  
// equations using secant method 
#include <bits/stdc++.h> 
using namespace std; 
// function takes value of x and returns f(x) 
float f(float x) 
{ 
    // we are taking equation as x^3+x-1 
    float f = pow(x, 3) + x - 1; 
    return f; 
} 
  
void secant(float x1, float x2, float E) 
{ 
    float n = 0, xm, x0, c; 
    if (f(x1) * f(x2) < 0) { 
        do { 
            // calculate the intermediate value 
            x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1)); 
  
            // check if x0 is root of equation or not 
            c = f(x1) * f(x0); 
  
            // update the value of interval 
            x1 = x2; 
            x2 = x0; 
  
            // update number of iteration 
            n++; 
  
            // if x0 is the root of equation then break the loop 
            if (c == 0) 
                break; 
            xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1)); 
        } while (fabs(xm - x0) >= E); // repeat the loop 
                                // until the convergence 
  
        cout << "Root of the given equation=" << x0 << endl; 
        cout << "No. of iterations = " << n << endl; 
    } else
        cout << "Can not find a root in the given inteval"; 
} 
  
// Driver code 
int main() 
{ 
    // initializing the values 
    float x1 = 0, x2 = 1, E = 0.0001; 
    secant(x1, x2, E); 
    return 0; 
} 

Output :
Root of the given equation = 0.682326
No. of iterations = 5