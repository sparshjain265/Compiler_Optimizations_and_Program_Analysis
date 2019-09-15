; ModuleID = 'hello.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1

; Function Attrs: nounwind uwtable
define i32 @main() #0 !dbg !4 {
  %1 = alloca i32, align 4
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  store i32 0, i32* %1, align 4
  call void @llvm.dbg.declare(metadata i32* %i, metadata !11, metadata !12), !dbg !13
  call void @llvm.dbg.declare(metadata i32* %j, metadata !14, metadata !12), !dbg !15
  %2 = call i32 (i8*, ...) @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8], [3 x i8]* @.str, i32 0, i32 0), i32* %i), !dbg !16
  %3 = load i32, i32* %i, align 4, !dbg !17
  %4 = icmp sgt i32 %3, 0, !dbg !19
  br i1 %4, label %5, label %8, !dbg !20

; <label>:5                                       ; preds = %0
  %6 = load i32, i32* %i, align 4, !dbg !21
  %7 = add nsw i32 %6, 1, !dbg !23
  store i32 %7, i32* %j, align 4, !dbg !24
  br label %11, !dbg !25

; <label>:8                                       ; preds = %0
  %9 = load i32, i32* %j, align 4, !dbg !26
  %10 = sub nsw i32 %9, 1, !dbg !27
  store i32 %10, i32* %j, align 4, !dbg !28
  br label %11

; <label>:11                                      ; preds = %8, %5
  %12 = load i32, i32* %j, align 4, !dbg !29
  ret i32 %12, !dbg !30
}

; Function Attrs: nounwind readnone
declare void @llvm.dbg.declare(metadata, metadata, metadata) #1

declare i32 @__isoc99_scanf(i8*, ...) #2

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind readnone }
attributes #2 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!8, !9}
!llvm.ident = !{!10}

!0 = distinct !DICompileUnit(language: DW_LANG_C99, file: !1, producer: "clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)", isOptimized: false, runtimeVersion: 0, emissionKind: 1, enums: !2, subprograms: !3)
!1 = !DIFile(filename: "hello.c", directory: "/home/COPA/llvm3.8")
!2 = !{}
!3 = !{!4}
!4 = distinct !DISubprogram(name: "main", scope: !1, file: !1, line: 2, type: !5, isLocal: false, isDefinition: true, scopeLine: 2, isOptimized: false, variables: !2)
!5 = !DISubroutineType(types: !6)
!6 = !{!7}
!7 = !DIBasicType(name: "int", size: 32, align: 32, encoding: DW_ATE_signed)
!8 = !{i32 2, !"Dwarf Version", i32 4}
!9 = !{i32 2, !"Debug Info Version", i32 3}
!10 = !{!"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"}
!11 = !DILocalVariable(name: "i", scope: !4, file: !1, line: 3, type: !7)
!12 = !DIExpression()
!13 = !DILocation(line: 3, column: 5, scope: !4)
!14 = !DILocalVariable(name: "j", scope: !4, file: !1, line: 3, type: !7)
!15 = !DILocation(line: 3, column: 7, scope: !4)
!16 = !DILocation(line: 4, column: 1, scope: !4)
!17 = !DILocation(line: 6, column: 5, scope: !18)
!18 = distinct !DILexicalBlock(scope: !4, file: !1, line: 6, column: 5)
!19 = !DILocation(line: 6, column: 7, scope: !18)
!20 = !DILocation(line: 6, column: 5, scope: !4)
!21 = !DILocation(line: 6, column: 12, scope: !22)
!22 = !DILexicalBlockFile(scope: !18, file: !1, discriminator: 1)
!23 = !DILocation(line: 6, column: 13, scope: !22)
!24 = !DILocation(line: 6, column: 11, scope: !22)
!25 = !DILocation(line: 6, column: 10, scope: !22)
!26 = !DILocation(line: 7, column: 8, scope: !18)
!27 = !DILocation(line: 7, column: 9, scope: !18)
!28 = !DILocation(line: 7, column: 7, scope: !18)
!29 = !DILocation(line: 8, column: 8, scope: !4)
!30 = !DILocation(line: 8, column: 1, scope: !4)
