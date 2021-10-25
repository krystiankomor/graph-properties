#include <DataReader.h>
#include "gtest/gtest.h"

class DataReaderFixture : public ::testing::Test {
protected:
    void SetUp() override
    {
        dataReader = new DataReader();
    }

    void TearDown() override
    {
        delete dataReader;
    }

    DataReader * dataReader{};
};

TEST_F(DataReaderFixture, ReadFromFile)
{
    const char * filename = "sample.txt";

    vector<string> data = DataReader::readFile(filename);

    EXPECT_EQ(filename, data[0]);
}