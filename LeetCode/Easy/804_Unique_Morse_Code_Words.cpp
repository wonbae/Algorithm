class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
//         string mos[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
//         string tmp,tmp2[10];
//         int index, count = 0;
        
        
//         for(int i = 0; i < words.size(); i++){
//             tmp = "";
//             for(int j = 0; j < words.size(); j++){
//                 if(words[i][j] == NULL){
//                     continue;
//                 }else{
//                     // cout<<words[i][j]<<endl;
//                     index = words[i][j] - 'a';
//                     // cout<<index<<endl;
//                     tmp += mos[index];
//                 }
               
//             }
//             cout<<tmp<<endl;
//             if(tmp2[i] == tmp){
//                 count++;
//             }
//             tmp2[i] = tmp;
            
//         }
        
//         return count;
        vector<string> reference= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
    unordered_map<string,int> transformations;
    
    for(int i = 0; i < words.size(); i++){
        string temp = "";
        for(int j = 0; j < words[i].size(); j++){
            temp+= (reference[ static_cast<int>(words[i][j]) - static_cast<int>('a')]);
        }
        if( transformations.find(temp) == transformations.end() ){
            transformations.insert(pair<string,int>(temp,1));
        }
    }
    
    return transformations.size();
}
        
    
};
