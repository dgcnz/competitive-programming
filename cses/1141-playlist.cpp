#include <bits/stdc++.h>

using namespace std;
using vi  = vector<int>;
using mii = map<int, int>;

// @idea:
//  - let's say you're at position i, we need to find the next position j, such
//  that all numbers in the range [i, j] are unique.
//  - Equivalently, all members of range [i, j] have a frequency of 1.
//  - Starting at position i, traverse all indices k > i increasing their
//  frequency until a number xj is found such that it's frequency is already 1
//  (this means that it has been visited already in [i, j]).

int main(void)
{
    int n;
    cin >> n;

    vi  k(n);
    mii freq;

    for (auto &ki : k)
        cin >> ki;

    int ans = 0;
    for (int i = 0, j = 0; i < n; ++i)
    {
        while (j < n and freq[k[j]] == 0)
        {
            ++freq[k[j]];
            ++j;
        }
        ans = max(j - i, ans);
        freq[k[i]]--;
    }

    cout << ans << endl;

    return 0;
}
