#include <iostream>
#include <string.h>
using namespace std;


int a[100] = {0,}, b[100] = {0,};
int result = 0;

void DFS(int n)
{
    if(a[n] == 99 || b[n] == 99)
    {
        result = 1;
        return;
    }
    else
    {
        if(a[n] != 0)
        {
            DFS(a[n]);
        }
        if(b[n] != 0)
        {
            DFS(b[n]);
        }
    }

}


int main(){
    int T,Num;
    int index, value;

    for(int tc = 1; tc <= 10; tc++){
        cin>>T>>Num;
        result = 0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));

        for(int i = 0; i < Num; i++){
            cin>>index>>value;

            if(a[index] == 0){
                a[index] = value;
            }else{
                b[index] = value;
            }
        }

        // for(int i = 0; i < Num; i++){
        //     cout<<"i : "<<i<<", a: "<<a[i]<<", ";
        //     cout<<" b: "<<b[i]<<endl;
        // }
        DFS(0);

        cout<<"#"<<tc<<" "<<result<<endl;
    }
    return 0;
}