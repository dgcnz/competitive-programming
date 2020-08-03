#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int              n;
    string           stat;
    map<string, int> counter;
    cin >> n;
    while (n--)
    {
        cin >> stat;
        counter[stat]++;
    }
    cout << "AC x " << counter["AC"] << endl;
    cout << "WA x " << counter["WA"] << endl;
    cout << "TLE x " << counter["TLE"] << endl;
    cout << "RE x " << counter["RE"] << endl;
    return 0;
}
