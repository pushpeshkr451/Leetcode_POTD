class Solution {
public:
    int numWaterBottles(int a, int b) {
        int ans=a;
        int empty_cnt=a;
        int full_cnt=0;
        while(empty_cnt>=b){
            full_cnt=empty_cnt/b;
            ans+=full_cnt;
            empty_cnt=(empty_cnt%b)+full_cnt;
        }
        return ans;
    }
};
