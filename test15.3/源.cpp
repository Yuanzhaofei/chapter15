#include"Quote.h"
#include<iostream>
using namespace std;
int main() {
	//Quote baseBook("1", 10);//�������ԭ����
	//Bulk_quote bulkBook("1", 10, 5, 0.8	);//�����ۿ���
	//Step_quote stepBook("1", 10, 5, 0.8);//��������ۿ�
	//print_total(cout,baseBook, 10);
	//print_total(cout, bulkBook, 10);
	//print_total(cout, stepBook, 10);
	//Bulk_quote bulkBook_default(bulkBook);
	//print_total(cout, bulkBook_default, 10);
	//Disc_quote discBook;
	//test15.26
	{
		Quote quoteBook("1", 10), quoteBook2(quoteBook);//ʹ��Quote�Ŀ������캯��
		cout << endl;
		Bulk_quote bulkBook("1", 10, 5, 0.8), bulkBook2(bulkBook);//ʹ��Bulk_quote�Ŀ������캯��
	}
	system("pause");
	return 0;
}