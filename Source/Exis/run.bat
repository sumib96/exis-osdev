@echo off

set ProjectRoot=C:\Users\faszomat\Desktop\Repo\VisualUefi

set QEMU=%ProjectRoot%\debugger\
set Name="Exis Test"
set Drive=%ProjectRoot%\samples\x64\Release\

%QEMU%qemu -name %Name% -drive file=%QEMU%OVMF_CODE-need-smm.fd,if=pflash,format=raw,unit=0,readonly=on -drive file=%QEMU%OVMF_VARS-need-smm.fd,if=pflash,format=raw,unit=1 -drive file=fat:rw:%Drive%,media=disk,if=virtio,format=raw -drive file=%QEMU%UefiShell.iso,format=raw -m 512 -machine q35,smm=on -nodefaults -vga std -global driver=cfi.pflash01,property=secure,value=on -global ICH9-LPC.disable_s3=1
