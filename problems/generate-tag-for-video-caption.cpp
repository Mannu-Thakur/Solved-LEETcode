[3582] Generate Tag for Video Caption  

https://leetcode.com/problems/generate-tag-for-video-caption/description/

* algorithms
* Easy (31.38%)
* Source Code:       3582.generate-tag-for-video-caption.cpp
* Total Accepted:    34.1K
* Total Submissions: 108.8K
* Testcase Example:  '"Leetcode daily streak achieved"'

You are given a string caption representing the caption for a video.

The following actions must be performed in order to generate a valid tag for the video:


	
	Combine all words in the string into a single camelCase string prefixed with '#'. A camelCase string is one where the first letter of all words except the first one is capitalized. All characters after the first character in each word must be lowercase.
	
	
	Remove all characters that are not an English letter, except the first '#'.
	
	
	Truncate the result to a maximum of 100 characters.
	


Return the tag after performing the actions on caption.

 
Example 1:


Input: caption = "Leetcode daily streak achieved"

Output: "#leetcodeDailyStreakAchieved"

Explanation:

The first letter for all words except "leetcode" should be capitalized.


Example 2:


Input: caption = "can I Go There"

Output: "#canIGoThere"

Explanation:

The first letter for all words except "can" should be capitalized.


Example 3:


Input: caption = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"

Output: "#hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh"

Explanation:

Since the first word has length 101, we need to truncate the last two letters from the word.


 
Constraints:


	1 <= caption.length <= 150
	caption consists only of English letters and ' '.


