RMDIR /Q /S ".\build"
cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Release -DCMAKE_C_COMPILER:FILEPATH=C:\MinGW\bin\gcc.exe -DCMAKE_CXX_COMPILER:FILEPATH=C:\MinGW\bin\g++.exe -Sf:%~p0 -Bf:%~p0/build -G "Unix Makefiles"
cmake . --fresh -G "Unix Makefiles"
make