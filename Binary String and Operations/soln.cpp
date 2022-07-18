#include<bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, i;
    int ans = 0;
    string s;
    cin >> n;
    cin >> s;
    
    if (s[0] == '0' || s[n-1] == '0') {
        cout << "-1\n";
        return 0;
    }
    
    int flag = 0, cnt = 0;
    string st = "";
    for (i=0; i<n; ++i) {
        if (!flag) {
            if (s[i] == '1') {
                cnt = 1;
                flag = 1;
            }
        } else {
            if (s[i] == '0') {
                if (cnt == 1) {
                    st += "1";
                } else if (cnt == 2) {
                    st += "11";
                } else if (cnt == 3) {
                    st += "1";
                    ans += 1;
                } else {
                    ans += (cnt - 2);
                    st += "11";
                }
                cnt = 0;
                flag = 0;
            } else {
                cnt++;
            }
        }
        if (s[i] == '0') st += s[i];
    }
    if (flag) {
        //cout << cnt << "\n";
        if (cnt == 1) {
            st += "1";
        } else if (cnt == 2) {
            st += "11";
        } else if (cnt == 3) {
            st += "1";
            ans += 1;
        } else {
            ans += (cnt - 2);
            st += "11";
        }
    }
    
    flag = 0;
    
    s = "";
    i = 0;
    for (;;) {
        //cout << st << "\n";
        n = (int)st.length();
        if ((i < n-1) && (st.substr(i, 2) == "11")) {
            flag = 1;
            i += 2;
        } else {
            i += 1;
        }
        
        if (i == n) {
            break;
        }
        
        while (st[i] == '0') {
            i++;
        }
        
        if ((i < n-1) && (st.substr(i, 2) == "11")) {
            if (flag) {
                ans += 2;
                s += '1';
            } else {
                ans += 1;
                s += "11";
            }
            s += st.substr (i+2);
        } else {
            if (flag) {
                ans += 1;
                s += "11";
                st[i] = '1';
            } else {
                ans += 1;
                s += '1';
            }
            s += st.substr (i+1);
        }
        
        st = s;
        s = "";
        i = 0;
    }
    cout << ans << " " << st << "\n";
    return 0;
}