[329] Longest Increasing Path in a Matrix  

https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

* algorithms
* Hard (55.36%)
* Source Code:       329.longest-increasing-path-in-a-matrix.cpp
* Total Accepted:    633.8K
* Total Submissions: 1.1M
* Testcase Example:  '[[9,9,4],[6,6,8],[2,1,1]]'

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 
Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].


Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.


Example 3:


Input: matrix = [[1]]
Output: 1


 
Constraints:


	m == matrix.length
	n == matrix[i].length
	1 <= m, n <= 200
	0 <= matrix[i][j] <= 2^31 - 1


