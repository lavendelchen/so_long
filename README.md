![so_long_demo](https://42born2code.slack.com/files/U024VBK6JMU/F05HGM4EL8Z/screen_recording_2023-07-14_at_5.06.22_pm.mov)

### COMPILATION ON WSL
for compilation to work on WSL, you're going to have to initiate XMING following the 
"Compilation on Linux" and "Getting a screen on WSL" sections on this website: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

now, you're gonna have to routinely do two things:
* at every new start of your computer, launch XLaunch and follow the steps for it again.
* for every new terminal, you're going to have to type this: <br>
`export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0` <br>
into the command line before compiling. 
you can make an alias in `.bashrc` to make it easier, unfortunately i couldn't get it to work yet
by just adding a rule in the Makefile.
