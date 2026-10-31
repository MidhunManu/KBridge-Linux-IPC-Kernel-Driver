savedcmd_kbridge.o := ld -EL  -maarch64elf -z noexecstack --no-warn-rwx-segments   -r -o kbridge.o @kbridge.mod 
