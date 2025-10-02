#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
struct FastInputOutput {
    FastInputOutput() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
} fastio_init;
#ifdef LOCAL
    #define dbg(x) cerr << #x << " = " << (x) << '\n'
    #define startClock auto _start=chrono::high_resolution_clock::now();
    #define endClock auto _end=chrono::high_resolution_clock::now(); \
        cerr<<"Time: "<<chrono::duration_cast<chrono::milliseconds>(_end-_start).count()<<" ms\n";
#else
    #define dbg(x)
    #define startClock
    #define endClock
#endif
class Solution {
public:
    const int MOD=1e9+7;
    inline int mdadd(int a,int b,int m){ a+=b; if(a>=m) a-=m; return a;}
    int zigZagArrays(int n, int l, int r) {
        startClock
        vector<vector<vector<int>>>dp(3,vector<vector<int>>(r-l+1,vector<int>(4,0)));
        vector<vector<int>>pref(r-l+2,vector<int>(3,0));
        int c=0;
        for(int j=l;j<=r;j++){
            int i=j-l;
            dp[0][i][2]=1;
            dp[0][i][1]=1;
            dp[1][i][1]=i;
            dp[1][i][2]=(r-l-i);
            if(i==0)pref[i][1]=dp[1][0][1],pref[i][2]=dp[1][0][2];
            else{
                pref[i][1]=mdadd(pref[i-1][1],dp[1][i][1],MOD);
                pref[i][2]=mdadd(pref[i-1][2],dp[1][i][2],MOD);
            }
         
        }
        for(int i=2;i<n;i++){
            
            for(int jj=l;jj<=r;jj++){
                int j=jj-l;
                dp[2][j][2]=((pref[r-l][1]-pref[j][1])%MOD+MOD)%MOD;
                if(j-1>=0)
                dp[2][j][1]=pref[j-1][2];
            }
            for(int jj=l;jj<=r;jj++){
                int j=jj-l;
                if(j==0)pref[j][1]=dp[2][j][1],pref[j][2]=dp[2][j][2];
                else{
                pref[j][1]=mdadd(pref[j-1][1],dp[2][j][1],MOD);
                pref[j][2]=mdadd(pref[j-1][2],dp[2][j][2],MOD);
                }
            }
            
        }
        
        int ans=0;
        for(int xx=l;xx<=r;xx++){
            int x=xx-l;
            ans=mdadd(ans,dp[2][x][1],MOD);
            ans=mdadd(ans,dp[2][x][2],MOD);
        }
        endClock
        return ans;
        
        
    }
};
