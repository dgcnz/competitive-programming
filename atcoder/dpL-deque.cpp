#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;

// Our intuition tells us that the state might be current sequence + player
// However, note that every sequence uniquely identifies its current player
// Example: If we start with [10, 80, 90, 30], then all states with even
//          size will belong to player 1.
// We can further note that since we only take elements from the sides,
// a good state definition could be:
// i : current index on left and j: current index on right
// Then, we can run minimax, storing the partial results on a memo table

const int NMAX = 3e3 + 11;

int  n, a[NMAX], li, ri;
ll   mem[NMAX][NMAX];
bool vis[NMAX][NMAX];

ll solve(bool maximizer)
{
    int l, r;
    ll  left_ans, right_ans;

    if (li > ri)
        return 0;

    ll &ans = mem[li][ri];
    if (vis[li][ri])
        return ans;
    vis[li][ri] = true;

    l        = a[li++];           // try
    left_ans = solve(!maximizer); // partial ans
    --li;                         // undo

    r         = a[ri--];           // try
    right_ans = solve(!maximizer); // partial ans
    ++ri;                          // undo

    if (maximizer)
        ans = max(l + left_ans, r + right_ans);
    else
        ans = min(left_ans - l, right_ans - r);
    return ans;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    li = 0, ri = n - 1;

    cout << solve(true) << endl;
    return 0;
}
