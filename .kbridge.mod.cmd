savedcmd_kbridge.mod := printf '%s\n'   kbridge_main.o proc.o | awk '!x[$$0]++ { print("./"$$0) }' > kbridge.mod
