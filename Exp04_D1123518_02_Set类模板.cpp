/*
�Ѹ������ϡ���Set���Ķ��������������ϸ�Ķ���������
�����������μ�ʵ��̲�P27��
������ҵ��ɹ��ܣ�
���ø�Set�����������ϵĽ�����

��������ҵΪSet��Ŀͻ���������Set��������й��ܡ�
��Ҫ��
0. �������в��۲��Ѹ����Գ����ִ��Ч����
   ����Union�������α������������޸ģ����ʱ���ش�����ʾ��Ϣ��
   Ȼ�����ע�͵��Ѹ����Գ���������main�������������й��ܡ�
1. ��������set�ౣ���Ԫ���������ʹ�char�޸�Ϊint��
   ����ֱ�ӽ�set���޸�Ϊģ���ࡣ
   ���������������
2. �������������ϵĽ�����������ָ��ͬ�����������ϵ�Ԫ�������ɵ��¼��ϡ�
   �Դ���������ı��ļ���ѧ��_d1.txt��ѧ��_d2.txt���е������������������ǵĽ�����
   ��������Ľ���д����һ���ı��ļ���ѧ��_d3.txt����
   ��ÿ��5�������ĸ�ʽ����ԭʼ�����ļ���ѧ��_d1.txt��ѧ��_d2.txt���е����ݱ��ֲ��䡣
3. ���裺д��ԭʼ�����ļ���ѧ��_d1.txt��ѧ��_d2.txt�������ݼ����ģ��Զ��ļ�������ԣ�
   �ļ��е�������Ŀ���꣬������֤������20��������
   ������֮�������ɿո񡢻��߻س����м����
   ѡ����ʵĶ��뷽ʽ������ѭ���ķ�ʽ��
   ��ʾ�����˿�����Ҫ�ĳԿջس��Ĳ�������ʹ��getline()������Ϊ���ļ��������ݵĺ�����
3. ����Ҫ�ύ������ݵ�txt�ļ���txt�ļ�Ӧ���ɳ����Զ����ɡ� 
4. ���⹦�ܲ����ӣ���set�ඨ���Ѹ������������30��������ɡ�

������
1. ����������ԭ�в��Գ���󣬽�set��Ԫ�����͸�Ϊint��
   ���ߣ�һ����λ����set�ඨ��Ϊ��ͨ�õ�ģ���ࡣ
2. ��main�����У���ofstream�����ı��ļ���ѧ��_d1.txt��ѧ��_d2.txt����д��ԭʼ���ݡ�
   ����ʹ�����·������:ofstream ofile("D1234567_d1.txt");�Զ����빤��Ĭ��·����
3. ��main�����У���ifstream�����ı��ļ���ѧ��_d1.txt��ѧ��_d2.txt������ȡ�������С�
   ���ֱ�����������������С��������·�������Զ���Ĭ��·���в��ҵ�����2.�д������ļ���   
4. ��ȡ��ͳ��Ԫ�ظ������ֱ�ͨ������3��ȡ���������ݴ�������Set����
5. ��main�����У�����set�ĳ�Ա����Intersect()��������ݽ������������
   �����´����ĵ�����Set�����С�
6. ��main�����У������������е���������д�뵽�ı��ļ� 
   ��ѧ��_d3.txt���У�Ȼ��رո��ļ���
   ��������<<���������ֱ��������ݵ��ļ�������ķ�ʽ��
   ��������<<�����������[]���������main�����ж�ȡset���Ԫ��д���ļ���
7. �����ļ���ÿ��5�������ĸ�ʽд�롣
8*.����>>���ף��ɳ�����ɣ���˼���������������⡣

�� ��������ǰ��׼��������
����ofstream��������ԭʼ�����ļ�ѧ��_d1.txt��ѧ��_d2.txt��������һЩ������
����֮�������ɿո񡢻��߻س����м����
���������ļ�������Ϊ��
d1.txt��
23   17   56    0   88   
33   94   45   13   22   
18   25   66   86   99   
35   67
 
d2.txt��
32   21   33   56   66   
85   99   20   11   45   
98   22   67   81   91   
69   65   76   89

�� �������к�ĺ˶Թ�����ʹ�ü��±��������ɵ��ļ� d3.txt��
�˶������Ƿ���ȷ��
��ѧ��_d1.txt��ѧ��_d2.txt�������ϣ��� ѧ��_d3.txt����ӦΪ�� 
56   67   33   45   22   
66   99

���Թ�����Ҳ�������趨�������ݣ�����ʹ����������������ɲ��ԡ�
��ע�����ѧϰ������Set�ඨ���ʵ�֣�MyString���ʵ�ֿ��Բο����ж�����Ԫ�ؿ��Ƶķ�ʽ��
�������и���Set�࣬����������㷨��

����
����>>�������һ�ּ��׷�����
���ȶ���Ԫ�ظ�������3��Ȼ��ѭ������Ԫ�أ�������ʱ����12,34,56.
��ͨ�����ص�>>���ļ�����set�����ʱ���ļ�����Ҫ��Ԫ��֮ǰ����Ԫ�صĸ�����
��ʱ����Ӧ�أ�������<<ʱ��Ҳ�������Ԫ�ظ�����Ȼ��ѭ�������Ԫ�ء�
*/

