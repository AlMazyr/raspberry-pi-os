BIN=build/kernel8.elf
MONITOR_PORT=1235

#qemu-system-aarch64 -s -S \
qemu-system-aarch64 \
	-M raspi3 \
	-m 512 \
	-nographic \
	-no-reboot \
	-kernel ${BIN} \
	-monitor telnet:127.0.0.1:${MONITOR_PORT},server,nowait \
	-serial stdio \

