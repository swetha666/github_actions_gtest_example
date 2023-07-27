#include "gtest/gtest.h"
class C{};
class B
{
    C* ptr;
    public:
    B(C* addressOfobject): ptr{addresOfobject}
    {

    }
};

class A
{
    B* ptr;
    public:
    A(B* addressOfobject): ptr{addresOfobject}
    {

    }
    bool operation()
    {
        return true;
    }
};
TEST(TestFixtureTestSuite,OperationTrueTest)
{
    //Arrange
    C cobj;
    B bobj(&cobj);
    A aobj(&bobj);
    //Act and Assert
    ASSERT_TRUE(obj.operation());
}
TEST(TestFixtureTestSuite,OperationFalseTest)
{
    //Arrange
    C cobj;
    B bobj(&cobj);
    A aobj(&bobj);
    //Act and Assert
    ASSERT_FALSE(obj.operation());
}