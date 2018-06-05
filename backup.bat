mkdir .\backup\current
mkdir .\backup\current\nas
mkdir .\backup\current\chr
mkdir .\backup\current\docs
mkdir .\backup\current\tlm
mkdir .\backup\current\mus
mkdir .\backup\current\res
mkdir .\backup\current\res\tools

copy /b *.bat .\backup\current\*.bat
copy /b *.inc .\backup\current\*.inc
copy /b nas\*.exe .\backup\current\nas\*.exe
copy /b nas\*.nas .\backup\current\nas\*.nas
copy /b chr\*.chr .\backup\current\chr\*.chr
copy /b docs\*.txt .\backup\current\docs\*.txt
copy /b tlm\*.* .\backup\current\tlm\*.*
copy /b mus\*.* .\backup\current\mus\*.*
copy /b res\*.* .\backup\current\res\*.*
copy /b res\tools\*.* .\backup\current\res\tools\*.*
copy /b *.txt .\backup\current\*.txt
