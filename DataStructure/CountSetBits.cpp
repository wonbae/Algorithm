// C++ program to Count set
// bits in an integer
#include <bits/stdc++.h>
using namespace std;

/* Function to get no of set bits in binary
representation of positive integer n */
int totalHammingDistance(vector<int>& A) {     
    int ans = 0;
    int N=A.size();
    for(int j=0; j<32; j++)
    {
        int n = 0, m=0;
        for(int i=0; i<N; i++)
        {
            // cout<<A[i]<<", "<<(1<<j)<<", "<<(A[i]&(1<<j))<<"\n";
            if(A[i]&(1<<j))
                n++;
            else
                m++;
        }
        ans += n*m;
    }
    return ans;
}

/* Program to test function countSetBits */
int main()
{
    vector<int> a;
    a.push_back(4);
    a.push_back(14);
    a.push_back(2);
    cout << totalHammingDistance(a);
    return 0;
}
