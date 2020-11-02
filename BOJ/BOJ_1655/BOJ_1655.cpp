#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, mediean;
    cin>>n;
    priority_queue<int, vector<int>, greater<int> > minheap;
    priority_queue<int> maxheap;

    for(int i = 0; i < n; i++){
        cin>>a;
        if(maxheap.size() == 0){
            maxheap.push(a);
        }else{
            if(maxheap.size() > minheap.size()){
                minheap.push(a);
            }else if(maxheap.size() <= minheap.size()){
                maxheap.push(a);
            }
            if(maxheap.top() > minheap.top()){
                int maxtmp = maxheap.top();
                int mintmp = minheap.top();
                maxheap.pop();
                minheap.pop();
                minheap.push(maxtmp);
                maxheap.push(mintmp);
            }
        }
        mediean = maxheap.top();
        cout<<mediean<<"\n";
    }
    return 0;
}