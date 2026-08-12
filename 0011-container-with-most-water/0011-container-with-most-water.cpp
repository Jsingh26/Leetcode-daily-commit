class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int max_heigth = 0;
        int overall_max = INT_MIN;
        while(l<r){
            
            max_heigth=min(height[l],height[r])*(r-l);
            overall_max=max(overall_max,max_heigth);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
           
            
        }
        return overall_max;
    }
};