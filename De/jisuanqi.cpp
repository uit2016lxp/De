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
inline double str2num(const string &str){	//字符串转换成实数的函数
	istringstream stream(str);//读取字符
	double result;
	stream>>result;//将值写入结果
	return result;
}
bool calc::pipei()//逐个读取所有字符，若输入的为“（”压入栈，若输入的为“）”，若其后不为空，则弹出栈顶元素，若为空，则报错
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
int calc::iny(char a){                //栈内操作符的优先级
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
int calc::outy(char a){							//栈外操作符的优先级
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
string calc::zhuan(){						//中缀表达式转后缀表达式
	stack<char> S;
	char t='#';
	S.push(t);
	string c;
	bool o=0;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(isdigit(s[i])||s[i]=='.')//判断是否为数字跟小数点
            {
			c=c+s[i];
            o=1;
			if(i==l-1)
				c=c+' ';//用空格区分开
		}
		else{
			if(o==1){
				c=c+' ';
				o=0;
			}
			if(iny(S.top())<outy(s[i]))//栈顶元素小于栈外元素，入栈
				S.push(s[i]);
			else{
				while(iny(S.top())>outy(s[i]))//栈外元素小于栈顶元素，将栈外元素入栈，弹出栈顶元素
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
	while(S.top()!='#')//依次输出
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
		cout<<s<<endl;		//输出后缀表达式每个实数后有一个空格作为分割
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
		cout<<"括号不匹配无法进行计算"<<endl;
    }
}
int main()
{
	calc a;
	a.run();
}


