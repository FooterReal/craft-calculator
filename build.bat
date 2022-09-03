RMDIR /Q /S ".\build"
cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Release -S %~dp0 -B %~dp0/build -G "Unix Makefiles"
cmake . --fresh -G "Unix Makefiles"
make