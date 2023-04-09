#pragma once
#include <bits/stdc++.h>

class Timer {
public:
    void start(std::string name);
    void display();

private:
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point curTime;
    std::string name;
};

std::vector<int> readIntArray(std::istream& instream);
void printArray(std::vector<int>& arr);

void Timer::start(std::string name) {
    this->name = name;
    startTime = std::chrono::high_resolution_clock::now();
};

void Timer::display() {
    curTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> dur = curTime - startTime;
    std::cout << name << " Completed in " << dur.count() << "s" << std::endl;
};

std::vector<int> readIntArray(std::istream& instream) {
    int n;
    instream >> n;
    std::vector<int> temp(n);
    for (int i = 0; i < n; i++) instream >> temp[i];
    return temp;
}

void printArray(std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) std::cout << arr[i] << ' ';
    std::cout << std::endl;
}
