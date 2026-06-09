// Last updated: 09/06/2026, 19:42:59
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
         double e1 = sides[0];
        double e2 = sides[1];
        double e3 = sides[2];

        if(e1+e2<=e3 || e1+e3<=e2 || e2+e3<=e1 ) return {};

        double a = acos((e1*e1+e2*e2 - e3*e3)/(2.0*e1*e2))*180.0/M_PI;
        double b = acos((e1*e1+e3*e3 - e2*e2)/(2.0*e1*e3))*180.0/M_PI;
        double c = acos((e3*e3+e2*e2 - e1*e1)/(2.0*e3*e2))*180.0/M_PI;

        vector<double>ans = {a,b,c};

        sort(ans.begin(),ans.end());

        return ans;
    }
};