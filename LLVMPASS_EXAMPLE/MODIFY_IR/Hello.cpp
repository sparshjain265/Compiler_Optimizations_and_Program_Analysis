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
#include "llvm/IR/InstrTypes.h"

using namespace llvm;

#define DEBUG_TYPE "hello"
//
STATISTIC(HelloCounter, "Counts number of functions greeted");

namespace {
  // Hello - The first implementation, without getAnalysisUsage.
  struct Hello : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    Hello() : FunctionPass(ID) {}

    bool runOnFunction(Function &func) override {
llvm::LLVMContext &context = func.getContext();
for (Function::iterator B = func.begin(); B != func.end(); ++B) {
//BasicBlock* Blk = B;
int count=0;
for (BasicBlock::iterator I = B->begin(); I != B->end(); ++I){
errs()<<"/*count= "<<++count<<"  */";
//print instruction  
I->print(errs());
errs()<<"\n";
if (I->getOpcode() == Instruction::Add) {
/* Create a new instruction varaible with name newinst_sub
newinst_sub operation (opcode)= Substraction (Instruction::Sub)
newinst_sub operand(0) and operand (1)  =  I->operand(0) and I->Operand (1), of the variable  I of type Instruction (BasicBlock::iterator to be precise). 
*/

Instruction *newinst_sub=BinaryOperator::Create(Instruction::Sub,I->getOperand(0),I->getOperand(1)); 

/* Insert the newinst_sub after BasicBlock::iterator I
The argument to insertAfter is type of Instruction *, so I is typecasted to Instruction * (pointer to Instruction class). 
*/

newinst_sub->insertAfter( (Instruction *)I);

/* Create a Type of Int32 */

Type *t_int32=Type::getInt32Ty(context);

/* Create three constant int variables newvalue1,newvalue2 and newalue3 of Int32 type (variable t_int32) created in previous step with numeric-values 1500, 2500 and  3500 respectively  */
 
  Value *newvalue1 = ConstantInt::get(t_int32, 1500); 
   Value *newvalue2 = ConstantInt::get(t_int32, 2500);
   Value *newvalue3 = ConstantInt::get(t_int32, 3500);

/* Create a new instruction varaible with name newinst_mul
newinst_mul operation (opcode)= Multiplication(Instruction::Mul)
newinst_mul operand(0) and operand(1) are newvalue1 and newvalue2 respectively.
Insert instruction after newinst_sub. 
*/

Instruction *newinst_mul=BinaryOperator::Create(Instruction::Mul,newvalue1,newvalue2);
newinst_mul->insertAfter ( newinst_sub); 

   /* replace operand of I with newvalue3 and print I*/

   I->setOperand(0, newvalue3);
errs()<<"\n Modified first operand of add instruction "<<count << "\n\n";
I->print(errs());

/* The two new instructions added will be printer in next iterations (cnt+1 and cnt+2).
Print the Instruction */
errs()<<"\n\n Next two instructions at: count= " << count+1 << " and count= "<< count+2 << " are the added sub and mul instructions respectively\n\n";

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
