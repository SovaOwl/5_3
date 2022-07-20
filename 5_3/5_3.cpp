#include <iostream>
#include <string>

using namespace std;

//Родитель
class Figure {

private:
    int side;
    string figure_name, check_correctness_figure;

protected:

    void give_figure_name(string name)
    {
        figure_name = name;
    }
    void give_check_correctness_figure(string figure_check)
    {
        check_correctness_figure = figure_check;
    }
    int get_field()
    {
        return side;
    }
    string get_figure_name()
    {
        return figure_name;
    }
    string get_is_figure_right()
    {
        return check_correctness_figure;
    }

public:
    Figure(int side_count)
    {
        figure_name = "Фигура:";
        check_correctness_figure = "Правильная";
        side = 0;
    }
    virtual void get_info()
    {
        cout << figure_name << endl;
        cout << check_correctness_figure << endl;
        cout << "Количество сторон: " << side << endl << endl;
    }
};

//Пошли треугольники
class Triangle :public Figure
{
private:
    int a1, b1, c1;
    int A1, B1, C1;

protected:
    string get_figure_parameters()
    {
        if ((A1 + B1 + C1) == 180)
        {
            return "Правильная";
        }
        else
        {
            return "Неправильная";
        }
    }

public:
    Triangle(int a2, int b2, int c2, int A2, int B2, int C2) :Figure(3)
    {
        give_figure_name("Треугольник:");
        a1 = a2, b1 = b2, c1 = c2, A1 = A2, B1 = B2, C1 = C2;
        give_check_correctness_figure(get_figure_parameters());

    }
    void get_info() override
    {
        cout << get_figure_name() << endl;
        cout << get_is_figure_right() << endl;
        cout << "Количество сторон: " << get_field() << endl;
        cout << "Стороны: " << "a=" << a1 << " " << "b=" << b1 << " " << "c=" << c1 << endl;
        cout << "Углы: " << "A=" << A1 << " " << "B=" << B1 << " " << "C=" << C1 << endl << endl;
    }
};

class Right_triangle :public Triangle //прямоугольный треугольник (угол C всегда равен 90)
{
public:
    Right_triangle(int a, int b, int c, int A, int B) :Triangle(a, b, c, A, B, 90)
    {
        give_figure_name("Прямоугольный треугольник");
    }
};

class Isosceles_triangle : public Triangle //равнобедренный треугольник (стороны a и c равны, углы A и C равны)
{
public:
    Isosceles_triangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A)
    {
        give_figure_name("Равнобедренный треугольник:");
    }
};

class Equilateral_triangle : public Triangle //равносторонний треугольник (все стороны равны, все углы равны 60)
{
public:
    Equilateral_triangle(int a) : Triangle(a, a, a, 60, 60, 60)
    {
        give_figure_name("Равносторонний треугольник:");
    }
};

//Пошли четырёхугольники

class Quadrilateral :public Figure
{
private:
    int a1, b1, c1, d1;
    int A1, B1, C1, D1;

protected:
    string get_figure_parameters()
    {
        if ((A1 + B1 + C1 + D1) == 360)
        {
            return "Правильная";
        }
        else
        {
            return "Неправильная";
        }
    }

public:

    Quadrilateral(int a2, int b2, int c2, int d2, int A2, int B2, int C2, int D2) :Figure(4)
    {
        give_figure_name("Четырёхугольник:");
        a1 = a2, b1 = b2, c1 = c2, d1 = d2, A1 = A2, B1 = B2, C1 = C2, D1 = D2;
    }
    void get_info() override
    {
        cout << get_figure_name() << endl;
        cout << get_figure_parameters() << endl;
        cout << "Количество сторон: " << get_field() << endl;
        cout << "Стороны: " << "a=" << a1 << " " << "b=" << b1 << " " << "c=" << c1 << " " << "d=" << d1 << endl;
        cout << "Углы: " << "A=" << A1 << " " << "B=" << B1 << " " << "C=" << C1 << " " << "D=" << D1 << endl << endl;
    }
};

class Rectangle : public Quadrilateral //прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90)
{
public:
    Rectangle(int a, int b) : Quadrilateral(a, b, a, b, 90, 90, 90, 90)
    {
        give_figure_name("Прямоугольник:");
    }
};

class Square : public Quadrilateral //квадрат (все стороны равны, все углы равны 90)
{
public:
    Square(int a) : Quadrilateral(a, a, a, a, 90, 90, 90, 90)
    {
        give_figure_name("Квадрат:");
    }
};

class Parallelogram : public Quadrilateral //параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны)
{
public:
    Parallelogram(int a, int b, int A, int B) : Quadrilateral(a, b, a, b, A, B, A, B)
    {
        give_figure_name("Параллелограмм:");
    }
};

class Rhombus : public Quadrilateral //ромб (все стороны равны, углы A,C и B,D попарно равны)
{
public:
    Rhombus(int a, int A, int B) : Quadrilateral(a, a, a, a, A, B, A, B)
    {
        give_figure_name("Ромб:");
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

    Figure figure(0);
    Triangle triangle(10, 20, 30, 50, 60, 70);
    Right_triangle right_triangle(10, 20, 30, 50, 60);
    Right_triangle right_triangle1(10, 20, 30, 50, 40);
    Isosceles_triangle isosceles_triangle(10, 20, 50, 40);
    Equilateral_triangle equilateral_triangle(30);

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);
    
    print_figures(&figure);
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