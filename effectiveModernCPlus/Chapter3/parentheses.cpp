#include <iostream>

//2nd Usage for Default Value
class Widget
{
  private:
    int i{0};//fine
    int j = 0;//fine
    //int k(0); //error
};


//4 Problem of {} it degrades to initializer list.Here it preferes intializer list one
//Same Problem Will occur instead of Copy or move constructor initializer list one would be called
class Shape
{
  public:

    Shape(const Shape &shape)
    {
      std::cout << "\n Copy Constructor \n";
    }

    Shape(int i,double d)
    {
      std::cout << "\n Int and Doubel one called " << std::endl;
    }

    Shape(std::initializer_list<int> v)
    {
      std::cout << "\n Intializer One Called " << std::endl;
    }

    //Convert to int
    operator int() const
    {
       return 0;
    }
};



int main()
{
  //1.Initialization---------------------------------------------------
  int a { 3 };
  int b = 4;
  int c (4);

  std::cout << a << " " << b << " " << c << "\n";


  //2. will give error------------------------------------------------
  //int a1 { 3,54 };
 //std::cout << a1 << "\n";
 //int a1(3,4);
 //std::cout << a1 << "\n";

  //3rd Usage it prohbits implicity narrow conversion-----------------
  //will give warning
  double x = 4.4,y = 3.2;

  int sum {x + y};
  
  double sum1 {x + y};//this wont

  std::cout << sum << "\n";
  std::cout << sum1 << "\n";

  //No Warning Below
  int sum2(x+y);
  
  std::cout << sum2 << "\n";


  //4.Problem of parentheses-----------------------------------------
  //Shape s{10,5.0};-------------------------Will be converted to intializer list one
  Shape s(10,5.0);

  Shape d{10,5};

  Shape e = s; //thiss will call copy constructor

  Shape f{s}; // This wont call copy constructor




}
