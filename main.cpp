#include "Easy.h"
#include <windows.h>
#include <iostream>

using namespace std;

template <class T>
int getArrayLen(T& array)
{
	return (sizeof(array) / sizeof(array[0]));
}
int main(){
	Easy easy = Easy();

	//int distance = easy.hammingDistance(1, 4);

	/*
	std::vector<std::string> a = easy.fizzBuzz(15);
	for (std::string b : a)
		OutputDebugString(b.c_str());
	*/

	//OutputDebugString(easy.reverseString("siths").c_str());

	/*
	int n[] = { 1, 2,2, 4, 5 };
	std::vector<int> a(n, n + 5);
	std::vector<int> x = easy.findDisappearedNumbers(a);
	for (int i = 0; i < x.size(); i++){
		OutputDebugString(std::to_string(x.at(i)).c_str());
	}
	*/

	/*
	int n[] = {0,1,1};
	vector<vector<int> > b(1, vector<int>(n, n+3));
	char s[128];
	sprintf_s(s, " %d ", easy.islandPerimeter(b));
	OutputDebugString(s);
	*/
	/*
	char s[128];
	string a = "abcd";
	string b = "abcde";
	sprintf_s(s, " %c ", easy.findTheDifference(a, b));
	OutputDebugString(s);
	*/
	int a[] = { 1,2 ,3};
	int b[] = { 1,1 };
	vector<int>  av(a, a + getArrayLen(a));
	vector<int>  bv(b, b + getArrayLen(b));
	char s[128];
	sprintf_s(s, " %d \n", easy.findContentChildren(av, bv));
	OutputDebugString(s);
	return 0;
}