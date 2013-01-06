/*********************************************\
2�� ��һC�������ܶ�������������ÿ����������-9999Ϊ������ǣ�������������1000�������Դ�С����Ĵ���������ڵ�һ��������Ҳ�ڵڶ��������е�����������ͬһ����������������Σ���������ʱ���������ڵ������ÿո����)��
*********************************************/

#include <iostream.h>
struct MyList
{
	int m_num;
	MyList *m_pNext;
};
void Input(MyList &head)
{
	cout<<"\n���������� ����-9999����:\n"<<endl;

	int temp = 0;
	cin>>temp;

	MyList *p = &head;
	head.m_num = 0;
	head.m_pNext = NULL;

	MyList *tp = NULL;
	bool bFlag = true;
	while(-9999 != temp)
	{
		p = head.m_pNext;
		if(0 != head.m_num)
		{
			bFlag = true;
			while(p->m_num < temp)
			{
				if(NULL == p->m_pNext)
				{
					bFlag = false;
					break;
				}
				p = p->m_pNext;
			}
			if(p->m_num != temp)
			{
				tp = new MyList;
				if(bFlag)
				{
					tp->m_num = p->m_num;
					p->m_num = temp;
				}
				else
				{
					tp->m_num = temp;
				}
				tp->m_pNext = p->m_pNext;
				p->m_pNext = tp;

				head.m_num ++;
			}
		}
		else
		{
			tp = new MyList;
			tp->m_num = temp;
			tp->m_pNext = NULL;
			head.m_pNext = tp;
			head.m_num ++;
		}
		cin>>temp;
	}
}
void GetSort(MyList &A,MyList &B,MyList &C)
{
	MyList *pA = NULL;
	MyList *pB = NULL;
	MyList *pC = NULL;
	MyList *tp;
	pA = A.m_pNext;
	pB = B.m_pNext;
	pC = &C;
	C.m_num = 0;
	for(int i = 0; i<A.m_num; i++)
	{
		if(pA == NULL || pB == NULL )
			return;
		while(pA->m_num < pB->m_num)
		{
			if(NULL== pA->m_pNext)
				return;
			pA = pA->m_pNext;
		}
		if(pA->m_num == pB->m_num)
		{
			C.m_num ++;
			tp = new MyList;
			tp->m_num = pA->m_num;
			tp->m_pNext = NULL;
			pC->m_pNext = tp;
			pC = pC->m_pNext;
			pA = pA->m_pNext;
			pB = pB->m_pNext;
		}
		else
		{
			while(pA->m_num > pB->m_num)
			{
				if(NULL== pB->m_pNext)
					return;
				pB = pB->m_pNext;
			}
		}
	}
}
void ShowList(MyList &T)
{
	MyList *p = T.m_pNext;
	for(int i = 0; i<T.m_num; i++)
	{
		cout<<p->m_num<<" ";
		p = p->m_pNext;
	}
	cout<<endl;
}
void Destroy(MyList &T)
{
	MyList *p = T.m_pNext;
	MyList *tp;
	for(int i = 0; i<T.m_num; i++)
	{
		tp = p->m_pNext;
		delete p;
		p = tp;
	}

}
int main()
{
	MyList A;
	MyList B;
	MyList C;
	Input(A);
	ShowList(A);
	Input(B);
	ShowList(B);
	GetSort(A,B,C);
	cout<<"������Ϊ:"<<endl;
	ShowList(C);
	Destroy(A);
	Destroy(B);
	Destroy(C);
	return 0;
}