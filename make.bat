@echo off

start "" "..\..\..\tools\TextPad\TextPad.exe" ram.inc macroses.inc bank7.inc bank6.inc bank5.inc bank4.inc bank3.inc bank2.inc bank1.inc bank0.inc

pause 0

:again

del !ngb2prev.nes
rename !ngb2.nes !ngb2prev.nes

cd nas

dasm bank0.nas -f3 -obank0.bin

echo log/lst generate...
dasm bank0.nas -f3 -l!ngb2.lst -obank0.bin > !err.log

echo assemble...
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
del !ngb2.chr
del !ngb2.hdr

copy /b !ngb2.nes ..\!ngb2.nes > NUL

del !ngb2.nes

cd ..

echo ===OLD ROM===
if exist !ngb2prev.nes nas\m3checksum !ngb2prev.nes
echo ===NEW ROM===
if exist !ngb2.nes nas\m3checksum !ngb2.nes

echo done.
pause 0

goto :again

:eof
