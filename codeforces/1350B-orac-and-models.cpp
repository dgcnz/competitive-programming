#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using vi = vector<int>;

const int NMAX = 1e5 + 11;

int n, s[NMAX];

// dp(i) = max{dp(j) | j <- [1,2..i], i mod j == 0, s[j] < s[i] } + 1

int solve(void)
{
    vi dp(n + 1, 1);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 2; j * i <= n; ++j)
            if (s[i] < s[i * j])
                dp[i * j] = max(dp[i * j], dp[i] + 1);
    }
    return *max_element(dp.begin(), dp.end());
}

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> s[i];

        cout << solve() << endl;
    }
    return 0;
}
