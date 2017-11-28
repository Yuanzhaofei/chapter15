#include"Quote.h"
#include<iostream>
//打印销售总额函数定义
ostream& print_total(ostream& os, Quote& book, size_t n) {
	os << "book: " << book.isbn() << " # sold: "
		<< n << " total due: " << book.net_price(n) << endl;
	return os;
}
//基类degug函数，显示所有数据成员
void Quote::debug() const {
	cout << "ISBN: " << bookNum 
		<< " price: " << price << endl;
}
// 派生类Bulk_quote构造函数
Bulk_quote::Bulk_quote(const string& book, double sales_price, size_t min_cnt, double disc):
	Disc_quote(book,sales_price,min_cnt,disc){/*为空*/}
// 派生类Bulk_quote的销售额函数
double Bulk_quote::net_price(size_t bookCnt) const {
	if (bookCnt >= min_qty)
		return bookCnt*discount*price;
	else
		return bookCnt*price;
}
//派生类Bulk_quote的degug函数，显示所有数据成员
void Bulk_quote::debug() const {
	Quote::debug();		// 打印基类子对象成员
	cout << "min_qyt: " << min_qty 
		<< "discount: " << discount << endl;
}
// 派生类Step_quote构造函数
Step_quote::Step_quote(const string& book, double sales_price, size_t min_cnt, double disc) :
	Disc_quote(book, sales_price, min_cnt, disc) {/*为空*/
}
// 派生类Step_quote的销售额函数
double Step_quote::net_price(size_t bookCnt) const {
	if (bookCnt <= min_qty)
		//不超过一定量时，享受折扣
		return bookCnt*discount*price;
	else
		//超过部分原价销售
		return min_qty*discount*price + (bookCnt - min_qty)*price;
}
