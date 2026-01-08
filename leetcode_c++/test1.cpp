 #include <iostream>
#include <vector>
#include "testThread.h"
#include "TComplex.h"
#include "LeetCode.h"
 using namespace std;

 //************************************
 // Method:    reverseString
 // FullName:  reverseString
 // Access:    public 
 // Returns:   std::string
 // Qualifier:
 // Parameter: string s
 //************************************

 extern int jiecheng(int n);
 string reverseString(string s) {
	
	 string temp = s;

	 for(int i=0;i<s.length();i++)
	 {
		 temp[i]=s[s.length()-i-1];
		printf("%d   ",&temp[i]);
	 }
	 printf("abc");
	 return temp;

 }

 vector<int> testVector()
 {
	 vector <int> vecN;
	 cout<<"before vecN capacity:"<<vecN.capacity()<<endl;

	 vecN.reserve(20);
	 cout<<"after vecN capacity:"<<vecN.capacity()<<endl;

	 cout<<"size"<<vecN.size()<<endl;

	 for (int i=0;i<30;i++)
	 {
		 vecN.push_back(i);
		 cout<<vecN.size()<<endl;
		 printf("%d\n",&vecN+1);

	 }
// 	 vecN.clear();
// 	 cout<<"vecN capacity is "<<vecN.capacity()<<endl;
// 	 cout<<"vecN size is "<<vecN.size()<<endl;
	 return vecN;

 }

extern void hannoi(int n,char from,char buffer,char to);
extern void heneita(int n ,char from,char buffer,char to);
extern int feibona(int n);

typedef struct node *linkList;
extern  node* initlinkList(int num[],int length);
extern void printLink(linkList head);

extern int getlengthRecursion(linkList head);

extern int getlengthTailRecursion(linkList head,int *num);

extern void stdForeach();

extern  void stdForeach();

extern  void stdLambda();

extern  void stdFunction();

extern  void stdBind();
struct fle
{
	char val;
	int array[];
};

extern void testcin();
extern void testif();

extern void teststring();
void testVar();

//测试sqlite
void testSqlite();

int main()
{
// 	string get = reverseString("hello");
// 	printf("%s",get.c_str());
// 	while(true){
// 
// 	}

	//测试线程
//	testThread::runThread3();

	//cout<<jiecheng(5)<<endl;

	//cout<<"请输入汉诺塔的层数:";
	//int a;
	//cin>>a;
	//hannoi(a,'A','B','C');
	//heneita(a,'A','B','C');

	//feibona(5);

	//测试链表
	//int nums[]={0,1,2,3,4};
	//cout<<"数组长度为："<<sizeof(nums)/sizeof(int)<<endl;
	//linkList list1= initlinkList(nums,sizeof(nums)/sizeof(int));
	//printLink(list1);

	//int len =0;
	//cout<<"递归法求链表长度为:"<<getlengthRecursion(list1)<<endl;

	//cout<<"尾递归求链表长度为:"<<getlengthTailRecursion(list1,&len)<<endl;

	//string 的长度为28
	//string menus[] = {"new","start","regret"};
	//cout<<"长度"<<sizeof(menus)<<endl;
	//cout<<"长度"<<sizeof(menus[0])<<endl;
	//string str = "012345678901234567890123456789012345678901234567890123456789";
	//string *p=&str;
	//cout<<"长度"<<sizeof(str)<<endl;
	//cout<<"长度"<<strlen(str.c_str())<<endl;
	//cout<<"长度"<<sizeof(string)<<endl;
	//cout<<"长度"<<sizeof(&str)<<endl;
	//cout<<"长度"<<sizeof(struct fle)<<endl;
	

	//stdForeach();

	//stdLambda();

	//stdFunction();

	//stdBind();

	//testcin();

	//testif();

// 	TComplex a(2,3), b(18,27);
// 	TComplex c = a+b;
// 	c.display();
// 	TComplex d = c-a;
// 	d.display();

//	testVar();

// 	testSqlite();

//  	vector<int> vec1 = testVector();
// 	for (int i=0;i<vec1.size();i++)
// 	{
// 		cout<<vec1[i]<<endl;
// 
// 	}

// 	teststring();

// 	string aa = LeetCode::leetcode3("abcabcbb");
// 	cout<<aa.c_str()<<endl;
// 
// 	cout<< LeetCode::leetcode3("bbbbbbbb").c_str()<<endl;
// 	cout<< LeetCode::leetcode3("pwwkew").c_str()<<endl;
// 	
// 	cout<< LeetCode::leetcode3("bbtablud").c_str()<<endl;

//    	cout<< LeetCode::leetcode5("babad").c_str()<<endl;
//    	cout<< LeetCode::leetcode5("cbbd").c_str()<<endl;
// 
// 	cout<< LeetCode::leetcode5("abcda").c_str()<<endl;

// 	cout<< LeetCode::leetcode6("A",1).c_str()<<endl;

// 	vector <string> abc;
// 	cout<< LeetCode::leetcode14(abc).c_str()<<endl;

	/*
	{//leetcode15 
		int nums[]={-1, 0, 1, 2, -1, -4};
		vector <int> vecNum;
		for (unsigned int i=0;i<sizeof(nums)/sizeof(int);i++)
		{
			vecNum.push_back(nums[i]);
		}
		vector<vector <int>> vecNums;

		vecNums=LeetCode::leetcode15(vecNum);
		for (auto vecnum: vecNums)
		{
			for (auto num:vecnum)
			{
				cout<<num;
				cout<<"   ";
			}
			cout<<endl;
		}
	}
	*/

	{
		int nums[]={-1, 2, 1, 4};
		vector <int> vecNum;
		for (unsigned int i=0;i<sizeof(nums)/sizeof(int);i++)
		{
			vecNum.push_back(nums[i]);
		}
		cout<< LeetCode::leetcode16(vecNum,1)<<endl;

	}

	while(true){

	}

	return 0;
}

