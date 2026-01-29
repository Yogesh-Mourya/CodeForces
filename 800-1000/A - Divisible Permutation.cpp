// You are given an integer n
// . Construct a permutation∗
//  p
//  of length n
//  satisfying the following condition:

// |pi−pi+1|
//  is divisible by i
//  for every 1≤i≤n−1
// .
// It can be proven that such a permutation always exists under the constraints of the problem.

// ∗
// A permutation of length n
//  is an array consisting of n
//  distinct integers from 1
//  to n
//  in arbitrary order. For example, [2,3,1,5,4]
//  is a permutation, but [1,2,2]
//  is not a permutation (2
//  appears twice in the array), and [1,3,4]
//  is also not a permutation (n=3
//  but there is 4
//  in the array).

// Input
// Each test contains multiple test cases. The first line contains the number of test cases t
//  (1≤t≤100
// ). The description of the test cases follows.

// The only line of each test case contains a single integer n
//  (2≤n≤100
// ) — the length of the permutation p
//  to be constructed.

// Output
// For each test case, output n
//  integers p1,p2,…,pn
//  (1≤pi≤n
// , all pi
// -s are distinct) — the permutation you constructed.

// If there are multiple valid permutations, you may output any of them.

// Example
// InputCopy
// 2
// 2
// 3
// OutputCopy
// 1 2
// 2 3 1
// Note
// In the first test case, p=[1,2]
//  satisfies the condition because |p1−p2|=|1−2|=1
// , which is divisible by 1
// .

// In the second test case, p=[2,3,1]
//  satisfies the condition because:

// |p1−p2|=|2−3|=1
// , which is divisible by 1
// , and
// |p2−p3|=|3−1|=2
// , which is divisible by 2
// .



#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a = n/2+1;
        int b;
        
        if(n%2 == 0) b = a - 1;
        else b = a + 1;
        
        if(a>b){
            for(int i = 0; i < n; i++){
                if(i%2 == 0) cout << a++ << " ";
                else cout << b-- << " ";
            }
        }
        else{
            for(int i = 0; i < n; i++){
                if(i%2 == 0) cout << a-- << " ";
                else cout << b++ << " ";
            }
        }
        
        cout << "\n";
    }
    return 0;
}
