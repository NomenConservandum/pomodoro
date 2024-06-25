# pomodoro + random short breaks
Pomodoro with 25 minutes long sessions. During a session at random there appear short 10 seconds breaks.
It also uses sounds to indicate a beginning or an end of short / long breaks and sessions
## installation
> [!NOTE]
> There probably will be releases available, but here's the manual on installation.
### Linux
Open your terminal with **Ctrl+Alt+t** and enter these commands (if necessary):
> sudo apt install sox

> sudo apt install libsox-fmt-all

After that enter these commands:
> git clone https://github.com/NomenConservandum/pomodoro-random-breaks.git Linux

> cd pomodoro-random-breaks/

> g++ pomodoro.cpp -o pomodoro

After that you can use it in the pomodoro-random-breaks folder by typing this command:

> ./pomodoro

### Windows
Bruh I'm so lazy at the moment, just check the releases, you should find one for Windows.
