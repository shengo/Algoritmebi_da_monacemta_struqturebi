#include <iostream> 
#include <sstream> 
#include <iterator> 
#include <vector>
#include <list>
#include <functional>
#include <fstream>
#include <algorithm>
#include <stack>
#include <queue>


using namespace std; 


template <typename InIt, typename OutIt>
OutIt myCopy(InIt begin, InIt end, OutIt result)
{
	while(begin != end)
		{
		*result = *begin;
		begin ++;
		result++;
		}
	return result;
}

template <typename FwdIt>
FwdIt neigbours(FwdIt begin, FwdIt end)
{
	if(begin != end)
		{
			FwdIt next = begin++;
			while(next != end)
			{
				if(*next == *begin) return begin;
				begin++;
				next++;
			}
	}
	return end;
}

template <typename FwdIt, typename T>
void itReplace(FwdIt begin, FwdIt end, T v1, T v2)
{
	while(begin != end)
			{
				if(*begin == v1) *begin=v2;				
				begin++;
			}
}
	

template <typename FwdIt>
void itPrint(FwdIt begin, FwdIt end)
{
	while(begin != end)
			{
				cout<<*begin<<" ";			
				begin++;
			}
	cout<<endl;
}
template <typename FwdIt>
void itPrint_rec(FwdIt begin, FwdIt end)
{
	if(begin == end) cout<<endl;
	else
	{
	cout<<*begin<<" ";			
	begin++;
	itPrint_rec(begin, end);
	}
}



int main()
{
	
	vector<int> v;
	for (int i = 0; i<9; i++)
		v.push_back(rand() % 77);

	ostream_iterator<int> oi(cout, "\t");
	copy(v.begin(), v.end(), oi);
	cout << endl;
	
	stack<int> s;
	queue<int, list<int> > q;
	priority_queue<int> pq;
	priority_queue<int, vector<int>, greater<int> > pq2;
	
	for (int i = 0; i<9; i++)
	{
		s.push(v[i]);
		q.push(v[i]);
		pq.push(v[i]);
		pq2.push(v[i]);
	}

	cout<<"Stack:"<<endl;
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;

	cout<<"Queue:"<<endl;
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;

	cout<<"Priority Queue:"<<endl;
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;

	cout<<"Priority Queue2(less):"<<endl;
	while(!pq2.empty())
	{
		cout<<pq2.top()<<" ";
		pq2.pop();
	}
	cout<<endl;

	system("PAUSE");
	return main();

}
