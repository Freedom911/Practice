//shared pointer allows more than one pointer to point to single object
#include <iostream>
#include <memory>
class Rectangle
{
 public:
   Rectangle(int l,int b):length(l),bre(b){}
   void area(){std::cout << "\n AREA IS = " << length << " " << bre <<"\n";}
 private:
   int length,bre;
};

template<class T>
class custom_shared_ptr
{
  public:
    custom_shared_ptr():m_ptr(nullptr),m_refCount(new int(0)){}
    custom_shared_ptr(T*ptr):m_ptr(ptr),m_refCount(new int(1)){}

    //Copy Constructor
    custom_shared_ptr(const custom_shared_ptr&rhs)
    {
      this->m_ptr = rhs.m_ptr;
      this->m_refCount = rhs.m_refCount;
      std::cout << "\n Copy called " << *m_refCount;
      if(rhs.m_ptr)
      {    (*m_refCount)++;
      std::cout << "\n Copy called " << *m_refCount;
      }
    }

    //assignment operator
    custom_shared_ptr &operator = (const custom_shared_ptr &obj)
    {
      //check for self assignement
      if(&obj == this)
        return *this;
      cleanup();
      this->m_ptr = obj.m_ptr;
      this->m_refCount = obj.m_refCount;
      if(obj.m_ptr)
        (*this->m_refCount)++;

    }

    //move constructor
    custom_shared_ptr(custom_shared_ptr&&rhs)
    {
      this->m_ptr = rhs.m_ptr;
      this->m_refCount = rhs.m_refCount;
      rhs.m_ptr = rhs.m_refCount = nullptr;
    }
    custom_shared_ptr operator = (custom_shared_ptr &&obj)
    {
      cleanup();
      this->m_ptr = obj.m_ptr;
      this->m_refCount = obj.m_refCount;
      obj.m_ptr = obj.m_refCount = nullptr;
    }

    ~custom_shared_ptr()
    {
      cleanup();
    }

    //overload methods
    //return reference so that we can do *ptr = value
//   T &operator *()
//   {
//     return *m_ptr;
//   }
//
    //return a pointer
    T *operator->()
    {
      return m_ptr;
    }

    int get_count()
    {
      if(m_refCount)
        return *m_refCount;
      return -1;
    }

  private:
    void cleanup()
    {
      (*m_refCount)--;

      if(*m_refCount == 0)
      {
        delete m_ptr;
        m_ptr = nullptr;
        delete m_refCount;
        m_refCount = nullptr;
      }

    }
    T*m_ptr;
    int *m_refCount; //we are using pointer to m_refCount since we want m_refCount to be maintained accross objects
                        //so we make pointer because if we change at one place it is reflected at all
                        //can also make static
};


int main()
{

#if 0
  std::shared_ptr<Rectangle>spr(new Rectangle(3,4));
  spr->area();
  //std::weak_ptr<Rectangle>spr1 = spr; //if we use weak pointer then ref count is not increased
  std::shared_ptr<Rectangle>spr1 = spr; 

  std::cout << "\n Reference count is = " << spr1.use_count();
#else
  custom_shared_ptr<Rectangle>spr(new Rectangle(3,4));
  spr->area();
  {
    //std::weak_ptr<Rectangle>spr1 = spr; //if we use weak pointer then ref count is not increased
    custom_shared_ptr<Rectangle>spr1 = spr; 

    std::cout << "\n Reference count is = " << spr.get_count();
  }
    std::cout << "\n Reference count is = " << spr.get_count();
#endif


}

