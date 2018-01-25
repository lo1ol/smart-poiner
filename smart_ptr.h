#ifndef SMART_PTR_H
#define SMART_PTR_H

template <typename BaseType>
class smart_ptr{
private:
    BaseType* obj;
    int* count;
public:
    smart_ptr();
    smart_ptr(BaseType* ptr);
    smart_ptr(smart_ptr& sptr);
    smart_ptr& operator= (smart_ptr& sptr);
    BaseType* operator-> ();
    BaseType& operator* ();
    BaseType& operator[](int n);
    ~smart_ptr();
    int get_count();
    void reset();
    void swap(smart_ptr& sptr);

private:
    void remove();
};



template <typename BaseType>
smart_ptr<BaseType>::smart_ptr(BaseType* ptr)
{
        obj = ptr;
        count=new int;
        *count = 1;
        std::cout<<"catch pointer on "<<obj<<". Count = "<<*count<<std::endl;
}


template <typename BaseType>
smart_ptr<BaseType>::smart_ptr(
        smart_ptr& sptr)
{
        obj = sptr.obj;
        count = sptr.count;
        (*count)++;
        std::cout<<"catch pointer on "<<obj<<". Count = "<<*count<<std::endl;
}

template <typename BaseType>
smart_ptr<BaseType>::smart_ptr(){
    count = nullptr;
}


template <typename BaseType>
smart_ptr<BaseType>& smart_ptr<BaseType>::operator= (smart_ptr& sptr){
    if (count != nullptr){
        remove();
    }
    if (this != &sptr){
        obj = sptr.obj;
        count = sptr.count;
        (*count)++;
    }
    std::cout<<"catch pointer on "<<obj<<". Count = "<<*count<<std::endl;
    return *this;
}


template <typename BaseType>
BaseType& smart_ptr<BaseType>::operator* (){
    return *obj;
}


template <typename BaseType>
BaseType* smart_ptr<BaseType>::operator-> (){
    return obj;
}


template <typename BaseType>
smart_ptr<BaseType>::~smart_ptr (){
    remove();
}


template <typename BaseType>
void smart_ptr<BaseType>::remove(){
    if (count == nullptr)
        return;

    (*count)--;
    if (*count == 0){
        std::cout<<"remove pointer on "<<obj<<" completele"<<std::endl;
        delete obj;
        obj = nullptr;
        delete count;
        count = nullptr;
    }
    else
        std::cout<<"remove pointer on "<<obj<<". "<<*count<<" left"<<std::endl;
}

template <typename BaseType>
void smart_ptr<BaseType>::reset(){
    if (count == nullptr)
        return;
    else{
        remove();
        count = nullptr;
    }
}

template <typename BaseType>
int smart_ptr<BaseType>::get_count(){
    if (count == nullptr)
        return 0;
    return *count;
}


template <typename BaseType>
BaseType& smart_ptr<BaseType>::operator[](int n){
    return obj[n];
}

template <typename BaseType>
void smart_ptr<BaseType>::swap(smart_ptr& sptr){
    int* tmp_count;
    BaseType* tmp_obj;
    tmp_count = sptr.count;
    tmp_obj = sptr.obj;
    sptr.count = this->count;
    sptr.obj = this->obj;
    this->count = tmp_count;
    this->obj = tmp_obj;
}

#endif // SMART_PTR_H
