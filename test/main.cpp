#include "pthread.h"
#include "gtest/gtest.h"
#include "data_In.h"
#include "positive_negative.h"


int main(int argc, char **argv){

::testing::InitGoogleTest(&argc,argv);
    
    return RUN_ALL_TESTS();
}
