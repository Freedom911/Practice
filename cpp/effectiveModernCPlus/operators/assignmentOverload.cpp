//Progam for operatoer overloading of = operatoer
#include <iostream>
#include <cstring>

class Actor
{
  public:
    Actor()
    {
      m_size = 0;
      m_chr = nullptr;
    }
    Actor(size_t size)
    {
      m_size = size;
      m_chr = new char[size+1];
      strcpy(m_chr,"hello");
    }

    void show()
    {
      std::cout << "Actor Name = " << m_chr << "\n";
    }

    ~Actor()
    {
      std::cout << "\n Destrctor called \n";
      delete []m_chr;
    }

    Actor &operator=(const Actor &obj)
    {
      std::cout << "\n Calling equal override method \n";

      //Check self assignement
      if(this != &obj)
      {
        //delete old memory
        delete []m_chr;
        m_size = obj.m_size;
        m_chr = new char[m_size + 1];
        strcpy(m_chr,obj.m_chr);
      }

      return *this;
    }

    char *m_chr;
    size_t m_size;
};
int main()
{
  Actor a(10);
  a.show();
  Actor b;
  b = a;
  b.show();
}
