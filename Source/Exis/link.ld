ENTRY(main)

SECTIONS
{
	. = 0x1000;

	.text : ALIGN(4096)
	{
	_TEXT_START_ = .;
	*(.text)
	_TEXT_END_ = .;
	}
	
	.data : ALIGN(4096)
	{
	_DATA_START_ = .;
	*(.data)
	_DATA_END_ = .;
	}

	.bss : ALIGN(4096)
	{
	_BSS_START_ = .;
	*(.bss)
	_BSS_END_ = .;
	}
}