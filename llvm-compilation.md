#Steps

1 Install clang using apt-get

    sudo apt-get install clang
        
2 Download llvm source code
 
     http://releases.llvm.org/3.8.0/llvm-3.8.0.src.tar.xz
    
3 Extract llvm source code in $HOME folder
      
         cp llvm-3.8.0.src.tar.xz $HOME
         cd $HOME
         tar -xvf llvm-3.8.0.src.tar.xz 
     
3  Make a folder $HOME/llvm3.8

    mkdir $HOME/llvm3.8
    
4  change directory

    cd $HOME/llvm3.8
    
5   configure llvm 

    cmake $HOME/llvm-3.8.0.src

6   install llvm. This will take  around one hour (lesser/greater than one hour based on your laptop)

    cmake --build .
    
7  Write a sample C program name hello.c and do the steps below ( your still in $HOME/llvm3.8 folder)

        
        clang -O3 -emit-llvm hello.c -c -o hello.bc
        ./bin/opt  -load ./lib/LLVMHello.so -hello ./hello.bc
        ./bin/opt  -load ./lib/LLVMHello.so -hello ./hello.bc
        
8 The source code of the LLVM pass Hello is available at 

        $HOME/llvm-3.8.0.src/lib/Transforms/Hello/Hello.cpp
        

#Note
Steps are taken from https://llvm.org/docs/CMake.html