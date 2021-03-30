#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

string solve(string s)
{
    set<char> working;

    int n = s.size(), i = 0;
    while (i < n)
    {
        int  j = i;
        char c = s[i];
        while (j < n and s[j] == c)
            ++j;
        if ((j - i) % 2)
            working.insert(c);
        i = j;
    }

    return string(all(working));
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
