#include <iostream>
using namespace std;

void helper(vector<vector<int>> &mat, int row, int col, string path, vector<string> &ans){
    int n = mat.size();

    if(row<0 || col<0 || row>=n || col>=n || mat[row][col] == 0 || mat[row][col] == -1){
        return;
    }
    if(row == n-1 && col == n-1){
        ans.push_back(path);
        return;
    }

    mat[row][col] = -1; //visit
    //decision at cell
    helper(mat, row-1, col, path+"U", ans);
    helper(mat, row+1, col, path+"D", ans);
    helper(mat, row, col-1, path+"L", ans);
    helper(mat, row, col+1, path+"R", ans);

    mat[row][col] = 1; //backtrack //unvisit


}


vector<string> findPath(vector<vector<int>> &mat){
    int n = mat.size();
    vector<string> ans;
    string path = "";

    helper(mat, 0, 0, path, ans);

    return ans;

}
int main()
{
    vector<vector<int>> mat = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
    vector<string> ans = findPath(mat);
    for(auto x: ans){
        cout<<x<<endl;
    }
    
    return 0;
}