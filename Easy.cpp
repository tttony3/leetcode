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

void  Easy::moveZeroes(std::vector<int>& nums){
	int num = 0;
	for (int i = 0; i < nums.size(); i++){
		if (nums[i] == 0){
			num++;
			nums.erase(nums.begin()+i);
			i--;
		}
	}
	for (; num>0; num--){
		nums.push_back(0);
	}

}

vector<int>  Easy::twoSum(vector<int>& numbers, int target){
	int index1=0 ,index2=0;
	bool isFind = false;
	int i = 0;
	for (int one : numbers){
		int two = target - one;
		int tempi = i+1;
		int j = numbers.size() - 1;
		while (tempi <= j && !isFind){
			if (tempi == j){
				if (numbers[j] == two){
					index1 = i;
					index2 = j;
					isFind = true;
				}
				break;
			}
			else{
				if (two == numbers[tempi]){
					index1 = i;
					index2 = tempi;
					isFind = true;
					break;
				}
				else if (two == numbers[j]){
					index1 = i;
					index2 = j;
					isFind = true;
					break;
				}
				else if (j-tempi ==1){
					break;
				}
				else if (two == numbers[(tempi + j) / 2]){
					index1 = i;
					index2 = (tempi + j) / 2;
					isFind = true;
					break;
				}
				else if (two < numbers[(tempi + j) / 2]){
					j = (tempi + j) / 2;
				}
				else if (two > numbers[(tempi + j) / 2]){
					tempi = (tempi + j) / 2;
				}
				 
			}
		}
		i++;
	}
	vector<int> result;
	result.push_back(++index1);
	result.push_back(++index2);
	return result;
}

int Easy::minMoves(vector<int>& nums){
	int min = 0;;
	for (int i = 0; i < nums.size(); i++){
		if (i == 0)
			min = nums[0];
		else{
			if (nums[i] < min)
				min = nums[i];
		}
	}
	int moves = 0;
	for (int num : nums){
		if (num != min)
			moves += num - min;
	}
	return moves;
}

