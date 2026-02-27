#include <iostream>

//SImilar to autoptr which is depreceated

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

    //The copy constructor does move thingy.
    //This is solutin 3 i told neche
    //This is how auto ptr did
    //drawback is when we accessed the original not realizing it was moved. it will be null so boom crash
    //other drawback is it doesnt handle array thats why auto ptr was depreached
    SmartPointer(SmartPointer &rhs)//note not const
    {
      //normally we do copying of memory here we move the membership
      //better would be do in move constructor 
      this->m_ptr = rhs.m_ptr;
      rhs.m_ptr = nullptr;
      
    }

    //Copy assignment
    SmartPointer &operator = (SmartPointer & a)
    {
      
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

int main()
{
  SmartPointer<int> pt(new int());
  //Without Copy constructor and assignment it crashes. as both now points to same reosurce
  //Solution 1 would be to mark both copy constructor and assignment to be deleted to avoid copying
  //Drawback is in the followig case
  /**
   *  generateResource()
   * {
   *    Resource * res {new Resource()};
   *    return SmartPointer(res);
   * }
   * 
   * NOw since we have deleted the copy and assignment we cannt return with value but if we tried returning by reference
   * now since SmartPointer goes out of scope destructor will be called which deletes the memery which is not we required. so 
   * returning without reference is the only thing we can do which causes shallow copy
   * I remember in my challanScreen when I introduced smartpointer in a function and created a pointer with that it crashed
   * as soon as it got out of the scope.
   * 
   * Solution 2 
   * Make Copy constructor and assignment overload. but copying can be expensive
   * 
   * 
   * Solution 3 
   * Best of all - Move
   * With move we transfer the ownership 
   */
  SmartPointer<int> pt1(pt);
  std::cout << "\n Here\n";
  //(*pt will be nullptr)
  *pt1 = 100;
  std::cout << "Pointer value is - " << *pt1 << "\n";

}
