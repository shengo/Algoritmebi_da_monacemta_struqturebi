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

bool comparePairs(const pair<string, int>& a, const pair<string, int>& b) 
{ 
	return (a.first < b.first); 
}

bool comparePairs2(const pair<string, int>& a, const pair<string, int>& b) 
{ 
	return (a.second < b.second); 
}

int main()
{
	
	int val[] = {100, 630, 134, 24, -34, 384, 34, 100}; 

	vector<int>v(val, val+8);

	ostream_iterator<int> out(cout, " ");
	copy(v.begin(), v.end(), out);
	cout << endl;
	cout << endl;

	for (int i = 2; i <= v.size(); i++)
		push_heap(v.begin(), v.begin() + i);
	
	cout << "This is heap:\n";
	copy(v.begin(), v.end(), out);
	cout << endl;
	cout << endl;


	for (int i = v.size(); i >= 2; i--)
		pop_heap(v.begin(), v.begin() + i);
	cout << "This is sorted container:" << endl;
	copy(v.begin(), v.end(), out);
	cout << endl;
	cout << endl;


	random_shuffle(v.begin(), v.end());
	cout << "This is shuffled container:" << endl;
	copy(v.begin(), v.end(), out);
	cout << endl;
	cout << endl;

	make_heap(v.begin(), v.end());
	cout << "This is heap:\n";
	copy(v.begin(), v.end(), out);
	cout << endl;
	cout << endl;


	sort_heap(v.begin(), v.end());
	cout << "This is sorted container:" << endl;
	copy(v.begin(), v.end(), out);
	cout << endl;
	cout << endl;

	
	cout<<"Array version:"<<endl<<endl;



	char ar[] = { 'f', 'g', 'q', 'i', 'a', 'u', 'f', 'o'};
	int size = sizeof(ar) / sizeof(ar[0]);
	
	ostream_iterator<char> out2(cout, " ");
	
	copy(ar, ar+size, out2);
	cout << endl;
	cout << endl;

	for (int i = 2; i <= size; i++)
		push_heap(ar + 0, ar + i);
	
	cout << "This is heap:\n";
	copy(ar, ar + size, out2);
	cout << endl;
	cout << endl;

	for (int i = size; i >= 2; i--)
		pop_heap(ar , ar + i);
	cout << "This is sorted container:" << endl;
	copy(ar, ar + size, out2);
	cout << endl;
	cout << endl;


	random_shuffle(ar, ar + size);
	cout << "This is shuffled container:" << endl;
	copy(ar, ar + size, out2);
	cout << endl;
	cout << endl;

	make_heap(ar, ar + size);
	cout << "This is heap:\n";
	copy(ar, ar + size, out2);
	cout << endl;
	cout << endl;


	sort_heap(ar, ar + size, [](char a, char b) {return a<b;});
	cout << "This is sorted container:" << endl;
	copy(ar, ar + size, out2);
	cout << endl;
	cout << endl;
	


	vector<pair <string, int> > vv;
	/*{ 
		pair<string, int>("Giorgi", 87), 
		pair<string, int>("Anni", 97), 
		pair<string, int>("Ket", 91), 
		pair<string, int>("Lala", 90), 
		pair<string, int>("Abraam", 93), 
		pair<string, int>("Gogi", 77) 
	};
	*/
	
	vv.push_back( pair<string, int>("Giorgi", 87) );
	vv.push_back( pair<string, int>("Anni", 97) );
	vv.push_back( pair<string, int>("Ket", 91) );
	vv.push_back( pair<string, int>("Lala", 90) );
	vv.push_back( pair<string, int>("Abraam", 93) );
	vv.push_back( pair<string, int>("Gogi", 77) );

	make_heap(vv.begin(), vv.end());
	sort_heap(vv.begin(), vv.end());

	for(int i=0; i<vv.size(); i++)
		cout<<vv[i].first<<" "<<vv[i].second<<endl;
	
	cout<<endl<<"Sort by values:"<<endl<<endl;;

	make_heap(vv.begin(), vv.end(), comparePairs2);
	sort_heap(vv.begin(), vv.end(), [](pair<string, int>a, pair<string, int>b){return a.second < b.second;});

	for(int i=0; i<vv.size(); i++)
		cout<<vv[i].first<<" "<<vv[i].second<<endl;
	


	system("PAUSE");
	return main();

}
