#pragma once

extern void x64_Lgdt(void *Gdtr);
extern void x64_Sgdt(void *Gdtr);
extern void x64_Lidt(void *Ldtr);