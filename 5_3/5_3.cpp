#include <iostream>
#include <string>

using namespace std;

//Родитель
class Figure {

protected:
    int side;
    string figure_name;

    Figure(int side_count, const string& name = "Фигура:") : side(side_count), figure_name(name)
    {}

    virtual bool check_correctness_figure() const
    {
        return true;
    }

    string get_figure_name() 
    {
        return figure_name;
    }


public:
    Figure() :side(0)
    {}

    virtual void get_info()
    {
        cout << figure_name << endl;
        cout << (check_correctness_figure() ? "Правильная" : "Неправильная") << endl;
        cout << "Количество сторон: " << side << endl << endl;
    }
};

//Пошли треугольники
class Triangle :public Figure
{
protected:
    int a1, b1, c1;
    int A1, B1, C1;

    bool check_correctness_figure() const override
    {
        return ((A1 + B1 + C1) == 180) ? true : false;
    }

public:
    Triangle(int a2, int b2, int c2, int A2, int B2, int C2, const string& name = "Треугольник:") :Figure(3, name)
    {
        a1 = a2, b1 = b2, c1 = c2;
        A1 = A2, B1 = B2, C1 = C2;
    }
    void get_info() override
    {
        cout << get_figure_name() << endl;
        cout << (check_correctness_figure() ? "Правильная" : "Неправильная") << endl;
        cout << "Количество сторон: " << side << endl;
        cout << "Стороны: " << "a=" << a1 << " " << "b=" << b1 << " " << "c=" << c1 << endl;
        cout << "Углы: " << "A=" << A1 << " " << "B=" << B1 << " " << "C=" << C1 << endl << endl;
    }
};

class Right_triangle :public Triangle //прямоугольный треугольник (угол C всегда равен 90)
{
public:
    Right_triangle(int a1, int b1, int c1, int A1, int B1, int C1) :Triangle(a1, b1, c1, A1, B1, C1, "Прямоугольный треугольник:")
    {}
    bool check_correctness_figure() const override
    {
        return Triangle::check_correctness_figure() && C1 == 90 ? true : false;
    }
};

class Isosceles_triangle : public Triangle //равнобедренный треугольник (стороны a и c равны, углы A и C равны)
{
public:
    Isosceles_triangle(int a1, int b1, int c1, int A1, int B1, int C1) : Triangle(a1, b1, c1, A1, B1, C1, "Равнобедренный треугольник:")
    {}
    bool check_correctness_figure() const override
    {
        return Triangle::check_correctness_figure() && ((a1 == c1) && (A1 == C1)) ? true : false;
    }
};

class Equilateral_triangle : public Triangle //равносторонний треугольник (все стороны равны, все углы равны 60)
{
public:
    Equilateral_triangle(int a1, int b1, int c1, int A1, int B1, int C1) : Triangle(a1, b1, c1, A1, B1, C1, "Равносторонний треугольник:")
    {}
    bool check_correctness_figure() const override
    {
        return ((A1 == B1 == C1 == 60) && (a1 == b1 == c1)) ? true : false;
    }
};

//Пошли четырёхугольники 

class Quadrilateral :public Figure
{
protected:
    int a1, b1, c1, d1;
    int A1, B1, C1, D1;

    bool check_correctness_figure() const override
    {
        return ((A1 + B1 + C1 + D1) == 360) ? true : false;
    }

public:
    Quadrilateral(int a2, int b2, int c2, int d2, int A2, int B2, int C2, int D2, const string& name = "Четырехугольник:") :Figure(4, name)
    {
        a1 = a2, b1 = b2, c1 = c2, d1 = d2;
        A1 = A2, B1 = B2, C1 = C2, D1 = D2;
    }
    void get_info() override
    {
        cout << get_figure_name() << endl;
        cout << (check_correctness_figure() ? "Правильная" : "Неправильная") << endl;
        cout << "Количество сторон: " << side << endl;
        cout << "Стороны: " << "a=" << a1 << " " << "b=" << b1 << " " << "c=" << c1 << " " << "d=" << d1 << endl;
        cout << "Углы: " << "A=" << A1 << " " << "B=" << B1 << " " << "C=" << C1 << " " << "D=" << D1 << endl << endl;
    }
};

class Rectangle : public Quadrilateral //прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90)
{
public:
    Rectangle(int a1, int b1, int c1, int d1, int A1, int B1, int C1, int D1) : Quadrilateral(a1, b1, c1, d1, A1, B1, C1, D1, "Прямоугольник:")
    {}
    bool check_correctness_figure() const override
    {
        return (Quadrilateral::check_correctness_figure() && (A1 == B1 == C1 == D1 == 90) && (a1 == c1 && b1 == d1)) ? true : false;
    }
};

class Square : public Quadrilateral //квадрат (все стороны равны, все углы равны 90)
{
public:
    Square(int a1, int b1, int c1, int d1, int A1, int B1, int C1, int D1) : Quadrilateral(a1, b1, c1, d1, A1, B1, C1, D1, "Квадрат:")
    {}
    bool check_correctness_figure() const override
    {
        return (Quadrilateral::check_correctness_figure() && (A1 == B1 == C1 == D1 == 90) && (a1 == b1 == c1 == d1)) ? true : false;
    }
};

class Parallelogram : public Quadrilateral //параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны)
{
public:
    Parallelogram(int a1, int b1, int c1, int d1, int A1, int B1, int C1, int D1) : Quadrilateral(a1, b1, c1, d1, A1, B1, C1, D1, "Параллелограмм:")
    {}
    bool check_correctness_figure() const override
    {
        return (Quadrilateral::check_correctness_figure() && (a1 == c1 && b1 == d1) && (A1 == C1 && B1 == D1)) ? true : false;
    }
};

class Rhombus : public Quadrilateral //ромб (все стороны равны, углы A,C и B,D попарно равны)
{
public:
    Rhombus(int a1, int b1, int c1, int d1, int A1, int B1, int C1, int D1) : Quadrilateral(a1, b1, c1, d1, A1, B1, C1, D1, "Ромб:")
    {}
    bool check_correctness_figure() const override
    {
        return (Quadrilateral::check_correctness_figure() && (a1 == b1 == c1 == d1) && (A1 == C1 && B1 == D1)) ? true : false;
    }
};

//Функции вывода на экран
void print_figures(Figure* figure)
{
    figure->get_info();
}
int main()
{
    setlocale(LC_ALL, "Rus");

    Triangle triangle(10, 20, 30, 50, 60, 70);
    Right_triangle right_triangle(10, 20, 30, 50, 60, 90);
    Right_triangle right_triangle1(10, 20, 30, 50, 40, 90);
    Isosceles_triangle isosceles_triangle(10, 20, 10, 50, 60, 50);
    Equilateral_triangle equilateral_triangle(30, 30, 30, 60, 60, 60);

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20, 10, 20, 90, 90, 90, 90);
    Square square(20, 20, 20, 20, 90, 90, 90, 90);
    Parallelogram parallelogram(20, 30, 20, 30, 30, 40, 30, 40);
    Rhombus rhombus(30, 30, 30, 30, 30, 40, 30, 40);
    
    print_figures(&triangle);
    print_figures(&right_triangle);
    print_figures(&right_triangle1);
    print_figures(&isosceles_triangle);
    print_figures(&equilateral_triangle);

    print_figures(&quadrilateral);
    print_figures(&rectangle);
    print_figures(&square);
    print_figures(&parallelogram);
    print_figures(&rhombus);
}