#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    vector<string> nums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for (int i = a; i <= b; i++)
    {
        if (1 <= i <= 9)
        {
            cout << nums[i] << endl;
        }
        else
            cout << (i % 2 == 0 ? "even" : "odd") << endl;
    }
}