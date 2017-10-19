@echo off  
:loop  
    rand.exe > data.in
	std.exe < data.in > std.out
    tree.exe < data.in > data.out
    fc data.out std.out
if not errorlevel 1 goto loop
pause
