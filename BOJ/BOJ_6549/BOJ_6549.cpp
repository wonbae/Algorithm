#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define MAXSIZE 100000
using namespace std;

int v[MAXSIZE + 1];
int segTree[4*MAXSIZE];
int n;

void init(int node, int start, int end){
    if(start == end){
        segTree[node] = start;
    }
    else{
        int mid = (start + end) / 2;
        init(node*2, start, mid);
        init(node*2+1, mid+1, end);
        if(v[segTree[node*2]] <= v[segTree[node*2+1]]){
            segTree[node] = segTree[node*2];
        }else{
            segTree[node] = segTree[node*2+1];
        }
    }
    
}


int query(int node, int left, int right, int start, int end){
    if(right < start || end < left){
        return -1;
    }

    if(start <= left && right <= end){
        return segTree[node];
    }

    int mid = (left + right) / 2;
    int lt = query(node*2, left, mid, start, end);
    int rt = query(node*2+1, mid+1, right, start, end);

    if(lt == -1) return rt;
    if(rt == -1) return lt;
    if(v[lt] <= v[rt]){
        return lt;
    }
    return rt;
}


long long devide(int start, int end){
    int mid = query(1, 0, n-1, start, end);

    long long res = (long long)v[mid] * (end - start + 1);  //넓이
    if(start <= mid - 1){
        long long ans = devide(start, mid-1);
        res = max(res, ans);
    }
    if(mid+1 <= end){
        long long ans = devide(mid+1, end);
        res = max(res, ans);
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    
    while(1){
        cin>>n;
        if(n==0) return 0;

        for(int i = 0; i < n; i++){
            cin>>v[i];
        }
        
        init(1, 0, n-1);

        cout<<devide(0, n-1)<<"\n";
    }
    return 0;
}