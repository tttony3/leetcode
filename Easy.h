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
};

#endif