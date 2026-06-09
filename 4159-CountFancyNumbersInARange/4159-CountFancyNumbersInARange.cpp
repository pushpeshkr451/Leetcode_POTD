// Last updated: 09/06/2026, 19:43:45
class Solution {
public:

    string s;
    long long dp[20][11][4][2][140][2];

    bool goodSum(int x){
        if(x < 10) return true;
        string t = to_string(x);

        bool inc = true, dec = true;
        for(int i=1;i<t.size();i++){
            if(t[i] <= t[i-1]) inc = false;
            if(t[i] >= t[i-1]) dec = false;
        }
        return inc || dec;
    }

    long long f(int pos,int last,int trend,int tight,int sum,int started){

        if(pos == s.size()){
            if(!started) return 0;

            if(trend != 3) return 1;

            if(goodSum(sum)) return 1;

            return 0;
        }

        long long &res = dp[pos][last+1][trend][tight][sum][started];
        if(res != -1) return res;

        res = 0;

        int limit = tight ? s[pos]-'0' : 9;

        for(int d=0; d<=limit; d++){

            int ntight = tight && (d==limit);

            if(!started && d==0){
                res += f(pos+1,-1,0,ntight,sum,0);
            }
            else{
                int ntrend = trend;

                if(!started){
                    ntrend = 0;
                }
                else{
                    if(trend==3){
                        ntrend = 3;
                    }
                    else{
                        if(last==-1){
                            ntrend = 0;
                        }
                        else{
                            if(trend==0){
                                if(d > last) ntrend = 1;
                                else if(d < last) ntrend = 2;
                                else ntrend = 3;
                            }
                            else if(trend==1){
                                if(d > last) ntrend = 1;
                                else ntrend = 3;
                            }
                            else if(trend==2){
                                if(d < last) ntrend = 2;
                                else ntrend = 3;
                            }
                        }
                    }
                }

                res += f(pos+1,d,ntrend,ntight,sum+d,1);
            }
        }

        return res;
    }

    long long solve(long long x){
        if(x <= 0) return 0;
        s = to_string(x);
        memset(dp,-1,sizeof(dp));
        return f(0,-1,0,1,0,0);
    }

    long long countFancy(long long l, long long r) {
        return solve(r) - solve(l-1);
    }
};