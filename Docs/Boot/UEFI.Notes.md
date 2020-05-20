# Secund Stage Bootloader notes about UEFI

## Interrupts
The interrupts must be disabled before we do anything. It can corrupt the boot / kernel runtime initialization.

## Design
The UEFI protocol / library names should be used as a prefix for Header / C files in the Source directory for convention.
Every module than can have the same functions within.

## Goals
- The UEFI init. behavior can change on different UEFI implementation, so the right code will be actually running.
- Check for availability of UEFI protocols and hardware capabilities, like GOP, Resolutions etc.