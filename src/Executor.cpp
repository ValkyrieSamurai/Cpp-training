#include "Executor.h"

Executor::Executor(int x, int y, char heading) {
    pos = {x, y, heading};
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

Position Executor::Query() const {
    return pos;
}

void Executor::Execute(const string& commands) {
    for (char command: commands) {
        switch (command) {
        case 'M': MoveForward(); break;
        case 'L': TurnLeft(); break;
        case 'R': TurnRight(); break;
        default: break;
        }
    }
}

