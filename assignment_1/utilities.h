#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>
using namespace std;

template <typename T>
T* allocated(const int index){
    T* tmp = new T [index + 1];
    T* dest = tmp;
    int c = 0;
    for(int i = 0; i < index + 1; i++){
        *dest = T();
        dest++;
        c++;
    }
    cout << c<< endl;
    dest = nullptr;
    return tmp;
};

template <typename T>
T* allocated(T* copy_this, const int index){
    T* tmp = new T [index + 1];
    T* dest = copy_this;
    T* src = tmp;
    while (dest != nullptr){
        dest = src;
        dest++;
        src++;
    }
    dest = nullptr;
    deallocated(copy_this);
    return tmp;
};


template <typename T>
void deallocated(T* delete_this){
    delete [] delete_this;
};




#endif