#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    bool sol = false;
    set<char> nums = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int a = 0; a < 100000; a++)
    {
        if (a % n == 0)
        {
            int b = a / n;
            set<char> check;
            string s = to_string(a) + to_string(b);

            if (b < 10000)
                s += '0';

            for (char c : s)
                check.insert(c);

            if (check == nums)
            {
                cout << a << " / " << setw(5) << setfill('0') << b << " = " << n << endl;
                sol = true;
            }
        }
    }
    if (!sol)
    {
        cout << "There are no solutions for N." << endl;
    }
    return 0;
}