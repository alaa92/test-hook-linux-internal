if [ ! -d build ]; then
    mkdir build
fi

clang++ -g -m32 target.cpp -o build/target -ldl
clang++ -m32 -shared -fPIC inject.cpp mem/mem.cpp -o build/libinject.so
