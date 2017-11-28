#pragma once
/*C++ primer
*练习15.20
*检验访问控制与继承，定义各种方式继承的派生类，判断派生类向基类的类型转换是否合法*/
#ifndef BASE_H
#define BASE_H
using namespace std;
//基类Base
class Base {
public:
};
//公有继承的派生类Pub_Derv
class Pub_Derv : public Base {
	void memfcn(Base&b) { b = *this; }
};
//保护继承的派生类Protected_Derv
class Protected_Derv : protected Base {
	void memfcn(Base&b) { b = *this; }
};
//私有继承的派生类Private_Derv
class Private_Derv : private Base {
	void memfcn(Base&b) { b = *this; }
};
//Pub_Derv的公有继承派生类
class Derived_from_Public : public Pub_Derv {
	void memfcn(Base&b) { b = *this; }
};
//Protected_Derv的公有继承派生类
class Derived_from_Protected : protected Protected_Derv {
	void memfcn(Base&b) { b = *this; }
};
//Private_Derv的公有继承派生类
class Derived_from_Private : private Private_Derv {
	//void memfcn(Base&b) { b = *this; }//在Private_Derv中Base为私有成员，所以Private_Derv的派生类无法访问Base，也就不能完成类型转换
};
#endif // !BASE_H
