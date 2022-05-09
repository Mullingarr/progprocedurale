//
// Created by Mattia Lunardi on 07/05/22.
//

#ifndef PROGPROCEDURALE_ITERATOR_H
#define PROGPROCEDURALE_ITERATOR_H

template<class T>class Iterator{
public:
    explicit Iterator(T *ptr): ptr(ptr){}

    Iterator operator++(){
        ++ptr;
        return *this;
    }

    bool operator!=(const Iterator& other) const {return ptr != other.ptr;}
    const T& operator*() const {return *ptr;}
    //https://stackoverflow.com/questions/8164567/how-to-make-my-custom-type-to-work-with-range-based-for-loops
    //todo: implement begin and end
private:
    T *ptr;
};

#endif //PROGPROCEDURALE_ITERATOR_H
