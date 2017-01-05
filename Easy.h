#ifndef _EASY_H
#define _EASY_H

#include<vector>
#include <string>

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
};

#endif