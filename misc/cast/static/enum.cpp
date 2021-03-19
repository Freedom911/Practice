//Static CAst Can be used for converting both scoped and unscoped enum to integral type
//and reverse
#include <iostream>

enum Color{red,green,blue};
enum class ColorScoped{red1,green1,blue1};
enum class ColorInt:char
{
  red2 = 'r',
  green2 = 'g',
  blue2 = 'b'
};


int main()
{
  Color r = red;
  ColorScoped c = ColorScoped::red1;
  ColorInt i = ColorInt::red2;

  //will give error
  //std::cout  << i << "\n";
  //
  char ch = static_cast<char>(i);
  std::cout << ch << "\n";


  int t = static_cast<int>(i);
  std::cout << t << "\n";

  //Gives error
  //std::cout << c << "\n";

  std::cout << static_cast<int>(c) << "\n";

  //Gives Error
  //ColorScoped cse = 2;
  ColorScoped cs = static_cast<ColorScoped>(2);
}

