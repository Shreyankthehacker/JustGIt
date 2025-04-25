g++ -o sorting main.cpp sorting.cpp
./sorting

g++ -pg -o sorting main.cpp sorting.cpp
./sorting
gprof sorting gmon.out > profiling_report.txt
