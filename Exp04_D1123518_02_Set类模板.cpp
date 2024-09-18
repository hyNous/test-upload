/*
已给出集合“类Set”的定义程序。请自行仔细阅读并理解程序。
类的属性详情参见实验教材P27，
本次作业完成功能：
利用该Set类求两个集合的交集。

即本次作业为Set类的客户程序，利用Set类完成下列功能。
【要求】
0. 首先运行并观察已给测试程序的执行效果。
   其中Union函数将课本范例略作了修改，溢出时返回错误提示信息。
   然后可以注释掉已给测试程序，自行在main函数编程完成下列功能。
1. 将给定的set类保存的元素数据类型从char修改为int，
   或者直接将set类修改为模板类。
   用以完成下述功能
2. 求两个整数集合的交集，交集是指由同属于两个集合的元素所构成的新集合。
   对存放在两个文本文件（学号_d1.txt、学号_d2.txt）中的两个整数集合求它们的交集，
   并将求出的交集写入另一个文本文件（学号_d3.txt）中
   按每行5个整数的格式，而原始数据文件（学号_d1.txt和学号_d2.txt）中的内容保持不变。
3. 假设：写入原始数据文件（学号_d1.txt、学号_d2.txt）的数据见后文，对读文件程序而言，
   文件中的整数数目不详，但都保证不超过20个整数，
   且整数之间以若干空格、或者回车换行间隔。
   选择合适的读入方式及控制循环的方式。
   提示：除了可能需要的吃空回车的操作，不使用getline()函数作为从文件读入数据的函数。
3. 不需要提交存放数据的txt文件，txt文件应该由程序自动生成。 
4. 本题功能不复杂，且set类定义已给，建议控制在30分钟内完成。

【程序】
1. 首先在运行原有测试程序后，将set类元素类型改为int，
   或者，一步到位，将set类定义为更通用的模板类。
2. 在main函数中：以ofstream流打开文本文件（学号_d1.txt、学号_d2.txt），写入原始数据。
   建议使用相对路径，如:ofstream ofile("D1234567_d1.txt");自动存入工程默认路径。
3. 在main函数中：以ifstream流打开文本文件（学号_d1.txt、学号_d2.txt），读取整数序列。
   并分别存入两个整型数组中。采用相对路径，会自动在默认路径中查找到步骤2.中创建的文件。   
4. 读取并统计元素个数，分别通过步骤3读取的两组数据创建两个Set对象。
5. 在main函数中：调用set的成员函数Intersect()，求出数据交集及其个数，
   存入新创建的第三个Set对象中。
6. 在main函数中：将交集对象中的整数依次写入到文本文件 
   （学号_d3.txt）中，然后关闭该文件。
   若重载了<<，用类对象直接输出数据到文件是最简便的方式。
   若不重载<<，则可在重载[]运算符后，在main函数中读取set类的元素写入文件。
7. 所有文件按每行5个整数的格式写入。
8*.重载>>不易，可尝试完成，并思考可能遇到的问题。

● 程序运行前的准备工作：
先用ofstream创建两个原始数据文件学号_d1.txt和学号_d2.txt，并输入一些整数，
整数之间以若干空格、或者回车换行间隔。
两个数据文件的内容为：
d1.txt：
23   17   56    0   88   
33   94   45   13   22   
18   25   66   86   99   
35   67
 
d2.txt：
32   21   33   56   66   
85   99   20   11   45   
98   22   67   81   91   
69   65   76   89

● 程序运行后的核对工作：使用记事本打开所生成的文件 d3.txt，
核对内容是否正确。
若学号_d1.txt、学号_d2.txt内容如上，则 学号_d3.txt内容应为： 
56   67   33   45   22   
66   99

测试过程中也可自行设定其他数据，包括使用其他数据类型完成测试。
并注意体会学习范例中Set类定义的实现，MyString类的实现可以参考其中对数组元素控制的方式。
建议自行复现Set类，至少理解其算法。

附：
重载>>运算符的一种简易方案：
首先读入元素个数，如3，然后循环读入元素，如整型时读入12,34,56.
则通过重载的>>从文件构造set类对象时，文件中需要在元素之前存有元素的个数。
此时，相应地，在重载<<时，也首先输出元素个数，然后循环输出各元素。
*/

