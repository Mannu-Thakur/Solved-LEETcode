[1053] Previous Permutation With One Swap  

https://leetcode.com/problems/previous-permutation-with-one-swap/description/

* algorithms
* Medium (49.41%)
* Source Code:       1053.previous-permutation-with-one-swap.cpp
* Total Accepted:    45K
* Total Submissions: 91.1K
* Testcase Example:  '[3,2,1]'

Given an array of positive integers arr (not necessarily distinct), return the lexicographically largest permutation that is smaller than arr, that can be made with exactly one swap. If it cannot be done, then return the same array.

Note that a swap exchanges the positions of two numbers arr[i] and arr[j]

 
Example 1:


Input: arr = [3,2,1]
Output: [3,1,2]
Explanation: Swapping 2 and 1.


Example 2:


Input: arr = [1,1,5]
Output: [1,1,5]
Explanation: This is already the smallest permutation.


Example 3:


Input: arr = [1,9,4,6,7]
Output: [1,7,4,6,9]
Explanation: Swapping 9 and 7.


 
Constraints:


	1 <= arr.length <= 10^4
	1 <= arr[i] <= 10^4