//������Ķ�������
#include<iostream> 
#include<fstream>
using namespace std; 
 
const int maxnum=20; 
enum ErrCode{noErr,overflow}; 
 
template <typename T> class set
{
private:  
	T elements[maxnum];       
	int num;                  //�����д洢����ЧԪ�ظ���
public:  
	set(){num=0;}  
	bool Member(T);        //�ж�Ԫ��elem�Ƿ�Ϊ�����ϵĳ�Ա  
	ErrCode AddElem(T);    //����Ԫ��elem���뱾����  
	void RmvElem(T);       //��Ԫ��elem�Ӹü�����ɾȥ  
	void Copy(set);           //��ʵ������ʶ�ļ����е�����Ԫ�ظ��Ƶ���������ȥ  
	bool Equal(set);          //�ж������ϸ��԰�����Ԫ���Ƿ���ȫ��ͬ  
	void print();             //��ʾ�����ϵ�����Ԫ��  
	set Intersect(set s1);    //�󱾼������һ������ָ���ļ��ϵĽ���������Ϊ����ֵ  
	ErrCode Union(set &s0, const set&s1);  //�󱾼�����s1��ָ���ļ��ϵĲ�������ͨ����������s0����  
	                          //�󲢺���Ϊ�����㷨�ĸĽ��棬���ʱ���ش�����ʾ��Ϣ
	bool Contain(set);        //�жϱ������Ƿ����ʵ������ʶ�ļ��������е�Ԫ�� 
	template <typename T> friend ostream& operator<<(ostream& out, const set<T>& );
	template <typename T> friend istream& operator>>(istream& in, set<T>&);
	T &operator[](int a);
}; 

//���Ķ��������������Ա�������㷨���������и��֣�
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
	if(Member(elem))  return noErr;      //����������elem�����ظ�����  
	if(num<maxnum)
	{  
		elements[num++]=elem;   
		return noErr;  
	}  
	else return overflow;      //�������� 
} 

template <typename T> void set<T>::RmvElem(T elem)
{ 
	int i;  
	for(i=0;i<num;i++)   
	    if(elements[i]==elem)
	    {
	        for(;i<num-1;i++)  
	            elements[i]=elements[i+1]; //��ɾ��һ��Ԫ�غ����к��Ԫ��ǰ��һλ    
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
	if(num!=s.num) return false;       //Ԫ�ظ�����ͬ  
	for(i=0;i<num;i++)   
	    if(!s.Member(elements[i])) 
	    	return false;       //�в�ͬԪ��  
	return true; 
} 

template <typename T> void set<T>::print()
{
	if(0==num) cout << "���Ͽ�" << endl;
	else
	{ 
		cout<<"���ϵ�Ԫ�ذ�����"<<endl;  
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
			cout << "++Union���++\n";
			return overflow;
			//���������ǰ��ֹ�����أ�����Ԫ�ض���
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
	if (0 == s.num) out << "���Ͽ�" << endl;
	else
	{
		out << "���ϵ�Ԫ�ذ�����" << endl;
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
	//�������ޣ����ͽ���Ϊ����int��char
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

	//��T�滻Ϊcharʱ�����ص�>>���Զ����CharToInt(char* &p, int& n)����������
	//˵��Ĭ��Ԥ������µĿ�ִ�У��޷����������,ע�Ϳ��ܳ���������������
	
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
	