//集合类的定义如下
#include<iostream> 
#include<fstream>
using namespace std; 
 
const int maxnum=20; 
enum ErrCode{noErr,overflow}; 
 
template <typename T> class set
{
private:  
	T elements[maxnum];       
	int num;                  //集合中存储的有效元素个数
public:  
	set(){num=0;}  
	bool Member(T);        //判断元素elem是否为本集合的成员  
	ErrCode AddElem(T);    //将新元素elem加入本集合  
	void RmvElem(T);       //将元素elem从该集合中删去  
	void Copy(set);           //将实参所标识的集合中的所有元素复制到本集合中去  
	bool Equal(set);          //判断两集合各自包涵的元素是否完全相同  
	void print();             //显示本集合的所有元素  
	set Intersect(set s1);    //求本集合与第一参数所指出的集合的交，并且作为返回值  
	ErrCode Union(set &s0, const set&s1);  //求本集合与s1所指出的集合的并，并且通过引用类型s0返回  
	                          //求并函数为范例算法的改进版，溢出时返回错误提示信息
	bool Contain(set);        //判断本集合是否包含实参所标识的集合中所有的元素 
	template <typename T> friend ostream& operator<<(ostream& out, const set<T>& );
	template <typename T> friend istream& operator>>(istream& in, set<T>&);
	T &operator[](int a);
}; 

//请阅读并理解下述各成员函数的算法，并可自行复现！
template <typename T> bool set<T>::Member(T elem)
{  
	int i;  
	for(i=0;i<num;i++)   
	    if(elements[i]==elem) 
	    	return true;  
	return false; 
} 

template <typename T> ErrCode set<T>::AddElem(T elem)
{    
	if(Member(elem))  return noErr;      //集合中已有elem，不重复加入  
	if(num<maxnum)
	{  
		elements[num++]=elem;   
		return noErr;  
	}  
	else return overflow;      //数组已满 
} 

template <typename T> void set<T>::RmvElem(T elem)
{ 
	int i;  
	for(i=0;i<num;i++)   
	    if(elements[i]==elem)
	    {
	        for(;i<num-1;i++)  
	            elements[i]=elements[i+1]; //当删除一个元素后，所有后继元素前移一位    
	        num--;   
	    } 
} 

template <typename T> void set<T>::Copy(set s)
{
    int i;  
    for(i=0;i<s.num;i++) 
        elements[i]= s.elements[i];  
    num= s.num; 
} 

template <typename T> bool set<T>::Equal(set s)
{  
	int i;  
	if(num!=s.num) return false;       //元素个数不同  
	for(i=0;i<num;i++)   
	    if(!s.Member(elements[i])) 
	    	return false;       //有不同元素  
	return true; 
} 

template <typename T> void set<T>::print()
{
	if(0==num) cout << "集合空" << endl;
	else
	{ 
		cout<<"集合的元素包括："<<endl;  
		for (int i = 0; i < num; i++)
			cout << elements[i] << "  ";
		cout<<endl; 
	}
} 

template <typename T> set<T> set<T>::Intersect(set s1)
{  
	int i,j; 
	set s;   
	for(i=0;i<num;i++)   
	    for(j=0;j<s1.num;j++)    
	        if(elements[i]==s1.elements[j])
	        {
	            s.elements[s.num++]=elements[i];     
	            break;    
	        }  
	return s; 
} 
template <typename T> ErrCode set<T>::Union(set &s0, const set&s1)
{
	while(s0.num) 
	{
		s0.RmvElem(s0.elements[--s0.num]);
	}
	s0.Copy(s1);
	for (int i = 0; i < num; i++)
	{
		if (s0.AddElem(elements[i]) == overflow)
		{
			cout << "++Union溢出++\n";
			return overflow;
			//若溢出则提前终止并返回，多余元素丢弃
		}
	}
	return noErr;
} 

