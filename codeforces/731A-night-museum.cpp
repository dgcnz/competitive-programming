#include <bits/stdc++.h>

using namespace std;

inline int ord(char c) { return c - 'a'; }

int main(void)
{
    int    ans = 0, last = 0;
    string s;

    cin >> s;

    for (auto c : s)
    {
        ans += min(26 - abs(ord(c) - last), abs(ord(c) - last));
        last = ord(c);
    }

    cout << ans << endl;

    return 0;
}
