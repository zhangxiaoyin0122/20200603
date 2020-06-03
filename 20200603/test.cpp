#include <iostream>
#include <string>
using namespace std;

void test() {
	string str;  //������ַ���
	string str1("123");  //���캯�������ַ���
	string str2 = "456";
	string str3(str2);  //��������
	string str4("1234567890", 5); //12345
	string str5(str4, 2, 2);  //34
	string str6(10, 'x'); //xxxxxxxxxx
}

void test2() {
	string str("1234567890");
	int ret1 = str.size(); //������Ч�ַ��ĸ���
	int ret2 = str.length(); //������Ч�ַ��ĸ���
	int ret3 = str.capacity(); //���Դ�ŵ������Ч�ַ�����
	str.clear(); //ֻ������ݲ��ı�����

}
void test3() {
	string str("1234567890");
	int size = str.size();
	int cap = str.capacity();
	//resize(n) : ��n > size �� n>capacityʱ,����(���µĿռ�+��������+�ͷſռ�)+�µ�λ�ø�ֵ�����û�и���ֵ�ַ���Ĭ�ϸ�ֵ'\0' + �޸�size
	str.resize(20);
	int size1 = str.size();
	int cap1 = str.capacity();
	//resize(n) :��n < size ʱ,ֻ�޸�size
	str.resize(10);
	int size2 = str.size();
	int cap2 = str.capacity();
	//resize(n): �� n > size, �� n < capacityʱ: �µ�λ�ø�ֵ�����û�и���ֵ�ַ���Ĭ�ϸ�ֵ'\0' + �޸�size
	str.resize(30, 'a');
	int size3 = str.size();
	int cap3 = str.capacity();

}
void test4(){
	string str("0123456789");
	int size = str.size();
	int cap = str.capacity();

	//reserve: ����������һ�����޸�size������, 
	//�����С�������ǰ����С�����Ҫ��С������С��size,�����κβ����������С����������size������м�С�Ĳ���
	str.reserve(20);
	size = str.size();
	cap = str.capacity();

	str.reserve(5);
	size = str.size();
	cap = str.capacity();

}

void test5(){
	string s;
	//������ʵ������Ŀռ���ܲ�ͬ�� �ַ����ص㣺��'\0'��������Ҫ��'\0'Ԥ���ռ�
	//PJ��string ���ݹ��̣� ���Ϊ���ַ������󣬳�ʼ������СΪ15����һ������2������������1.5������
	int size = s.size();
	//ʹ��reserve��ǰ���ÿռ䣬�������Խ�ʡ���ݵĿ�������ߴ���Ч��
	s.reserve(200);
	int cap = s.capacity();

	cout << "��ʼ������" << cap << endl;
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