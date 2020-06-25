#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int NMAX = 1e6 + 11;
const int MOD  = 1e9 + 7;

int  mem[NMAX];
bool vis[NMAX];

ll dp(int sum)
{
    if (sum < 0)
        return 0;
    else if (sum == 0)
        return 1;

    int &ans = mem[sum];
    if (vis[sum])
        return ans;

    vis[sum] = true;
    for (int d = 1; d <= 6; ++d)
        ans = (ans + dp(sum - d) % MOD) % MOD;

    return ans;
}

int main(void)
{
    int n;
    cin >> n;

    cout << dp(n) << endl;
    return 0;
}
