class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        map<int, int> x; 

        for(auto i: nums)
        {
            x[i]++;
            
        }
        for(auto it = x.begin(); it!= x.end(); it++)
        {
            if(it->second > 1) return true;
        }
      return false;
    }

};