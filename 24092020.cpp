//контейнери <deque> https://metanit.com/cpp/tutorial/7.8.php 
// контейнер <list> двозвязний список
#include <iostream>
#include <deque>
#include <list>
using namespace std;
template <class T>
ostream& operator << (ostream& os, const deque<T>& d) {
	for (auto el : d)
		cout << el << '\t'; cout << endl;
	return os;
}
template <class T>
ostream& operator << (ostream& os, list<T>& d) {
	for (auto el : d)
		cout << el << '\t'; cout << endl;
	return os;
}

void test() {
	int mas[]{ 5, 10, 15, 4, 30 };
	deque <int> d1;
	deque <float> d2(2, 9.99f); //явно вказуэмо тип флоат щоб можна було покласти в <float>
	deque <int> d3(mas, mas + 5);
	cout << d1 << endl; // працює лише з перевантаженим оператором << 
	cout << d2 << endl; // працює лише з перевантаженим оператором << 
	cout << d3 << endl; // працює лише з перевантаженим оператором << 
}
void test2() {
	int mas[]{ 5, 10, 15, 4, 30 };
	deque <int> d1;
	deque <float> d2(2, 9.99f); //явно вказуэмо тип флоат щоб можна було покласти в <float>
	deque <int> d3(mas, mas + 5);
	cout << d3[1];
	//по доступу до елементыв:
	d3.at(1); cout << endl; //- те саме що і квадратні дужки
	//front
	//back
	cout << d1.empty(); cout << endl;
	//size()
	deque <int> d4({ 5,4,-10,3,2,1 }); //ініціалайзер ліст
	deque <int> d5(10); //10 нулів
	cout << d5; cout << endl;

	auto it = d4.begin() + 2;
	cout << *it << endl;

	d4.push_front(100); // вставили сотню на початок
	cout << d4; cout << endl;
	//cout << *it << endl; //не працює
	d4.pop_front(); // видалили з початку сотню
	cout << d4; cout << endl;
}

void test3() {
	int mas[]{ 5, 10, 15, 4, 30 };
	deque <int> d3(mas, mas + 5);
	deque <int> d4({ 5,4,-10,3,2,1 }); //ініціалайзер ліст
	auto it = d4.begin() + 2;
	cout << *it << endl;
	it = d4.insert(it, 2, 200); // 2 по 200 в 2 позицію
	cout << d4; cout << endl;
	d4.insert(it, d3.begin(), d3.end());
	cout << d4; cout << endl;
}

void test4() {
	list <int> s1;
	list <int> s2(10);
	list <int> s3(5, 100);
	list <int> s4({ 5, 3, 2, 10, 15 });
	cout << s1; cout << endl;// працює лише з перевантаженим оператором << 
	cout << s2; cout << endl;// працює лише з перевантаженим оператором << 
	cout << s3; cout << endl;// працює лише з перевантаженим оператором << 
	cout << s4; cout << endl;// працює лише з перевантаженим оператором << 
	auto it = ++s4.begin();
	it++;
	cout << *it;
}
void test5() {
	list <int> s1;
	list <float> s2(10);
	list <int> s3(5, 100);
	list <int> s4({ 5, 3, 2, 10, 15 });
	cout << s1; cout << endl;// працює лише з перевантаженим оператором << 
	cout << s2; cout << endl;// працює лише з перевантаженим оператором << 
	cout << s3; cout << endl;// працює лише з перевантаженим оператором << 
	cout << s4; cout << endl;// працює лише з перевантаженим оператором << 
	auto it = s4.begin();
	advance(it, 2); //зсуває на 2
	cout << *it; cout << endl;
	int k = distance(s4.begin(), it);
	cout << k; cout << endl;
	s1.assign(3, 100);
	cout << s1;
}
void test6() {
	list <int> s1;
	list <float> s2(10);
	list <int> s3(5, 100);
	list <int> s4({ 5, 3, 2, 10, 15 });
	auto it = s4.begin();
	advance(it, 2);
	s1.assign(it, s4.end());
	cout << s1;
}
void test7() {
	list <int> s1;
	list <float> s2(10);
	list <int> s3(5, 100);
	list <int> s4({ 5, 3, 2, 10, 15 });
	auto it = s4.begin();
	advance(it, 2);
	s4.insert(it, 100);
	cout << s4;
	s4.insert(it, 3, 200);
	cout << s4;
	s4.insert(it, s3.begin(), s3.end());
	cout << s4;
}
void test8() {
	list <int> s1;
	list <float> s2(10);
	list <int> s3(5, 100);
	list <int> s4({ 5, 3, 2, 10, 15 });
	auto it = s4.begin();
	advance(it, 2);
	s4.erase(it);
	cout << s4;
}
bool IsNotEven(int k) { return k % 2; }
void test9() {
	list <int> s1;
	list <float> s2(10);
	list <int> s3(5, 100);
	list <int> s4({ 5, 3, 2, 10, 15 });
	/*auto it = s4.begin();
	while (it != s4.end())
	{
		if (*it % 2)
			it = s4.erase(it);
		else
			++it;
	}
	cout << s4;*/
	//або
	//s4.remove(10);
	//або
	s4.remove_if(IsNotEven);
	cout << s4;
}
int main()
{
	//test();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	test9();
	//test();


}