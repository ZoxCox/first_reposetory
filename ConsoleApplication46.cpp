#pragma warning(disable: 4486)
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;



class person
{
private:
	string firstname;
	string lastname;
	long number;
public:
	person():firstname("noname"), lastname("noname"), number(0) {}
	person(string f, string l, long n) :firstname(f), lastname(l), number(n){}
	friend ostream& operator << (ostream& s, person p1)
	{
		s << p1.firstname << " " << p1.lastname << "  Phonenumber: " << p1.number;
		return s;
	}
	bool operator < (const person p2) const 
	{
		if (this->lastname == p2.lastname)
			return (this->firstname < p2.firstname);
		return (this->lastname < p2.lastname);
	}
};
class comparePersons
{
public:
	bool operator()(const person p1, const person p2)const
	{
		return (p1 < p2);
	}
};
int main()
{ 
	multiset<person, comparePersons>mst;
	multiset<person, comparePersons>::iterator iter1;

	person p1("aaa", "bbb", 1);
	person p2("aaab", "bbba", 2);
	person p3("aaa", "bbb", 1);
	person p4("aaabb", "bbbaa", 4);
	person p5("aaabbb", "bbbaaa", 5);
	
	mst.insert(p1);
	mst.insert(p2);
	mst.insert(p3);
	mst.insert(p4);
	mst.insert(p5);
	iter1 = mst.begin();
	
	ostream_iterator<person> out(cout, ", \n");
	copy(mst.begin(), mst.end(), out);
	






}