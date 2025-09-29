#include<iostream>
using namespace std;

//  DIRECT RECURSION - function calls itself
//  NON - TAILED - computation performed before calling function (*n)
int factorial (int n) {
    if (n == 0) return 1;  // base case (stopping condition)
    
    return n*factorial(n-1); // general case
}

// INDIRECT RECURSION - when a function(A) calls a funct(B) that calls the prev func(A)
// TAILED - NO computation performed before calling function 
int funcA(int n);
int funcB(int n);

int funcA(int n) {  // function A that calls funct B
    if (n > 0) {
        cout << n << endl;
        funcB(n-1);
    }
    return 0;
}
int funcB(int n) {  // function B that calls funct A
    if (n > 1) {
        cout << n << endl;
        funcA(n/2);
    }
    return 0;
}

//  NESTED RECURSION - 
int nested(int n) {
    if (n > 100) { 
        return n-10;
    }
    return nested(nested(n+11)); // solves the nested one first
}

int main() {
    int num = 5;
    int x = factorial(num);
    cout << "DIRECT RECURSION: " << endl;
    cout << "Factorial of " << num << ": " << x << endl;;
    
    cout << "\nINDIRECT RECURSION: " << endl;
    funcA(10);

    cout << "\nNESTED RECURSION: " << endl;
    int m = nested(97);
    cout << m << endl;;
    return 0;
}