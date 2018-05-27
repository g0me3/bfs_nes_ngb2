@echo off

:again

cd nas

echo assemble...

rem dasm bank0.nas -f3 -l!ngb.lst -obank0.bin >> !err.log

for %%f in (*.nas) do call :dodasm %%f > NUL

goto :build

:dodasm
dasm %1 -f3 -o%~n1.bin
goto :eof

:build
echo build...

rename hdr.bin !ngb.hdr > NUL
rename chr.bin !ngb.chr > NUL

copy /b bank0.bin+bank1.bin+bank2.bin+bank3.bin+bank4.bin+bank5.bin+bank6.bin+bank7.bin !ngb.prg > NUL

nesimage j !ngb > NUL

echo cleanup...
for %%f in (*.bin) do del %%f
del !ngb.prg
del !ngb.hdr
del !ngb.chr

copy /b !ngb.nes ..\!ngb.nes > NUL
cd ..

echo done.
