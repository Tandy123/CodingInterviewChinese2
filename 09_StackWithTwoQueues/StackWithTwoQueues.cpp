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

// 面试题9扩展：用两个队列实现栈
// 题目：用两个队列实现一个栈。栈的声明如下，请实现它的两个函数appendTail
// 和deleteTail，分别完成在栈尾部插入结点和在栈尾部删除结点的功能。

#include "Stack.h"

// ====================测试代码====================
void Test(char actual, char expected)
{
	if (actual == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
	CStack<char> stack;

	stack.appendTail('a');
	stack.appendTail('b');
	stack.appendTail('c');

	char tail = stack.deleteTail();
	Test(tail, 'c');

	tail = stack.deleteTail();
	Test(tail, 'b');

	stack.appendTail('d');
	tail = stack.deleteTail();
	Test(tail, 'd');

	stack.appendTail('e');
	tail = stack.deleteTail();
	Test(tail, 'e');

	tail = stack.deleteTail();
	Test(tail, 'a');

	return 0;
}

