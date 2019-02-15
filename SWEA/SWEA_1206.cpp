#include <iostream>
#include <algorithm>
//#include <memory.h>
using namespace std;
int main(){
    int Tower_num = 0;
   

    for(int T = 0; T < 10; T++){
        cin>>Tower_num;

		int View = 0, tmp = 0;
        int Tower[1001]={0,};
        //memset(Tower,0,sizeof(Tower));
        
        for(int i = 0; i < Tower_num; i++){
            cin>>Tower[i];
        }

        for(int j = 2; j < Tower_num-2; j++){
            tmp = Tower[j] - max(max(Tower[j-2], Tower[j-1]),max(Tower[j+1],Tower[j+2]));
            if(tmp>0){
                View += tmp;
            }
        }

        cout<<"#"<<T+1<<" "<<View<<endl;

    }

    return 0;
}