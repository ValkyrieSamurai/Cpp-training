#pragma once
#include <string>
#include <memory>
using namespace std;

struct Position {
    int x;
    int y;
    char heading;
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y && heading == other.heading;
    }
};

class Executor
{
private:
    Position pos{};
    bool isAccelerated;
public:
    Executor(int x = 0, int y = 0, char heading = 'N', bool isAccelerated = false); //带默认参数的构造函数
    ~Executor();

    void MoveForward(); //前进
    void TurnLeft(); //左转
    void TurnRight(); //右转
    void Accelerate(); //切换加速/正常状态

    Position GetPosition() const; //获取位置和朝向
    bool GetAccelerated() const; //获取加速状态

    void Execute(const string& commands); //批量执行命令
};

//ICommand虚基类
class ICommand : public Executor
{
public:
    virtual void Operate (Executor& executor) = 0;
    virtual ~ICommand() = default;
};

//MoveCommand子类
class MoveCommand : public ICommand
{
public:
    void Operate(Executor& executor) override;
};

//TurnLeftCommand子类
class TurnLeftCommand : public ICommand
{
public:
    void Operate(Executor& executor) override;
};

//TurnRightCommand子类
class TurnRightCommand : public ICommand
{
public:
    void Operate(Executor& executor) override;
};

//FastCommand子类
class FastCommand : public ICommand
{
public:
    void Operate(Executor& executor) override;
};