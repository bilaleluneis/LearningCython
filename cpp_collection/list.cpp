/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "list.h"

template<typename T> List<T>:: List() {
    _data = nullptr;
    _size = 0;
}

template<typename T> List<T>:: ~List() {
    _size = 0;
    resetData(nullptr);
}

template<typename T> void List<T>:: push(T val) {
    T *tmp = new T[_size + 1];
    for(int i=0; i < _size; i++)
        tmp[i] = _data[i];
    tmp[_size] = val;
    resetData(tmp);
    _size ++;
}

template<typename T> pair<T, bool> List<T>:: pop() {
    bool success = false;
    T *tmp = nullptr;
    T val;
    
    if(_size == 1){
        val = _data[_size - 1];
        success = true;
        resetData(nullptr);
        _size = 0;
    }
    
    if(_size >  1){
        val = _data[_size - 1];
        success = true;
        tmp = new T[_size - 1];
        for(int i=0; i < _size; i++)
            tmp[i] = _data[i];
        resetData(tmp);
        _size --;
    }
    
    return {val, success};
}

template<typename T> void List<T>:: resetData(T *newData) {
    if(_data != nullptr){
        delete[] _data;
        _data = nullptr;
    }
    _data = newData;
}

template<typename T> int List<T>:: size() const { return _size; }

//forwad delclaration of supported specializations

// int type specializations
template class List<int>;
template class List<List<int>>;
template class List<pair<int, int>>;

// char type specializations
template class List<char>;
template class List<List<char>>;

// float type specializations
template class List<float>;
template class List<List<float>>;
template class List<pair<float, float>>;







