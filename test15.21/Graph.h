#pragma once
/*C++ primer
*��ϰ15.21����ͼ�λ�Ԫ��Ӧ��������֯�ɼ̳���ϵ*/
#ifndef GRAPH_H
#define GRAPH_H
#define pi 3.1415926//ʹ��Ԥ���붨��piֵ
//����Graph
class Graph {
public:
	virtual ~Graph() = 0;//����������
};
//��άͼ����
class Graph_2d :public Graph{
public:
	virtual double get_perimeter()=0;//�麯�������ܳ�
	virtual double ger_area()=0;//�麯���������
};
//��άͼ����
class Graph_3d : public Graph{
public:
	virtual double get_surArea()=0;//�麯����������
	virtual double get_volume()=0;//�麯���������
};
//������
class Rectangle :public Graph_2d {
public:
	Rectangle(double len,double wid):length(len),width(wid){/*Ϊ��*/}
	virtual double get_perimeter() { return length + width; }//�麯�������ܳ�
	virtual double ger_area() { return length*width; }//�麯���������
private:
	double length;
	double width;
};
//Բ��
class Circle :public Graph_2d {
public:
	Circle(double r):radius(r){/*Ϊ��*/}
	virtual double get_perimeter() { return 2 * radius*pi; }//�麯�������ܳ�
	virtual double ger_area() { return pi*radius*radius; }//�麯���������
private:
	double radius;//�뾶
};
//����
class Sphere :public Graph_3d {
public:
	Sphere(double r) :radius(r) {/*Ϊ��*/ }
	virtual double get_surArea() { return 4 * pi*radius*radius; }//�麯����������
	virtual double get_volume() { return 4 * pi*radius*radius*radius / 3; }//�麯���������
private:
	double radius;
};
#endif // !GRAPH_H
