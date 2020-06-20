/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   list.h
 * Author: bilaleluneis
 *
 * Created on June 8, 2020, 9:21 PM
 */

#ifndef LIST_H
#define LIST_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include <stdbool.h>

    typedef struct {
        int* data;
        int size;
    } List;
    
    typedef struct {
        int val;
        bool success;
    } pop_result;
    
    List* init();
    void discard(List*);
    void push(int, List*);
    pop_result  pop(List*);
    

#ifdef __cplusplus
}
#endif

#endif /* LIST_H */

