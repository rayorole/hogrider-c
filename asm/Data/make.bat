@echo off

cd Image
python png2bin.py image.bin
cd ..\Song
python midi2bin.py nyan.mid song.bin

cd ..

type Image\image.bin Song\song.bin Other\message.txt > data.bin
Compressor\compress.exe data.bin compressed.bin