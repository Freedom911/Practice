#include <iostream>

//SImilar to autoptr which is depreceated
//This contains fix of autoptr with move constructor and assignment

template<class T>
class SmartPointer
{
  public:
    SmartPointer(T*ptr = nullptr)
    {
      m_ptr = ptr;
    }
    ~SmartPointer()
    {
      delete m_ptr;
      m_ptr = nullptr;
    }

    //overload * operator
    //we are returning reference so that we can assign value
    T& operator*()
    {
      return *m_ptr;
    }

    T* operator->()
    {
      return m_ptr;
    }

    //The copy constructor
    SmartPointer(const SmartPointer &rhs)//should be deleted
    {
      std::cout << "\n Copy Constructor \n";
      m_ptr = new T;
      *m_ptr = *rhs.m_ptr ;//copy value
      
    }

    //Move Constructor
    //Should be noexcept
    SmartPointer( SmartPointer &&rhs) noexcept :m_ptr{rhs.m_ptr}
    {
      std::cout << "\n Move Constructor \n";
      rhs.m_ptr = nullptr;
    }

    //Copy assignment ddo deep copy
    SmartPointer &operator = (const SmartPointer & a)//should be deleted
    {
      std::cout << "\n Copy Assignment \n";
      if(&a == this)
      {
        return *this;
      }
      delete m_ptr;
      m_ptr = new T();
      *m_ptr = *a.m_ptr;
      return *this;
    }

    //Move assignment
    SmartPointer &operator = (SmartPointer && a)
    {
      std::cout << "\n Move assignment \n";
      if(&a == this)
      {
        return *this;
      }
      delete m_ptr;
      m_ptr = a.m_ptr;
      a.m_ptr = nullptr;
      return *this;
    }



  private:
    T* m_ptr;
};


//In this specific code, 
//the reason you don't see the Move Constructor message is due to a 
//standard C++ optimization called Copy Elision (specifically, NRVO - Named Return Value Optimization).
//originally it should do
/**
 * However, the C++ compiler is smarter. It realizes that res is just going to be moved into pt1 anyway.
 *  So, it constructs res directly inside the memory address of pt1.
 * Since the object is built where it needs to stay, there is no "moving" to do.
 *  Therefore, the Move Constructor is never called.
 */
SmartPointer<int> generateResource()
{
  SmartPointer<int> res{new int()};
  return res;
}

int main()
{
  SmartPointer<int> pt(new int());

  SmartPointer<int> pt1 = generateResource();//compiler optimizes  with copy espilon no move just directly assignt to pt1
  SmartPointer<int>pt2;
   //here the compiler will call the move assignment and not copy. and no copy espilon optimization
   //The compiler detects it s a temporary value so move assignemnt
  pt2 = generateResource();
  std::cout << "Pointer value is - " << *pt1 << "\n";

}
