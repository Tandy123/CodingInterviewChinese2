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

// 面试题44：数字序列中某一位的数字
// 题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这
// 个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一
// 个函数求任意位对应的数字。

#include <iostream>
#include <algorithm>

using namespace std;

int countOfInteger(int digits) {
	if (digits == 1) {
		return 10;
	}
	else {
		return (int)pow(10, digits-1) * 9;
	}
}

int beginNumber(int digits) {
	if (digits == 1) {
		return 0;
	}
	else {
		return (int)pow(10, digits - 1);
	}
}

int digitAtIndex(int digits, int index){
	int number = beginNumber(digits) + index/digits;
	int indexFromRight = index % digits;
	return (number / (int)pow(10, digits - indexFromRight - 1))% 10;
}

int digitAtIndex(int index) {
	if (index < 0) {
		return -1;
	}
	int digits = 1;
	while (true) {
		int numbers = countOfInteger(digits);
		if (numbers * digits > index) {
			return digitAtIndex(digits, index);
		}
		index -= numbers * digits;
		++digits;
	}
	return -1;
}

void test(const char* testName, int inputIndex, int expectedOutput)
{
	if (digitAtIndex(inputIndex) == expectedOutput)
		cout << testName << " passed." << endl;
	else
		cout << testName << " FAILED." << endl;
}

int main()
{
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);  // 数字99的最后一位，9
	test("Test6", 190, 1);  // 数字100的第一位，1
	test("Test7", 1000, 3); // 数字370的第一位，3
	test("Test8", 1001, 7); // 数字370的第二位，7
	test("Test9", 1002, 0); // 数字370的第三位，0
	return 0;
}