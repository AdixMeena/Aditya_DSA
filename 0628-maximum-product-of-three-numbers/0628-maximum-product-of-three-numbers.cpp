
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // Sort the array in ascending order
        sort(nums.begin(), nums.end());
      
        // Get the size of the array
        int n = nums.size();
      
        // Calculate product of three largest numbers
        // This handles the case when all numbers are positive or when there are negative numbers
        // but the three largest positive numbers give the maximum product
        int productOfThreeLargest = nums[n - 1] * nums[n - 2] * nums[n - 3];
      
        // Calculate product of the largest number with two smallest numbers
        // This handles the case when there are two large negative numbers that,
        // when multiplied together and then with the largest positive number,
        // give a larger product
        int productWithTwoSmallest = nums[n - 1] * nums[0] * nums[1];
      
        // Return the maximum of the two possible products
        return max(productOfThreeLargest, productWithTwoSmallest);
    }
};