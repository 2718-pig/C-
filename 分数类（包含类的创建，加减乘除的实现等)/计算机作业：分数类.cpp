//编程：建立一个分数类。分数类的数据成员包括分子和分母，操作包括显示、输入、约分、通分、比较、加、减、乘、除、求相反数。

#include<iostream>
#include<cmath>
using namespace std;

class fraction{
    friend void printfraction(fraction& f);
	int above;         //分子
	int below;         //分母
	void reduction();            //约分
	void makeCommond(fraction& b); //通分
public:
	fraction(int a=0,int b=1){       //构造函数
		above=a;below=b;
        reduction();//进行一次约分，便于后续加减等操作
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
    int get_above()const{return above;};
    int get_below()const{return below;};
};
int max_remainder(int m,int n){     //求最大公因数
//此处使用辗转相除法：简单来说，就是把第i次的除数做第i+1次的被除数，把第i次的余数做第i+1次的除数，直到余数等于0
    int r=0;
    while(r=m%n){
        m=n;
        n=r;
    }
    return n;
}//此处也可以用递归，代码如下：
    // int max_remainder(int m,int n){
    //     if(m%n==0){
    //         return n;
    //     }   else{
    //         int r=m%n;
    //         return max_remainder(n,r);
    //     }
    // }
void fraction::reduction(){     //约分:分子分母同时除以最大公约数
    int remainder=max_remainder(this->above,this->below);
    this->above/=remainder;
    this->below/=remainder;
}
void fraction::makeCommond(fraction& b){    //通分
    int temp=(this->below)*b.below;
    this->above*=b.below;
    b.above*=this->below;
    this->below=b.below=temp;
}
fraction fraction::add(fraction b){     //加法实现
    this->makeCommond(b);
    return fraction((this->above+b.above),this->below);
}
fraction fraction::sub(fraction b){   //减法实现
    this->makeCommond(b);
    return fraction((this->above-b.above),this->below);
}
fraction fraction::mul(fraction b){   //乘法
    fraction temp(this->above*b.above,this->below*b.below);\
    temp.reduction();
    return temp;
}
fraction fraction::reciprocal(){      //倒数
    fraction temp(this->below,this->above);
    return temp;
}
fraction fraction::div(fraction b){    //除法
    fraction temp=this->mul(b.reciprocal());
    return temp;
}
bool fraction::equal(fraction b){       //等于运算
    b.reduction();
    if(this->above==b.above&&this->below==b.below){
        cout<<"二者相等"<<endl;
        return 1;
    }   else{
        cout<<"二者不相等"<<endl;
        return 0;
    }
}        
bool fraction::greaterThan(fraction b){     //大于运算
    b.reduction();
    this->makeCommond(b);
    if(this->above>b.above){
        cout<<"前者大于后者"<<endl;
        return 1;
    }   else{
        cout<<"前者不大于后者"<<endl;
        return 0;
    }
}  
bool fraction::lessThan(fraction b){  //小于运算
    b.reduction();
    this->makeCommond(b);
    if(this->above<b.above){
        cout<<"前者小于后者"<<endl;
        return 1;
    }   else{
        cout<<"前者不小于后者"<<endl;
        return 0;
    }
}
void fraction::display(){   //打印分数
    this->reduction();
    if(this->above==this->below){
        cout<<1<<endl;
        return;
    }
    if(this->below<0){
        this->above*=-1;
        this->below*=-1;
    }
    cout<<this->above<<"/"<<this->below<<endl;
}   
void fraction::input(){     //输入分数
    int m_above,m_below;
    cout<<"请输入分子:"<<endl;
    cin>>m_above;
    cout<<"请输入分母"<<endl;
    cin>>m_below;
    this->above=m_above;
    this->below=m_below;
}
int main(){
   
	return 0;
}