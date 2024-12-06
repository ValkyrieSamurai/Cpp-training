#include <gtest/gtest.h>

#include "Executor.h"

TEST(ExecutorTest, initialize_default_parameters)
{
    Executor executor;
    Position target = {0,0,'N'};
    ASSERT_EQ(target, executor.GetPosition());
    ASSERT_EQ(false, executor.GetAccelerated());
}

TEST(ExecutorTest, initialize_parameters_that_are_passed_in)
{
    Executor executor(1, 2, 'S', true);
    Position target = {1,2,'S'};
    ASSERT_EQ(target, executor.GetPosition());
    ASSERT_EQ(true, executor.GetAccelerated());
}

TEST(ExecutorTest, check_MoveForwrd)
{
    Executor executor(1, 1, 'E');
    executor.Execute("MMM");
    Position target = {4,1,'E'};
    ASSERT_EQ(target, executor.GetPosition());
}

TEST(ExecutorTest, check_TurnLeft_and_TurnRight)
{
    Executor executor(-2, 1, 'W');
    executor.Execute("MRMRMLMLM");
    Position target = {-3,3,'W'};
    ASSERT_EQ(target, executor.GetPosition());
}

TEST(ExecutorTest, check_Accelerate)
{
    Executor executor;
    executor.Execute("MFMFM");
    Position target = {0,4,'N'};
    ASSERT_EQ(target, executor.GetPosition());
    ASSERT_EQ(false, executor.GetAccelerated());
}

TEST(ExecutorTest, check_continuous_operations)
{
    string commands;
    string loop = "MRMLFRLF";
    for (int i = 1; i <=500; i++) {
        commands += loop;
    }
    Executor executor;
    executor.Execute(commands);
    Position target = {1000,1000,'N'};
    ASSERT_EQ(target, executor.GetPosition());
    ASSERT_EQ(false, executor.GetAccelerated());
}