#include "gtest/gtest.h"
class C{};
class B
{
    C* ptr;
    public:
    B(C* addressOfobject): ptr{addressOfobject}
    {

    }
};

class A
{
    B* ptr;
    public:
    A(B* addressOfobject): ptr{addressOfobject}
    {

    }
    bool operation()
    {
        return true;
    }
};

class TestFixtureTestSuite:public testing::Test
{
protected:
A* aptr;
B* bptr;
C* cptr;

TestFixtureTestSuite(){
    //Initialization
}
~TestFixtureTestSuite(){
    //Releasing the Resources
}
void SetUp()
{
    //Arrange
    this ->cptr= new C();
    this ->bptr= new B(cptr);
    this ->aptr= new A(bptr);
}
void TearDown()
{
    //delete resources
    delete cptr;
    delete bptr;
    delete aptr;
}
};

TEST_F(TestFixtureTestSuite,OperationTrueTest)
{
    //Act and Assert
    ASSERT_TRUE(aptr->operation());
}
TEST_F(TestFixtureTestSuite,OperationFalseTest)
{
    //Act and Assert
    ASSERT_FALSE(aptr->operation());
}