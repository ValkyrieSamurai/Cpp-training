#include <gtest/gtest.h>

#include "Executor.h"

TEST(ExecutorTest, initialize_default_parameters)
{
    Executor executor;
    Pose target = {0, 0,'N'};
    ASSERT_EQ(target, executor.GetPosition());
    ASSERT_EQ(false, executor.GetAccelerated());
}

TEST(ExecutorTest, initialize_parameters_that_are_passed_in)
{
    Pose pose = {1, 2, 'S'};
    Executor executor(pose);
    Pose target = {1,2,'S'};
    ASSERT_EQ(target, executor.GetPosition());
    ASSERT_EQ(false, executor.GetAccelerated());
}

TEST(ExecutorTest, check_MoveForwrd)
{
    Pose pose = {1, 1, 'E'};
    Executor executor(pose);
    executor.Execute("MMM");
    Pose target = {4,1,'E'};
    ASSERT_EQ(target, executor.GetPosition());
}

TEST(ExecutorTest, check_TurnLeft_and_TurnRight)
{
    Pose pose = {-2, 1, 'W'};
    Executor executor(pose);
    executor.Execute("MRMRMLMLM");
    Pose target = {-3,3,'W'};
    ASSERT_EQ(target, executor.GetPosition());
}

TEST(ExecutorTest, check_Accelerate)
{
    Executor executor;
    executor.Execute("MFMFM");
    Pose target = {0,4,'N'};
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
    Pose target = {1000,1000,'N'};
    ASSERT_EQ(target, executor.GetPosition());
    ASSERT_EQ(false, executor.GetAccelerated());
}