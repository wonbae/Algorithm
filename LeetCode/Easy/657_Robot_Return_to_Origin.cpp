//#16ms, 10MB
class Solution {
public:
    bool judgeCircle(string moves) {
        bool res = false;
        // int index = 0;
        int count = 0, count2 = 0;
        
        for(int i = 0; i < moves.length(); i++){
            switch(moves[i]){
                case 'U':
                    count += 1;
                    break;
                case 'D':
                    count -= 1;
                    break;
                case 'L':
                    count2 += 1;
                    break;
                case 'R':
                    count2 -= 1;
                    break; 
            }                 
        }
        return count == 0 && count2 == 0;
    }
};
