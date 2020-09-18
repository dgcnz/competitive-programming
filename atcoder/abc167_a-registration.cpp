#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string s, t;
    cin >> s >> t;

    bool ok = s == t.substr(0, t.size() - 1);

    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
