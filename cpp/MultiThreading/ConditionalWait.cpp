/**
  * What is conditional Wait. ? It is basically to avoid busy waiting
  * It allows signalling to wake up other threads like we did in ostream
  * a thread calls notify which is basically yeild and other threads gets to know they can execute
  * It is a very good concept
  * So there is some structure that needs to be followed
  * we have std::conditional_wait variable . which needs unique lock why? not lock guard?
  * See Unique lock is smarter it even allows locking and unlocking while lock guard is dumb the mutex is unlocked
  * Only when it goes out of scope. so 
  * std::unique_lock<std::mutex>ul(mux)
  * cv.wait(ul,[]{return ready}) ->This step try to unlock the mutex ul then check the condition which is return ready
  * if it returns true then it proceed with the execution other wise it waits
  * It keeps unlocking and locking the mutex thats why unique lock
  * in other thread we use the same mutex to check
  * Here we can use lock guard or unique lock but unique lock shall be used as 
  * we will use unique lock here as well we will call unlock before notifying because assume
  * we called notify with lock guard but lock guard is called at the destructor .so when we call notify we sitll having the mutex
  * the other thread will check the mutex and it will not be able to use it
  */
  
  #include <iostream>
  #include <thread>
  #include <mutex>
  #include <condition_variable>
  #include <chrono>
  
  std::condition_variable cv;
  std::mutex mux;
  int balance = 0;
  
  void AddMoney(int money)
  {
	  std::unique_lock<std::mutex> ul(mux);
	  std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	  balance+= money;
	  ul.unlock();
	  cv.notify_one();//notify on the threads that they can use
  }
  
  void WithdrawMoney(double money)
  {
	  std::unique_lock<std::mutex>ull(mux);//same mutex
	  
	  // this line will wait till the balance >= 0. It will 	unlock the mutex so no busy waiting
	  //lock hatya then Add Money executes and this gets in sleep
	  //then then addmoney can take lock and proceed so now cv waits
	  //balance check kia if true then it can proceed further downards else it waits
	  //so this will print two times. initially this fucntion has lock it prints wait check balance so it reutrns false which release the mutex
	  // so that add moeny can execute once it notifies the lambda executes and waiting is printed
	  cv.wait(ull,[]{std::cout << "\n WAITING " << std::endl ;return balance != 0;});
	  
	  if(balance >= money)
	  {
		  balance -= money;
		  std::cout << "\n Withdrawing Money = " << money << " Current Balance = " << balance << "\n";
	  }
	  else
	  {
		  std::cout << "\n AMmount Cant be deduceted because balnce is less \n";
	  }
  }
  
  int main()
  {
	  std::thread t1(WithdrawMoney,100);
	  std::thread t2(AddMoney,200);
	  t1.join();
	  t2.join();
  }