#include<iostream>
#include<vector>

using namespace std;

class NumberOfRotation {
public:
    int bs(vector<int>& nums)
    {
        int mid, start, end, N, next, prev;
        start = 0;
        end = nums.size() - 1;
        N = nums.size();

        //check which half is sorted, as element is in unsorted half
        while(start <= end)
        {
            if (nums[start] <= nums[end]) 
            {
               return start;
            }
             mid = start + (end - start) / 2;
             next = (mid + 1) % N;
             prev = (mid - 1 + N) % N;
            if(nums[mid] <= nums[next] && nums[mid] <= nums[prev])
            {
                return mid;
            }

            if(nums[mid] >= nums[start])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        
        }

        return -1;

    }
    int chat(vector<int>& arr)
    {
        int low = 0;
        int high = arr.size() - 1;
    
        while (low <= high) {
            // If the array is already sorted, then there is no rotation
            if (arr[low] <= arr[high]) {
                return low;
            }
            
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % arr.size();
            int prev = (mid - 1 + arr.size()) % arr.size();
            
            // Check if mid is the minimum element
            if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
                return mid;
            }
            // Decide which half to search
            if (arr[mid] >= arr[low]) {
                // Left half is sorted, move to the right half
                low = mid + 1;
            } else {
                // Right half is sorted, move to the left half
                high = mid - 1;
            }
        }
    }
};