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

#pragma once
#include <queue>
#include <exception>

using namespace std;

template <typename T> class CStack
{
public:
	CStack(void);
	~CStack(void);

	// 在队列末尾添加一个结点
	void appendTail(const T& node);

	// 删除队列的头结点
	T deleteTail();

private:
	queue<T> queue1;
	queue<T> queue2;
};

template <typename T> CStack<T>::CStack(void)
{
}

template <typename T> CStack<T>::~CStack(void)
{
}

template<typename T> void CStack<T>::appendTail(const T& element)
{
	if (queue2.size() == 0)
	{
		queue1.push(element);
	}
	else
	{
		queue2.push(element);
	}
}

template<typename T> T CStack<T>::deleteTail()
{
	T tail;
	if (queue2.size() == 0)
	{
		while (queue1.size()>1)
		{
			T& data = queue1.front();
			queue1.pop();
			queue2.push(data);
		}
		if (queue1.size() == 0)
			throw new exception("stack is empty");

		tail = queue1.front();
		queue1.pop();
	}
	else if (queue1.size() == 0)
	{
		while (queue2.size()>1)
		{
			T& data = queue2.front();
			queue2.pop();
			queue1.push(data);
		}
		if (queue2.size() == 0)
			throw new exception("stack is empty");

		tail = queue2.front();
		queue2.pop();
	}
	return tail;
}
