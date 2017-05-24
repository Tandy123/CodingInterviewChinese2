/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������9��չ������������ʵ��ջ
// ��Ŀ������������ʵ��һ��ջ��ջ���������£���ʵ��������������appendTail
// ��deleteTail���ֱ������ջβ�����������ջβ��ɾ�����Ĺ��ܡ�

#include "Stack.h"

// ====================���Դ���====================
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

