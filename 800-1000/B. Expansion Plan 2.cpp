// ⠀
// You are analyzing an infinite grid with coordinates (X,Y)
//  (specifically, the cell immediately above (0,0)
//  is (0,1)
// , and the cell immediately on the right of (0,0)
//  is (1,0)
// ). Initially, only the cell at (0,0)
//  is black.

// You are given a string a1a2…an
//  of length n
//  consisting of characters "4"
//  and "8"
// , which describes n
//  expansion operations. For each i
//  from 1
//  to n
// , the following happens for all cells simultaneously:

// if si="4"
// : for each cell, if it is orthogonally adjacent to a black cell (i.e., it shares a side), it becomes black; otherwise, its state remains the same;
// if si="8"
// : for each cell, if it is orthogonally or diagonally adjacent to a black cell (i.e, it shares a side or a corner), it becomes black; otherwise, its state remains the same.
// Is the cell (x,y)
//  black at the end of the process?

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤104
// ). The description of the test cases follows.

// The first line of each test case contains three integers n
// , x
// , y
//  (1≤n≤2⋅105,−109≤x,y≤109
// ) — the number of expansion operations, and the x
//  and y
//  coordinates of the cell you are interested in, respectively.

// The second line of each test case contains a string s
//  of length n
//  consisting of characters "4"
//  and "8"
//  — the types of expansion operations.

// It is guaranteed that the sum of n
//  over all test cases does not exceed 2⋅105
// .

// Output
// For each test case, output YES
//  if the cell (x,y)
//  is black after the expansion operations described by the string s
// , and NO
//  otherwise.

// The judge is case-insensitive (for example, YES
// , Yes
// , yes
// , yEs
//  will all be recognized as positive answers).

// Example
// InputCopy
// 6
// 3 3 3
// 888
// 4 5 1
// 4884
// 4 3 -3
// 4884
// 7 -7 -5
// 4884884
// 10 0 0
// 4884884888
// 1 1 1
// 4
// OutputCopy
// YES
// NO
// YES
// NO
// YES
// NO
// Note
// The first three test cases are illustrated below:


// In the first test case, after the expansion operations in the string "888"
// , cell (3,3)
//  is black, so the answer is YES
// .

// In the second test case, cell (5,1)
//  is white after the expansion operations in the string "4884"
// .

#include <bits/stdc++.h>
using namespace std;

#define ll long long
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    
    while (t--) {
        int n,x,y;
        cin >> n >> x >> y;
        if(x < 0) x *= -1;
        if(y < 0) y *= -1;
        string s;
        cin >> s;
        int a=0,b=0;
        
        for(int i = 0; i < n; i++){
            if(s[i] == '4') a++;
            else b++;
        }
        int i = b + a, j = b;
        
        while(i >= b && j <= a + b){
            if(x <= i && y <= j){
                cout << "YES" << '\n';
                goto done;
            } 
            i--;
            j++;
        }
        cout << "NO" << '\n';
        done:;
    }

    return 0;
}
