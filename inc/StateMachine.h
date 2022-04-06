#pragma once
#include <cstddef>
#include <utility>
#include <vector>

struct StateMachine final
{
    StateMachine() = default;

    void add(bool& state)
    {
        fortunes_.push_back(&state);
    }

    void backMain()
    {
        for(size_t i{1}; i < fortunes_.size(); ++i)
            *(fortunes_[i]) = false;
    }

    ~StateMachine() = default;

private:
    std::vector<bool*> fortunes_;
};
