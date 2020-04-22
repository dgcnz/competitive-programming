#include <iostream>
#include <string>

using namespace std;

bool is_upper(char c) { return 'A' <= c and c <= 'Z'; }

string lower(string s)
{
    string ans = s;

    for (int i = 0, len = s.size(); i < len; ++i)
        if (is_upper(s[i]))
            ans[i] += ('a' - 'A');

    return ans;
}

int main(void)
{
    string s1, s2;

    cin >> s1 >> s2;

    s1 = lower(s1);
    s2 = lower(s2);

    cout << (s1 == s2 ? 0 : (s1 > s2 ? 1 : -1)) << endl;

    return 0;
}
