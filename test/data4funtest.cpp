#include <gmock/gmock.h>

#include <iostream>

using namespace testing;
using namespace std;

namespace
{

class TestFixture : public Test
{
public:
    string test;
};

TEST_F(TestFixture, PassByDefault)
{
    EXPECT_TRUE(test.empty());
}

}