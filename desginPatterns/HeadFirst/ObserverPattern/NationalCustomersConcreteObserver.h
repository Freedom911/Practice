#pragma once
#include "Observer.h"
#include "Subject.h"
#include <thread>
#include <sstream>

class NationalCustomersConcreteObserver:public Observer
{
  public:
  NationalCustomersConcreteObserver(Subject *SubjectToRegisterFor,std::string userName)
  {
      m_subject = SubjectToRegisterFor;
      m_bChangeAcknowledged = true;
      m_bStopThread = false;
      m_userName = userName;
      m_subject->Register(this);

      std::cout << "\n User = " << m_userName << " subscribed to " << m_subject->GetProductName() << "\n";
  }

  ~NationalCustomersConcreteObserver()
  {
      m_bStopThread = true;
      m_thread.join();
      m_subject->UnRegister(this);
      std::cout << "\n User = " << m_userName << " Unsubscribed from " << m_subject->GetProductName() << " list\n";
  }

  void StartOperation()
  {
    m_thread = std::thread(&NationalCustomersConcreteObserver::SendEmail,this);   
  }
  
  void Update()
  {
      m_bChangeAcknowledged = false;
  }

  private:
  void SendEmail()
  {

      while(m_bStopThread == false)
      {
          if(m_bChangeAcknowledged == true)
          {
              //sleep
              std::this_thread::sleep_for(std::chrono::seconds(1));
              continue;
          }
          
          float Price = m_subject->GetPrice();
          float Discount = m_subject->GetDiscountPercentage();
          float PriceAfterDiscount = m_subject->GetPrice() - ((Discount/100.0) * Price);
          std::ostringstream out;
          out <<  "\nProduct  " << m_subject->GetProductName() << " is on ";
          out <<  Discount << "% and is available at Rs. ";
          out << PriceAfterDiscount << "/. only. Hurry before the offer ends!! Sending Mail to " << m_userName << "\n";

          std::cout << out.str() << std::endl;
          //send Email
          m_bChangeAcknowledged = true;
      }
  }

  std::thread m_thread;
  Subject* m_subject {nullptr};
  bool m_bChangeAcknowledged;
  bool m_bStopThread;
  std::string m_userName;
};
