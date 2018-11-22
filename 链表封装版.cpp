# include <cstdio>
# include <algorithm>
#include <string.h>
#include<cstring>

using namespace std

struct lianbiao
{ 
	struct node
	{
		int val;
		node * next;
		
		node(){}
		node(int val): val(val), next(0){}
	};
	
	node head;
	//�ڵ�n�����������val��0��Ϊ�ڿ�ͷ���� 
	void insert(int n , int val)
	{
		if(head.val < n)
		{
			puts("��Ч����");
			return; 
		}
		
		int i;
		node * now = &head;
		for(i = 0 ; i < n ; i++)
			now = now->next;
			
		node * p = new node(val);
		p->next = now->next;
		now->next = p;
		
		head.val++;
	}
	//ɾ����n��Ԫ��, 0��Ϊɾ���׽ڵ㣨ͬ1�� 
	void del(int n)
	{
		if(head.val < n)
		{
			puts("��Чɾ��");
			return;
		} 
		
		int i;
		node * now = &head;
		for(i = 1 ; i < n ; ++i)
			now = now->next;
			
		node * p = now->next;
		now->next = p->next;
		
		delete(p);
		head.val--;
	}
	
	void print()
	{
		if(!head.val)
		{
			puts("empty list!");
			return;
		}
		
		node * now = head.next;
		int i;
		for(i = 0 ; i < head.val ; ++i, now = now->next)
			printf("%d%s", now->val, i == head.val - 1 ? "\n" : " ");
	}

	void sort()
	{	
		if(head.val < 2)
			return;
	
		bool f = 1;
		while(f)
		{
			f = 0;
			node * now = head.next;
			
			int i;
			for(i = 0 ; i < head.val - 1 ; ++i, now = now->next)
			{
				if(now->val > now->next->val)
				{
					swap(now->val , now->next->val);
					f = 1;
				}
			}
		}
	}
	
	void push_front(int val)
	{
		insert(0 , val);
	}
	
	void pop_front()
	{
		del(1);
	}
	
	bool empty()
	{
		return !head.val;
	}
};

lianbiao lb;

int main()
{
	int a;
	while(1)
	{
		scanf("%d", &a);
		if(!a)
			break;
		lb.push_front(a);
	}
	
	lb.print();
	lb.sort();
	
	while(1)
	{
		lb.print();
		if(lb.empty())
			break;
		lb.pop_front();
	}
	
	return 0;
}
