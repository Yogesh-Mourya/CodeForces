// Consider an n×n
//  grid filled with numbers as follows:

// the first row contains integers from 1
//  to n
//  from left to right;
// the second row contains integers from (n+1)
//  to 2n
//  from left to right;
// this pattern continues until the n
// -th row, which contains integers from (n2−n+1)
//  to n2
//  from left to right.
// Let's define the cost of a cell as its value plus the sum of its neighboring cells' values. Two cells are considered neighboring if they share a side.

// Your task is to calculate the maximum cost among all cells in the grid.

// The grid for n=4
//  and the optimal answer for it. The yellow cell has the maximum possible cost; the green cells are its neighbors. The cost of the cell is 15+11+14+16=56
// .
// Input
// The first line contains a single integer t
//  (1≤t≤100
// ) — the number of test cases.

// The only line of each test case contains a single integer n
//  (1≤n≤100
// ).

// Output
// For each test case, print a single integer — the maximum cost among all cells in the grid.

// Example
// InputCopy
// 5
// 1
// 2
// 3
// 4
// 5
// OutputCopy
// 1
// 9
// 29
// 56
// 95
// Note
// In the first example, there is only 1
//  cell with the cost 1
// .

// In the second example, the cell with value 4
//  has the maximum cost: 4+2+3=9
// .

// In the third example, the cell with value 8
//  has the maximum cost: 8+5+7+9=29
// .

// In the fourth example, the cell with value 15
//  has the maximum cost: 15+11+14+16=56
// .

// In the fifth example, the cell with value 19
//  has the maximum cost: 19+14+18+20+24=95
// .

#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
 
int cellVal(int i, int j, int& n){
    if(i>=0 && i < n && j >= 0 && j < n) return n*i+j+1;
        
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
        int val = 0;
 
        if(n==1){ 
            cout << 1 << "\n";
            goto done;
        }
        else if(n==2){
            val = cellVal(1,1,n);
            for(int d = 0; d < 4; d++) val += cellVal(1 + dx[d] ,1 + dy[d] , n);
        }
        else if(n==3){
            val = cellVal(2,1,n);
            for(int d = 0; d < 4; d++) val += cellVal(2 + dx[d] ,1 + dy[d] , n);
        }
        else if(n==4){
            val = cellVal(3,2,n);
            for(int d = 0; d < 4; d++) val += cellVal(3 + dx[d] ,2 + dy[d] , n);
        }
        else{
            val = cellVal(n-2,n-2,n);
            for(int d = 0; d < 4; d++) val += cellVal(n-2 + dx[d] ,n-2 + dy[d] , n);
        }
        
        cout << val << "\n";
        done:;
    }
 
    return 0;
}
