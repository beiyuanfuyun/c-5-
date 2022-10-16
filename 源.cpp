#define _CRT_SECURE_NO_WARNINGS
//----------------05特殊构造方式-------------------
//**01.拷贝构造函数
//02.调用时机
// 03.浅拷贝与深拷贝
//
//------------01-------------------------
//通过拷贝对自身类型对象构造自身，自动调用（也是一种构造函数）
// 定义：
// 出参数列表只写自身类型引用外，与其他的构造一样
// 实例：类名{类名 const&引用名）{}
// 这里的const也可以不加，但是这里是拷贝，所以加上，以防被修改


//------------------02---------------------------------
//1.用旧对象^初始化^新对象，通常会调用我们写的构造函数而不是系统默认的，
//2.函数的形参为普通对象,在调用时可以用引用&出去备份，会调用拷贝构造
//3.函数返回值为类类型，返回普通对象，会调用拷贝构造函数，但是拷贝函数会消耗内存的，
//  
//但是&引用很有危险，当返回为局部变量时，会释放掉原空间，第二次调用会出错
//但是可以用拷贝构造来规避局部变量问题，就相当于克隆了一部分
//malloc申请的为堆区的区域，而且可以自动是释放，
//static虽然可以将局部变量变成全局变量，但是相应的区域也会变化，从栈区变成了全局区，而且无法释放一直占用你的内存

//----------------------03-----------------------------
//浅拷贝：只复制指向某个对象的指针，而不复制对象的本身，新旧对象还是共享同一块的内存
//深拷贝：另外创造一个一模一样的对象，新的对象跟原对象不共享内存
//
//

 

#include<iostream>
#include<string>
using namespace std;

//class person
//{
//public:
//	int m_age;
//	string m_name;
//	person();
//	person(int val,string  name);
//	void show();
//
//public:
//	//拷贝构造
//	person(person	& other)//这个&不能掉了，把外面对向的实体传进来，如果不想传进来的值被修改，可以用const进行修饰
//	//const &  省略掉实参本体的拷贝，且避免被修改
//	{
//		this->m_age = other.m_age=100;
//			//指针类型可以用->,对象类型用.访问
//		cout << "---拷贝成功----" << endl;
//		this->m_name = other.m_name;
//	}//自行拷贝构造，参数必须是同类型的，要对应好
//
//	
//};
//const person& fun(person const& p1)//这时候形参变实参//通过引用节约内存，防止备份
//{
//	//cout << "调用成功" << endl;
//	cout << "age:" << p1.m_age << endl;
//	cout << "name:" << p1.m_name << endl;
//	return p1;
//}
//person::person()
//{
//    this->m_age = 18;
//	this->m_name = "zhan";
//}
//person::person(int val,string name)//m_这样的前缀可以避免构造函数内的age造成误会这样就要用this指针去指名是类内age，但是用m_age就可以省略相关问题
//{
//	m_age = 28;
//	m_name = "suan";
//}
//void person::show()
//{
//	cout << "age:"<<m_age << endl;
//	cout << "name:" <<m_name<< endl;
//}

//----------03-------------------
//class node
//{
//public:
//	int* p;
//	node()
//	{
//		cout << "调用node构造" << endl;
//		p = new int;
//		*p = 100;
//	}
//	node(node const& other)
//	{
//		this->p = new int;
//		*(this->p) = *(other.p);
//		//深拷贝内存独立
//	}
//	~node()
//	{
//		cout << "调用析构" << endl;
//		delete p;
//		p = nullptr;
//	}
//};
//
//
//
//int main()
//{
//	//person p1;
//	//person p2(45, "zi");
//	//cout << "p1:" << endl;
//	//p1.show();
//	//cout << "p2:" << endl;
//	//p2.show();
//
//	//p1 = p2;//用的是默认的拷贝
//	//cout << "p1:" << endl;
//	//p1.show();
//	//cout << "p2:" << endl;
//	//p2.show();
//
//
//	//fun(p1);
//	//cout << "p1:" << endl;
//	//p1.show();
//
//
//	person p1(34, "wenshuang");
//	//person p2(p1);//这个时候会调用拷贝构造函数，但是如果里面的不完整，则会随机复值，不是默认的，默认的会全部复制一遍，哪怕不完整
//	//p2.show();
//	cout << "person的内存大小:" << sizeof(person)<<"字节" << endl;
//	fun(p1);
//
//
//	//-------------03浅-----------------
//		//node* pnode = new node;//由于是像内存申请的一块空间，最后没有动用析构
//		//node n1(*pnode);//调用  拷贝构造  、、相当于默认拷贝
//		//delete pnode;//delete时会   调用析构   一个删外面的一个删内面的
//		//return  0;//调用析构
//		////这就是浅拷贝的危害
//		// 公用一块的p的内存
//	//----------03深-----------
//	//释放堆区对象，栈区对象仍存在
//	//格式：类名（类名 const& other），其实和拷贝函数格式一样，其实实际上是一种再申请，不是公用一个p的地址
//
//}
