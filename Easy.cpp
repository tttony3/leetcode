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
		if (((z >> i) & 0x1)>0)
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

	return 0;
}

vector<string> Easy::findWords(vector<std::string>& words){
	vector<string> result;
	map<char, int > map;
	char line1[] = { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' };
	char line2[] = { 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' };
	char line3[] = { 'z', 'x', 'c', 'v', 'b', 'n', 'm' };
	for (int i = 0; i < sizeof(line1); i++){
		map.insert(pair<char, int>(line1[i], 1));
	}
	for (int i = 0; i < sizeof(line2); i++){
		map.insert(pair<char, int>(line2[i], 2));
	}
	for (int i = 0; i < sizeof(line3); i++){
		map.insert(pair<char, int>(line3[i], 3));
	}
	for (int i = 0; i < words.size(); i++){
		int line = 0;
		for (int j = 0; j < words[i].size(); j++){
			std::map<char, int>::iterator sIt;
			char c = tolower(words[i].at(j));
			sIt = map.find(c);
			if (line != sIt->second){
				if (line == 0)
					line = sIt->second;
				else{
					line = 4;
					break;
				}

			}
		}
		if (line != 4){
			result.push_back(words[i]);
		}


	}
	return result;
}

int Easy::findComplement(int num){
	int len = 0;
	int result = 0;
	for (int i = 0; i < 32; i++){
		if ((num >> i) & 0x1 == 0x1 && len<i){
			len = i;
		}
	}
	for (int i = 0; i < len; i++){
		if ((num >> i) & 0x1 == 0x1){
			result += 0x0 << i;
		}else
			result += 0x1 << i;
	}
	return result;
}

std::vector<int>  Easy::nextGreaterElement(std::vector<int>& findNums, std::vector<int>& nums){
	vector<int> result;
	for (int i = 0; i < findNums.size(); i++){
		bool isFind = false;
		for (int j = 0; j < nums.size(); j++){
			if (nums[j] == findNums[i]){
				for (int k = j; k < nums.size(); k++){
					if (nums[k]>findNums[i]){
						isFind = true;
						result.push_back(nums[k]);
						break;
					}
				}
				if (!isFind)
					result.push_back(-1);
				break;
			}
			
		}
		
	}
	return result;
}

int Easy::findMaxConsecutiveOnes(vector<int>& nums){
	int len = 0;
	int max = 0;
	for (int num : nums){
		if (num == 1)
			len++;
		else{
			if (len > max)
				max = len;
			len = 0;
		}
	}
	if (len > max)
		max = len;
	return max;
}

vector<int> Easy::constructRectangle(int area) {
	int l =sqrt(area);
	int w = l;
	while (l*w != area){
		if (l*w > area){
			l -= 1;
			w = area / l;
		}
		else if (l*w < area){
			l += 1;
			w = area / l;
		}
	}
	vector<int> result;
	result.push_back(l);
	result.push_back(w);
	return result;
}

string int2str(const int &int_temp)
{
	stringstream stream;
	stream << int_temp;
	string string_temp = stream.str();   //此处也可以用 stream>>string_temp  
	return string_temp;
}

vector<string>  Easy::findRelativeRanks(vector<int>& nums) {
	vector<string> result;
	
	vector<int> temp = nums;
	for (int i = 0; i < temp.size()-1; i++){
		for (int j = 1; j < temp.size()-i; j++){
			if (temp[j]>temp[j - 1]){
				int tmp = temp[j];
				temp[j] = temp[j - 1];
				temp[j - 1] = tmp;
			}
		}
	}
	for (int num : nums){
		int i = 0;
		int j = nums.size()-1;
		while (1){
			if (num == temp[i]){
				switch (i)
				{
				case 0 :
					result.push_back("Gold Medal");
					break;
				case 1:
					result.push_back("Silver Medal");
					break; 
				case 2:
					result.push_back("Bronze Medal");
					break;
				default:
					result.push_back(int2str(i+1));
					break;
				} 
					
				break;
			}
			else if (num == temp[j]){
				switch (j)
				{
				case 0:
					result.push_back("Gold Medal");
					break;
				case 1:
					result.push_back("Silver Medal");
					break;
				case 2:
					result.push_back("Bronze Medal");
					break;
				default:
					result.push_back(int2str(j+1));
					break;
				}

				break;
			}
			if (num < temp[(i + j) / 2]){
				i = (i + j) / 2;
			}
			else if (num > temp[(i + j) / 2]){
				j = (i + j) / 2;
			}
			else if (num == temp[(i + j) / 2]){
				switch ((i + j) / 2)
				{
				case 0:
					result.push_back("Gold Medal");
					break;
				case 1:
					result.push_back("Silver Medal");
					break;
				case 2:
					result.push_back("Bronze Medal");
					break;
				default:
					result.push_back(int2str((i + j) / 2+1));
					break;
				}
				break;
			}
		}
	}
	return result;
}