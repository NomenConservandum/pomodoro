#include <iostream>
#include <chrono>
#include <thread>
#include <random>

using namespace std;

void normal_break() {
    cout << "Take a break.\n\n";
	system("play -q ~/pomodoro/sounds/buzzer.wav");
    this_thread::sleep_for(chrono::minutes(5));
}

void short_break() {
    cout << "\n\n\nTake a SHORT break (10 seconds).\n";
	system("play -q ~/pomodoro/sounds/buzzer_short_break_start.wav");
    this_thread::sleep_for(chrono::seconds(10));
	cout << "Short break is over.\nBack to the grind.\n";
	system("play -q ~/pomodoro/sounds/buzzer_short_break_stop.wav");
}

int main() {
    int cnt;
    random_device rd;
    uniform_int_distribution<int> dist(100, 240);
    
    cout << "Welcome to Pomodoro (25/5) + random short (10 seconds) breaks timer.\nThis version has a different structure from the previous release.\n";
    cout << "Enter the amount of 25 minute sessions (optimal number is 4): ";
    cin >> cnt;
    
    for (int i = 1; i <= cnt; ++i) {
        cout << "It's time to grind.\n\n";
        system("play -q ~/pomodoro/sounds/buzzer.wav");
        
        int time = 25*60; // a single session's length (in seconds)
        
        for (int i = 0; i < 10 && time > 300; ++i) { // random breaks
            int rest = dist(rd); // time to elapse before a short break (in seconds)
            time -= rest + 10;
            this_thread::sleep_for(chrono::seconds(rest));
            short_break();
        }
        
        this_thread::sleep_for(chrono::seconds(time));
        
        if (i != cnt) normal_break();
    }
    cout << "\n\nCongratulations on the work done!";
    return 0;
}
