#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int    n, last, ans = 0;
    string s;
    cin >> n >> s;

    last = 0; // dummy
    for (auto c : s)
    {
        if (c == last)
            ++ans;
        last = c;
    }

    cout << ans << endl;

    return 0;
}
