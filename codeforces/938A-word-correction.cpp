#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <bits/stdc++.h>
#include <cplib/utils/io>
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
    int    n;
    string s;
    cin >> n >> s;

    auto is_vowel = [](char c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or
               c == 'y';
    };
    char prev = 0;
    for (auto c : s)
    {
        if (!is_vowel(c) or !is_vowel(prev))
            cout << c;
        prev = c;
    }
    cout << endl;
    return 0;
}
