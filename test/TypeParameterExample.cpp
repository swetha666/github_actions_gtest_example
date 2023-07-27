
#include "gtest/gtest.h"
using testing::Types;
class ITempSensor
{
    public:
    virtual int getoutsideTemp()=0;
};
class ModelATempSensor:public ITempSensor
{
    public:
    int getoutsideTemp(){return 23;}
};
class ModelBTempSensor:public ITempSensor
{
    public:
    int getoutsideTemp(){return 23;}
};
class AutoTempRegulator
{
    ITempSensor* tempSensorPtr;
    public:
    AutoTempRegulator(ITempSensor* address):tempSensorPtr{address}{}
    void regulateTemp()
    {
        this ->tempSensorPtr->getoutsideTemp();
    }
};
template <typename T>
ITempSensor* createObject();
template <>
ITempSensor* createObject<ModelATempSensor>() { return new ModelATempSensor(); }
template <>
ITempSensor* createObject<ModelBTempSensor>() { return new ModelBTempSensor(); }

template <typename T>

class TempSensorFixture:public testing::Test
{
    protected:
    TempSensorFixture():objUnderTest{ createObject<T>()}{}
    //Arrange
    ITempSensor* objUnderTest;
};
typedef Types<ModelATempSensor,ModelBTempSensor> Implementations;
TYPED_TEST_SUITE(TempSensorFixture, Implementations);
TYPED_TEST(TempSensorFixture,GetTempTest)
{
    ASSERT_EQ(this->objUnderTest->getoutsideTemp(),23);
}

class FakeTempSensor:public ITempSensor
{
    public:
     public:
    int getOutSideTemp(){return 0;}
};
TEST(AutoTempRegulatorTestSuite,RegulateTempTest)
{
    FakeTempSensor stub;
    AutoTempRegulator codeUnderTest(&stub);
    codeUnderTest.regulateTemp();
}