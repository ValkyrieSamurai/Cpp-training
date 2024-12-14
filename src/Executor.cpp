#include "Executor.h"
#include "Command.h"

Executor::Executor(const Pose& pose) noexcept : poseHandler(pose) {}

Executor::Executor() noexcept : poseHandler() {}

Executor::~Executor() = default;

bool Executor::GetAccelerated() const noexcept {
    return poseHandler.GetAccelerated();
}

Pose Executor::GetPosition() const noexcept {
    return poseHandler.GetPosition();
}

void Executor::Execute(const string& commands) noexcept{
    for (auto cmd: commands) {
        //根据不同指令切换至对应子类的Operate操作
        switch (cmd) {
        case 'M': make_shared<MoveCommand>()->Operate(this->poseHandler); break;
        case 'L': make_shared<TurnLeftCommand>()->Operate(this->poseHandler); break;
        case 'R': make_shared<TurnRightCommand>()->Operate(this->poseHandler); break;
        case 'F': make_shared<FastCommand>()->Operate(this->poseHandler); break;
        default: break;
        }
    }
}
