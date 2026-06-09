// Last updated: 09/06/2026, 19:42:56
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<long long,int>mp;

        int lim=(int)cbrt(n);

        for(int a=1;a<=lim;a++){
            for(int b=a;b<=lim;b++){
                long long x=1LL*a*a*a+1LL*b*b*b;

                if(x>n)break;
                mp[x]++;
            }
        }

        vector<int>ans;
        for(auto it:mp){
            if(it.second>=2){
                ans.push_back((int)it.first);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;
    }
};