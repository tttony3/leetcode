#ifndef _EASY_H
#define _EASY_H

#include<vector>
#include <string>
#include <ctype.h>
#include <sstream>
class Easy
{
public:
	Easy();
	~Easy();
public :
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	};
	struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
	};
public:
	int hammingDistance(int x, int y);
	std::vector<std::string> fizzBuzz(int n);
	std::string reverseString(std::string s);
	std::vector<int> findDisappearedNumbers(std::vector<int>& nums);
	int islandPerimeter(std::vector<std::vector<int>>& grid);
	int singleNumber(std::vector<int>& nums);
	int getSum(int a, int b);
	int maxDepth(TreeNode* root);
	char findTheDifference(std::string s, std::string t);
	TreeNode* invertTree(TreeNode* root);// 226. Invert Binary Tree
	int findContentChildren(std::vector<int>& g, std::vector<int>& s); //455. Assign Cookies
	std::vector<std::string> findWords(std::vector<std::string>& words);//500. Keyboard Row
	int findComplement(int num);//476. Number Complement
	std::vector<int> nextGreaterElement(std::vector<int>& findNums, std::vector<int>& nums);//496. Next Greater Element
	int findMaxConsecutiveOnes(std::vector<int>& nums);//485. Max Consecutive Ones
	std::vector<int> constructRectangle(int area);//492. Construct the Rectangle
	std::vector<std::string> findRelativeRanks(std::vector<int>& nums);//506. Relative Ranks
	void moveZeroes(std::vector<int>& nums);//283. Move Zeroes
	std::vector<int> twoSum(std::vector<int>& numbers, int target);//167. Two Sum II - Input array is sorted
	int minMoves(std::vector<int>& nums);//453. Minimum Moves to Equal Array Elements
	bool canConstruct(std::string ransomNote, std::string magazine);//383. Ransom Note
	int sumOfLeftLeaves(TreeNode* root);//404. Sum of Left Leaves
	std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2);//349. Intersection of Two Arrays
	std::string convertToBase7(int num);//504. Base 7
	bool isSameTree(TreeNode* p, TreeNode* q);//100. Same Tree
	int longestPalindrome(std::string s);//409. Longest Palindrome
	std::vector<std::string> readBinaryWatch(int num);//401. Binary Watch
	int maxProfit(std::vector<int>& prices);//122. Best Time to Buy and Sell Stock II
	int firstUniqChar(std::string s);//387. First Unique Character in a String
	void deleteNode(ListNode* node);//237. Delete Node in a Linked List
	int titleToNumber(std::string s);//171. Excel Sheet Column Number
	int majorityElement(std::vector<int>& nums);//169. Majority Element
	bool isAnagram(std::string s, std::string t);//242. Valid Anagram
	bool containsDuplicate(std::vector<int>& nums); //217. Contains Duplicate
	int romanToInt(std::string s);//13. Roman to Integer
	ListNode* reverseList(ListNode* head);//206. Reverse Linked List
	int missingNumber(std::vector<int>& nums);//268. Missing Number
	std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2);//350. Intersection of Two Arrays II
	int numberOfBoomerangs(std::vector<std::pair<int, int>>& points);//447. Number of Boomerangs
	std::string addStrings(std::string num1, std::string num2);//415. Add Strings
	TreeNode* sortedArrayToBST(std::vector<int>& nums);//108. Convert Sorted Array to Binary Search Tree
};

#endif