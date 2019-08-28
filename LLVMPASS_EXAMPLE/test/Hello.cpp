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
#include "llvm/IR/Constants.h"


using namespace llvm;

#define DEBUG_TYPE "hello"

STATISTIC(HelloCounter, "Counts number of functions greeted");

namespace {
  // Hello - The first implementation, without getAnalysisUsage.
  struct Hello : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    Hello() : FunctionPass(ID) {}

    bool runOnFunction(Function &func) override {
for (Function::iterator B = func.begin(); B != func.end(); ++B) {
//BasicBlock* Blk = B;
for (BasicBlock::iterator I = B->begin(); I != B->end(); ++I){
I->print(errs());
errs()<<"\n";
if (I->getOpcode() == Instruction::Add) {
errs()<<"ADD statement\n";
   /* read the first operand of instruction */
   Value *oldvalue = I->getOperand(0);
errs()<< oldvalue->getName();

   /* construct new constant; here 0x1234 is used as value */
   Value *newvalue = ConstantInt::get(oldvalue->getType(), 1500); 

   /* replace operand with new value */
   I->setOperand(0, newvalue);
errs()<< "Set Operand done\n";
I->print(errs());
errs()<<"\n";
}
}
}
      ++HelloCounter;
      errs() << "Hello: ";
      errs().write_escaped(func.getName()) << '\n';
      return false;
    }
  };
}

char Hello::ID = 0;
static RegisterPass<Hello> X("hello", "Hello World Pass");

namespace {
  // Hello2 - The second implementation with getAnalysisUsage implemented.
  struct Hello2 : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    Hello2() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      ++HelloCounter;
      errs() << "Hello: ";
      errs().write_escaped(F.getName()) << '\n';
      return false;
    }

    // We don't modify the program, so we preserve all analyses.
    void getAnalysisUsage(AnalysisUsage &AU) const override {
      AU.setPreservesAll();
    }
  };
}

char Hello2::ID = 0;
static RegisterPass<Hello2>
Y("hello2", "Hello World Pass (with getAnalysisUsage implemented)");
