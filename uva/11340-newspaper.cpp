#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()

using namespace std;

inline string format_dollar(int cents)
{
    stringstream ss;
    int          dollars = cents / 100;
    cents                = cents % 100;

    ss << dollars << "." << setw(2) << setfill('0') << cents << "$";
    return ss.str();
}

int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        int            k, m;
        map<char, int> value;
        string         s;

        cin >> k;
        while (k--)
        {
            char c;
            cin >> c;
            cin >> value[c];
        }
        cin >> m;
        cin.ignore();

        int cents = 0;
        while (m--)
        {
            getline(cin, s);
            cents = accumulate(all(s), cents, [&value](int acc, char c) {
                return acc + value[c];
            });
        }
        cout << format_dollar(cents) << endl;
    }
    return 0;
}
