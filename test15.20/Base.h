#pragma once
/*C++ primer
*��ϰ15.20
*������ʿ�����̳У�������ַ�ʽ�̳е������࣬�ж�����������������ת���Ƿ�Ϸ�*/
#ifndef BASE_H
#define BASE_H
using namespace std;
//����Base
class Base {
public:
};
//���м̳е�������Pub_Derv
class Pub_Derv : public Base {
	void memfcn(Base&b) { b = *this; }
};
//�����̳е�������Protected_Derv
class Protected_Derv : protected Base {
	void memfcn(Base&b) { b = *this; }
};
//˽�м̳е�������Private_Derv
class Private_Derv : private Base {
	void memfcn(Base&b) { b = *this; }
};
//Pub_Derv�Ĺ��м̳�������
class Derived_from_Public : public Pub_Derv {
	void memfcn(Base&b) { b = *this; }
};
//Protected_Derv�Ĺ��м̳�������
class Derived_from_Protected : protected Protected_Derv {
	void memfcn(Base&b) { b = *this; }
};
//Private_Derv�Ĺ��м̳�������
class Derived_from_Private : private Private_Derv {
	//void memfcn(Base&b) { b = *this; }//��Private_Derv��BaseΪ˽�г�Ա������Private_Derv���������޷�����Base��Ҳ�Ͳ����������ת��
};
#endif // !BASE_H
