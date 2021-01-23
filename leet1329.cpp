#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<auto>> v)
{
    cout << "[";
    for (int i = 0; i < v.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << ", ";
        }
        cout << "],";
    }
    cout << "]" << endl;
}
class Solution
{
public:
    void solve(int si, int sj, vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size();
        vector<int> diagonal;
        int i = si, j = sj, idx = 0;
        //copy diagonal starting at mat[si][sj]
        while (i < n && j < m)
        {
            diagonal.push_back(mat[i++][j++]);
        }
        //sort it
        sort(diagonal.begin(), diagonal.end());
        idx = 0, i = si, j = sj;
        //place it back
        while (i < n && j < m)
        {
            mat[i++][j++] = diagonal[idx++];
        }
    }
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size(), i = 0;
        while (i < n)
        { //diagonals in first column
            solve(i++, 0, mat);
        }
        i = 0;
        while (i < m)
        { //diagonals from first row
            solve(0, i++, mat);
        }
        return mat;
    }
};
int main()
{
    vector<vector<int>> v = {{3, 3, 1, 1}, {2, 2, 1, 2}, {1, 1, 1, 2}};
    Solution ob;
    print_matrix(ob.diagonalSort(v));
    return 0;
}