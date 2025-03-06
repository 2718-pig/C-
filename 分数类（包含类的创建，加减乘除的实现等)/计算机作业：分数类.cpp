//��̣�����һ�������ࡣ����������ݳ�Ա�������Ӻͷ�ĸ������������ʾ�����롢Լ�֡�ͨ�֡��Ƚϡ��ӡ������ˡ��������෴����

#include<iostream>
#include<cmath>
using namespace std;

class fraction{
    friend void printfraction(fraction& f);
	int above;         //����
	int below;         //��ĸ
	void reduction();            //Լ��
	void makeCommond(fraction& b); //ͨ��
public:
	fraction(int a=0,int b=1){       //���캯��
		above=a;below=b;
        reduction();//����һ��Լ�֣����ں����Ӽ��Ȳ���
	}
	fraction add(fraction);      //���������
	fraction sub(fraction);      //��������ȥʵ�η���
	fraction mul(fraction);      //���������
	fraction div(fraction);      //����������ʵ�η���
	fraction reciprocal();       //����
	bool equal(fraction);        //��������
	bool greaterThan(fraction);  //��������
	bool lessThan(fraction);     //С������
	void display();              //��ʾ����
	void input();                //�������
    int get_above()const{return above;};
    int get_below()const{return below;};
};
int max_remainder(int m,int n){     //���������
//�˴�ʹ��շת�����������˵�����ǰѵ�i�εĳ�������i+1�εı��������ѵ�i�ε���������i+1�εĳ�����ֱ����������0
    int r=0;
    while(r=m%n){
        m=n;
        n=r;
    }
    return n;
}//�˴�Ҳ�����õݹ飬�������£�
    // int max_remainder(int m,int n){
    //     if(m%n==0){
    //         return n;
    //     }   else{
    //         int r=m%n;
    //         return max_remainder(n,r);
    //     }
    // }
void fraction::reduction(){     //Լ��:���ӷ�ĸͬʱ�������Լ��
    int remainder=max_remainder(this->above,this->below);
    this->above/=remainder;
    this->below/=remainder;
}
void fraction::makeCommond(fraction& b){    //ͨ��
    int temp=(this->below)*b.below;
    this->above*=b.below;
    b.above*=this->below;
    this->below=b.below=temp;
}
fraction fraction::add(fraction b){     //�ӷ�ʵ��
    this->makeCommond(b);
    return fraction((this->above+b.above),this->below);
}
fraction fraction::sub(fraction b){   //����ʵ��
    this->makeCommond(b);
    return fraction((this->above-b.above),this->below);
}
fraction fraction::mul(fraction b){   //�˷�
    fraction temp(this->above*b.above,this->below*b.below);\
    temp.reduction();
    return temp;
}
fraction fraction::reciprocal(){      //����
    fraction temp(this->below,this->above);
    return temp;
}
fraction fraction::div(fraction b){    //����
    fraction temp=this->mul(b.reciprocal());
    return temp;
}
bool fraction::equal(fraction b){       //��������
    b.reduction();
    if(this->above==b.above&&this->below==b.below){
        cout<<"�������"<<endl;
        return 1;
    }   else{
        cout<<"���߲����"<<endl;
        return 0;
    }
}        
bool fraction::greaterThan(fraction b){     //��������
    b.reduction();
    this->makeCommond(b);
    if(this->above>b.above){
        cout<<"ǰ�ߴ��ں���"<<endl;
        return 1;
    }   else{
        cout<<"ǰ�߲����ں���"<<endl;
        return 0;
    }
}  
bool fraction::lessThan(fraction b){  //С������
    b.reduction();
    this->makeCommond(b);
    if(this->above<b.above){
        cout<<"ǰ��С�ں���"<<endl;
        return 1;
    }   else{
        cout<<"ǰ�߲�С�ں���"<<endl;
        return 0;
    }
}
void fraction::display(){   //��ӡ����
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
void fraction::input(){     //�������
    int m_above,m_below;
    cout<<"���������:"<<endl;
    cin>>m_above;
    cout<<"�������ĸ"<<endl;
    cin>>m_below;
    this->above=m_above;
    this->below=m_below;
}
int main(){
   
	return 0;
}