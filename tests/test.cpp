#include <gtest/gtest.h>

#include "Executor.h"

TEST(ExecutorTest, initialize_default_parameters)
{
    Executor example;
    Position target = {0,0,'N'};
    ASSERT_EQ(target, example.Query());
}

TEST(ExecutorTest, initialize_parameters_that_are_passed_in)
{
    Executor example (1, 2, 'S');
    Position target = {1,2,'S'};
    ASSERT_EQ(target, example.Query());
}

TEST(ExecutorTest, check_MoveForwrd)
{
    Executor example(1, 1, 'E');
    example.Execute("MMM");
    Position target = {4,1,'E'};
    ASSERT_EQ(target, example.Query());
}

TEST(ExecutorTest, check_TurnLeft_and_TurnRight)
{
    Executor example(-2, 1, 'W');
    example.Execute("MRMRMLMLM");
    Position target = {-3,3,'W'};
    ASSERT_EQ(target, example.Query());
}