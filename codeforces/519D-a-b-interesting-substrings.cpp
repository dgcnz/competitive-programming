#include <iostream>
#include <map>

// Key idea:
// - let's say that acc[i] stores the sum of values from 0 to i
// - Note that for finding ranges (i, j) whose sum is 0
// it is sufficient to say that acc[i-1] == acc[j].
// - Why? Let's say acc[k] for all k is [3, 4, 5, 6, ..., 5, ...]
//                                                i       j
// - We can see that (i, j) contributes nothing to i - 1, ie sum(i, j) = 0
// - Now, we should not consider i and j, as the problem says
// so we want acc[i] == acc[j-1]
// - We can now store a map indexed by letters in the alphabet tracking their
// sums

using namespace std;
using ll = long long;

const int CMAX = 26;

map<ll, ll> m[CMAX + 1];
int          x[CMAX + 1];

ll solve(string s)
{
    int n = s.size(), cur;

    ll ans = 0, sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cur = s[i] - 'a';
        ans += m[cur][sum];
        sum += x[cur];
        ++m[cur][sum];
    }

    return ans;
}

int main(void)
{
    string s;
    for (int i = 0; i < CMAX; ++i)
        cin >> x[i];

    cin >> s;
    cout << solve(s) << endl;

    return 0;
}
