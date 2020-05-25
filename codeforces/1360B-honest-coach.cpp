#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

const int NMAX = 50;
int       n, s[NMAX];

int solve(void)
{
    int ans = INT_MAX;
    sort(s, s + n);
    for (int i = 1; i < n; ++i)
        ans = min(ans, s[i] - s[i - 1]);
    return ans;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> s[i];

        cout << solve() << endl;
    }
    return 0;
}
