#prama once
#include "..\BaseTypes.h"
#include "AsmLib.h"

#define IDT_InterruptGate	0b10001110
#define IDT_CallGate		0b10001100
#define IDT_TrapGate		0b10001111

typedef struct IDT_ENTRY_64
{
	uint16_t    isr_low;      // The lower 16 bits of the ISR's address
	uint16_t    kernel_cs;    // The GDT segment selector that the CPU will load into CS before calling the ISR
	uint8_t	    ist;          // The IST in the TSS that the CPU will load into RSP; set to zero for now
	uint8_t     attributes;   // Type and attributes; see the IDT page
	uint16_t    isr_mid;      // The higher 16 bits of the lower 32 bits of the ISR's address
	uint32_t    isr_high;     // The higher 32 bits of the ISR's address
	uint32_t    reserved;     // Set to zero
} __attribute__((packed)) IDT_ENTRY_64;

typedef struct IDT_ENTRY_64
{
    UINT16 Limit;
    UINT64 Base;
} __attribute__((packed)) IDT_DESCRIPTOR_64;

IDT_ENTRY_64 Idt[256];
IDT_DESCRIPTOR_64 Idtr;

IDT_ENTRY_64 idt_set_descriptor(void* isr, uint8_t flags) {
    IDT_ENTRY_64* desc;
 
    descr->base_low       = (uint64_t)isr & 0xFFFF;
    desc->cs             = 0x08; //GDT_OFFSET_KERNEL_CODE;
    desc->ist            = 0;
    desc->attributes     = flags;
    desc->base_mid       = ((uint64_t)isr >> 16) & 0xFFFF;
    des->base_high      = ((uint64_t)isr >> 32) & 0xFFFFFFFF;
    des->rsv0           = 0;

	return desc;
}

void LoadIDT();