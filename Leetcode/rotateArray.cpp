#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverse(vector<int> & nums, int a, int b){
        int i = a; 
        int j = b;
        
        while(i < j){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        //reversing whole array
        reverse(nums, 0, n - 1);
        
        //reversing first k elements
        reverse(nums, 0, k - 1);
        
        //reversing remaining array
        reverse(nums, k, n - 1);
           
    }
    
    
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    Solution ob;
    ob.rotate(nums, k);

    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    return 0;
}