#include<iostream>
using namespace std;
// Given n pairs of parentheses, generate all combinations of well-formed parentheses.
// for n = 3: ["((()))","(()())","(())()","()(())","()()()"]

void parenthesesCombin (int left, int right, string curr, int n){
    // for n, brakets in each cominations = 2*n
    if (left+right == n*2 && left == right) {  // all combinations made
        cout << curr << endl;  // print the combination found
        return;
    }
    if (left < n) parenthesesCombin(left+1, right, curr + "(", n);  // if left < n, means we can add more opening brackets
    if (left > right) parenthesesCombin(left, right+1, curr + ")", n); // if right < left, means we can add more closing brackets
}

int main() {
    int n;  // no of brackets
    cout << "Enter n: ";
    cin >> n;  // user input
    string s = ""; 
    parenthesesCombin(0,0,s,n);
    return 0;
}
