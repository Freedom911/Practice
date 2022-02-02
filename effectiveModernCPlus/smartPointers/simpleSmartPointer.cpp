#include <iostream>

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

  private:
    T* m_ptr;
};

int main()
{
  SmartPointer<int> pt(new int());
  *pt = 100;
  std::cout << "Pointer value is - " << *pt << "\n";

}
