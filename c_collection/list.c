/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "list.h"
#include <stdlib.h>


 List* init() {
     List* list = malloc(sizeof(List));
     list->size = 0;
     return list;
 }
 
 void discard(List* list) {
     if(list){
         if(list->size != 0)
             free(list->data);
         free(list);
     }
 }
 
 void push(int value, List* list) {
     int *tmp;
     if(list->size == 0){
         list->data = malloc(sizeof(int));
     }else{
         tmp = malloc((list->size + 1) * sizeof(int));
         for(int i=0; i < list->size; i++)
             tmp[i] = list->data[i];
         free(list->data);
         list->data = tmp;
     }
     list->data[list->size] = value;
     list->size ++;
 }
 
 pop_result pop(List* list) {
     pop_result result;
     result.val = 0;
     result.success = false;
     int* new_data = NULL;
     if(list->size != 0) {
         list->size --;
         result.val = list->data[list->size];
         result.success = true;
         if(list->size !=0){
             new_data = malloc(list->size * sizeof(int));
             for(int i=0; i < list->size; i++)
             new_data[i] = list->data[i];
         }
         free(list->data);
         list->data = new_data;
     }
     return result;
 }

