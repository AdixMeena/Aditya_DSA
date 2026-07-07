class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        int size = nums.size();

        vector <int> arr(2*size);

        for(int i = 0; i < 2*size; i++)
        {
            arr[i] = nums[i%size];
        }        
            return arr;
    }

};