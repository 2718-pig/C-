//编程：建立一个分数类。分数类的数据成员包括分子和分母，操作包括显示、输入、约分、通分、比较、加、减、乘、除、求相反数。

#include<iostream>
#include<cmath>
using namespace std;

class fraction{
	int above;         //分子
	int below;         //分母
	void reduction();            //约分
	void makeCommond(fraction&); //通分
public:
	fraction(int a=0,int b=1){       //构造函数
		above=a;below=b;
	}
	fraction add(fraction);      //两分数相加
	fraction sub(fraction);      //本分数减去实参分数
	fraction mul(fraction);      //两分数相乘
	fraction div(fraction);      //本分数除以实参分数
	fraction reciprocal();       //求倒数
	bool equal(fraction);        //等于运算
	bool greaterThan(fraction);  //大于运算
	bool lessThan(fraction);     //小于运算
	void display();              //显示分数
	void input();                //输入分数
};
void fraction::reduction(){                //约分先求最大公约数
	int a,b,temp;
	if(below<0){
		above=-above;
		below=-below;
	}
	a=abs(above);
	b=abs(below);
	while(a%b){                  //欧几里德法求最大公约数
		temp=a;
		a=b;
		b=temp%b;
	}
	above/=b;
	below/=b;
}
void fraction::makeCommond(fraction &b){
	int temp;
	reduction();
	b.reduction();
	above*=b.below;
	b.above*=below;
	temp=below*b.below;
	below=b.below=temp;
	}
fraction fraction::add(fraction b){
	fraction temp;
	makeCommond(b);          //通分
	temp.above=above+b.above;
	temp.below=below;
	temp.reduction();          //约分
	return temp;
}
fraction fraction::sub(fraction b){
	fraction temp;
	makeCommond(b);          //通分
	temp.above=above-b.above;
	temp.below=below;
	temp.reduction();          //约分
	return temp;
}
fraction fraction::mul(fraction b){
	fraction temp;
	temp.above=above*b.above;
	temp.below=below*b.below;
	temp.reduction();          //约分
	return temp;
}
fraction fraction::div(fraction b){
	fraction temp;
	if(b.above==0){
		cout<<"零不能作除数！"<<endl;
		exit(1);
	}
	temp.above=above*b.below;
	temp.below=below*b.above;
	temp.reduction();          //约分
	return temp;
}
fraction fraction::reciprocal(){
	fraction temp;
	temp.above=below;
	temp.below=above;
	temp.reduction();          //约分
	return temp;
}
bool fraction::equal(fraction b){
	makeCommond(b);          //通分
	return(above==b.above);
}
bool fraction::greaterThan(fraction b){
	makeCommond(b);          //通分
	return(above>b.above);
}
bool fraction::lessThan(fraction b){
	makeCommond(b);          //通分
	return(above<b.above);
}
void fraction::display(){
	reduction();          //约分
	cout<<"为："<<above<<"/"<<below<<endl;
}
void fraction::input(){
	while(1){
		cout<<"请顺序输入分子和分母（整数）："<<endl;
		cin>>above>>below;
		if(below==0)  cout<<"分母不可为零！"<<endl;
		else{
			reduction();
			return;
		}
	}
}
int main(){
	fraction f1(-3,-5),f2(-3,5),f3(3,-7),f4,f5(8);
	cout<<"f1"; f1.display();
	cout<<"f2"; f2.display();
	cout<<"f3"; f3.display();
	cout<<"f4"; f4.display();
	cout<<"f5"; f5.display();
	if(f1.greaterThan(f2))  cout<<"f1>f2"<<endl;
	if(f2.lessThan(f3))  cout<<"f2<f3"<<endl;
	if(f1.equal(f1))  cout<<"f1==f1"<<endl;
	f4=f1.add(f3);
	cout<<"f4=f1+f3"; f4.display();
	f4=f1.sub(f2);
	cout<<"f4=f1-f2"; f4.display();
	f4=f1.mul(f3);
	cout<<"f4=f1*f3"; f4.display();
	f4=f2.div(f3);
	cout<<"f4=f2/f3"; f4.display();
	f4=f2.reciprocal();
	cout<<"f4=1/f2"; f4.display();
	f4.input();                
	cout<<"f4"; f4.display();
	return 0;
}

