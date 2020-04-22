#include <bits/stdc++.h>

using namespace std;

map<string, bool> exists;

int main(void)
{
    int    n;
    string s;
    cin >> n;

    while (n--)
    {
        cin >> s;
        if (exists[s])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        exists[s] = true;
    }
    return 0;
}
