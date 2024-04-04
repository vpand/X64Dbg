src = 'E:/VM.CODES/YUNYOO/a64dbg/A64Dbg/unimpl.src.ll'
dst = 'E:/VM.CODES/YUNYOO/a64dbg/A64Dbg/unimpl.ll'
undef = 'undefined symbol: '

with open(src, 'r') as fpsrc:
    with open(dst, 'w') as fpdst:
        fpdst.write('''
; ModuleID = 'unimpl.cpp'
source_filename = "unimpl.cpp"
target datalayout = "e-m:w-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-windows-msvc19.11.0"     

declare dso_local void @abort() #1
   
        ''')
        while True:
            line = fpsrc.readline()
            if (len(line) == 0):
                break
            if line.find(undef) > 0:
                items = line.split(undef)
                fpdst.write('''
; Function Attrs: noinline optnone uwtable
define weak dso_local void @"%s"() #0 {
  call void @abort()
  ret void
}
                ''' % (items[1].rstrip()))
        fpdst.write('''
attributes #0 = { noinline optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="none" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0, !1}
!llvm.ident = !{!2}

!0 = !{i32 1, !"wchar_size", i32 2}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{!"clang version 11.0.0 (git://code.qt.io/clang/llvm-project.git e43a39a3ed2ec0a05638956cdebfd2f7cf164692)"}
        ''')