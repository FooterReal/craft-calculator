cmake --no-warn-unused-cli -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE -DCMAKE_BUILD_TYPE:STRING=Release -S %~dp0/src -B %~dp0/build -G "Unix Makefiles"
cmake ./src --fresh -G "Unix Makefiles"
make