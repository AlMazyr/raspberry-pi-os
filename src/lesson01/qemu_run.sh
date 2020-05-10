#BIN=build/kernel8.elf
BIN=kernel8.img
MONITOR_PORT=1235

#qemu-system-aarch64 \
qemu-system-aarch64 -s -S \
	-M raspi3 \
	-m 512 \
	-nographic \
	-no-reboot \
	-kernel ${BIN} \
	-monitor telnet:127.0.0.1:${MONITOR_PORT},server,nowait \
	-serial stdio \

