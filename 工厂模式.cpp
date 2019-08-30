//���������������ϸ�ڡ� 
//�򵥹�����
//�ŵ㣺�ӿ�ͳһ 
//ȱ��:Υ���˿��չ��� 
//����չ���ţ����޸Ĺر� 
/*#include<bits/stdc++.h>
using namespace std;
class Product{
	public:
		virtual void Do() = 0;
};
class ProductA:public Product{
	public:
		void Do(){
			cout<<"ProductA"<<endl;
		}
};
class ProductB:public Product{
	public:
		void Do(){
			cout<<"ProductB"<<endl;
		}
};
class ProductC:public Product{
	public:
		void Do(){
			cout<<"ProductC"<<endl;
		}
};
class Factory{
	private:
	 	Product *product;
	public:
		Factory(int n){
			switch(n){
				case 1:product = new ProductA();
				break;
				case 2:product = new ProductB();
				break;
				case 3:product = new ProductC();
			}
		}
	void send(){
		product->Do();
	}
	~Factory(){
		delete product;
	}
};
int main(){
	Factory *factory = new Factory(2);
	factory->send();
}*/

//����ģʽ
//�ṩһ�����ڴ�������Ľӿ�(�����ӿ�)������ʵ����(����ʵ����)����ʵ������һ����(��Ʒ��)�������ɸ�ʵ���ഴ����Ӧ���ʵ����
/*#include<bits/stdc++.h>
using namespace std;
class Product{
	public:
		virtual void Do() = 0;
};
class ProductA:public Product{
	public:
		void Do(){
			cout<<"ProductA"<<endl;
		}
};
class ProductB:public Product{
	public:
		void Do(){
			cout<<"ProductB"<<endl;
		}
};
class ProductC:public Product{
	public:
		void Do(){
			cout<<"ProductC"<<endl;
		}
};
class Factory{
	private:
	 	Product *product;
	public:
		Factory(Product *n){
			product = n;
		}
	void send(){
		product->Do();
	}
	~Factory(){
		delete product;
	}
};
int main(){
	Factory *factory = new Factory(new ProductB());
	factory->send();
}*/

//���󹤳�ģʽ
#include<bits/stdc++.h>
using namespace std;
class Product{
	public:
	virtual void Do() = 0; 
};
class ProductA:public Product{
	public:
		void Do(){
			cout<<"ProductA"<<endl;
		}
};
class ProductB:public Product{
	public:
		void Do(){
			cout<<"ProductB"<<endl;
		}
};
class Factory{
	protected:
		Product *product;
	public:
		virtual void send() = 0;
}; 
class FactoryA:public Factory{
	public:
		FactoryA(Product *t){
			product = t;
		}
		void send(){
			product->Do();
		}
		~FactoryA(){
			delete product;
		}
};
class FactoryB:public Factory{
	public:
		FactoryB(Product *t){
			product = t;
		}
		void send(){
			product->Do();
		}
		~FactoryB(){
			delete product;
		}
};
int main(){
	Factory *fa = new FactoryA(new ProductB());
	fa->send();
} 

