//Gauss Elimination Method
#include <bits/stdc++.h>
#define FasterIO ios_base::sync_with_stdio(false);cin.tie()
#define FileIO freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout)
#define NL <<"\n"
#define E 0.0001

using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
    FasterIO;
    FileIO;

    int n,i,j,k;
    cout << "Enter the no. of equations\n";
    cin >> n;

    //Array declaration
    double a[n][n+1],x[n];

    //Getting Input
    cout << "\nEnter the elements of the augmented-matrix row-wise:\n";
    for(i=0; i<n; i++)
        for(j=0; j<=n; j++)
            cin >> a[i][j];

    //Gauss Elimination
    for(i=0; i<n-1; i++)
        for(k=i+1; k<n; k++) {
            double t = a[k][i] / a[i][i];
            for(j=0; j<=n; j++)
                a[k][j] -= (t*a[i][j]);
        }

    //Display the matrix after Gauss Elimination
    cout<<"\n\nThe matrix after gauss-elimination is as follows:\n";
    for(i=0; i<n; i++) {
        for(j=0; j<=n; j++)
            cout << a[i][j]<< "\t";
        cout << "\n";
    }

    //Back subtraction (Calculation the values of X1, X2 and X3)
    for(i=n-1; i>=0; i--) {
        x[i] = a[i][n];
        for(j=i+1; j<n; j++)
            if(j != i)
                x[i] = x[i] - (a[i][j] * x[j]);
        x[i] = x[i] / a[i][i];
    }

    //Display the values of X1, X2 and X3
    cout << "\nThe values of the variables are as follows:\n";
    for(i=0; i<n; i++)
        cout << "X" << i+1 << " = " << x[i] << "\n";


    return 0;
}



