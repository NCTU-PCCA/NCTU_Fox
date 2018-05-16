cls
g++ %p%.cpp -Wall -Wextra -Wshadow -std=c++11 -o %p%
if /i "%ERRORLEVEL%" == "0" @for %%i in (%p%_*.txt) do @echo ====== %%i ====== & %p% < %%i