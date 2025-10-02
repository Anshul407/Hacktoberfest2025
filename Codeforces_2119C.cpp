
#include <bits/stdc++.h>
using namespace std;

// ---------------- FAST I/O ----------------
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
struct FastInputOutput {
    FastInputOutput() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
} fastio_init;

// Optional getchar/putchar I/O (ultra fast for huge inputs)
inline int readInt() {
    int x=0, f=1; char c=getchar();
    while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar(); }
    while(c>='0'&&c<='9'){ x=(x<<3)+(x<<1)+(c-'0'); c=getchar(); }
    return x*f;
}
inline void writeInt(long long x) {
    if(x<0){ putchar('-'); x=-x; }
    char s[20]; int n=0;
    do{ s[n++]=x%10+'0'; x/=10; }while(x);
    while(n--) putchar(s[n]);
    putchar('\n');
}

using ll   = long long;
using ull  = unsigned long long;
using ld   = long double;

using pii  = pair<int,int>;
using pll  = pair<ll,ll>;
using pdd  = pair<ld,ld>;

using vi   = vector<int>;
using vll  = vector<ll>;
using vd   = vector<double>;
using vld  = vector<ld>;
using vb   = vector<bool>;
using vc   = vector<char>;
using vs   = vector<string>;

using vpi  = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;

// ---------------- STL ----------------
using si   = set<int>;
using sll  = set<ll>;
using sc   = set<char>;
using ss   = set<string>;

using mii  = map<int,int>;
using mll  = map<ll,ll>;
using mci  = map<char,int>;
using msi  = map<string,int>;

using umii = unordered_map<int,int>;
using umll = unordered_map<ll,ll>;
using umci = unordered_map<char,int>;
using umsi = unordered_map<string,int>;

using usi  = unordered_set<int>;
using usll = unordered_set<ll>;
using usc  = unordered_set<char>;
using uss  = unordered_set<string>;

using dq   = deque<int>;
using dqll = deque<ll>;
// ---------------- MACROS ------------------
#define all(x)   (x).begin(), (x).end()
#define rall(x)  (x).rbegin(), (x).rend()
#define pb       push_back
#define eb       emplace_back
#define ff       first
#define ss       second
#define sz(x)    (int)(x).size()
#define loop(i,n) for(int i=0;i<(n);i++)
#define rep(i,a,b) for(int i=(a); i<=(b); i++)
#define per(i,a,b) for(int i=(a); i>=(b); i--)
#define int long long int

// ---------------- CONSTANTS ---------------
const ll INF  = 1e18;
const int MOD = 1e9+7;
const int MOD2= 998244353;

// ---------------- RNG + HASH --------------
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = rng();
        return splitmix64(x + FIXED_RANDOM);
    }
};
using safe_map = unordered_map<ll,ll,custom_hash>;

// ---------------- MODULAR ARITH -----------
inline ll mdadd(ll a,ll b,ll m=MOD){ a+=b; if(a>=m) a-=m; return a; }
inline ll mdsub(ll a,ll b,ll m=MOD){ a-=b; if(a<0) a+=m; return a; }
inline ll mdmul(ll a,ll b,ll m=MOD){ return ( (__int128)a * b ) % m; }
ll mdpow(ll a,ll b,ll m=MOD){ ll res=1; while(b){ if(b&1) res=mdmul(res,a,m); a=mdmul(a,a,m); b>>=1; } return res; }
ll mdinv(ll a,ll m=MOD){ return mdpow(a,m-2,m); } // m must be prime

// ---------------- DEBUG + CLOCK -----------
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

// ---------------- SOLVE -------------------
void solve(){
   ll n,l,r,k;
   cin>>n>>l>>r>>k;
   ll limit = 0;
ll temp = l;
while(temp) {
    temp >>= 1;
    limit++;
}
   if(n%2==1){
     cout<<l<<endl;
     return ;
   }
    if(n==2){
      cout<<-1<<endl;
      return ;
    }
  ll ans=1LL<<limit;
  if(ans>r){
    cout<<-1;
    cout<<endl;
    return ;
  }
  if(n-k<=1){
    cout<<ans;
    cout<<endl;
  }else{
    cout<<l;
    cout<<endl;
  }
}

// ---------------- MAIN --------------------
signed main(){
    fastio;
    startClock
    
    int t;
    cin>>t;
    while(t--) solve();
    
    endClock
    return 0;
}
