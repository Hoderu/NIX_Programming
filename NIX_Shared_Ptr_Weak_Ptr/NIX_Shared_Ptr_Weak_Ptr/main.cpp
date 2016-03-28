//
//  main.cpp
//  Unique_ptr
//
//  Created by Андрей Решетников on 16.03.16.
//  Copyright © 2016 mipt. All rights reserved.
//

namespace student
{
template <class T> class shared_ptr
    {
    public:
        T* data;
        int* my_shared_counter;
        int* my_weak_counter;
    public:
        shared_ptr()
        {
            data = nullptr;
            my_shared_counter = nullptr;
            my_weak_counter = nullptr;
        }
        shared_ptr(T* pointer)
        {
            if (!pointer)
            {
                data = nullptr;
                my_shared_counter = nullptr;
                my_weak_counter = nullptr;
            }
            else
            {
                data = pointer;
                my_shared_counter = new int(1);
                my_weak_counter = new int(0);
            }
        }
        shared_ptr(shared_ptr&& other)
        {
            data = other.data;
            my_shared_counter = other.my_shared_counter;
            my_weak_counter = other.my_weak_counter;
            other.data = nullptr;
            other.my_shared_counter = nullptr;
            other.my_weak_counter = nullptr;
        }
        shared_ptr(shared_ptr const& other)
        {
            data = other.data;
            my_shared_counter = other.my_shared_counter;
            my_weak_counter = other.my_weak_counter;
            if (data)
            {
                ++(*my_shared_counter);
            }
        }
        
        shared_ptr(T* pointer, int* shared, int* weak)
        {
            data = pointer;
            my_shared_counter = shared;
            if (data)
            {
                ++(*my_shared_counter);
            }
            my_weak_counter = weak;
        }
        
        void reset(T* pointer)
        {
                if (data && !(--(*my_shared_counter)))
                {
                    delete data;
                    if (!(*my_weak_counter))
                    {
                        delete my_shared_counter;
                        delete my_weak_counter;
                    }
                }
            if (pointer != nullptr)
            {
                my_shared_counter = new int(1);
                my_weak_counter = new int(0);
            }
            data = pointer;
        }
        
        void reset()
        {
            reset(nullptr);
        }
        
        ~shared_ptr()
        {
            reset();
        }
        
        T& operator*()
        {
            return *data;
        }
        
        T* operator->()
        {
            return data;
        }
        
        shared_ptr& operator=(shared_ptr<T>&& other)
        {
            reset();
            data = other.data;
            my_shared_counter = other.my_shared_counter;
            my_weak_counter = other.my_weak_counter;
            other.data = nullptr;
            other.my_shared_counter = nullptr;
            other.my_weak_counter = nullptr;
            return *this;
        }
        
        shared_ptr& operator=(shared_ptr<T> const& other)
        {
            reset();
            data = other.data;
            my_shared_counter = other.my_shared_counter;
            my_weak_counter = other.my_weak_counter;
            if (data)
            {
                ++(*my_shared_counter);
            }
            return *this;
        }
        
        T* get()
        {
            return data;
        }
        
        void swap(shared_ptr<T>& x)
        {
            T* swap_parametrs = data;
            data = x.data;
            x.data = swap_parametrs;
            
            int* swap_counters = my_shared_counter;
            my_shared_counter = x.my_shared_counter;
            x.my_shared_counter = swap_counters;
            swap_counters = my_weak_counter;
            my_weak_counter = x.my_weak_counter;
            x.my_weak_counter = swap_counters;
        }
        
        operator bool()
        {
            return data;
        }
        
        int use_count()
        {
            if (data)
            {
                return *my_shared_counter;
            }
            else
            {
                return 0;
            }
        }
    };
    
    template<class T> class weak_ptr
    {
        T* data;
        int* my_shared_counter;
        int* my_weak_counter;
    public:
        weak_ptr()
        {
            data = nullptr;
            my_weak_counter = nullptr;
            my_shared_counter = nullptr;
        }
        weak_ptr(weak_ptr const& other)
        {
            data = other.data;
            my_shared_counter = other.my_shared_counter;
            my_weak_counter = other.my_weak_counter;
            if (data)
            {
                ++(*my_weak_counter);
            }
        }
        
        weak_ptr(weak_ptr&& other)
        {
            data = other.data;
            my_shared_counter = other.my_shared_counter;
            my_weak_counter = other.my_weak_counter;
            other.data = nullptr;
            other.my_shared_counter = nullptr;
            other.my_weak_counter = nullptr;
        }
        
        weak_ptr(shared_ptr<T> const& other)
        {
            data = other.data;
            my_shared_counter = other.my_shared_counter;
            my_weak_counter = other.my_weak_counter;
            if (data)
            {
                ++(*my_weak_counter);
            }
        }
        
        void reset()
        {
                if (data && !(--*my_weak_counter) && !(*my_shared_counter))
                {
                    delete my_weak_counter;
                    delete my_shared_counter;
                }
            data = nullptr;
            my_shared_counter = nullptr;
            my_weak_counter = nullptr;
        }
        
        weak_ptr& operator = (shared_ptr<T> const& other)
        {
            reset();
            data = other.data;
            my_shared_counter = other.my_shared_counter;
            my_weak_counter = other.my_weak_counter;
            if (data)
            {
                ++(*my_weak_counter);
            }
            return *this;
        }
        
        ~weak_ptr()
        {
            reset();
        }
        
        weak_ptr& operator = (weak_ptr const& other)
        {
            reset();
            data = other.data;
            my_shared_counter = other.my_shared_counter;
            my_weak_counter = other.my_weak_counter;
            if (data)
            {
                ++(*my_weak_counter);
            }
            return *this;
        }
        
        weak_ptr& operator = (weak_ptr&& other)
        {
            reset();
            data = other.data;
            my_shared_counter = other.my_shared_counter;
            my_weak_counter = other.my_weak_counter;
            other.data = nullptr;
            other.my_shared_counter = nullptr;
            other.my_weak_counter = nullptr;
            return *this;
        }
        
        void swap (weak_ptr& x)
        {
            T* swap_parametrs = data;
            data = x.data;
            x.data = swap_parametrs;
            
            int* swap_counter = my_shared_counter;
            my_shared_counter = x.my_shared_counter;
            x.my_shared_counter = swap_counter;
            swap_counter = my_weak_counter;
            my_weak_counter = x.my_weak_counter;
            x.my_weak_counter = swap_counter;
        }
        
        int use_count()
        {
            if (data)
            {
                return *my_shared_counter;
            }
            else
            {
                return 0;
            }
        }
        
        bool expired()
        {
            return !(use_count());
        }
        
        shared_ptr<T> lock()
        {
            if (!(*my_shared_counter))
            {
                return shared_ptr<T>();
            }
            return shared_ptr<T>(data, my_shared_counter, my_weak_counter);
        }
    };
}