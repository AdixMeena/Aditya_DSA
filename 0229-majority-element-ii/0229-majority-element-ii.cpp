#include<bits/stdc++.h>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int mm = (nums.size()/3) + 1;
        vector<int>ans;
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
            
            if(freq[nums[i]] == mm)
            {
                ans.push_back(nums[i]);
            }
        } 
        return ans;
        
    }
};