#include <iostream>
#include <stack>

using namespace std;

template <class T>
class MyQueue
{
public:
	void push(T t)
	{
		head.push(t);
	}

	//删除对头元素
	//因为queue是一种先进先出，而stack是先进后出，
	//所以需要把head里的数据拷贝到tail中然后再从tail中pop头元素
	void pop()
	{
		while (!head.empty())
		{
			tail.push(head.top());
			head.pop();
		}
		tail.pop();

		//再将队尾栈容器元素拷贝到队头栈容器中
		while (!tail.empty())
		{
			head.push(tail.top());
			tail.pop();
		}
	}

	T& back()
	{
		return head.top();
	}

	//返回第一个元素
	T& front()
	{
		while (!head.empty())
		{
			tail.push(head.top());
			head.pop();
		}

		int tmp = tail.top();

		//再将队尾栈容器元素拷贝到队头栈容器中
		while (!tail.empty())
		{
			head.push(tail.top());
			tail.pop();
		}

		return tmp;
	}

private:
	stack<int> head;
	stack<int> tail;
};

int main()
{
	MyQueue<int> q;
	for (int i = 5; i < 10; i++)
	{
		q.push(i);
	}

	cout << q.front() << endl;
	cout << q.back() << endl;

	system("pause");
	return 0;

}
