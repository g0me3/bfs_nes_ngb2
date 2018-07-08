for f in *.pak; do ./ngb2dec "$f" "${f%.pak}.unp"; done
