#include "Executor.h"

Executor::Executor(int x, int y, char heading, bool isAccelerated) {
    this->pos = {x, y, heading};
    this->isAccelerated = isAccelerated;
}

Executor::~Executor() = default;

void Executor::MoveForward() {
    switch (pos.heading) {
    case 'N': pos.y++; break;
    case 'S': pos.y--; break;
    case 'W': pos.x--; break;
    case 'E': pos.x++; break;
    default: break;
    }
}

void Executor::TurnLeft() {
    switch (pos.heading) {
    case 'N': pos.heading = 'W'; break;
    case 'S': pos.heading = 'E'; break;
    case 'W': pos.heading = 'S'; break;
    case 'E': pos.heading = 'N'; break;
    default: break;
    }
}

void Executor::TurnRight() {
    switch (pos.heading) {
    case 'N': pos.heading = 'E'; break;
    case 'S': pos.heading = 'W'; break;
    case 'W': pos.heading = 'N'; break;
    case 'E': pos.heading = 'S'; break;
    default: break;
    }
}

void Executor::Accelerate() {
    isAccelerated = !isAccelerated;
}

Position Executor::GetPosition() const {
    return pos;
}

bool Executor::GetAccelerated() const {
    return isAccelerated;
}


void Executor::Execute(const string& commands) {
    for (auto cmd: commands) {
        //根据不同指令切换至对应子类的Operate操作
        switch (cmd) {
        case 'M': make_shared<MoveCommand>()->Operate(*this); break;
        case 'L': make_shared<TurnLeftCommand>()->Operate(*this); break;
        case 'R': make_shared<TurnRightCommand>()->Operate(*this); break;
        case 'F': make_shared<FastCommand>()->Operate(*this); break;
        default: break;
        }
    }
}

//在子类中实现基类的虚函数
void MoveCommand::Operate(Executor& executor) {
    if (executor.GetAccelerated()) {
        executor.MoveForward();
        executor.MoveForward();
    }
    else {
        executor.MoveForward();
    }
}

void TurnLeftCommand::Operate(Executor& executor) {
    if (executor.GetAccelerated()) {
        executor.MoveForward();
        executor.TurnLeft();
    }
    else {
        executor.TurnLeft();
    }
}

void TurnRightCommand::Operate(Executor& executor) {
    if (executor.GetAccelerated()) {
        executor.MoveForward();
        executor.TurnRight();
    }
    else {
        executor.TurnRight();
    }
}

void FastCommand::Operate(Executor& executor) {
    executor.Accelerate();
}