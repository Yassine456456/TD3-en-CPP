
#include <iostream>
#include <queue>
#include <stack>
#include <cctype>
#include <string>
using namespace std;

bool isPalindrome(const string& input) {
    queue<char> q;
    stack<char> s;

    for (char c : input) {
        if (isalnum((unsigned char)c)) {
            c = tolower((unsigned char)c);
            q.push(c);
            s.push(c);
        }
    }

    while (!q.empty()) {
        if (q.front() != s.top()) {
            return false;
        }

        q.pop();
        s.pop();
    }

    return true;
}

int main() {
    string input;

    cout << "Entrez un mot : ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "C'est un palindrome" << endl;
    }
    else {
        cout << "Ce n'est pas un palindrome" << endl;
    }

    return 0;
}
