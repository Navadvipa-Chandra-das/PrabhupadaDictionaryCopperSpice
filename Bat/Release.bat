set BUILD_DIR=D:/CopperSpicePrg/PrabhupadaDictionary/Release/Build

cd %BUILD_DIR%
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Release ^
-DCMAKE_INSTALL_PREFIX="D:/CopperSpicePrg/PrabhupadaDictionary/Release/Bin" ^
-DCMAKE_PREFIX_PATH="D:/CopperSpice/Release/Lib/cmake/CopperSpice" ^
D:/CopperSpicePrg/PrabhupadaDictionary/Source

cd %BUILD_DIR%
ninja -v

cd %BUILD_DIR%
ninja -v install
