//Finding root using Newton Raphson Method
#include <bits/stdc++.h>
#define FasterIO ios_base::sync_with_stdio(false);cin.tie()
#define FileIO freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout)
#define NL <<"\n"
#define E 0.0001
#define f(x) (x*x)-(3*x)+2
#define dxf(x) (2*x)-3

using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    FasterIO;
    //FileIO;

    double root, x = 0;
    int Count = 2;
    cout << "X1 = " << x NL;
    while(1) {
        double temp = x, y, z;
        y = f(x); z = dxf(x);
        x -= (y/z);
        cout << "X" << Count << " = "  << x NL;
        Count++;
        if(((x-temp)/x) <= E)
            break;
    }

    return 0;
}

