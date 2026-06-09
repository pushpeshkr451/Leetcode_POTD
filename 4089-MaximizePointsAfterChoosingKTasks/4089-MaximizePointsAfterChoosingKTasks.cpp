// Last updated: 09/06/2026, 19:44:15
class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        int n=t1.size();
        vector<long long>diff(n);

        long long base=0;
        for(int i=0;i<n;i++){
            base+=t2[i];
            diff[i]=(long long)t1[i]-t2[i];
            
        }

        sort(diff.begin(),diff.end(),greater<long long>());
        long long ans=base;

        for(int i=0;i<n;i++){
            if(i<k ||diff[i]>0)ans+=diff[i];
            else break;
        }

        return ans;
    }
};