bool Easy::canConstruct(string ransomNote,string magazine){
	int magaz[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (char m : magazine){
		magaz[m - 'a'] ++;
	}
	for (char r : ransomNote){
		magaz[r - 'a'] --;
		if (magaz[r - 'a'] < 0)
			return false;
	}
	return true;
}

int Easy::sumOfLeftLeaves(Easy::TreeNode* root){
	if (root == NULL)
		return 0;
	int sum = 0;
	if (NULL != root->left){
		if (root->left->left == NULL && root->left->right == NULL)
			sum += root->left->val;
		else
			sum += sumOfLeftLeaves(root->left);
	}
	if ( NULL != root->right){
		 sum += sumOfLeftLeaves(root->right);
	}

	return sum;
}

vector<int> Easy::intersection(vector<int>& nums1, vector<int>& nums2) {
	set<int> resultSet;
	map<int, int> nums1map;
	vector<int> result;
	for (int i : nums1){
		nums1map.insert(pair<int, int>(i, 1));
	}
	for (int i : nums2){
		map<int, int >::iterator l_it;;
		l_it = nums1map.find(i);
		if (l_it != nums1map.end()){
			resultSet.insert(i);
		}
	}
	set<int>::iterator it; 
	for (it = resultSet.begin(); it != resultSet.end(); it++){
		result.push_back(*it);
	}
	return result;
}

string Easy::convertToBase7(int num) {
	int result =0;
	int i;
	int j;
	for (j=0 ; num / 7 != 0; num = num/7,j++){
		result += (num%7) * pow(10,j);
	}
	result += (num % 7) * pow(10, j);
	return int2str(result);
}

bool Easy::isSameTree(Easy::TreeNode* p, Easy::TreeNode* q){
	if (p == NULL && q == NULL)
		return true;
	else if (p != NULL && q == NULL)
		return false;
	else if (p == NULL && q != NULL)
		return false;
	else {
		if (p->val == q->val){
			return true & isSameTree(p->left, q->left)& isSameTree(p->right, q->right);
		}
		else
			return false;
	}
}

int Easy::longestPalindrome(string s){
	int a[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int b[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (char c : s){
		if (int(c) > 96)
			a[int(c-'a')]++;
		else
			b[int(c-'A')]++;
	}
	int sum = 0;
	for (int i : a){
		sum += i / 2 * 2;
	}
	for (int i : b){
		sum += i / 2 * 2;
	}
	if (sum < s.length() && sum != 0)
		return ++sum;
	else if (sum == 0 && s.length()>0)
		return 1;
	else
		return sum;
}

vector<string> Easy::readBinaryWatch(int num){
	vector<string> results;
	for (int i = 0; i <= num; i++){
		int hour = i;
		int minute = num - i;
		for (int h = 0; h <= 11; h++){
			int xh = 0;
			int sumh = 0;
			while (xh < 4){
				sumh += (h >> xh) & 0x1 ? 1 : 0;
				xh++;
			}
			if (sumh == hour){
				for (int m = 0; m <= 59; m++){
					int xm = 0;
					int summ = 0;
					while (xm < 6){
						summ += (m >> xm) & 0x1 ? 1 : 0;
						xm++;
					}
					if (summ == minute){
						string result = int2str(h);
						result += ":";
						if (m < 10)
							result += "0" + int2str(m);
						else
							result += int2str(m);
						results.push_back(result);
					}
				}
			}
		}
	}
	return results;
}

int Easy::maxProfit(vector<int>& prices){
	bool isHave = false;
	int price = 0;
	int profit = 0;
	for (int i = 0; i < prices.size();i++){
		if (i == prices.size() - 1){
			if (isHave)
				profit += prices[i] - price;
		}
		else{
			if (prices[i] < prices[i + 1] && !isHave){
				price = prices[i];
				isHave = true;
			}
			else if (prices[i] > prices[i + 1] && isHave){
				profit += prices[i] - price;
				isHave = false;

			}
		}
	}
	return profit;
}

int Easy::firstUniqChar(string s){
	int nums[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int i = 0;
	for (char c : s){
		nums[int(c - 'a')]++;
	}
	for (char c : s){
		if (nums[int(c - 'a')] == 1)
			return i;
		i++;
	}
	return -1;
}

void Easy::deleteNode(Easy::ListNode* node){
	node->val = node->next->val;
	node->next = node->next->next;
}

int Easy::titleToNumber(string s){
	int sum = 0;
	for (int i = 0; i < s.length(); i++){
		sum += int(s[i] - 'A' + 1) * pow(26, s.length()-i-1);
	}
	return sum;
}

int Easy::majorityElement(vector<int>& nums){
	map<int, int> m;
	for (int num : nums){
		map<int, int >::iterator l_it;;
		l_it = m.find(num);
		if (l_it != m.end()){
			(l_it->second)++;
			if (l_it->second > nums.size() / 2)
				return l_it->first;
		}
		else{
			m.insert(pair<int, int>(num, 1));
			if (1 > nums.size() / 2)
				return num;
		}
	}
	return 0;
}

bool Easy::isAnagram(string s, string t){
	int nums[26] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	for (char c : s){
		nums[int(c - 'a')]++;
	}
	for (char c : t){
		nums[int(c - 'a')]--;
	}
	for (int i : nums){
		if (i != 0)
			return false;
	}
	return true;
}

bool Easy::containsDuplicate(vector<int>& nums){
	map<int, int> m;
	for (int num : nums){
		map<int, int >::iterator l_it;;
		l_it = m.find(num);
		if (l_it != m.end()){
			return true;
		}
		else{
			m.insert(pair<int, int>(num, 1));
		}
	}
	return false;;
}

int Easy::romanToInt(string s){
	int sum = 0;
	for (char c : s){
		switch (c)
		{
		case 'I':
			sum += 1;
			break;
		case 'V':
			sum += 5;
			break;
		case 'X':
			sum += 10;
			break;
		case 'L':
			sum += 50;
			break;
		case 'C':
			sum += 100;
			break;
		case 'D':
			sum += 500;
			break;
		case 'M':
			sum += 1000;
			break;
		}
	}
	int last = 0;
	for (char c : s){
		int x;
		switch (c)
		{
		case 'I':
			x= 1;
			break;
		case 'V':
			x= 5;
			break;
		case 'X':
			x= 10;
			break;
		case 'L':
			x= 50;
			break;
		case 'C':
			x= 100;
			break;
		case 'D':
			x= 500;
			break;
		case 'M':
			x= 1000;
			break;
		}
		if (last == 0)
			last = x;
		else{
			if (last < x)
				sum -= 2 * last;
		}
		last = x;
	}
	return sum;
}

Easy::ListNode* Easy::reverseList(Easy::ListNode* head){
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	ListNode* last =NULL;
	ListNode* next =NULL;
	while (head->next != NULL){
		next = head->next;
		head->next = last;
		last = head;
		head = next;
	}
	head->next = last;
	return head;
	
}

int Easy::missingNumber(vector<int>& nums){
	int sum = 0;
	bool has = false;
	for (int i = 0; i < nums.size()+1; i++){
		sum += i;
	}
	for (int num : nums){
		if (num == 0)
			has = true;
		sum -= num;
	}
	return has ? sum : 0;
}

vector<int> Easy::intersect(vector<int>& nums1, vector<int>& nums2){
	map<int, int> nums1map;
	vector<int> result;
	for (int i : nums1){
		map<int, int >::iterator l_it;
		l_it = nums1map.find(i);
		if (l_it != nums1map.end()){
			l_it->second++;
		}
		else
			nums1map.insert(pair<int, int>(i, 1));
	}
	for (int i : nums2){
		map<int, int >::iterator l_it;;
		l_it = nums1map.find(i);
		if (l_it != nums1map.end() && l_it->second>0){
			result.push_back(i);
			l_it->second--;
		}
	}	
	return result;
}

int Easy::numberOfBoomerangs(vector<pair<int, int>>& points){
	int sum = 0;
	for (int i = 0; i < points.size(); i++){
		map<int, int> m;
		for (int j = 0; j < points.size(); j++){
			if (i == j)
				continue;
			map<int, int >::iterator l_it;
			int dis = pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2);
			l_it = m.find(dis);
			if (l_it != m.end()){
				l_it->second++;
			}
			else
				m.insert(pair<int, int>(dis, 1));
		}
		map<int, int>::iterator it;
		for (it = m.begin(); it != m.end(); ++it){
			if (it->second > 1){
				sum += it->second*(it->second - 1);
			}
		}

	}
	return sum;
}

string Easy::addStrings(string num1, string num2){
	string result = "";
	int c = 0;//进位
	for (int i = 0; i < (num1.length()<num2.length() ? num2.length() + 1 : num1.length()+1); i++){
		int a = 0;
		int b = 0;
		if (i < num1.length())
			a = int(num1[num1.length() - i - 1] - 48);
		if (i < num2.length())
			b = int(num2[num2.length() - i - 1] - 48);
		
		result = int2str((a+b+c)%10) + result;
		c = (a + b + c) / 10;
	}
	int i =0;
	for (; i < result.length(); i++){
		if (result[i] != '0'){
			break;
		}
	}
	result = result.substr(i, result.length());
	return result==""?"0":result;
}

Easy::TreeNode* Easy::sortedArrayToBST(vector<int>& nums){

}