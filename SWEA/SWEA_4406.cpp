//SW EA4406
#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int T;
    cin>>T;

    for(int i=1;i<=T;i++){
        char arr[51];
        cin>>arr;
        cout<<"#"<<i<<" ";

        for(int k=0;k<strlen(arr);k++){
            if(arr[k] != 'a' && arr[k] != 'e' && arr[k] != 'i' && arr[k] != 'o' && arr[k] != 'u'){
                cout<<arr[k];
            }
        }
        cout<<endl;
    }
    return 0;
}
