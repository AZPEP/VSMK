ENTRY(main)

SECTIONS {
	. = 0x100000;

	.text : {
		* (.multiboot)
		* (.text)
	}
	.bss BLOCK(4K) : {
		* (COMMON)
		* (.bss)
	}

	.data BLOCK(4K) : {
		* (.data)
	}
	
}