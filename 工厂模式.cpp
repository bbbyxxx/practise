//工厂处理创建对象的细节。 
//简单工厂：
//优点：接口统一 
//缺点:违背了开闭规则 
//对扩展开放，对修改关闭 
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

//工厂模式
//提供一个用于创建对象的接口(工厂接口)，让其实现类(工厂实现类)决定实例化哪一个类(产品类)，并且由该实现类创建对应类的实例。
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

//抽象工厂模式
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

