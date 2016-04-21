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
#include <iomanip>


using namespace std; 

class volcanoe{
public:
	string name;
	int height;

	volcanoe(){name = ""; height = 0;};
	volcanoe(string s, int h) {name = s; height = h;}
	~volcanoe(){};

	bool operator <(volcanoe v) {return this->height < v.height;}


	friend istream & operator >>(istream &in, volcanoe &v);
	friend ostream & operator <<(ostream &out, volcanoe &v);
	

};

istream & operator >>(istream &in, volcanoe &v) {in>>v.name>>v.height; return in;}
ostream & operator <<(ostream &out, volcanoe &v) {out<<v.name<<" "<<v.height<<endl; return out;}

int main()
{

	volcanoe arr [5];
	volcanoe tmp;

	cout<<"Enter 5 volcanoe Name, Height"<<endl;
	for(int i = 0; i < 5; i++)
	{	
		cin>>tmp;
		arr[i] = tmp;
	}

	for(int j = 0; j < 5; j++)
	{
		cout<<arr[j];
	}

	cout<<endl;
	
	int size = sizeof(arr)/sizeof(arr[0]);
	//make_heap(arr, arr + size, [](volcanoe &v1, volcanoe &v2){return v1.height < v2.height;});
	//sort_heap(arr, arr + size, [](volcanoe &v1, volcanoe &v2){return v1.height < v2.height;});
	make_heap(arr, arr + size);
	sort_heap(arr, arr + size);

	cout<<"sorted"<<endl;
	for(int j = 0; j < 5; j++)
	{
		cout<<arr[j];
	}

	system("PAUSE");
	return main();

}
