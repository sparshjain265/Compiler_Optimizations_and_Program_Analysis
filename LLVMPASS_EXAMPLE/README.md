#Writing an LLVM Pass

1) Create a folder in $LLVMSRC/lib/Transforms/passname and move to that folder. Example pass disccused has name "itrinstBB"

		mkdir $LLVMSRC/lib/Transforms/itrinstBB
		cd $LLVMSRC/lib/Transforms/itrinstBB


2) Write your code in passname.cpp 


3) Create CMakeLists.txt 


		if( NOT LLVM_REQUIRES_RTTI )
  	     	if( NOT LLVM_REQUIRES_EH )
		set(LLVM_EXPORTED_SYMBOL_FILE ${CMAKE_CURRENT_SOURCE_DIR}/itrBB.exports)
	       endif()
		endif()

		if(WIN32 OR CYGWIN)
		  set(LLVM_LINK_COMPONENTS Core Support)
		endif()

		add_llvm_loadable_module( LLVMitrinstBB
		  itrinstBB.cpp

		  DEPENDS
		  intrinsics_gen
		  )


4)  Create an empty file  passname.exports



		touch itrBB.exports


5)  move to folder one level up (i.e to $LLVMSRC/lib/Transforms) and add passname directory to CMakeLists.txt.

 
               cd ..
               echo "add_subdirectory(itrinstBB)" >> CMakeLists.txt


6) move to build folder and do a make


		cd  $BUILDROOT
                make

#Notes

An eight minute video in the url will be helpful, if some issues come (https://www.youtube.com/watch?v=5DuT9E2cnjM)
