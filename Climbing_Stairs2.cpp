class Solution {
public:
    vector<int>dp;
    int solve(vector<int>&c,int i){
        if(i==c.size()-1)return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=INT_MAX;
        for(int j=i+1;j<min((int)c.size(),i+4);j++){
            int curcost=j-i;
            curcost*=curcost;
            ans=min(ans,curcost+c[j]+solve(c,j));
        }
        return dp[i]=ans;

    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>c;
        c.push_back(0);
        dp.resize(n+1,-1);
        for(auto &i:costs)c.push_back(i);
        return solve(c,0);
    }
};
