cd nas

echo assemble...

for f in *.nas; do ./dasm $f -f3 -o"${f%.nas}.bin"; done

echo build...

mv hdr.bin !ngb2.hdr
mv chr.bin !ngb2.chr

cat bank0.bin bank1.bin bank2.bin bank3.bin bank4.bin bank5.bin bank6.bin bank7.bin > !ngb2.prg
cat !ngb2.hdr !ngb2.prg !ngb2.chr > ../!ngb2.nes

echo cleanup...

rm *.bin
rm !ngb2.hdr !ngb2.prg !ngb2.chr

cp !ngb2.nes ../!ngb2.nes

echo done.
