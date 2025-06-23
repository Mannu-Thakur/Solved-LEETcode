[3452] Sum of Good Numbers  

https://leetcode.com/problems/sum-of-good-numbers/description/

* algorithms
* Easy (69.17%)
* Source Code:       3452.sum-of-good-numbers.cpp
* Total Accepted:    43.8K
* Total Submissions: 63.3K
* Testcase Example:  '[1,3,2,1,5,4]\n2'

Given an array of integers nums and an integer k, an element nums[i] is considered good if it is strictly greater than the elements at indices i - k and i + k (if those indices exist). If neither of these indices exists, nums[i] is still considered good.

Return the sum of all the good elements in the array.

 
Example 1:


Input: nums = [1,3,2,1,5,4], k = 2

Output: 12

Explanation:

The good numbers are nums[1] = 3, nums[4] = 5, and nums[5] = 4 because they are strictly greater than the numbers at indices i - k and i + k.


Example 2:


Input: nums = [2,1], k = 1

Output: 2

Explanation:

The only good number is nums[0] = 2 because it is strictly greater than nums[1].


 
Constraints:


	2 <= nums.length <= 100
	1 <= nums[i] <= 1000
	1 <= k <= floor(nums.length / 2)


