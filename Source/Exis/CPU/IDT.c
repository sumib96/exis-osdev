#include "IDT.h"

void LoadIDT()
{
    Idtr.Limit = 0x0FFF;
    Idtr.Base = &Idt;

    IDT_ENTRY_64 int_PageFault = (IDT_ENTRY_64*)(idtr.Base + 0xE * sizeof(IDT_ENTRY_64));
    int_PageFault->idt_set_descriptor();

    Lidt((void*)&Idtr);
}