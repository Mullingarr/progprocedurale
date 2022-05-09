//
// Created by Mattia Lunardi on 05/05/22.
//

#ifndef PROGPROCEDURALE_LIST_H
#define PROGPROCEDURALE_LIST_H
#include <vector>

template<class T> class List {
public:
    List(){this->numberOfItems = 0;}
    explicit List(const T&item){
        this->items.push_back(item);
        this->numberOfItems++;
    }
    ~List() = default;
    T get_head(){return this->items.front();}
    std::vector<T> get_list(){return this->items;}
    void push(const T&i){this->items.push_back(i); this->numberOfItems++;}
    T pop(){
        T item = this->items.front();
        this->items.pop_back();
        return item;
    }

    T get_at_index(int index){
        T ris = this->items[index];
        this->items.erase(this->items.begin() + (index - 1));
        this->numberOfItems--;
        return ris;
    }
    [[nodiscard]] int size() const {return this->numberOfItems;};
    T& begin(){return this->items.front();}
    T& end(){return this->items.back();}
    T& operator++(){
        T elem = items[last_pos_index];
        last_pos_index++;
        return elem;
    }
private:
    std::vector<T> items;
    int numberOfItems = 0;
    size_t last_pos_index = 0;
};


#endif //PROGPROCEDURALE_LIST_H
