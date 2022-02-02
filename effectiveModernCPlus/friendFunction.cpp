//Real world example of using friend function of adding a complex class with matrix class
#include <iostream>
class Matrix;
class Complex
{
  public:
    Complex()
    {
      real = 5;
      imagi = 10;
    }
    void show()
    {
      std::cout << "\n VALUE is = " << real << " " << imagi << "\n";
    }

  private:
    friend Complex operator+(const Complex&rhs,const Matrix &lhs);
    double real,imagi;
};
class Matrix
{
  public:
    Matrix()
    {
      real = 5;
    }

  private:
    friend Complex operator+(const Complex&rhs,const Matrix &lhs);
    double real;
};

Complex operator+(const Complex&rhs,const Matrix &lhs)
{
  Complex newOb = rhs;
  newOb.real += lhs.real;
  newOb.imagi += lhs.real;
  return newOb;
}

int main()
{
  Complex c;
  Matrix m;
  Complex d = c+ m;
  d.show();
}
