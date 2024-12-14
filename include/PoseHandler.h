
#ifndef POSEHANDLER_H
#define POSEHANDLER_H

#pragma once

struct Pose {
    int x;
    int y;
    char heading;
    bool operator==(const Pose& other) const {
        return x == other.x && y == other.y && heading == other.heading;
    }
};

class PoseHandler
{
public:
    PoseHandler(const Pose& pose) noexcept; //给定参数的构造函数
    PoseHandler() noexcept; //默认参数的构造函数
    PoseHandler(const PoseHandler&) = delete;
    PoseHandler& operator=(const PoseHandler&) = delete;

    void MoveForward() noexcept; //前进
    void TurnLeft() noexcept; //左转
    void TurnRight() noexcept; //右转
    void Accelerate() noexcept; //切换加速/正常状态

    bool GetAccelerated() const noexcept; //获取加速状态
    Pose GetPosition() const noexcept; //获取位置和朝向

private:
    Pose pose{0, 0, 'N'}; //默认初始位置和朝向
    bool isAccelerated{false}; //默认非加速状态
};

#endif // POSEHANDLER_H

