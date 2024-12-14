
#ifndef COMMAND_H
#define COMMAND_H

#pragma once
#include "PoseHandler.h"

//ICommand虚基类
class ICommand
{
public:
    virtual void Operate (PoseHandler& poseHandler) const noexcept = 0;
    virtual ~ICommand() = default;
};

//MoveCommand子类
class MoveCommand : public ICommand
{
public:
    void Operate(PoseHandler& poseHandler) const noexcept override{
        if (poseHandler.GetAccelerated()) {
            poseHandler.MoveForward();
        }
        poseHandler.MoveForward();
    }
};

//TurnLeftCommand子类
class TurnLeftCommand : public ICommand
{
public:
    void Operate(PoseHandler& poseHandler) const noexcept override{
        if (poseHandler.GetAccelerated()) {
            poseHandler.MoveForward();
        }
        poseHandler.TurnLeft();
    }
};

//TurnRightCommand子类
class TurnRightCommand : public ICommand
{
public:
    void Operate(PoseHandler& poseHandler) const noexcept override{
        if (poseHandler.GetAccelerated()) {
            poseHandler.MoveForward();
        }
        poseHandler.TurnRight();
    }
};

//FastCommand子类
class FastCommand : public ICommand
{
public:
    void Operate(PoseHandler& poseHandler) const noexcept override{
        poseHandler.Accelerate();
    }
};

#endif // COMMAND_H