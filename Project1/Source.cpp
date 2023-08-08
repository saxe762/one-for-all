#include <iostream>
#include <chrono>

class Timer {
public:
    //��l�ƭp�ɾ��������ܼ�
    Timer() : isRunning(false), totalDuration(0), pauseDuration(0) {}

    //�}�l�p��
    void start() {
        if (!isRunning) {
            isRunning = true;
            startTime = std::chrono::high_resolution_clock::now();//�����}�l�ɶ�
            std::cout << "Timer started." << std::endl;
        }
    }

    //�Ȱ��p��
    void pause() {
        if (isRunning) {
            pauseTime = std::chrono::high_resolution_clock::now();//�����Ȱ��ɶ�
            isRunning = false;//�N�p�ɾ��аO���Ȱ�
            std::cout << "Timer paused." << std::endl;
        }
    }

    //�~��p��
    void resume() {
        if (!isRunning) {
            auto endTime = std::chrono::high_resolution_clock::now();//�����~��p�ɪ��ɶ�
            pauseDuration += std::chrono::duration_cast<std::chrono::milliseconds>(endTime - pauseTime).count();//�p��Ȱ��ɶ��ò֥[���`�Ȱ��ɶ�
            isRunning = true;//�N�p�ɾ��аO���B�椤
            std::cout << "Timer resumed." << std::endl;
        }
    }

    //��������p��
    void stop() {
        if (isRunning) {
            auto endTime = std::chrono::high_resolution_clock::now();//��������p�ɪ��ɶ�
            totalDuration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() - pauseDuration;//�p���`�B��ɶ��æ����Ȱ��ɶ�
            isRunning = false;//�N�p�ɾ��аO������
            std::cout << "Timer stopped." << std::endl;
        }
    }

    //��ܸg�L�ɶ�
    void display() const {
        if (isRunning) {
            auto currentTime = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - startTime).count() - pauseDuration;// �p��g�L���ɶ��æ����Ȱ��ɶ�
            std::cout << "Elapsed time: " << elapsed << " seconds" << std::endl;
        }
        else {
            std::cout << "Total duration: " << totalDuration / 1000 << " seconds" << std::endl;//����`�B��ɶ�
        }
    }

private:
    bool isRunning;//�аO�p�ɾ��O�_�B�椤
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;//�p�ɾ��}�l�ɶ��I
    std::chrono::time_point<std::chrono::high_resolution_clock> pauseTime;//�p�ɾ��Ȱ��ɶ��I
    float totalDuration;//�p�ɾ����`�B��ɶ�
    float pauseDuration;//�p�ɾ����`�Ȱ��ɶ�
};

int main() {
    Timer timer;

    std::cout << "press enter to start" << std::endl;
    if (std::cin.get()) {
        system("cls"); //�M���ù�
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