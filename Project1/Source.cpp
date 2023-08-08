#include <iostream>
#include <chrono>

class Timer {
public:
    //初始化計時器的內部變數
    Timer() : isRunning(false), totalDuration(0), pauseDuration(0) {}

    //開始計時
    void start() {
        if (!isRunning) {
            isRunning = true;
            startTime = std::chrono::high_resolution_clock::now();//紀錄開始時間
            std::cout << "Timer started." << std::endl;
        }
    }

    //暫停計時
    void pause() {
        if (isRunning) {
            pauseTime = std::chrono::high_resolution_clock::now();//紀錄暫停時間
            isRunning = false;//將計時器標記為暫停
            std::cout << "Timer paused." << std::endl;
        }
    }

    //繼續計時
    void resume() {
        if (!isRunning) {
            auto endTime = std::chrono::high_resolution_clock::now();//紀錄繼續計時的時間
            pauseDuration += std::chrono::duration_cast<std::chrono::milliseconds>(endTime - pauseTime).count();//計算暫停時間並累加到總暫停時間
            isRunning = true;//將計時器標記為運行中
            std::cout << "Timer resumed." << std::endl;
        }
    }

    //完全停止計時
    void stop() {
        if (isRunning) {
            auto endTime = std::chrono::high_resolution_clock::now();//紀錄停止計時的時間
            totalDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() - pauseDuration;//計算總運行時間並扣除暫停時間
            isRunning = false;//將計時器標記為停止
            std::cout << "Timer stopped." << std::endl;
        }
    }

    //顯示經過時間
    void display() const {
        if (isRunning) {
            auto currentTime = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count() - pauseDuration;// 計算經過的時間並扣除暫停時間
            std::cout << "Elapsed time: " << elapsed << " seconds" << std::endl;
        }
        else {
            std::cout << "Total duration: " << totalDuration / 1000 << " seconds" << std::endl;//顯示總運行時間
        }
    }

private:
    bool isRunning;//標記計時器是否運行中
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;//計時器開始時間點
    std::chrono::time_point<std::chrono::high_resolution_clock> pauseTime;//計時器暫停時間點
    float totalDuration;//計時器的總運行時間
    float pauseDuration;//計時器的總暫停時間
};

int main() {
    Timer timer;

    std::cout << "press enter to start" << std::endl;
    if (std::cin.get()) {
        system("cls"); //清除螢幕
        timer.start();
    }
    std::cout << "press enter to pause" << std::endl;
    if (std::cin.get()) {
        system("cls");
        timer.pause();
    }

    std::cout << "press enter to resume" << std::endl;
    if (std::cin.get()) {
        system("cls");
        timer.resume();
    }
    std::cout << "press enter to stop" << std::endl;
    if (std::cin.get()) {
        system("cls");
        timer.stop();
    }
    timer.display();


    return 0;
}