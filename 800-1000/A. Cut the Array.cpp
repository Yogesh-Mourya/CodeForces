// You are given an array of n
//  non-negative integers [a1,a2,…,an]
// .

// Your task is to cut it into three non-empty parts: a prefix, a middle part, and a suffix. Formally, you need to choose two integers l
//  and r
//  such that 1≤l<r<n
// , and obtain three parts:

// the prefix up the element at index l
//  inclusive (i.e., [a1,a2,…,al]
// );
// the central part from the element at index l+1
//  to the element at index r
//  inclusive (i.e., [al+1,al+2,…,ar]
// );
// the suffix from the element at index r+1
//  to n
//  inclusive (i.e., [ar+1,ar+2,…,an]
// ).
// Let s1,s2,s3
//  be the remainders of the sums of these parts modulo 3
// . In other words:

// s1=(∑i=1lai)mod3
// ;
// s2=(∑i=l+1rai)mod3
// ;
// s3=(∑i=r+1nai)mod3
// .
// Your task is to find such boundaries l
//  and r
//  that either all numbers s1,s2,s3
//  are different, or all numbers s1,s2,s3
//  are the same.

// Input
// The first line contains a single integer t
//  (1≤t≤1000
// ) — the number of test cases.

// Each test case consists of two lines:

// the first line contains a single integer n
//  (3≤n≤40
// );
// the second line contains n
//  integers a1,a2,…,an
//  (0≤ai≤40
// ).
// Output
// For each test case, if a suitable pair of integers l
//  and r
//  (1≤l<r<n
// ) exists, output these two integers (if there are multiple suitable pairs, you can output any of them). Otherwise, output two integers equal to 0
// .

// Example
// InputCopy
// 4
// 6
// 1 2 3 4 5 6
// 4
// 1 3 3 7
// 3
// 2 1 0
// 5
// 7 2 6 2 4
// OutputCopy
// 3 5
// 0 0
// 1 2
// 2 4
// Note
// Consider the examples from the statement:

// in the first example, the array is cut into parts [1,2,3]
// , [4,5]
// , [6]
// ; s1=s2=s3=0
// ;
// in the second example, there is no suitable cut;
// in the third example, the array is cut into parts [2]
// , [1]
// , [0]
// ; s1=2
// , s2=1
// , s3=0
// ;
// in the fourth example, the array is cut into parts [7,2]
// , [6,2]
// , [4]
// ; s1=0
// , s2=2
// , s3=1
// .

#include <bits/stdc++.h>
using namespace std;

int EqualOrNot(int i, int j, int n, vector<int> &v) {
    int a = 0, b = 0, c = 0;

    a = v[i-1] % 3;
    b = (v[j-1] - v[i-1]) % 3;
    c = (v[n-1] - v[j-1]) % 3;

    if ((a == b && b == c) || (a != b && b != c && a != c))
        return 1;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        int s = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            s+=v[i];
            v[i]=s;
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (EqualOrNot(i, j, n, v)) {
                    cout << i << " " << j << '\n';
                    goto done;
                }
            }
        }
        
        cout << "0 0\n";
        done:;
    }

    return 0;
}
