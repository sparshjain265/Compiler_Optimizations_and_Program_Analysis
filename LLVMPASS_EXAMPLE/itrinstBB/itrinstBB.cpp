//===- Hello.cpp - Example code from "Writing an LLVM Pass" ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements two versions of the LLVM "Hello World" pass described
// in docs/WritingAnLLVMPass.html
//
//===----------------------------------------------------------------------===//

#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

//#define DEBUG_TYPE "hello"

//STATISTIC(HelloCounter, "Counts number of functions greeted");

namespace {
  // Hello - The first implementation, without getAnalysisUsage.
  struct itrinstBB : public FunctionPass {
   static char ID;
    itrinstBB() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      errs() << "COPA: Hello: ";
      errs().write_escaped(F.getName()) << '\n';
      for(Function::iterator bb=F.begin();bb!=F.end(); bb++){
        errs()<< "BasicBlock name = " << bb->getName()<<"\n";
       errs() << "BasicBlok size = " << bb->size()<<"\n";
      for(BasicBlock::iterator i=bb->begin(); i!=bb->end();i++){
     errs()<< " \n" << bb->getName()<< " inst: " <<*i;
     errs()<< " instopcode: " <<i->getOpcode() <<"\n";
     errs()<< " instopcodename: " <<i->getOpcodeName() <<"\n";
     errs()<< " istbinaryop: " <<i->isBinaryOp() <<"\n";
     errs()<< " isCommutative: " <<i->isCommutative() <<"\n";
     errs()<< " Operands: One=" <<(i->getOperand(0))->hasName()<< "\n";
      }
      errs()<<"\n";
      }  
    return false;
    }
};

}
char itrinstBB::ID = 0;
static RegisterPass<itrinstBB> X("itrinstbb", "iterateinstBB Pass");
