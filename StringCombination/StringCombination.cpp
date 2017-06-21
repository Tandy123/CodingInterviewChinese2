/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题38-2：字符串的组合
// 题目：输入一个字符串，打印出该字符串中字符的所有组合。例如输入字符串abc，
// 则打印出由字符a、b、c所能组合出来的所有字符串a、b、c、ab、ac、bc和abc。
#include <cstdio>
#include <vector>

using namespace std;

void Combination(char *string, int number, vector<char> &result);

void Combination(char *string)
{
	if (string == NULL) {
		return;
	}
	vector<char> result;
	int i, length = strlen(string);
	for (i = 1; i <= length; ++i)
		Combination(string, i, result);
}

void Combination(char *string, int number, vector<char> &result)
{
	//assert(string != NULL);
	if (number == 0)
	{
		static int num = 1;
		printf("第%d个组合\t", num++);

		vector<char>::iterator iter = result.begin();
		for (; iter != result.end(); ++iter)
			printf("%c", *iter);
		printf("\n");
		return;
	}
	if (*string == '\0')
		return;
	result.push_back(*string);
	Combination(string + 1, number - 1, result);
	result.pop_back();
	Combination(string + 1, number, result);
}

// ====================测试代码====================
void Test(char* pStr)
{
    if(pStr == nullptr)
        printf("Test for nullptr begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

	Combination(pStr);

    printf("\n");
}

int main(int argc, char* argv[])
{
    Test(nullptr);

    char string1[] = "";
    Test(string1);

    char string2[] = "a";
    Test(string2);

    char string3[] = "abb";
    Test(string3);

    char string4[] = "abc";
    Test(string4);

    return 0;
}

