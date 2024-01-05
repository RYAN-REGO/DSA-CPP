class Solution {
public:
//using the shrinkable template
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int N = nums.size();
        long i = 0, j = 0, sum = 0, ans = 1;

        for(int j = 0; j < N; j++)
        {
            sum += nums[j];
            //we have to make the window valid
            while(((j - i + 1) * nums[j]) - sum > k)
            {
                //untill invalid 
                sum -= nums[i++];
            }
            //when it is valid 
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};

int functionName(vector<int>& nums, int k)
{
     int i = 0, j = 0, sum = 0, ans = 0;

     for(int j = 0; j < N; j++)
     {
        //keep updating the state
        //while(//invalid()//)
        {
            //update the state 
            //inorder to make it valid again
        }
        //after it is valid
        ans = max(ans, j-i+1);
     }

     return ans;
}