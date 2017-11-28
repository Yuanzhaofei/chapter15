#pragma once
/*
*C++primer��ϰ

*Ԭ����
*��ϰ15.3�������鼮����Quote��������ISBN�ź�δ���۵�ԭʼ�۸����뱾�����Եõ������ܶ�
*����print_total������������������󣬻�������ú����۱�������ISBN�ź����۶��ӡ�����������
*test15.5����������鼮������Bulk_Quote�������ۿۺ�����ۿ۱����������۱���������ͱ���ʱ�����ۿۼ�����
*/
#ifndef QUOTE_H
#define QUOTE_H
#include<string>
#include<iostream>
using namespace std;
//���ࣺԭ���鼮
class Quote {
public:
	Quote() = default;//Ĭ�ϳ�ʼ������
	Quote(const string& book, double sales_price) :
		bookNum(book),price(sales_price) {/*Ϊ��*/}
	//�������캯��
	Quote(const Quote&quoteBook):
		bookNum(quoteBook.bookNum),price(quoteBook.price) 
		{ cout << "Quote�࿽�����캯���� "; }
	string isbn() const { return bookNum; };						// ����ISBN��
	virtual double net_price(size_t n) const { return n*price; }	// ���������ܶ��
	virtual ~Quote() { cout << "Quote���������� "; }	// �����������ж�̬��
	virtual void debug() const;//�麯������ʾ�������ݳ�Ա
protected:
	double price = 0.0;			// ����ԭ�۵�double
private:
	string bookNum;				// ����ISBN�ŵ�string
};
//�������Disc_quote�����������ۿ۲���������Ľӿ�
class Disc_quote: public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const string& book, double sales_price, size_t qty, double disc) :
		Quote(book, sales_price), min_qty(qty),discount(disc) {/*Ϊ��*/}
	//�������캯��
	Disc_quote(const Disc_quote& discBook):
		Quote(discBook),min_qty(discBook.min_qty),discount(discBook.discount)
		{ cout << "Disc_quote�������캯���� "; }
	virtual double net_price(size_t n) const override = 0;//���麯�������ṩ�ӿ�
	//��������
	~Disc_quote()
	{
		cout << "Disc_quote���������� ";
	}
protected:
	size_t min_qty = 0;		// ���������ۿۼ۵���ͱ���
	double discount = 0.0;	// �����ۿ�
};
//������Bulk_quote�����ڸ����������ۿ�
class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string&, double, size_t, double);	// ���캯��
	//�������캯����15.7�ڣ������ʾ���忽�����캯������ʹ�û����Ĭ�Ϲ��캯����ʼ���������еĻ��ಿ�֣�min_qty = 0;  discount = 0.0	��
	Bulk_quote(const Bulk_quote&bulkBook):
		Disc_quote(bulkBook) {		cout << "Bulk_quote�������캯���� ";	}
	double net_price(size_t) const override;//������汾�����۶��													
	virtual void debug() const override;//�麯������ʾ�������ݳ�Ա
	//��������
	~Bulk_quote()
	{
		cout << "Bulk_quote���������� ";
	}

	//���ݳ�Ա�����ع���ת�Ƶ�Disc_quote���У�
//private:
//	size_t min_qty = 0;		// ���������ۿۼ۵���ͱ���
//	double discount = 0.0;	// �����ۿ�
};
//������Step_quote�������ۿ�
class Step_quote : public Disc_quote {
public:
	Step_quote() = default;
	Step_quote(const string&, double, size_t, double);	// ���캯��
	//�������캯��
	Step_quote(const Bulk_quote&stepBook) :
		Disc_quote(stepBook) {
		cout << "Step_quote�������캯���� ";
	}
	double net_price(size_t) const override;//������汾�����۶��
};
//������ӡ�����ܶ��
ostream& print_total(ostream&, Quote&, size_t);
#endif // !QUOTE_H
