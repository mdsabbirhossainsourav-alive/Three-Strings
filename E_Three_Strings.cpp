#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        string a,b,c;
        cin >> a >> b >> c;
        int n = a.size();
        int m = b.size();
        vector<int> dp(m+1);
        for(int j=1; j<=m; j++)
        {
            dp[j] = dp[j-1];
            if(b[j-1] != c[j-1])
            {
                dp[j]++;
            }
        }
        for(int i=1; i<=n; i++)
        {
            int frt = 0;
            for(int k=0; k<i; k++)
            {
                if(a[k] != c[k])
                {
                    frt++;
                }
            }
            dp[0] = frt;
            for(int j=1; j<=m; j++)
            {
                int tak = dp[j];
                if(a[i-1] != c[i+j-1])
                {
                    tak++;
                }
                int tke = dp[j-1];
                if(b[j-1] != c[i+j-1])
                {
                    tke++;
                }
                dp[j] = min(tak,tke);
            }
        }
        cout << dp[m] << endl;
    }
    return 0;
}