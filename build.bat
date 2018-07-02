@echo off

:again

cd nas

echo assemble...

rem dasm bank0.nas -f3 -l!ngb2.lst -obank0.bin >> !err.log

for %%f in (*.nas) do call :dodasm %%f > NUL

goto :build

:dodasm
dasm %1 -f3 -o%~n1.bin
goto :eof

:build
echo build...

rename hdr.bin !ngb2.hdr > NUL
rename chr.bin !ngb2.chr > NUL

copy /b bank0.bin+bank1.bin+bank2.bin+bank3.bin+bank4.bin+bank5.bin+bank6.bin+bank7.bin !ngb2.prg > NUL

nesimage j !ngb2 > NUL

echo cleanup...
for %%f in (*.bin) do del %%f
del !ngb2.prg
del !ngb2.hdr
del !ngb2.chr

copy /b !ngb2.nes ..\!ngb2.nes > NUL
cd ..

echo done.
