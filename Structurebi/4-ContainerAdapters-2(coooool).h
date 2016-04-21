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

class student{
public:
	string name;
	int score;
	student();
	student(string , int );

	friend istream & operator >>(istream  &, student  &);
	friend ostream & operator >>(ostream  &, student  &);

	friend bool operator <(const student& , const student& );
	friend bool operator >(const student& , const student& );

};

student :: student() {}
student :: student(string n, int s){
	name=n;
	score=s;
}

istream & operator >>(istream &in, student &s){
	in>>s.name>>s.score;
	return in;
}

ostream & operator <<(ostream &out, student &s){
	out<<"Student: "<<s.name<< setw(10) <<"score: "<<s.score<<endl;
	return out;
}

bool operator <(const student& s1, const student& s2)
			{
			  return s1.score < s2.score;
			}
bool operator >(const student& s1, const student& s2)
			{
			  return s1.score > s2.score;
			}


int main()
{
	stack<student> s;
	queue<student> q;
	priority_queue< student, vector<student>, less<student> > pq1;
	priority_queue< student, vector<student>, greater<student> > pq2;
	
	student st;
	
	while(cin>>st)
	{
		s.push(st);
		q.push(st);
		pq1.push(st);
		pq2.push(st);
	}
	cout<<"Containers created."<<endl<<endl;


	cout<<"Students (print stack):"<<endl;
	while (!s.empty()) 
		{ 
			cout << s.top(); 
			s.pop(); 
		}
	cout<<endl;

	cout<<"Students (print queue):"<<endl;
	while (!q.empty()) 
		{ 
			cout << q.front(); 
			q.pop(); 
		}
	cout<<endl;

	cout<<"Students (print prioritety queue- max first):"<<endl;
	while (!pq1.empty()) 
		{ 
			cout << pq1.top(); 
			pq1.pop(); 
		}
	cout<<endl;

	cout<<"Students (print prioritety queue- min first):"<<endl;
	while (!pq2.empty()) 
		{ 
			cout << pq2.top(); 
			pq2.pop(); 
		}
	cout<<endl;



	system("PAUSE");
	return main();

}
