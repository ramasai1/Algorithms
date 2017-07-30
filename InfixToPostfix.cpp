#include <iostream>
#include <stack>
#include <cctype>
#include <cstring>
using namespace std;
int main ()
{
    int t;
    cin >> t;
    string s1;
    stack<char> s;
    while(t--)
    {
        cin>>s1;
        int len = s1.length();
        for(int i = 0;i < len;i++)
        {
            if(isalpha(s1[i]))
                cout << s1[i];
            else if(s1[i] == ')' )
            {
                cout << s.top();
                s.pop();
            }
            else if (s1[i] != '(' )
                s.push(s1[i]);
        }
        cout << endl;
    }
    return 0;
}
