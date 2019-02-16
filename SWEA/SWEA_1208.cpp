#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    for(int tc = 0; tc < 10; tc++){
        int dump = 0, Max = 0, Min = 0, result = 0;
        int box[101] = {0,};
        cin>>dump;

        for(int i = 0; i < 100; i++){
            cin>>box[i];
        }

        for(int i = 0; i < dump; i++){

            // 최대값 찾아서 -1 최소값 찾아서 +1
            sort(box,box+100);
            box[0] += 1;
            box[99] -= 1;

        }

        sort(box,box+100);
        Max = box[99];
        Min = box[0];
        result = Max - Min;

        cout<<"#"<<tc+1<<" "<<result<<endl;
    }


    return 0;
}