/*#include<bits/stdc++.h>
using namespace std;
class My{
	public:
		static int sx;
};

int My::sx = 3; 

int main(){
    //cout<<sx;//错误 未定义sx	
	cout<<My::sx<<endl;
	My::sx = My::sx + 2;
	cout<<My::sx<<endl;
}*/



/*#include<bits/stdc++.h>
using namespace std;
class My{
	private:
		static int sx;
};

int My::sx = 3; 

int main(){
	cout<<My::sx<<endl;//访问权限不够 
}*/

/*#include<bits/stdc++.h>
using namespace std;
class My{
	private:
		static int sx;
	public:
		static void Print(){
			cout<<sx<<endl;
		} 
};

int My::sx = 3; 

int main(){
	My::Print();
	//My::sx = My::sx + 2;//访问权限不够 	
}*/

/*
声明类My，有数据成员x（默认值为0）
       		①声明构造函数初始化x
       		②创建对象my1（3），my2（5），new My（7）
       		要求：将三个对象的x成员之和存入一个静态数据sum中，然后输出sum（通过静态方法AddPrint来实现）  
*/
/*#include<bits/stdc++.h>
using namespace std;
class My{
	private:
		int x;
		static int sum;
		public:
			My(){
				x = 0;
			}
			My(int x){
				this->x = x;
			}
			static void AddPrint(int t1,int t2,int t3){
			 	sum = t1 + t2 + t3;
				cout<<sum<<endl;
			}
			int getx(){
				return x;
			}
};

int My::sum = 0;

int main(){
	My my1(3),my2(4);
	My *p1 = new My(7);
	My::AddPrint(my1.getx(),my2.getx(),p1->getx());
}*/
#include<bits/stdc++.h>
using namespace std;
class My{
	private:
		int x;
		static int sum;
		public:
			My(){
				x = 0;
			}
			My(int x){
				this->x = x;
			}
			static void AddPrint(My t1,My t2,My t3){
			 	sum = t1.x + t2.x + t3.x;
				cout<<sum<<endl;
			}
	
};

int My::sum = 0;

int main(){
	My my1(3),my2(4);
	My *p1 = new My(7);
	My::AddPrint(my1,my2,*p1);
} 


//单例模式 
/*#include<bits/stdc++.h>
using namespace std;
class Singleton{
	private:
		static Singleton *Instance;
		Singleton(){
			cout<<"Singleton"<<endl;
		}
		public:
			static Singleton *Create(){
				if(!Instance){
					Instance = new Singleton();
				}
				return Instance;
			}
};

Singleton *Singleton::Instance = NULL;

int main(){
	Singleton *p = Singleton::Create();
	Singleton *q = Singleton::Create();
	Singleton *m = Singleton::Create();
} */
