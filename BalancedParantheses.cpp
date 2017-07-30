//
// Created by Ramasai Tadepalli on 7/29/17.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool is_balanced(stack<char>);

int main() {
    stack<char> st;
    string input;
    cin >> input;
    for (char x : input) {
        st.push(x);
    }
    if (is_balanced(st))
        cout << "balanced";
    else cout << "not balanced";
    return 0;
}

bool is_balanced(stack<char> input) {
    vector<char> vec;
    while(!input.empty()) {
        char x = input.top();
        vec.push_back(x);
        input.pop();
    }
    int length = vec.size();
    int one = 0, two = length - 1;
    bool result = true;
    while(two >= one) {
        if(((vec.at(one) == '(' && vec.at(two) != ')') || (vec.at(one) == ')' && vec.at(two) != '('))
                || ((vec.at(one) == '[' && vec.at(two) != ']') || (vec.at(one) == ']' && vec.at(two) != '['))
                || ((vec.at(one) == '{' && vec.at(two) != '}') || (vec.at(one) == '}' && vec.at(two) != '{'))) {
            result = false;
            break;
        }
        one++;
        two--;
    }
    return result;
}

