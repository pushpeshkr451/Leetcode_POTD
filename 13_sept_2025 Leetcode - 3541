class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>vowel_cnt;
        unordered_map<char,int>conso_cnt;

        for(auto it:s){
            if(it=='a'|| it=='e'||it=='i'||it=='o'||it=='u'){
                vowel_cnt[it]++;
            }
            else{
                conso_cnt[it]++;
            }
        }

        int max1=0,max2=0;
        for(auto it:vowel_cnt){
            max1=max(max1,vowel_cnt[it.first]);
        }

        for(auto it:conso_cnt){
            max2=max(max2,conso_cnt[it.first]);
        }

        return max1+max2;

    }
};
