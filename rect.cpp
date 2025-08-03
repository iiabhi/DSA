#include <iostream>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        if(n==0) return 0;

        stack<int> stk;
        //left smallest element.
        
        vector<int> left(n);

        for(int i=0; i<n; i++){
            while(!stk.empty() && heights[i] <= heights[stk.top()]){
                stk.pop();
            }
            if(stk.empty()){
                left[i] = -1;
            }else{
                left[i] = stk.top();
            }
            stk.push(i);
        }

        while(!stk.empty()){
            stk.pop();
        }
        //right smallest element.
        vector<int> right(n);

        for(int i=n-1; i>=0; i--){
            while(!stk.empty() && heights[i] <= heights[stk.top()]){
                stk.pop();
            }
            if(stk.empty()){
                right[i] = n;
            }else{
                right[i] = stk.top();
            }
            stk.push(i);
        }
        // for(auto x: left){
        //     cout<<x<<" ";
        // }

        int maxArea = 0;
        for(int i=0; i<n; i++){
            int width = right[i] - left[i] - 1;
            
            int area = heights[i]*width;
            maxArea = max(area, maxArea);
        }
        return maxArea;

    }

int main()
{
    vector<int> vec = {2,1,5,6,2,3};
    cout<<largestRectangleArea(vec)<<endl;
    return 0;
}