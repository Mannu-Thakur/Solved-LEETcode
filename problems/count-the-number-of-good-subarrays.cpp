[2537] Count the Number of Good Subarrays  

https://leetcode.com/problems/count-the-number-of-good-subarrays/description/

* algorithms
* Medium (66.00%)
* Source Code:       2537.count-the-number-of-good-subarrays.cpp
* Total Accepted:    118.4K
* Total Submissions: 179.4K
* Testcase Example:  '[1,1,1,1,1]\n10'

Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.

 
Example 1:


Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.


Example 2:


Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.


 
Constraints:


	1 <= nums.length <= 10^5
	1 <= nums[i], k <= 10^9


