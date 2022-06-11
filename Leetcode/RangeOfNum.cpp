/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int first(vector<int> &nums, int target, int l, int h){
        int mid;
        while(l <= h)
        {
            mid = (l + h)/2;
            if((mid == 0 || target > nums[mid - 1]) && nums[mid] == target)
                return mid;
            if(nums[mid] >= target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    
    int last(vector<int> &nums, int target, int l, int h){
        int mid;
        while(l <= h)
        {
            mid = (l+h)/2;
            if((mid == nums.size() - 1 || target < nums[mid + 1]) && nums[mid] == target)
                return mid;
           if(nums[mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f, l;
        f = first(nums, target, 0, nums.size() - 1);
        l = last(nums, target, 0, nums.size() - 1);
        
        return {f, l};
    }
};

int main(){
    vector<int> ans;
    int num[] = {5, 7, 7, 8, 8, 10};
    vector<int> arr;
    arr.insert(arr.begin(), num, num+6);
    Solution ob;
    ans = ob.searchRange(arr, 8);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}