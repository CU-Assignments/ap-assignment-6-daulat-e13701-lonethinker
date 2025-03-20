class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int n = nums.size();
            vector<int> dpMax(n), dpMin(n);
            dpMax[0] = dpMin[0] = nums[0];
            int result = nums[0];
    
            for (int i = 1; i < n; i++) {
                if (nums[i] < 0) swap(dpMax[i - 1], dpMin[i - 1]);
                dpMax[i] = max(nums[i], nums[i] * dpMax[i - 1]);
                dpMin[i] = min(nums[i], nums[i] * dpMin[i - 1]);
                result = max(result, dpMax[i]);
            }
    
            return result;
        }
    };
    