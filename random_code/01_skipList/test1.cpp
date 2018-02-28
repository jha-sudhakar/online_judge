
#include<iostream>
using namespace std;

class Base
{

	public:
		virtual void fun1()
		{
			cout <<"Inside base::fun1() \n";
		}
};

class d1: public Base
{

	public:
		virtual void fun1()
		{
			cout <<"Inside d1::fun1() \n";
		}

		void fun2()
		{
			cout <<"Inside d1::fun2() \n";
		}
};

int main()
{
Base* ptr = new d1();
ptr->fun1();
ptr->fun2();

return 0;
}
