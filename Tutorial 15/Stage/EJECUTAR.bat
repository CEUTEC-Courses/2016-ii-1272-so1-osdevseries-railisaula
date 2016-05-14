@echo off
echo Recuerde tener cargada la imagen Floppy que se encuentra en esta carpeta!

pause

echo Stage1 Cargando...

nasm -f bin Boot1.asm -o Boot1.bin
PARTCOPY Boot1.bin 0 3 -f0 0 
PARTCOPY Boot1.bin 3E 1C2 -f0 3E 

pause

echo Stage2 Cargando...

copy KRNLDR.SYS  A:\KRNLDR.SYS

pause

echo copiar KRNL32 A LA FLOPPY Cargando...
copy kRNL32.exe A:\KRNL32.exe

echo archivos cargados con exito a la floppy, ya puede ejecutar el archivo bochsrc :)

pause

