#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll t, i, mid, high, low, X, n, sum = 0, Y;
    cin>>t;

    while(t--){
        cin>>n>>X;
        ll O[n], R_O[n];
        sum = 0;
        
        for(i = 0; i < n; i++){
            cin>>O[i];
        }

        for(i = 0; i < n; i++){
            cin>>R_O[i];
            R_O[i] = max(0LL, R_O[i]-O[i]);
            sum += R_O[i];
        }
        if(sum == 0)    cout<<0<<"\n";
        else if(X == 1)     cout<<sum<<"\n";
        else{
            Y = X/2;
            X = X - Y;
            low = 0;
            high = 1000000000;
            while(low < high){
                mid = low + (high - low)/2;
                sum = 0;
                for(i = 0; i < n; i++){
                    if(mid*Y <= R_O[i]){
                        sum += (R_O[i] - mid*Y + X - 1)/X;
                    }
                }

                if(sum <= mid)      high = mid;
                else    low = mid+1;
            }
            cout<<low<<"\n";
        }
    }
}