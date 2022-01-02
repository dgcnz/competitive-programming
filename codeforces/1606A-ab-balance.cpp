#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
#include <cplib/utils/misc>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using namespace cplib;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);

    auto comp = [](string s)
    {
        int ba = 0, ab = 0, n = s.size();

        for (int i = 0; i < n - 1; ++i)
        {
            if (s[i] == 'b' and s[i + 1] == 'a')
                ba++;
            else if (s[i] == 'a' and s[i + 1] == 'b')
                ab++;
        }
        return make_pair(ab, ba);
    };

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        auto [ab, ba] = comp(s);

        if (ab > ba)
        {
            if (s.front() == 'a')
                s.front() = 'b';
            else if (s.back() == 'b')
                s.back() = 'a';
        }
        else if (ba > ab)
        {
            if (s.front() == 'b')
                s.front() = 'a';
            else if (s.back() == 'a')
                s.back() = 'b';
        }

        cout << s << endl;
    }
    return 0;
}
