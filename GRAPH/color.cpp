#include <iostream>
using namespace std;

void dfs(vector<vector<int>>& image, int sr, int sc, int color, int n, int m, int originalColor){
        if(sr<0 || sr>=n || sc<0 || sc>=m || image[sr][sc]==color || image[sr][sc]!=originalColor) return;

        image[sr][sc] = color;

        //call dfs for all four cases!
        dfs(image, sr+1, sc, color, n, m, originalColor);
        dfs(image, sr, sc+1, color, n, m, originalColor);
        dfs(image, sr-1, sc, color, n, m, originalColor);
        dfs(image, sr, sc-1, color, n, m, originalColor);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int originalColor = image[sr][sc];
         // we wont make visiteed array , for to check visited we check if it's color value is equals color or not.
         //starting node is given (sr, sc).

        dfs(image, sr, sc, color, n, m, originalColor);

        return image;
    }

int main()
{
    vector<vector<int>> image = {
    {1, 1, 1},
    {1, 1, 0},
    {1, 0, 1}
};
int sr = 1, sc = 1, color = 2;
vector<vector<int>> imageRes = floodFill(image, sr, sc, color);
for(auto it: imageRes){
    for(auto x: it){
        cout<<x<<" ";
    }
    cout<<endl;
}
    return 0;
}