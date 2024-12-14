#pragma once
#include <memory>
#include <string>

#include "PoseHandler.h"

using namespace std;

class Executor
{
private:
    PoseHandler poseHandler;
public:
    Executor(const Pose& pose) noexcept; //给定参数的构造函数
    Executor() noexcept; //默认参数的构造函数
    ~Executor(); //析构函数

    Pose GetPosition() const noexcept; //获取位置和朝向
    bool GetAccelerated() const noexcept; //获取加速状态

    void Execute(const string& commands) noexcept; //批量执行命令
};

