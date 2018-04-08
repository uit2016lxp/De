#include<iostream>
#include<string>
#include<stack>
#include<string>
#include<cctype>
#include<cmath>
#include<sstream>
using namespace std;
class calc
{
private:
	string s;
	bool pipei();
	int iny(char a);
	int outy(char a);
	string zhuan();
public:
	void run();
};
inline double str2num(const string &str){	//�ַ���ת����ʵ���ĺ���
	istringstream stream(str);//��ȡ�ַ�
	double result;
	stream>>result;//��ֵд����
	return result;
}
bool calc::pipei()//�����ȡ�����ַ����������Ϊ������ѹ��ջ���������Ϊ�������������Ϊ�գ��򵯳�ջ��Ԫ�أ���Ϊ�գ��򱨴�
{
	stack<char> S;
	bool judge=1;
	int l=s.length();
	int k=0;
	for(int i=0;i<l;i++){
		if(s[i]=='('){
			S.push(s[i]);
			k++;
		}
		else if(s[i]==')'){
			if(S.empty())
				judge=0;
			else{
				char str=S.top();
				S.pop();
			}
		}
		if(i==l-1&&S.empty()==0)
			judge=0;
	}
	if(judge){
		cout<<"ture"<<endl;return judge;
	}
	else{
		cout<<"error"<<endl;return judge;
	}
}
int calc::iny(char a){                //ջ�ڲ����������ȼ�
	switch(a){
		case '#':
			return 0;break;
		case '(':
			return 1;break;
		case '+':
			return 3;break;
		case '-':
			return 3;break;
		case '*':
			return 5;break;
		case '/':
			return 5;break;
		case '^':
			return 7;break;
	}
}
int calc::outy(char a){							//ջ������������ȼ�
	switch(a){
		case '+':
			return 2;break;
		case '-':
			return 2;break;
		case '*':
			return 4;break;
		case '/':
			return 4;break;
		case '(':
			return 8;break;
		case ')':
			return 1;break;
	}
}
string calc::zhuan(){						//��׺���ʽת��׺���ʽ
	stack<char> S;
	char t='#';
	S.push(t);
	string c;
	bool o=0;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(isdigit(s[i])||s[i]=='.')//�ж��Ƿ�Ϊ���ָ�С����
            {
			c=c+s[i];
            o=1;
			if(i==l-1)
				c=c+' ';//�ÿո����ֿ�
		}
		else{
			if(o==1){
				c=c+' ';
				o=0;
			}
			if(iny(S.top())<outy(s[i]))//ջ��Ԫ��С��ջ��Ԫ�أ���ջ
				S.push(s[i]);
			else{
				while(iny(S.top())>outy(s[i]))//ջ��Ԫ��С��ջ��Ԫ�أ���ջ��Ԫ����ջ������ջ��Ԫ��
                {
					c=c+S.top();
					S.pop();
				}
				if(iny(S.top())==outy(s[i]))
					S.pop();
				else
					S.push(s[i]);
			}
		}
	}
	while(S.top()!='#')//�������
    {
			c=c+S.top();
			S.pop();
	}
	return c;
}
void calc::run()
{
	cin>>s;
	if(pipei())
    {
		s=zhuan();
		cout<<s<<endl;		//�����׺���ʽÿ��ʵ������һ���ո���Ϊ�ָ�
		stack<double> m;
		int c=s.length();
		double a,b;
		string num,cl;
		for(int i=0;i<c;i++)
		{
			if(isdigit(s[i])||s[i]=='.')
				num=num+s[i];
			else if(s[i]==' ')
			{
                m.push(str2num(num));
                num=cl;
            }
			else{
				b=m.top();
                m.pop();
				a=m.top();
				m.pop();
				switch(s[i]){
					case '+':
						m.push(a+b);break;
					case '-':
						m.push(a-b);break;
					case '*':
						m.push(a*b);break;
					case '/':
						m.push(a/b);break;

				}
			}

		}
		double su=m.top();
		cout<<su<<endl;
	}
	else
    {
		cout<<"���Ų�ƥ���޷����м���"<<endl;
    }
}
int main()
{
	calc a;
	a.run();
}


