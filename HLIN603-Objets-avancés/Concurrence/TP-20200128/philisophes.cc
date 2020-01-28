#include <thread>
#include <iostream>
#include <mutex>
#include <functional>

class Philo{
public:
  void operator()(std::mutex & baguetteG, std::mutex & baguetteD, int place) const{

    while(true){
      std::this_thread::sleep_for(std::chrono::milliseconds(1));//je pense
      std::cout<< "Philisophe "<<place<<" pense"<<std::endl;
      baguetteG.lock();      
      baguetteD.lock();
      std::cout<< "Philisophe "<<place<<" mange"<<std::endl;
      std::this_thread::sleep_for(std::chrono::milliseconds(place));//je mange  
      baguetteG.unlock();
      baguetteD.unlock();    
    }
  }
};



int main(){
  
  std::thread tphilos[5];
  Philo philos[5];
  std::mutex baguettes[5];



  for(int i=0; i < 4; i++)
    tphilos[i] = std::thread(philos[i], std::ref(baguettes[i+1]),  std::ref(baguettes[i]), i+1);
  tphilos[4] = std::thread(philos[4], std::ref(baguettes[0]),  std::ref(baguettes[4]), 5);

  for(int i=0; i < 5; i++)
    tphilos[i].join();
  return 0;

}

