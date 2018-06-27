for %%f in (*.unp) do ngb2enc %%f %%~nf.pak
for %%f in (*.pak) do copy /b %%f ..\tlm\%%f
del *.pak
