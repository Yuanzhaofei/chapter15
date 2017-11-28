#pragma once
/*C++ primer
*练习15.21，将图形基元对应的类型组织成继承体系*/
#ifndef GRAPH_H
#define GRAPH_H
#define pi 3.1415926//使用预编译定义pi值
//基类Graph
class Graph {
public:
	virtual ~Graph() = 0;//虚析构函数
};
//二维图形类
class Graph_2d :public Graph{
public:
	virtual double get_perimeter()=0;//虚函数，求周长
	virtual double ger_area()=0;//虚函数，求面积
};
//三维图形类
class Graph_3d : public Graph{
public:
	virtual double get_surArea()=0;//虚函数，求表面积
	virtual double get_volume()=0;//虚函数，求体积
};
//方格类
class Rectangle :public Graph_2d {
public:
	Rectangle(double len,double wid):length(len),width(wid){/*为空*/}
	virtual double get_perimeter() { return length + width; }//虚函数，求周长
	virtual double ger_area() { return length*width; }//虚函数，求面积
private:
	double length;
	double width;
};
//圆类
class Circle :public Graph_2d {
public:
	Circle(double r):radius(r){/*为空*/}
	virtual double get_perimeter() { return 2 * radius*pi; }//虚函数，求周长
	virtual double ger_area() { return pi*radius*radius; }//虚函数，求面积
private:
	double radius;//半径
};
//球类
class Sphere :public Graph_3d {
public:
	Sphere(double r) :radius(r) {/*为空*/ }
	virtual double get_surArea() { return 4 * pi*radius*radius; }//虚函数，求表面积
	virtual double get_volume() { return 4 * pi*radius*radius*radius / 3; }//虚函数，求体积
private:
	double radius;
};
#endif // !GRAPH_H
