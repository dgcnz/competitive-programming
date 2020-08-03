#include <bits/stdc++.h>

using namespace std;

int solve(int n, string &s)
{
    int l, r, ans = 0;
    l = 0, r = n - 1;

    while (l < r)
    {
        while (l < n and s[l] != 'W') // left is looking for white stone
            ++l;
        while (r >= 0 and s[r] != 'R') // right is looking for red stone
            --r;
        if (l >= r)
            break;
        swap(s[l], s[r]);
        ++ans;
    }
    return ans;
}

int main(void)
{
    int    n;
    string s;
    cin >> n;
    cin >> s;

    cout << solve(n, s) << endl;

    return 0;
}
