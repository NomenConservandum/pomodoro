#include <iostream>
#include <chrono>
#include <thread>
#include <random>

using namespace std;

bool long_break = false;

void working_time() {
    cout << "It's time to grind.\n\n";
    this_thread::sleep_for(chrono::minutes(25));
    cout << "Take a break.\n\n";
    system("play -q ./sounds/buzzer.wav");
    long_break = true;
}

void random_breaks() {
    random_device rd;
    uniform_int_distribution<int> dist(50, 180);
    for (int i = 0; i < 15 && !long_break; ++i) {
        int n = dist(rd);
        this_thread::sleep_for(chrono::seconds(n));
        if (!long_break) {
            cout << "\n\n\nTake a SHORT break (10 seconds).\n";
	    system("play -q ./sounds/buzzer_short_break_start.wav");
            this_thread::sleep_for(chrono::seconds(10));
	    system("play -q ./sounds/buzzer_short_break_stop.wav");
	    cout << "Short break is over.\nBack to the grind.\n";
	}
    }
}

int main() {
    cout << "Welcome to Pomodoro (25/5) + random short (10 seconds) breaks timer.\n";
    int cnt = 4;
    cout << "Enter the amount of 25 minute sessions (optimal number is 4): ";  cin >> cnt;
    cout << endl;
    system("play -q ./sounds/buzzer.wav");
    for (int i = 0; i < cnt; ++i) {
        thread thr1(working_time);
        random_breaks();
        if (i != cnt - 1) {
            this_thread::sleep_for(chrono::minutes(5));
            long_break = false;
	    system("play -q ./sounds/buzzer.wav");
        }
    }
    cout << "Congratulations on the work done!";
    return 0;
}
