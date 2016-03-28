//
//  main.cpp
//  Unique_ptr
//
//  Created by Андрей Решетников on 12.03.16.
//  Copyright © 2016 mipt. All rights reserved.
//

#include <iostream>
#include <memory>

namespace student {
    class illegal_operation{};
    
    template<class T>
    class unique_ptr {
    private:
        T* data;
    public:
        unique_ptr() {
            data = nullptr;
        }
        unique_ptr(T* const _data) {
            data = _data;
        }
        unique_ptr(unique_ptr<T> &&_unique_ptr) {
            data = _unique_ptr.data;
            _unique_ptr.data = nullptr;
        }
        unique_ptr(unique_ptr<T> const &_unique_ptr) = delete;
        ~unique_ptr() {
            //if (nullptr != data) {
            //    delete data;
            //}
            data = nullptr;
        }
        T& operator*() {
            return *data;
        }
        T* operator->() {
            return data;
        }
        unique_ptr& operator=(unique_ptr<T> &&_unique_ptr) {
            //if (nullptr != data) {
            //    delete data;
            //}
            data =  nullptr;
            
            data = _unique_ptr.data;
            _unique_ptr.data = nullptr;
            return *this;
        }
        unique_ptr& operator=(unique_ptr<T> const &_unique_ptr) {
            throw illegal_operation();
        }
        T* release() {
            T* buffer = data;
            data = nullptr;
            return buffer;
        }
        void reset(T* const _data) {
            //if (nullptr != data) {
            //    delete data;
            //}
            data = nullptr;
            data = _data;
        }
        T* get() {
            return data;
        }
        void swap(unique_ptr<T> &_unique_ptr) {
            T* buffer = data;
            data = _unique_ptr.data;
            _unique_ptr.data = buffer;
        }
        operator bool() {
            return nullptr != data;
        }
    };
}


/*int main(int argc, const char * argv[]) {
    
    //std::unique_ptr<char> c;
    
    int x = 6;
    int* ptr;
    ptr = &x;
    
    int* ptr1;
    int y = 7;
    ptr1 = &y;
    
    unique_ptr<int> fff(ptr);
    std::cout << *fff.get() << std::endl;
    
    unique_ptr<int> fff1(ptr1);
    std::cout << *fff1.get() << std::endl;
    
    //fff.swap(fff1);
    fff.reset(ptr1);
    std::cout << *fff.get() << std::endl;
    
    
    return 0;
}
*/