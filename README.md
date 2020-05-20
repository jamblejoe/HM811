# HM811 projects

## C
Big project. Contains rudimentary linear algebra functionality, which lets users avoid pointers and dealing with memory ordering of matrices. On top of that we implement an inplace version of the LR (LU) decomposition. A test program can be compiled with `make` as `make lr` and run with `./lr` (`./lr.exe` on Windows).  

## Julia
Big project. Jupyter notebook showing how to calculate Lyapunov exponents. In the first part of the notebook is a first order explicit ODE solver (Euler method) implemented to solve the Lorenz system, a toy model for classical chaos, and functions to calculate Lyapunov exponent timeseries. In the second part, the Julia ecosystem is used to replace the simple ODE solver and to symbolically Jacobians. The notebook contains a lot of comments on Julia code and the process of calculating Lyapunov exponents. It should be understandable for readers with a little mathematical background and some knowledge of e.g. python or matlab.


## Perl
Small project. This is a simple perl program which reads on a Linux machine from the file /proc/stat the current cpu usage and prints it to the console. It can be run by simply typing `perl cpu.pl`.
