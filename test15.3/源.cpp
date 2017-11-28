#include"Quote.h"
#include<iostream>
using namespace std;
int main() {
	//Quote baseBook("1", 10);//定义基类原价书
	//Bulk_quote bulkBook("1", 10, 5, 0.8	);//定义折扣书
	//Step_quote stepBook("1", 10, 5, 0.8);//定义阶梯折扣
	//print_total(cout,baseBook, 10);
	//print_total(cout, bulkBook, 10);
	//print_total(cout, stepBook, 10);
	//Bulk_quote bulkBook_default(bulkBook);
	//print_total(cout, bulkBook_default, 10);
	//Disc_quote discBook;
	//test15.26
	{
		Quote quoteBook("1", 10), quoteBook2(quoteBook);//使用Quote的拷贝构造函数
		cout << endl;
		Bulk_quote bulkBook("1", 10, 5, 0.8), bulkBook2(bulkBook);//使用Bulk_quote的拷贝构造函数
	}
	system("pause");
	return 0;
}