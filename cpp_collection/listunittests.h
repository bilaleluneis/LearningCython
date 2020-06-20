/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   listunittests.h
 * Author: bilaleluneis
 *
 * Created on Jun 12, 2020, 5:41:21 AM
 */

#ifndef LISTUNITTESTS_H
#define LISTUNITTESTS_H

#include <cppunit/extensions/HelperMacros.h>
#include "list.h"

class listunittests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(listunittests);

    CPPUNIT_TEST(testList);
    CPPUNIT_TEST(testPush);
    CPPUNIT_TEST(testPop);
    CPPUNIT_TEST(testSupportedListTypes);

    CPPUNIT_TEST_SUITE_END();

public:
    listunittests();
    virtual ~listunittests();
    void setUp();
    void tearDown();

private:
    void testList();
    void testPush();
    void testPop();
    void testSupportedListTypes();
    List<int> *intList;

};

#endif /* LISTUNITTESTS_H */

