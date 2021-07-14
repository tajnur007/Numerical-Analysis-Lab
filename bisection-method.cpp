//Finding root using Bisection Method
#include <bits/stdc++.h>
#define FasterIO ios_base::sync_with_stdio(false);cin.tie()
#define FileIO freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout)
#define NL <<"\n"
#define f(x) (x*x)-(4*x)-10
#define E 0.0001

using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    FasterIO;
    //FileIO;
    double x0, x1, x2;
    double f0, f1, f2;
    double root;
    cout << "Enter the value of X1 and X2: ";
    cin >> x1 >> x2;

    f1 = f(x1); f2 = f(x2);
    if(f1*f2 < 0) {
        cout << "\n   x1  \t   x2  \t   x0" NL;
        while(1) {
            x0 = (x1+x2)/2;
            f0 = f(x0);

            if(f1*f0 < 0) {
                x2 = x0;
            }
            else {
                x1 = x0;
                f1 = f0;
            }

            cout <<  fixed << setprecision(4) << x1 << "\t" << x2 << "\t" << x0 NL;
            if(abs((x2-x1)/x2) < E) {
                root = (x1+x2)/2;
                cout << fixed << setprecision(4) << "\nApproximate root is: " << root NL;
                break;
            }
        }
    }


    return 0;
}

