@echo off

start "" "..\..\..\tools\TextPad\TextPad.exe" ram.inc macroses.inc bank7.inc bank6.inc bank5.inc bank4.inc bank3.inc bank2.inc bank1.inc bank0.inc

pause 0

:again

del !ngbprev.nes
rename !ngb.nes !ngbprev.nes

cd nas

echo assemble...

dasm bank0.nas -f3 -obank0.bin
dasm bank0.nas -f3 -l!ngb.lst -obank0.bin > !err.log

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
del !ngb.chr
del !ngb.hdr

copy /b !ngb.nes ..\!ngb.nes > NUL

del !ngb.nes

cd ..

echo ===OLD ROM===
if exist !ngbprev.nes nas\m3checksum !ngbprev.nes
echo ===NEW ROM===
if exist !ngb.nes nas\m3checksum !ngb.nes

echo done.
pause 0

goto :again

:eof
