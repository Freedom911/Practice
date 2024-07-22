#include "NationalCustomersConcreteObserver.h"
#include "IphoneConcreteSubject.h"
#include "PS5ConcreteSubject.h"
#include "SonyTVConcreteSubject.h"
#include <thread>
#include <chrono>
#include <random>

//Not Part of Strategy Pattern. 
//just using this to call notify of subject
//which in real world would come from outside
void GenerateSale(Subject * obj,std::string Product)
{
    std::mt19937_64 eng{std::random_device{}()};  // or seed however you want
    std::uniform_int_distribution<> dist{1500, 4500};
    while(true)
    {
      std::this_thread::sleep_for(std::chrono::milliseconds{dist(eng)});
      std::cout << "\n Initiating Sale for " << Product <<  std::endl;

      obj->Notify();

    }
}

int main()
{
    std::unique_ptr<IphoneConcreteSubject> iphoneProduct(new IphoneConcreteSubject());

    //Subscribe user 1 to Iphone Product
    NationalCustomersConcreteObserver user1(iphoneProduct.get(),"chotu");
    user1.StartOperation();

    //Subscribe user 2 to Iphone Product
    NationalCustomersConcreteObserver user2(iphoneProduct.get(),"yashu");
    user2.StartOperation();


    //Subscribe user 3 to PS5 Product
    std::unique_ptr<PS5ConcreteSubject> playStationProduct(new PS5ConcreteSubject());
    NationalCustomersConcreteObserver user3(playStationProduct.get(),"geralt");
    user3.StartOperation();

    //Subscribe user 4 to Sony Product
    std::unique_ptr<SonyTVConcreteSubject> sonyProduct(new SonyTVConcreteSubject());
    NationalCustomersConcreteObserver user4(sonyProduct.get(),"ezio");
    user4.StartOperation();

    //connor decides to subscribe for tv
    {
        NationalCustomersConcreteObserver user5(sonyProduct.get(),"Connor");
        user5.StartOperation();
    }
    //connor not want tv. On destructor it Unregisters

   

    std::thread t1(GenerateSale,iphoneProduct.get(),"Iphone");
    std::thread t2(GenerateSale,playStationProduct.get(),"PS5");
    std::thread t3(GenerateSale,sonyProduct.get(),"TV");

    t1.join();
    t2.join();
    t3.join();


}
