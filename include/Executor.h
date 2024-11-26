#pragma once
#include <string>
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
public:
    Executor(int x = 0, int y = 0, char heading = 'N');
    ~Executor();
    void MoveForward();
    void TurnLeft();
    void TurnRight();
    Position Query() const;
    void Execute(const string& commands);
};

