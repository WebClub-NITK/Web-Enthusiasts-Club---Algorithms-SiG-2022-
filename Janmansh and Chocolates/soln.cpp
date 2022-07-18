#include<bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1000000
#define INF 10000000
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define forf(i,a,b) for(i=a;i<b;i++)
#define forr(i,a,b) for(i=a;i>b;i--)
#define mp make_pair
#define f first
#define s second
#define pb(x) push_back(x)
typedef  long long  int ll;
typedef std::vector<ll> vi;

#define input(vec,a,b) for(ll i =a;i<b;i++) cin>>vec[i]
#define print(vec,a,b) for(ll i=a;i<b;i++) cout<<vec[i]<<" " ;cout<<endl;
#define all(a) a.begin(),a.end()
using namespace std;

void solve(ll Case){
    ll n;
    
    cin>>n;
    
    ll a[n] , dp[n][3] , i , j;

    forf(i,0,n)
    {
        cin>>a[i];
    }

    switch (a[0])
    {
    case 0:
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        break;
    case 1:
        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[0][2] = 0;
        break;
    case 2:
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 1;
        break;
    case 3:
        dp[0][0] = 0;
        dp[0][1] = 1;
        dp[0][2] = 1;
        break;
    default:
        assert(0);
        break;
    }

    for( i=1 ; i<n ; i++)
    {
        dp[i][0] = max(dp[i-1][0] , max(dp[i-1][1] , dp[i-1][2] ) );
        
        switch (a[i])
        {
        case 0:
            dp[i][1] = dp[i][0];
            dp[i][2] = dp[i][0];
            break;
        case 1:
            dp[i][1] = 1 + max(dp[i-1][0] , dp[i-1][2]);
            dp[i][2] = dp[i][0];
            break;
        case 2:
            dp[i][1] = dp[i][0];
            dp[i][2] = 1 + max(dp[i-1][0] , dp[i-1][1]);
            break;
        case 3:
            dp[i][1] = 1 + max(dp[i-1][0] , dp[i-1][2]);
            dp[i][2] = 1 + max(dp[i-1][0] , dp[i-1][1]);
            break;
        default:
            assert(0);
            break;
        }
    }

    ll ans =  max(dp[n-1][0] , max(dp[n-1][1] , dp[n-1][2] ) );

    cout<<ans<<endl;

}

int main()
{
      IO;
      ll t=1,i;
      cin>>t;


      for(i=1;i<=t;i++)
      {

          solve(i);
      }
    return 0;
}