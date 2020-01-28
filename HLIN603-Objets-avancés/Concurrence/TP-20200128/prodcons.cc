// compiler avec les options : -Wall -std=c++11
// Exercice 6,  
#include <thread>
#include <iostream>
#include <queue>
#include <future>

class Producteur{
public:
  void operator()(std::queue<int> & buffer, bool & fini) const{

    for (int i = 1; i <= 100; ++i) {
      buffer.push(i);
    }
    fini = true;
  }
};

class Consommateur{
public:
  int operator()(std::queue<int> & buffer, bool & fini) const{

    int summ = 0;
    while (!fini) {
      while (!buffer.empty()) {
	summ+=buffer.front(); 
	buffer.pop();
      }
    }
    return summ;
  }
};



int main(){
  
  Producteur prod;
  Consommateur cons;

  std::queue<int> buffer;
  bool fin = false;
  
  std::thread t1(prod,  std::ref(buffer), std::ref(fin));
  std::future<int> resultat = std::async(cons, std::ref(buffer), std::ref(fin));

  t1.join();
  int res = resultat.get();
  std::cout << "Somme : " << res << std::endl;
  return 0;

}

