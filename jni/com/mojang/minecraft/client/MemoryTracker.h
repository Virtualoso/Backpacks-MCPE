#pragma once

#include <string>

class MemoryTracker {

public:

    virtual ~MemoryTracker();
    virtual void* getStats() const = 0;

    MemoryTracker(std::string const&, MemoryTracker*);
    void memoryStats();

    static void* root;

};
