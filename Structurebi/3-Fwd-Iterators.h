#include <iostream> 
#include <sstream> 
#include <iterator> 
#include <vector>
#include <list>
#include <functional>
#include <fstream>
#include <algorithm>



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
	
	int v1val[] = {0,1,2,3,4,5,6,7,8,9};

	vector<int> v1(v1val, v1val+10);
	vector<int>v2(10);

	myCopy(v1.begin(), v1.end(), v2.begin());

	for(int i=0; i<v1.size(); i++)
		cout<<v1[i]<<" ";

	cout<<endl;

	for(int i=0; i<v2.size(); i++)
		cout<<v2[i]<<" ";

	cout<<endl;

	//auto out(cout, "\t");
	ostream_iterator<int> out(cout, "  "); 
	myCopy(v1.begin(), v1.end(), out);
	cout<<endl;


	string v3val[] = {"noli", "erti", "ori", "sami", "otxi", "xuti", "eqvsi", "shvidi", "rva", "cxra"};
	
	vector<string> v3(v3val, v3val+10);
	ostream_iterator<string> outS(cout, "  "); 
	myCopy(v3.begin(), v3.end(), outS);
	cout<<endl;



	int v4val[] = {0,1,2,3,4,4,6,7,8,9};
	vector<int> v4(v4val, v4val+10);
	
	list<int> lst(v4val, v4val+10);
	
	auto nbr_it = neigbours(v4.begin(), v4.end());
	auto nbr_it2 = neigbours(lst.begin(), lst.end());

	cout<<*nbr_it<<endl;
	cout<<*nbr_it++<<endl;


	int v5val[] = {3,4,33,3,4,3,6,12,3,3};
	vector<int> v5(v5val, v5val+10);

	cout<<"Before change: "<<endl;
	itPrint(v5.begin(), v5.end());
	cout<<"After change: "<<endl;
	itReplace(v5.begin(), v5.end(), 3, 0);
	itPrint(v5.begin(), v5.end());

	cout<<"After change, print with recursive: "<<endl;
	itPrint_rec(v5.begin(), v5.end());

	system("PAUSE");
	return main();

}
