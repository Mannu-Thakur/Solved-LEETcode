[327] Count of Range Sum  

https://leetcode.com/problems/count-of-range-sum/description/

* algorithms
* Hard (37.07%)
* Source Code:       327.count-of-range-sum.cpp
* Total Accepted:    90.5K
* Total Submissions: 244.2K
* Testcase Example:  '[-2,5,-1]\n-2\n2'

Given an integer array nums and two integers lower and upper, return the number of range sums that lie in [lower, upper] inclusive.

Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j inclusive, where i <= j.

 
Example 1:


Input: nums = [-2,5,-1], lower = -2, upper = 2
Output: 3
Explanation: The three ranges are: [0,0], [2,2], and [0,2] and their respective sums are: -2, -1, 2.


Example 2:


Input: nums = [0], lower = 0, upper = 0
Output: 1


 
Constraints:


	1 <= nums.length <= 10^5
	-2^31 <= nums[i] <= 2^31 - 1
	-10^5 <= lower <= upper <= 10^5
	The answer is guaranteed to fit in a 32-bit integer.