template <typename T> bool set<T>::Contain(set s)
{ 
	int i;  
	for(i=0;i<s.num;i++)   
	    if(!Member(s.elements[i])) 
	    	return false;  
	return true; 
} 
template <typename T> T& set<T>::operator[](int a) 
{
	if (a > num - 1) return elements[num - 1];
	else return elements[a];
}
template <typename T> ostream& operator<<(ostream& out, const set<T>&s)
{
	if (0 == s.num) out << "集合空" << endl;
	else
	{
		out << "集合的元素包括：" << endl;
		for (int i = 0; i < s.num; i++)
		{
			out << s.elements[i] << "  ";
			if ((i+1) % 5 == 0) out << endl;
		}
		out << endl;
	}
	return out;
}
void CharToInt(char* &p, int& n) 
{
	n = 0;
	while (*p >= '0' && *p <= '9')
	{
		n *= 10;
		n += *p - '0';
		p++;
	}
}
template <typename T> istream& operator>>(istream& in, set<T>&s)
{
	//能力所限，类型仅认为存在int和char
	s.num = 0;
	char temp[100] = {};
	int i = 0;
	while (!in.eof()&&i<60)
		in.get(temp[i++]);
	if ((temp[0] >= 'a' && temp[0] <= 'z') || (temp[0] >= 'A' && temp[0] <= 'Z') )
	{
		int j = 0;
		while (j < i) 
		{
			if (j == maxnum) break;
			if (temp[0] >= 'a' && temp[0] <= 'z' || temp[0] >= 'A' && temp[0] <= 'Z')
				s.elements[s.num++] = temp[j];
			j++;
		}
	}
	else    
	{
		char* p = temp;
		while (s.num< maxnum)
		{
			if (*p == '\n') p++;
			if (*p == '\0') break;
			CharToInt(p, s.elements[s.num++]);
			p++;
		}
	}
	return in;
}
 
int main()  
{
	ofstream o1,o2;
	o1.open("D1123518_d1.txt");
	o2.open("D1123518_d2.txt");
	int d1[17] = { 23,17,56,0,88,33,94,45,13,22,18,25,66,86,99,35,67 };
	int d2[19] = { 32,21,33,56,66,85,99,20,11,45,98,22,67,81,91,69,65,76,89 };
	for (int i = 0; i < 17; i++)
	{
		o1 << d1[i] << " ";
		if ((i+1) % 5 == 0) o1 << endl;
	}
	o1 << endl;
	for (int i = 0; i < 19; i++)
	{
		o2 << d2[i] << " ";
		if ((i + 1) % 5 == 0) o2 << endl;
	}
	o2 << endl;
	o1.close();
	o2.close();
	ifstream i1, i2;
	i1.open("D1123518_d1.txt");
	i2.open("D1123518_d2.txt");
	set<int> s1, s2, s3;
	i1 >> s1;
	i2 >> s2;
	s1.print();
	s2.print();
	i1.close();
	i2.close();
	s3 = s1.Intersect(s2);
	s3.print();
	ofstream o3;
	o3.open("D1123518_d3.txt");
	o3 << s3;
	o3.close();


	ofstream o4, o5;
	o4.open("D1123518_d4.txt");
	o5.open("D1123518_d5.txt");
	o4 << "Men always remember love because of romance only";
	o5 << "Marlboro";
	o4.close();
	o5.close();
	ifstream i3, i4;
	i3.open("D1123518_d4.txt");
	i4.open("D1123518_d5.txt");
	set<char> s4, s5, s6; 

	//当T替换为char时，重载的>>在自定义的CharToInt(char* &p, int& n)函数处报错
	//说明默认预设情况下的可执行，无法处理复杂情况,注释可能出错语句后运行正常
	
	i3 >> s4;
	i4 >> s5;
	s4.print();
	s5.print();
	i3.close();
	i4.close();
	s6 = s4.Intersect(s5);
	s6.print();
	ofstream o6;
	o6.open("D1123518_d6.txt");
	o6 << s6;
	o6.close();

    return 0; 
} 	
	