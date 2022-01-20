/*
 * @Author: Ace
 * @Date: 2022-01-19 02:15:47
 * @LastEditTime: 2022-01-19 02:17:27
 * @LastEditors: Ace
 * @Description: 
 * 可以输入预定的版权声明、个性签名、空行等
 */


#include "CallBack.hpp"



namespace demo1{
	using namespace std::placeholders;
	// 普通函数
	int add(int a, int b){return a+b;} 

	// 结构体或类
	struct Foo {
	   void print_sum(int n1, int n2)
	    {
		std::cout << n1+n2 << '\n';
	    }
	   int data = 10;
	};
	
	void demo1_test()
	{
		// 绑定全部参数和调用
		auto f1 = std::bind(add, 95, 5);
		f1(); // = 100

		// 绑定部分参数和调用
		//auto f2 = std::bind(add, 95, std::placeholders::_1);
		auto f2 = std::bind(add, 95, _1);
		f2(5); // = 100
		auto f3 = std::bind(add, _1, 5);
		f3(95); // = 100

		// 绑定成员函数，部分参数和调用
		Foo foo;
		auto f4 = std::bind(&Foo::print_sum, &foo, 10, _1);
		f4(20); // = 100
	}
};

namespace demo2{
	void fn(int n1, int n2, int n3) {
		std::cout << "#############fn  begin #####################\n";
		std::cout << "fn has been called.\n";
		std::cout << "n1:" << n1 << ", n2:" << n2 << ", n3:" << n3 << std::endl;
		std::cout << "#############fn  end   #####################\n";
	}
 
	int fn2() {
		std::cout << "#############fn2 begin #####################\n";
		std::cout << "fn2 has been called.\n";
		std::cout << "#############fn2 end   #####################\n";
		return -1;
	}
 
	void demo2_test()
	{
		using namespace std::placeholders;
		auto bind_test1 = std::bind(fn, 1, 2, 3);
		auto bind_test2 = std::bind(fn, _1, _2, _3);
		auto bind_test3 = std::bind(fn, 0, _1, _2);
		auto bind_test4 = std::bind(fn, _2, 0, _1);
	 
		bind_test1();//输出1 2 3
		bind_test2(3, 8, 24);//输出3 8 24
		bind_test2(1, 2, 3, 4, 5);//输出1 2 3，4和5会被丢弃
		bind_test3(10, 24);//输出0 10 24
		bind_test3(10, fn2());//输出0 10 -1
		bind_test3(10, 24, fn2());//输出0 10 24，fn2会被调用，但其返回值会被丢弃
		bind_test4(10, 24);//输出24 0 10
	}
};

namespace demo3{
	using namespace std::placeholders;
	using namespace std;
	ostringstream & printStr(ostringstream &os, const string& s, char c)
	{
	    os << s << c;
	    return os;
	}
	void demo3_test()
	{
		vector<string> words{"helo", "world", "this", "is", "C++11"};
		ostringstream os1;
		char c = ' ';
	      // ostream不能拷贝，若希望传递给bind一个对象，
	       // 而不拷贝它，就必须使用标准库提供的ref函数
	      //for_each(words.begin(), words.end(),std::bind(printStr, ref(os1), _1, c));
		os1 << "hello world";
		std::bind(printStr, ref(os1), _1, c);
	      cout << os1.str() << endl;
	}
};

namespace demo4{
	struct Foo {
	    int value;
	    void f() { std::cout << "f(" << this->value << ")\n"; }
	    void g() { std::cout << "g(" << this->value << ")\n"; }
	};
	void apply(Foo* foo1, Foo* foo2, void (Foo::*fun)()) {
	    (foo1->*fun)();  // call fun on the object foo1
	    (foo2->*fun)();  // call fun on the object foo2
	}
	void demo4_test() {
	    Foo foo1{1};
	    Foo foo2{2};
	    apply(&foo1, &foo2, &Foo::f);
	    apply(&foo1, &foo2, &Foo::g);
	}
};