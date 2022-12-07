
#include <iostream>
#include <gtest/gtest.h>
#include "message.h"
#include <ctime>
#include "user.h"
#include "server.h"
#include "crypto.h"
#include "stl.h"
#include <map>

int main(int argc, char **argv)
{
    if (false) // make false to run unit-tests
    {
        std::vector a{1,2,4,5,55,124};
        std::string tool =vector_to_string(a,'#');
        std::cout<<tool<<std::endl;
    }
    else
    {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret{RUN_ALL_TESTS()};
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}