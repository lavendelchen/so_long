**COMPILATION ON WSL**
for compilation to work on WSL, you're going to have to initiate XMING following the 
"Getting a screen" section on this website: https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

every time that you open vscode newly, you're going to have to type this:
`export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0`
into the command line before compiling and executing. 
you can make an alias to make it easier, but unfortunately i couldn't get it to work
by just adding a rule in the Makefile.