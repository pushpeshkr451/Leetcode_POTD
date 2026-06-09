// Last updated: 09/06/2026, 19:44:19
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int n=nums2.size();
        int b=max(1,(int)sqrt(n));
        int k=(n+b-1)/b;

        vector<long long>a(n);
        vector<long long>lz(k,0);
        vector<unordered_map<long long,int>>freq(k);

        for(int i=0;i<n;i++){
            a[i]=nums2[i];
            freq[i/b][a[i]]++;
        }

        vector<int>res;

        for(auto &q:queries){
            if(q[0]==1){
                int l=q[1],r=q[2];
                long long v=q[3];

                int bl=l/b,br=r/b;
                if(bl==br){
                    for(int i=l;i<=r;i++){
                        freq[bl][a[i]]--;
                        a[i]+=v;
                        freq[bl][a[i]]++;
                    }
                }
                else{
                    int el=(bl+1)*b-1;
                    for(int i=l;i<=el;i++){
                        freq[bl][a[i]]--;
                        a[i]+=v;
                        freq[bl][a[i]]++;
                    }
                    for(int b=bl+1;b<br;b++){
                        lz[b]+=v;
                    }
                    for(int i=br*b;i<=r;i++){
                        freq[br][a[i]]--;
                        a[i]+=v;
                        freq[br][a[i]]++;
                    }
                }
            }
            else{
                long long total=q[1];
                int ans=0;
                for(auto x:nums1){
                    long long tar=total-x;
                    for(int b=0;b<k;b++){
                        long long cnt=tar-lz[b];
                            if(freq[b].count(cnt)){
                                ans+=freq[b][cnt];
                            }
                    }
                }
                res.push_back(ans);
            }
        }
        return res;
    }
};