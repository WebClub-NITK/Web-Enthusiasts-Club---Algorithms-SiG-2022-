#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define Fio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Mod 1000000007

signed main()
{
    Fio;
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        vector<int> A(N), B(N);
        for(int i=0; i<N; i++)
            cin >> A[i];
        for(int i=0; i<N; i++)
            cin >> B[i];
        
        vector<int> A1 = A;
        sort(A1.begin(), A1.end());
        sort(B.begin(), B.end());

        map<int, int> position;
        for(int i=0; i<N; i++)
            position[A1[i]] = i;

        vector<int> result(N);
        for(int i=0; i<N; i++)
        {
            int pos = position[A[i]];
            result[i] = B[pos];
        }

        for(int i=0; i<N; i++)
            cout << result[i] << " ";

        cout << endl;
    }
}