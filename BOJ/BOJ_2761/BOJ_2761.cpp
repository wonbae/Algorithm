#include<math.h>
#include<iostream>
using namespace std;
#define EPS	(1.0E-10)
#define BIG (1,0E10)

double RadsPerDegree;

double FindAltitude(double d, double h, double alpha, double beta, double gamma){
    double a, b, c, z, tmp;

    a = tan(alpha * RadsPerDegree);
    a = 1.0/(a*a);
    b = tan(beta * RadsPerDegree);
    b = 1.0/(b*b);
    c = tan(gamma * RadsPerDegree);
    c = 1.0/(c*c);

    tmp = a + c - 2*b;

    if(tmp < EPS){
        return BIG;
    }
    z = sqrt(2.0/tmp);
    z = z*d+h;
    return z;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    double D, H, alpha, beta, gamma, ans;
    cin>>D>>H;

    RadsPerDegree = atan2(1.0, 1.0)/45.0;

    while(1){
        cin>>alpha>>beta>>gamma;
        if((alpha == 0.0) || (beta == 0.0) || (gamma == 0.0)){
            return 0;
        }
        ans = FindAltitude(D, H, alpha, beta, gamma);
        cout<<round(ans)<<"\n";
    }
    return 0;
}