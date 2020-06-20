/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   listunittests.cpp
 * Author: bilaleluneis
 *
 * Created on Jun 12, 2020, 5:41:22 AM
 */

#include "listunittests.h"


CPPUNIT_TEST_SUITE_REGISTRATION(listunittests);

listunittests::listunittests() {}

listunittests::~listunittests() {
    if(intList != nullptr){
        delete intList;
        intList = nullptr;
    }
}

void listunittests::setUp() { 
    cout << "in setUp()\n";
    intList = new List<int>(); 
}

void listunittests::tearDown() { 
    cout << "in tearDown()\n";
    if(intList != nullptr){
        delete intList; 
        intList = nullptr;
    }
}

void listunittests::testList() {
    cout << "in testList()\n";
    CPPUNIT_ASSERT(intList != nullptr);
    CPPUNIT_ASSERT(intList->size() == 0);
}



void listunittests::testPush() {
    cout << "in testPush()\n";
    CPPUNIT_ASSERT(intList->size() == 0);
    intList->push(10);
    CPPUNIT_ASSERT(intList->size() == 1);
}

void listunittests::testPop() {
    cout << "in testPop()\n";
    
    cout << "Test poping an empty list\n";
    CPPUNIT_ASSERT(intList->size() == 0);
    pair<int, bool> result = intList->pop();
    CPPUNIT_ASSERT(result.second == false);
    
    cout << "Test poping non empty list\n";
    intList->push(10);
    CPPUNIT_ASSERT(intList->size() == 1);
    result = intList->pop();
    CPPUNIT_ASSERT(result.second == true && result.first == 10);
}

void listunittests::testSupportedListTypes() {
    cout << "in testSupportedListTypes()\n";
    List<char> *charList = new List<char>();
    CPPUNIT_ASSERT(charList != nullptr);
    delete charList;
    charList = nullptr;
    CPPUNIT_ASSERT(charList == nullptr);
}

