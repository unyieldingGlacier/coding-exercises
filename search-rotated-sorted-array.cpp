/* LC 33
 * Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 */
#include<iostream>
#include<vector>
using namespace std;

//approach1 - find min elem; determine which side of min the key lies in and perform bin search only on that side.
int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1, m;
        if(n==0) return -1;
        //find min
        while(l < r) {
            m = l + ((r-l)>>1);
            if(nums[m] > nums[r]) l = m+1;
            else r = m;
        }
        
        //l=r=min=num_of_rotation
        int min1 = l;
        if(target == nums[min1]) return min1;
        
        l = (target <= nums[n-1])?min1:0;
        r = (target > nums[n-1])? min1: n-1;
        
        while(l <= r) {
            m = l + ((r-l)>>1);
            //int realmid = (m+min)%n;
            if(nums[m] == target) return m;
            else if(target > nums[m]) l = m+1;
            else r = m-1;
        }
        return -1;
    }

//approach2 - find min elem; perform normal binary search on the array starting from min
int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1, m;
        //find min
        while(l < r) {
            m = l + ((r-l)>>1);
            if(nums[m] > nums[r]) l = m+1;
            else r = m;
        }
        
        //l=r=min=num_of_rotation
        int min = l;
        l = 0, r = n-1;
        while(l <= r) {
            m = l + ((r-l)>>1);
            int realmid = (m+min)%n;
            if(nums[realmid] == target) return realmid;
            else if(nums[realmid] < target) l = m+1;
            else r = m-1;
        }
        return -1;
    }

/* Tested.
 * Time complexity: O(log n)
 * Space complexity: O(1)
 */
