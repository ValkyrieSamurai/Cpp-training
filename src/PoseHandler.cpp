#include "PoseHandler.h"

PoseHandler::PoseHandler(const Pose &pose) noexcept : pose(pose) {}

PoseHandler::PoseHandler() noexcept = default;

void PoseHandler::MoveForward() noexcept {
    switch (pose.heading) {
    case 'N': pose.y++; break;
    case 'S': pose.y--; break;
    case 'W': pose.x--; break;
    case 'E': pose.x++; break;
    default: break;
    }
}

void PoseHandler::TurnLeft() noexcept {
    switch (pose.heading) {
    case 'N': pose.heading = 'W'; break;
    case 'S': pose.heading = 'E'; break;
    case 'W': pose.heading = 'S'; break;
    case 'E': pose.heading = 'N'; break;
    default: break;
    }
}

void PoseHandler::TurnRight() noexcept {
    switch (pose.heading) {
    case 'N': pose.heading = 'E'; break;
    case 'S': pose.heading = 'W'; break;
    case 'W': pose.heading = 'N'; break;
    case 'E': pose.heading = 'S'; break;
    default: break;
    }
}

void PoseHandler::Accelerate() noexcept {
    isAccelerated = !isAccelerated;
}

Pose PoseHandler::GetPosition() const noexcept {
    return pose;
}

bool PoseHandler::GetAccelerated() const noexcept {
    return isAccelerated;
}

