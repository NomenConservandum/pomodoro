# pomodoro + random short breaks
Pomodoro with 25 minutes long sessions. During a session at random there appear short 10 seconds breaks.
It also uses sounds to indicate a beginning or an end of short / long breaks and sessions
## installation
> [!NOTE]
> There probably will be releases available, but here's the manual on installation.

### Instruction
Open your terminal with **Ctrl+Alt+t** and enter these commands (if necessary):
> sudo apt install sox

> sudo apt install libsox-fmt-all

After that enter these commands:
> cd ~

> git clone https://github.com/NomenConservandum/pomodoro.git

> cd pomodoro/

> git switch Linux

> g++ pomodoro.cpp -o pomodoro

After that you can use it in the 'pomodoro' folder by typing this command:

> ./pomodoro

I personally added it to my .zshrc file with alias command like here:
> alias pomodoro="~/pomodoro/./pomodoro"

So whenever I'm typing 'pomodoro' in terminal the program opens up. You can do the same if you are using zsh.
