#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required
using namespace __gnu_pbds; //required

template <typename T> using ordered_set =  tree<T, null_type, less<T>,
rb_tree_tag, tree_order_statistics_node_update>;


// s.find_by_order(k); returns the (k+1)th smallest element
// s.order_of_key(k); returns the number of elements in s strictly less than k

// #pragma GCC optimize("-Ofast")
// #pragma GCC optimize("trapv")
// #pragma GCC target(                                                            \
//     "sse,sse2,sse3,ssse3,sse4,sse4.2,popcnt,abm,mmx,avx2,tune=native")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-funroll-all-loops,-fpeel-loops,-funswitch-loops")
#define mod (1000000007)
#define pii pair<ll,ll>
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define f first
#define s second
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(), x.end()
#define print(vec, l, r)                                                       \
    for (int i = l; i <= r; i++)                                               \
        cout << vec[i] << " ";                                                 \
    cout << endl;
#define forf(i, a, b) for (int i = (a); i < (b); i++)
#define forr(i, a, b) for (int i = (a); i > (b); i -= 1)
#define input(vec, N) for (int i = 0; i < (N); i++) cin >> vec[i];                                            
typedef long long ll;
#define ld long double
const int N = (1e3+20);
const int M = (2e3+20);
const int MAXN = 4e6+12;
const ll INF = 2e18+90;
#define BLOCK 555

// const int RANDOM =
//     chrono::high_resolution_clock::now().time_since_epoch().count();
// struct chash {
//     int operator()(int x) const { return x ^ RANDOM; }
// };


ll expo_pow(ll x, ll y) {
    if (y == 0)
        return 1;
    y = y % (mod - 1);
    x %= mod;
    if (y == 0)
        y = mod - 1;
    ll res = 1;
    while (y) {
        if (y & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

int n;
ll dp[N][N];
ll a[N];

ll f(int i,int j){

  if(i==j) return 0;

  if(dp[i][j]!=-1) return dp[i][j];


  ll ans = 1e18;

  if(i+1<=n && i+1<=j) ans = min(ans,abs(a[i]-a[j])+f(i+1,j));
  if(j-1>=1 && j-1>=i) ans = min(ans,abs(a[j]-a[i])+f(i,j-1));


  return dp[i][j] = ans;


}

void solve(int te){

  cin>>n;  

  forf(i,1,n+1) cin>>a[i];

  memset(dp,-1,sizeof(dp));

  cout<<f(1,n)%mod<<'\n';

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    // freopen("input (8).txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // cin >> T;
    int t=1;
    // sieve();
    while (t<=T) {
        //cout<<"Case #"<<t<<": ";
        solve(t);
        t++;
    }
}