@ECHO OFF
mkdir VSbuild
cd VSbuild
cmake -G "Visual Studio 17 2022" -A x64 ..
PAUSE