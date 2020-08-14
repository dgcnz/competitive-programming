#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int const INF = 1e9;

int main(void)
{
    int    n;
    string s;
    vi     pw, pb;

    cin >> n >> s;
    s = ' ' + s;

    pw.resize(n + 1, 0), pb.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        pw[i] = pw[i - 1] + (s[i] == '.');
        pb[i] = pb[i - 1] + (s[i] == '#');
    }

    int ans = INF, left, right;

    // WWWBBB
    for (int i = 1; i <= n - 1; ++i) // i : pos of last white, inclusive
    {
        left = pb[i], right = (pw[n] - pw[i]);
        ans = min(ans, left + right);
    }
    ans = min({ans, n - pb[n], n - pw[n]});

    cout << ans << endl;

    return 0;
}
