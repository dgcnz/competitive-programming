#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// pretty cool idea from william li
// basically maintain a map with the count of the prefix sums seen so far
// Assuming you are at position i, if c = prefix_count[pref[i] - x], y > 0 that
// means that there's excatly c indices j before i such that they produce a
// sum of x

int main(void)
{
    int          n, x, ai;
    ll           s = 0, ans = 0;
    map<ll, int> prefix_count;

    cin >> n >> x;
    prefix_count[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        cin >> ai;
        s += ai;

        ans += prefix_count[s - x];
        ++prefix_count[s];
    }

    cout << ans << endl;
    return 0;
}
