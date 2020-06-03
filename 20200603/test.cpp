#include <iostream>
#include <string>
using namespace std;

void test() {
	string str;  //构造空字符串
	string str1("123");  //构造函数构造字符串
	string str2 = "456";
	string str3(str2);  //拷贝构造
	string str4("1234567890", 5); //12345
	string str5(str4, 2, 2);  //34
	string str6(10, 'x'); //xxxxxxxxxx
}

void test2() {
	string str("1234567890");
	int ret1 = str.size(); //返回有效字符的个数
	int ret2 = str.length(); //返回有效字符的个数
	int ret3 = str.capacity(); //可以存放的最大有效字符个数
	str.clear(); //只清空内容不改变容量

}
void test3() {
	string str("1234567890");
	int size = str.size();
	int cap = str.capacity();
	//resize(n) : 当n > size 且 n>capacity时,增容(开新的空间+拷贝内容+释放空间)+新的位置赋值（如果没有给赋值字符，默认赋值'\0' + 修改size
	str.resize(20);
	int size1 = str.size();
	int cap1 = str.capacity();
	//resize(n) :当n < size 时,只修改size
	str.resize(10);
	int size2 = str.size();
	int cap2 = str.capacity();
	//resize(n): 当 n > size, 且 n < capacity时: 新的位置赋值（如果没有给赋值字符，默认赋值'\0' + 修改size
	str.resize(30, 'a');
	int size3 = str.size();
	int cap3 = str.capacity();

}
void test4(){
	string str("0123456789");
	int size = str.size();
	int cap = str.capacity();

	//reserve: 调整容量，一定不修改size和内容, 
	//如果减小容量，是按需减小，如果要减小的容量小于size,不做任何操作，如果减小的容量大于size，则进行减小的操作
	str.reserve(20);
	size = str.size();
	cap = str.capacity();

	str.reserve(5);
	size = str.size();
	cap = str.capacity();

}

void test5(){
	string s;
	//容量和实际申请的空间可能不同： 字符串特点：以'\0'结束，需要给'\0'预留空间
	//PJ版string 增容过程： 如果为空字符串对象，初始容量大小为15，第一次增容2倍，后续按照1.5倍增容
	int size = s.size();
	//使用reserve提前开好空间，后续可以节省增容的开销，提高代码效率
	s.reserve(200);
	int cap = s.capacity();

	cout << "初始容量：" << cap << endl;
	for (int i = 0; i < 200; ++i){
		s.push_back(i);
		if (cap != s.capacity()){
			cap = s.capacity();
			cout << cap << endl;
		}
	}
}

void test6(){
	string s;
	s.reserve(100);
	int size = s.size();
	int cap = s.capacity();
	s.resize(13);
	s.reserve(10);
	size = s.size();
	cap = s.capacity();

	s.shrink_to_fit();
	size = s.size();
	cap = s.capacity();

	s.reserve(10000);
	size = s.size();
	cap = s.capacity();

	s.reserve(15);
	size = s.size();
	cap = s.capacity();
}
int main() {
	test2();
	system("pause");
	return 0;
}