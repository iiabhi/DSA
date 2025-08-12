	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 5
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	mov	w0, #0                          ; =0x0
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_button_event                   ; -- Begin function button_event
	.p2align	2
_button_event:                          ; @button_event
	.cfi_startproc
; %bb.0:
	adrp	x9, _button_presses@PAGE
	mov	w8, #1                          ; =0x1
	str	w8, [x9, _button_presses@PAGEOFF]
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_button_presses                 ; @button_presses
.zerofill __DATA,__common,_button_presses,4,2
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"button is pressed"

.subsections_via_symbols
