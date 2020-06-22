#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

ll manhattan(ii a, ii b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

ll solve(ll row, ll col)
{
    ll level  = max(row, col);
    ll dir    = level % 2; // 0 down, 1 up
    ll startv = (level - 1) * (level - 1) + 1;
    ii startp = (dir ? make_pair(level, 1LL) : make_pair(1LL, level));
    ll dist   = manhattan(startp, {row, col});
    return startv + dist;
}

int main(void)
{
    ll t, x, y;
    cin >> t;

    while (t--)
    {
        cin >> y >> x;
        cout << solve(y, x) << endl;
    }
    return 0;
}
