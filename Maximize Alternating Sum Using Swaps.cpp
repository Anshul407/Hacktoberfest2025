class Solution {
public:
    vector<int>p,r;
    void init(int n){
        p.resize(n+1,0);
        r.resize(n+1,0);
        for(int i=0;i<n;i++)p[i]=i;
    }
    int find(int u){
        if(u==p[u])return u;
        return p[u]=find(p[u]);
    }
    void unionbyrank(int u,int v){
        int up=find(u);
        int uv=find(v);
        if(up==uv)return ;
        if(r[up]>r[uv]){
            p[uv]=up;
        }else if(r[up]<r[uv]){
            p[up]=uv;
        }
        else{
            p[up]=uv;
            r[uv]++;
        }
    }
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        init(nums.size());
        unordered_map<int,vector<long long>>mp;
        for(auto &i:swaps){
            unionbyrank(i[0],i[1]);
        }
        for(int i=0.;i<nums.size();i++){
            int up=find(i);
            mp[up].push_back(i);
        }
        long long ans=0;
        for(auto &i:mp){
           int odd=0,even=0;
            for(auto &j:i.second){
                if(j%2)odd++;
                else even++;
            }
            auto curv=i.second;
            for(auto &ii:curv){
                ii=nums[ii];
            }
            sort(curv.rbegin(),curv.rend());
            int j=0;
            while(even--){
                ans+=curv[j];
                j++;       
            }
            while(odd--){
                ans-=curv[j];
                j++;       
            } 
      
        }
        return ans;
        
    }
};
