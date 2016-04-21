#include <iostream> 
#include <sstream> 
#include <iterator> 
#include <vector>
#include <functional>
#include <fstream>
#include <algorithm>



using namespace std; 


class rivers
{
private:
	string name;
	int length;
public:
	rivers();
	~rivers();
	friend istream & operator >> (istream &, rivers & );
	friend ifstream & operator >> (ifstream &, rivers & );

	friend ostream & operator << (ostream &, rivers &);
	int get_length();
	string get_name();
	void print();
};


rivers :: rivers() {}
rivers :: ~rivers() {}
int rivers :: get_length() {return length;}
string rivers :: get_name() {return name;}
void rivers :: print () {cout<<"River : "<<name<<", With length: "<<length<<endl;}

istream & operator >> (istream & in, rivers & r)
{
	in>>r.name>>r.length;
	return in;
}
ifstream & operator >> (ifstream & fin, rivers & r)
{
	fin>>r.name>>r.length;
	return fin;
}

ostream & operator << (ostream & out, rivers & r)
{
	out<<"River : "<<r.name<<", With length: "<<r.length<<endl;
	return out;
}


template <typename InputIterator >
void itPrint(InputIterator first, InputIterator last)
{
	while(first!=last)
		{
			cout<<*first<<endl;
			first++;
		}
}

template <typename InputIterator, typename Func >
InputIterator itMax(InputIterator first, InputIterator last, Func F)
{
	/**/
	InputIterator max=first;
	while(first!=last)
		{
			if(F(*max, *first)) max = first;

			first++;
		}
	return max;

}

bool isPred(rivers &a, rivers &b) 
{ 
	return (a.get_length() < b.get_length()); 
}


int main()
{
	
	vector<rivers> R;

	ifstream fin("data.txt");
	while(!fin.eof())
	{
		rivers tmp;
		fin>>tmp;
		R.push_back(tmp);
	}

	for(int i=0; i<R.size(); i++)
		cout<<R[i];
	
	cout<<endl;
	cout<<"Print using Iterators"<<endl;
	cout<<endl;

	itPrint(R.begin(), R.end());

	cout<<endl;
	cout<<"Max length river using Iterators :  "<<endl;
	cout<<endl;

	auto it = itMax(R.begin(), R.end(), [](rivers max, rivers r){return max.get_length() < r.get_length();} );
	//auto it = itMax(R.begin(), R.end(), isPred );


	//it->print();
	//cout<<it->get_name();
	cout<<*it<<endl;

	cout<<"Max length river using Iterators (2nd ver) :  "<<endl;
	it = itMax(R.begin(), R.end(), isPred );
	cout<<*it<<endl;


	system("PAUSE");
	return main();

}
