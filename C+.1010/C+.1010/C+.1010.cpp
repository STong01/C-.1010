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

	//ɾ����ͷԪ��
	//��Ϊqueue��һ���Ƚ��ȳ�����stack���Ƚ������
	//������Ҫ��head������ݿ�����tail��Ȼ���ٴ�tail��popͷԪ��
	void pop()
	{
		while (!head.empty())
		{
			tail.push(head.top());
			head.pop();
		}
		tail.pop();

		//�ٽ���βջ����Ԫ�ؿ�������ͷջ������
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

	//���ص�һ��Ԫ��
	T& front()
	{
		while (!head.empty())
		{
			tail.push(head.top());
			head.pop();
		}

		int tmp = tail.top();

		//�ٽ���βջ����Ԫ�ؿ�������ͷջ������
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
