#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <random>

using namespace std;

bool long_break = false;

void working_time() {
    system("color 4F");
    cout << "It's time to grind.\n";
    this_thread::sleep_for(chrono::minutes(25));
    system("color 2F");
    cout << "Take a break.\n";
    PlaySound(TEXT("buzzer.wav"), NULL, SND_FILENAME);
    long_break = true;
}

void random_breaks() {
    random_device rd;
    uniform_int_distribution<int> dist(50, 180);
    for (int i = 0; i < 15 && !long_break; ++i) { // скорее всего не сработает
        int n = dist(rd);
        // cout << "Short break will be in " << n << " second(s)\n";
        this_thread::sleep_for(chrono::seconds(n));
        if (!long_break) {
            system("color 2F");
            cout << "Take a SHORT break (10 seconds).\n";
            PlaySound(TEXT("buzzer_short_break_start.wav"), NULL, SND_FILENAME);
            this_thread::sleep_for(chrono::seconds(10));
            system("color 4F");
            PlaySound(TEXT("buzzer_short_break_stop.wav"), NULL, SND_FILENAME);
        }
    }
}

int main() {
    system("color 2F");
    cout << "Welcome to Pomodoro (25/5) + random short (10 seconds) breaks timer.\n";
    int cnt = 4;
    cout << "Enter the amount of 25 minute sessions (optimal number is 4): ";  cin >> cnt;
    // cout << "Press 'enter' to start\n";
    system("pause");
    PlaySound(TEXT("buzzer.wav"), NULL, SND_FILENAME);
    for (int i = 0; i < cnt; ++i) {
        thread thr1(working_time);
        random_breaks();
        if (i != cnt - 1) {
            this_thread::sleep_for(chrono::minutes(5));
            long_break = false;
            PlaySound(TEXT("buzzer.wav"), NULL, SND_FILENAME);
        }
    }
    cout << "Congratulations on the work done!";
    return 0;
}