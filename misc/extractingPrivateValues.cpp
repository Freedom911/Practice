//This Progam shows accessing Private values of a class without modifying
//it

#include <iostream>


class MainClass
{
  private:
    int a;
    int b;
    void someFunc()
    {
    }

  public:
    MainClass()
    {
    }

    void setValues(int w,int e)
    {
      a = w;
      b = e;
    }
};

class Helper
{
  private:
    int b1;
    int a1;
    int e;
  public:
    void getValues(int &c,int &d)
    {
      c = a1;
      d = b1;
    }
};

int main()
{
  MainClass m;
  m.setValues(50,100);
  Helper *helper = reinterpret_cast<Helper*>(&m);

  if(helper)
  {
    int c,d;
    helper->getValues(c,d);
    std::cout << "\n Values are == " << c << " " << d << "\n";
  }

}
