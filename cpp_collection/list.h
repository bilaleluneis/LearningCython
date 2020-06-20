/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   list.h
 * Author: bilaleluneis
 *
 * Created on June 11, 2020, 6:11 PM
 */

#ifndef LIST_H
#define LIST_H

#include <utility>

using namespace std;


template<typename T> struct List {
    
    public:
        List();
        ~List();
        void push(T value);
        pair<T, bool> pop();
        int size() const;
    
    private:
        T *_data;
        int _size;
        void resetData(T*);
        
};

#endif /* LIST_H */

