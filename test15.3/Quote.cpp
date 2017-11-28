#include"Quote.h"
#include<iostream>
//��ӡ�����ܶ������
ostream& print_total(ostream& os, Quote& book, size_t n) {
	os << "book: " << book.isbn() << " # sold: "
		<< n << " total due: " << book.net_price(n) << endl;
	return os;
}
//����degug��������ʾ�������ݳ�Ա
void Quote::debug() const {
	cout << "ISBN: " << bookNum 
		<< " price: " << price << endl;
}
// ������Bulk_quote���캯��
Bulk_quote::Bulk_quote(const string& book, double sales_price, size_t min_cnt, double disc):
	Disc_quote(book,sales_price,min_cnt,disc){/*Ϊ��*/}
// ������Bulk_quote�����۶��
double Bulk_quote::net_price(size_t bookCnt) const {
	if (bookCnt >= min_qty)
		return bookCnt*discount*price;
	else
		return bookCnt*price;
}
//������Bulk_quote��degug��������ʾ�������ݳ�Ա
void Bulk_quote::debug() const {
	Quote::debug();		// ��ӡ�����Ӷ����Ա
	cout << "min_qyt: " << min_qty 
		<< "discount: " << discount << endl;
}
// ������Step_quote���캯��
Step_quote::Step_quote(const string& book, double sales_price, size_t min_cnt, double disc) :
	Disc_quote(book, sales_price, min_cnt, disc) {/*Ϊ��*/
}
// ������Step_quote�����۶��
double Step_quote::net_price(size_t bookCnt) const {
	if (bookCnt <= min_qty)
		//������һ����ʱ�������ۿ�
		return bookCnt*discount*price;
	else
		//��������ԭ������
		return min_qty*discount*price + (bookCnt - min_qty)*price;
}
