//unique pointer is a smart poitner that uniquely owns the pointer. this poitenr cannot be copied and only be moved
#include <iostream>
#include <memory>
class Rectangle
{
 public:
   Rectangle(int l,int b):length(l),bre(b){}
   Rectangle(Rectangle &&obj)
   {
     length = obj.length;
     bre = obj.bre;
   }
   void area(){std::cout << "\n AREA IS = " << length << " " << bre <<"\n";}
 private:
   int length,bre;
};

template<class T>
class MyUniquePtr
{
  public:
   // MyUniquePtr():ptr(nullptr){}
    explicit MyUniquePtr(T*p):ptr(p){std::cout << "\n CALLED \n";}

    //Avoid Copying
    MyUniquePtr(const MyUniquePtr&p) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&p) = delete;

    //Allow Moving
    MyUniquePtr(MyUniquePtr&&p):ptr(std::move(p.ptr))
    {
      std::cout << "\n Moving "<<std::endl;
      p.ptr = nullptr;
    }

    //Destructor
    ~MyUniquePtr()
    {
      delete ptr;
      ptr = nullptr;
    }

    //overload *
    T&operator *()
    {
      return *ptr;
    }
    T*operator->()
    {
      return ptr;
    }

    operator bool()const
    {
      if(ptr)
        return true;
      
      return false;
    }


  private:
    T*ptr;
};

int main()
{

#if 0
  std::unique_ptr<Rectangle>upr(new Rectangle(3,4));
  upr->area();
  std::unique_ptr<Rectangle>up1;
  up1 = std::move(upr);
  if(up1)
    up1->area();


  if(!upr) //on moving upr will be null
    std::cout << "upr is dlete";
  else
    upr->area();
  //up1 = upr; //error as the assignement oeprator is deleted

#else

  //This Should give same behavior
  MyUniquePtr<Rectangle>upr(new Rectangle(3,4));
  upr->area();
  MyUniquePtr<Rectangle>up1 = std::move(upr);
  if(up1)
    up1->area();


  if(!upr) //on moving upr will be null
    std::cout << "upr is dlete";
  else
    upr->area();
  //up1 = upr; //error as the assignement oeprator is deleted
#endif


}

