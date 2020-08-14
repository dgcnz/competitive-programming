#include <bits/stdc++.h>

using namespace std;

vector<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};

bool isvowel(char c)
{
    c = tolower(c);
    return find(vowels.begin(), vowels.end(), c) != vowels.end();
}

bool isconsonant(char c)
{
    c = tolower(c);
    return find(vowels.begin(), vowels.end(), c) == vowels.end();
}

int main(void)
{
    string s, ans;
    cin >> s;

    for (auto c : s)
    {
        if (isvowel(c))
            continue;
        else if (isconsonant(c))
        {
            ans += ".";
            ans += tolower(c);
        }
        else
            ans += c;
    }

    cout << ans << endl;

    return 0;
}
