#pragma once
/*
*C++primer练习

*袁朝飞
*练习15.3，定义书籍基类Quote，保存又ISBN号和未打折的原始价格，输入本数可以得到销售总额
*定义print_total函数，输入输出流对象，基类的引用和销售本数，将ISBN号和销售额打印到输出流对象
*test15.5，定义打折书籍派生类Bulk_Quote，包含折扣和最低折扣本数，当销售本数超过最低本数时，按折扣价销售
*/
#ifndef QUOTE_H
#define QUOTE_H
#include<string>
#include<iostream>
using namespace std;
//基类：原价书籍
class Quote {
public:
	Quote() = default;//默认初始化函数
	Quote(const string& book, double sales_price) :
		bookNum(book),price(sales_price) {/*为空*/}
	//拷贝构造函数
	Quote(const Quote&quoteBook):
		bookNum(quoteBook.bookNum),price(quoteBook.price) 
		{ cout << "Quote类拷贝构造函数； "; }
	string isbn() const { return bookNum; };						// 返回ISBN号
	virtual double net_price(size_t n) const { return n*price; }	// 返回销售总额函数
	virtual ~Quote() { cout << "Quote析构函数； "; }	// 析构函数进行动态绑定
	virtual void debug() const;//虚函数，显示所有数据成员
protected:
	double price = 0.0;			// 保存原价的double
private:
	string bookNum;				// 保存ISBN号的string
};
//抽象基类Disc_quote，定义所有折扣策略派生类的接口
class Disc_quote: public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const string& book, double sales_price, size_t qty, double disc) :
		Quote(book, sales_price), min_qty(qty),discount(disc) {/*为空*/}
	//拷贝构造函数
	Disc_quote(const Disc_quote& discBook):
		Quote(discBook),min_qty(discBook.min_qty),discount(discBook.discount)
		{ cout << "Disc_quote拷贝构造函数； "; }
	virtual double net_price(size_t n) const override = 0;//纯虚函数，仅提供接口
	//析构函数
	~Disc_quote()
	{
		cout << "Disc_quote析构函数； ";
	}
protected:
	size_t min_qty = 0;		// 保存享受折扣价的最低本数
	double discount = 0.0;	// 保存折扣
};
//派生类Bulk_quote，高于给定量享受折扣
class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string&, double, size_t, double);	// 构造函数
	//拷贝构造函数，15.7节，如果显示定义拷贝构造函数，则使用基类的默认构造函数初始化派生类中的基类部分（min_qty = 0;  discount = 0.0	）
	Bulk_quote(const Bulk_quote&bulkBook):
		Disc_quote(bulkBook) {		cout << "Bulk_quote拷贝构造函数； ";	}
	double net_price(size_t) const override;//派生类版本的销售额函数													
	virtual void debug() const override;//虚函数，显示所有数据成员
	//析构函数
	~Bulk_quote()
	{
		cout << "Bulk_quote析构函数； ";
	}

	//数据成员经过重构，转移到Disc_quote类中；
//private:
//	size_t min_qty = 0;		// 保存享受折扣价的最低本数
//	double discount = 0.0;	// 保存折扣
};
//派生类Step_quote，阶梯折扣
class Step_quote : public Disc_quote {
public:
	Step_quote() = default;
	Step_quote(const string&, double, size_t, double);	// 构造函数
	//拷贝构造函数
	Step_quote(const Bulk_quote&stepBook) :
		Disc_quote(stepBook) {
		cout << "Step_quote拷贝构造函数； ";
	}
	double net_price(size_t) const override;//派生类版本的销售额函数
};
//声明打印销售总额函数
ostream& print_total(ostream&, Quote&, size_t);
#endif // !QUOTE_H
