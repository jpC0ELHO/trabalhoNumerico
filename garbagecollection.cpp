#include <math.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class disposing{};

class GarbageCollection
{
private:
   
    std::unordered_map<void*,int>refCount;

public:
   
   void add(void*obj){
    refCount[obj]=1;
   }

   void incrementRef(void* obj) {
    if (obj && refCount.find(obj) != refCount.end()) {
            refCount[obj]++;
        }
   }

   void decrementRef(void* obj) {

    if (obj && refCount.find(obj) != refCount.end()) {

            refCount[obj]--;

            if (refCount[obj] == 0) {
                delete (int*)obj; 
                refCount.erase(obj);
                std::cout << "Memoria livre!\n";
            }
        }
   }

};


GarbageCollection gc;

class PontoIntelig{

};


