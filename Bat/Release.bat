set BUILD_DIR=D:/CopperSpicePrg/PrabhupadaDictionaryOld/Release/Build

cd %BUILD_DIR%
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Release ^
-DCMAKE_INSTALL_PREFIX="D:/CopperSpicePrg/PrabhupadaDictionaryOld/Release/Bin" ^
-DCMAKE_PREFIX_PATH="D:/CopperSpice/Release/Lib/cmake/CopperSpice" ^
D:/CopperSpicePrg/PrabhupadaDictionaryOld/Source

cd %BUILD_DIR%
ninja -v

cd %BUILD_DIR%
ninja -v install
