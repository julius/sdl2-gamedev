#ifndef UTIL_TESTSIZE_H
#define UTIL_TESTSIZE_H

#include <util/Size.h>

#include <cxxtest/TestSuite.h>


/**
 * Test for the Size class.
 *
 * @author SwarmingLogic
 */
class TestSize : public CxxTest::TestSuite
{
public:

  void testBasic()
  {
    Size size;
    TS_ASSERT_EQUALS(size.width(),  -1);
    TS_ASSERT_EQUALS(size.height(), -1);

    Size size2(5,123);
    TS_ASSERT_EQUALS(size2.width(),  5);
    TS_ASSERT_EQUALS(size2.height(), 123);

    Size size3;
    size3.setHeight(12);
    TS_ASSERT_EQUALS(size3.height(), 12);
    TS_ASSERT_EQUALS(size3.width(), -1);
    size3.setWidth(42);
    TS_ASSERT_EQUALS(size3.width(), 42);

    // Copy constructor
    Size A(41, 23);
    Size B = A;
    TS_ASSERT_EQUALS(A, B);
    Size C(A);
    TS_ASSERT_EQUALS(A, C);
  }

  void testClassOperators() {
    Size opA(2, 3);
    Size opB(5, 7);
    opB += opA;
    TS_ASSERT_EQUALS(opB, Size(7, 10));
    opA -= Size(1,1);
    TS_ASSERT_EQUALS(opA, Size(1, 2));
    opB -= opB;
    TS_ASSERT_EQUALS(opB, Size(0, 0));
    Size opC(5,-3);
    opC *= 3.0;
    TS_ASSERT_EQUALS(opC, Size(15, -9));

  }

  void testFriendOperators() {
    Size opA(2, 3);
    Size opAcp(2, 3);
    Size opB(5, 7);

    // Comparison
    TS_ASSERT_DIFFERS(opA, opB);
    TS_ASSERT_EQUALS(opA, opA);
    TS_ASSERT_EQUALS(opA, opAcp);
    TS_ASSERT_EQUALS(opB, opB);
    TS_ASSERT(opA != opB);

    // Addition
    Size resAdd = opA + opB;
    Size resAddExp(7, 10);
    TS_ASSERT_EQUALS(resAdd, resAddExp);

    // Substraction
    Size resSub = opA - opB;
    Size resSubExp(-3, -4);
    TS_ASSERT_EQUALS(resSub, resSubExp);

    // Multiplication
    Size resMult = opA * 2.0;
    Size resMultExp(4, 6);
    TS_ASSERT_EQUALS(resMult, resMultExp);
    Size resMult2 = 3.0 * opA;
    Size resMult2Exp(6, 9);
    TS_ASSERT_EQUALS(resMult2, resMult2Exp);

    // Division
    Size resDiv = opB / 2.0;
    Size resDivExp(3, 4);
    TS_ASSERT_EQUALS(resDiv, resDivExp);
  }

  void testTranspose() {
    Size opA(2, 3);
    opA.transpose();
    TS_ASSERT_EQUALS(opA, Size(3,2));
  }

private:
};

#endif
