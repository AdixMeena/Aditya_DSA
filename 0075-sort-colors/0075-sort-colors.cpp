class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        // dutch national flag algo
        // only swap 0 & 2
   

        int high = nums.size() - 1;   
        int low = 0;  
        int mid = 0;
        
          while(mid <= high){

            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
          }

    }
};