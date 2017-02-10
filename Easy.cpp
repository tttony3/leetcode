#include "Easy.h"
#include <windows.h>
#include <map>
#include <set>
#include <algorithm>  
using namespace std;
Easy::Easy(){
}


Easy::~Easy()
{
}

int Easy::hammingDistance(int x, int y){
	int z = x^y;
	int num = 0;
	for (int i = 0; i<32;i++)
		if (((z >> i) & 0x00000000000000000000000000000001)>0)
			num++;
	return num;
}

std::vector <std::string> Easy::fizzBuzz(int n){
	std::vector<std::string> result;
	for (int i = 0; i < n; i++){
		if ((i + 1) % 15 == 0)
			result.push_back("FizzBuzz");
		else if ((i + 1) % 3 == 0)
			result.push_back("Fizz");
		else if ((i + 1) % 5 == 0)
			result.push_back("Buzz");
		else
			result.push_back(std::to_string(i + 1));

	}

	return result;

}

std::string Easy::reverseString(std::string s){
	const char *str = s.c_str();
	
	char *result = (char*) malloc((s.size()+1) * sizeof(char));
	memset(result, 0, sizeof(char)* (s.size()+1));
	for (unsigned int i = 0; i < s.size(); i++){
		result[i] = str[s.size() - i - 1];
	}
	
	std::string someString(result);
	return someString;
}

std::vector<int> Easy::findDisappearedNumbers(std::vector<int>& nums){
	const int count = nums.size();
	bool *b = (bool *)malloc(sizeof(bool)*count);
	memset(b, false, sizeof(bool)*count);
	std::vector<int> result;
	for (int i = 0; i < count; i++){
		b[nums[i]-1] = true;
	}

	for (int i = 0; i < count; i++){
		if (!b[i]){
			result.push_back(i+1);
		}
	}
	return result;
}

int Easy::islandPerimeter(vector<vector<int>>& grid){
	int height = grid.size();
	int width = grid[0].size();
	int length = 0;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			if (grid[i][j] == 1){
				if (i == 0 ||grid[i - 1][j] == 0  )
					length++;
				if ( i == height - 1 ||grid[i + 1][j] == 0)
					length++;
				if (j == 0 || grid[i][j - 1] == 0)
					length++;
				if (j == width - 1 ||grid[i][j + 1] == 0)
					length++;
			}
		}
	}
	return length;
}

int Easy::singleNumber(vector<int>& nums){
	int result = nums[0];
	for (int i = 1; i < nums.size();i++){
		result ^= nums[i];
	}
	return result;
}

int Easy::getSum(int a, int b){
	int result = 0;
	int pro = 0;
	for (int i = 0; i < 32; i++){
		int tempa = (a >> i)& 1;
		int tempb = (b >> i)& 1;
		int s1= tempa^tempb;
		int co1 = tempa & tempb;
		result += (s1 ^pro) <<i;
		pro = (s1 & pro) | co1;

	}
	return result;
}
int Easy::maxDepth(TreeNode* root){
	return root == NULL ? 0 : max(maxDepth(root->left),maxDepth(root->right)) + 1;
}

char Easy::findTheDifference(string s, string t){
	bool b[26];
	memset(b, false, sizeof(bool)*26);
	int i = 0;
	for (i = 0; i < s.size(); i++){
		b[(char)s[i] - 97] = !b[(char)s[i] - 97];
	}
	for (i = 0; i < t.size(); i++){
		b[(char)t[i] - 97] = !b[(char)t[i] - 97];
	}
	for (i = 0; i < 26; i++){
		if (b[i])
			return char(97 + i);
	}
	return 0;
}

void invertNode(Easy::TreeNode* root){
	if (root->left != NULL && root->right != NULL){
		Easy::TreeNode *temp = root->left;
		root->left = root->right;
		root->right = temp;
		invertNode(root->left);
		invertNode(root->right);
	}
	else if (root->left != NULL && root->right == NULL){
		root->right = root->left;
		root->left = NULL;
		invertNode(root->right);
	}
	else if (root->left == NULL && root->right != NULL){
		root->left = root->right;
		root->right = NULL;
		invertNode(root->left);
	}
}
Easy::TreeNode *Easy::invertTree(Easy::TreeNode* root){
	if (root == NULL)
		return NULL;
	invertNode(root);
	return root;
}

bool search(int g,vector<int>& s,int index){
	if (s[index] == g){
		return true;
	}
}


int Easy::findContentChildren(std::vector<int>& g, std::vector<int>& s){

	map<int, int >sMap;
	map<int, int >gMap;
	map<int, int>::iterator sIt;
	map<int, int>::iterator gIt;
	map<int, int >::iterator itera;
	map<int, int >::iterator tmpItera;
	int count = 0;


	for (int i : s){
		itera = sMap.find(i);
		if (itera == sMap.end())
			sMap[i] = 1;
		else
			sMap[i] = sMap[i] + 1;
	}
	for (int i : g){
		tmpItera = sMap.find(i);
		if (tmpItera != sMap.end()){
			count++;
			tmpItera->second = tmpItera->second - 1;
			if (tmpItera->second == 0){
				sMap.erase(tmpItera);
			}

		}
		else{
			itera = gMap.find(i);
			if (itera == gMap.end())
				gMap[i] = 1;
			else
				gMap[i] = gMap[i] + 1;
		}
	}

	bool isContinue = true;
	for (int delta = 1; isContinue; ++delta){
		for (sIt = sMap.begin(); sIt != sMap.end();){
			itera = gMap.find((sIt->first) - delta);
			if (itera != gMap.end() && itera->second >0 && sIt->second> 0){
				sIt->second = sIt->second - 1;
				itera->second = itera->second - 1;
				++count;
				if (itera->second == 0){
					gMap.erase(itera);
				}
				if (sIt->second == 0){
					sMap.erase(sIt++);
				}
				else
					sIt++;
			}
			else sIt++;
		}
		if (gMap.size() == 0 || sMap.size() == 0)
			return count;

		sIt = --sMap.end();
		gIt = gMap.begin();
		if (gIt == gMap.end() || sIt == sMap.end())
			return count;
		if (sIt->first < gIt->first){
			isContinue = false;
			break;
		}

	}
	return count;
}
