#include <iostream>
#include <unordered_map>
using namespace std;

int longest_substr_max2_distinct_char(string s)
{
    unordered_map<char, int> m;
    int n = s.length();
    int ptr1 = 0;
    int ans = 0;
    if(n <= 2)
    {
        ans = n;
    }
    else
    {
        for(int ptr2 = 0; ptr2 < n; ptr2++)
        {
            m[s[ptr2]]++;
            if(m.size() <= 2)
            {
                ans = max(ans, ptr2-ptr1+1);
            }
            else
            {
                while(m.size() > 2)
                {
                    if(m[s[ptr1]] > 1)
                        m[s[ptr1++]]--;
                    else
                        m.erase(s[ptr1++]);
                }
            }
        }
    }
    return ans;
}

int main()
{
    int t;

    cout << "Enter the number of test cases: ";
    cin >> t;

    while(t--)
    {
        string s;

        cin >> s;
        cout << longest_substr_max2_distinct_char(s) << "\n";
    }

    return 0;
}
