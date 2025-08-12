	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 5
	.globl	_insertAtBegin                  ; -- Begin function insertAtBegin
	.p2align	2
_insertAtBegin:                         ; @insertAtBegin
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	mov	x0, #16                         ; =0x10
	bl	_malloc
	str	x0, [sp, #8]
	ldur	w8, [x29, #-12]
	ldr	x9, [sp, #8]
	str	w8, [x9]
	ldur	x8, [x29, #-8]
	ldr	x8, [x8]
	ldr	x9, [sp, #8]
	str	x8, [x9, #8]
	ldr	x8, [sp, #8]
	ldur	x9, [x29, #-8]
	str	x8, [x9]
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_insertAtEnd                    ; -- Begin function insertAtEnd
	.p2align	2
_insertAtEnd:                           ; @insertAtEnd
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	mov	x0, #16                         ; =0x10
	bl	_malloc
	str	x0, [sp, #8]
	ldur	w8, [x29, #-12]
	ldr	x9, [sp, #8]
	str	w8, [x9]
	ldr	x8, [sp, #8]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #8]
	ldur	x8, [x29, #-8]
	cbnz	x8, LBB1_2
	b	LBB1_1
LBB1_1:
	ldr	x8, [sp, #8]
	ldur	x9, [x29, #-8]
	str	x8, [x9]
	b	LBB1_2
LBB1_2:
	ldur	x8, [x29, #-8]
	ldr	x8, [x8]
	str	x8, [sp]
	b	LBB1_3
LBB1_3:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp]
	ldr	x8, [x8, #8]
	cbz	x8, LBB1_5
	b	LBB1_4
LBB1_4:                                 ;   in Loop: Header=BB1_3 Depth=1
	ldr	x8, [sp]
	ldr	x8, [x8, #8]
	str	x8, [sp]
	b	LBB1_3
LBB1_5:
	ldr	x8, [sp, #8]
	ldr	x9, [sp]
	str	x8, [x9, #8]
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_deleteNode                     ; -- Begin function deleteNode
	.p2align	2
_deleteNode:                            ; @deleteNode
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	ldur	x8, [x29, #-8]
	ldr	x8, [x8]
	str	x8, [sp, #24]
                                        ; kill: def $x8 killed $xzr
	str	xzr, [sp, #16]
	b	LBB2_1
LBB2_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #24]
	mov	w9, #0                          ; =0x0
	str	w9, [sp, #12]                   ; 4-byte Folded Spill
	cbz	x8, LBB2_3
	b	LBB2_2
LBB2_2:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	w8, [x8]
	ldur	w9, [x29, #-12]
	subs	w8, w8, w9
	cset	w8, ne
	str	w8, [sp, #12]                   ; 4-byte Folded Spill
	b	LBB2_3
LBB2_3:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	w8, [sp, #12]                   ; 4-byte Folded Reload
	tbz	w8, #0, LBB2_5
	b	LBB2_4
LBB2_4:                                 ;   in Loop: Header=BB2_1 Depth=1
	ldr	x8, [sp, #24]
	str	x8, [sp, #16]
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #8]
	str	x8, [sp, #24]
	b	LBB2_1
LBB2_5:
	ldr	x8, [sp, #24]
	cbnz	x8, LBB2_7
	b	LBB2_6
LBB2_6:
	b	LBB2_8
LBB2_7:
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #8]
	ldr	x9, [sp, #16]
	str	x8, [x9, #8]
	ldr	x0, [sp, #24]
	bl	_free
	b	LBB2_8
LBB2_8:
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_search                         ; -- Begin function search
	.p2align	2
_search:                                ; @search
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, #16]
	str	w1, [sp, #12]
	ldr	x8, [sp, #16]
	ldr	x8, [x8]
	str	x8, [sp]
	b	LBB3_1
LBB3_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp]
	cbz	x8, LBB3_5
	b	LBB3_2
LBB3_2:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp]
	ldr	w8, [x8]
	ldr	w9, [sp, #12]
	subs	w8, w8, w9
	b.ne	LBB3_4
	b	LBB3_3
LBB3_3:
	mov	w8, #1                          ; =0x1
	str	w8, [sp, #28]
	b	LBB3_6
LBB3_4:                                 ;   in Loop: Header=BB3_1 Depth=1
	ldr	x8, [sp]
	ldr	x8, [x8, #8]
	str	x8, [sp]
	b	LBB3_1
LBB3_5:
	str	wzr, [sp, #28]
	b	LBB3_6
LBB3_6:
	ldr	w0, [sp, #28]
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_reverse                        ; -- Begin function reverse
	.p2align	2
_reverse:                               ; @reverse
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, #24]
                                        ; kill: def $x8 killed $xzr
	str	xzr, [sp, #16]
	ldr	x8, [sp, #24]
	ldr	x8, [x8]
	str	x8, [sp, #8]
	str	xzr, [sp]
	b	LBB4_1
LBB4_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #8]
	cbz	x8, LBB4_3
	b	LBB4_2
LBB4_2:                                 ;   in Loop: Header=BB4_1 Depth=1
	ldr	x8, [sp, #8]
	ldr	x8, [x8, #8]
	str	x8, [sp]
	ldr	x8, [sp, #16]
	ldr	x9, [sp, #8]
	str	x8, [x9, #8]
	ldr	x8, [sp, #8]
	str	x8, [sp, #16]
	ldr	x8, [sp]
	str	x8, [sp, #8]
	b	LBB4_1
LBB4_3:
	ldr	x0, [sp, #16]
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_cycle                          ; -- Begin function cycle
	.p2align	2
_cycle:                                 ; @cycle
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	str	x0, [sp, #32]
	ldr	x8, [sp, #32]
	ldr	x8, [x8]
	str	x8, [sp, #24]
	ldr	x8, [sp, #32]
	ldr	x8, [x8]
	str	x8, [sp, #16]
	b	LBB5_1
LBB5_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #16]
	mov	w9, #0                          ; =0x0
	str	w9, [sp, #12]                   ; 4-byte Folded Spill
	cbz	x8, LBB5_3
	b	LBB5_2
LBB5_2:                                 ;   in Loop: Header=BB5_1 Depth=1
	ldr	x8, [sp, #16]
	ldr	x8, [x8, #8]
	subs	x8, x8, #0
	cset	w8, ne
	str	w8, [sp, #12]                   ; 4-byte Folded Spill
	b	LBB5_3
LBB5_3:                                 ;   in Loop: Header=BB5_1 Depth=1
	ldr	w8, [sp, #12]                   ; 4-byte Folded Reload
	tbz	w8, #0, LBB5_7
	b	LBB5_4
LBB5_4:                                 ;   in Loop: Header=BB5_1 Depth=1
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #8]
	str	x8, [sp, #24]
	ldr	x8, [sp, #16]
	ldr	x8, [x8, #8]
	ldr	x8, [x8, #8]
	str	x8, [sp, #16]
	ldr	x8, [sp, #24]
	ldr	x9, [sp, #16]
	subs	x8, x8, x9
	b.ne	LBB5_6
	b	LBB5_5
LBB5_5:
	mov	w8, #1                          ; =0x1
	str	w8, [sp, #44]
	b	LBB5_8
LBB5_6:                                 ;   in Loop: Header=BB5_1 Depth=1
	b	LBB5_1
LBB5_7:
	str	wzr, [sp, #44]
	b	LBB5_8
LBB5_8:
	ldr	w0, [sp, #44]
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_removeCycle                    ; -- Begin function removeCycle
	.p2align	2
_removeCycle:                           ; @removeCycle
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	x0, [sp, #24]
	ldr	x8, [sp, #24]
	ldr	x8, [x8]
	str	x8, [sp, #16]
	ldr	x8, [sp, #24]
	ldr	x8, [x8]
	str	x8, [sp, #8]
	b	LBB6_1
LBB6_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #8]
	cbnz	x8, LBB6_4
	b	LBB6_2
LBB6_2:                                 ;   in Loop: Header=BB6_1 Depth=1
	ldr	x8, [sp, #8]
	ldr	x8, [x8, #8]
	cbnz	x8, LBB6_4
	b	LBB6_3
LBB6_3:
	b	LBB6_10
LBB6_4:                                 ;   in Loop: Header=BB6_1 Depth=1
	ldr	x8, [sp, #16]
	ldr	x8, [x8, #8]
	str	x8, [sp, #16]
	ldr	x8, [sp, #8]
	ldr	x8, [x8, #8]
	ldr	x8, [x8, #8]
	str	x8, [sp, #8]
	b	LBB6_5
LBB6_5:                                 ;   in Loop: Header=BB6_1 Depth=1
	ldr	x8, [sp, #16]
	ldr	x9, [sp, #8]
	subs	x8, x8, x9
	b.ne	LBB6_1
	b	LBB6_6
LBB6_6:
	ldr	x8, [sp, #24]
	ldr	x8, [x8]
	str	x8, [sp, #16]
	b	LBB6_7
LBB6_7:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #16]
	ldr	x9, [sp, #8]
	subs	x8, x8, x9
	b.eq	LBB6_9
	b	LBB6_8
LBB6_8:                                 ;   in Loop: Header=BB6_7 Depth=1
	ldr	x8, [sp, #16]
	ldr	x8, [x8, #8]
	str	x8, [sp, #16]
	ldr	x8, [sp, #8]
	ldr	x8, [x8, #8]
	ldr	x8, [x8, #8]
	str	x8, [sp, #8]
	b	LBB6_7
LBB6_9:
	ldr	x8, [sp, #8]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #8]
	b	LBB6_10
LBB6_10:
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_merge                          ; -- Begin function merge
	.p2align	2
_merge:                                 ; @merge
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	str	x0, [sp, #16]
	str	x1, [sp, #8]
	ldr	x8, [sp, #16]
	cbnz	x8, LBB7_2
	b	LBB7_1
LBB7_1:
	ldr	x8, [sp, #8]
	stur	x8, [x29, #-8]
	b	LBB7_7
LBB7_2:
	ldr	x8, [sp, #8]
	cbnz	x8, LBB7_4
	b	LBB7_3
LBB7_3:
	ldr	x8, [sp, #16]
	stur	x8, [x29, #-8]
	b	LBB7_7
LBB7_4:
	ldr	x8, [sp, #16]
	ldr	w8, [x8]
	ldr	x9, [sp, #8]
	ldr	w9, [x9]
	subs	w8, w8, w9
	b.ge	LBB7_6
	b	LBB7_5
LBB7_5:
	ldr	x8, [sp, #16]
	ldr	x0, [x8, #8]
	ldr	x1, [sp, #8]
	bl	_merge
	ldr	x8, [sp, #16]
	str	x0, [x8, #8]
	ldr	x8, [sp, #16]
	stur	x8, [x29, #-8]
	b	LBB7_7
LBB7_6:
	ldr	x0, [sp, #16]
	ldr	x8, [sp, #8]
	ldr	x1, [x8, #8]
	bl	_merge
	ldr	x8, [sp, #8]
	str	x0, [x8, #8]
	ldr	x8, [sp, #8]
	stur	x8, [x29, #-8]
	b	LBB7_7
LBB7_7:
	ldur	x0, [x29, #-8]
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_print                          ; -- Begin function print
	.p2align	2
_print:                                 ; @print
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	stp	x29, x30, [sp, #32]             ; 16-byte Folded Spill
	add	x29, sp, #32
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	ldur	x8, [x29, #-8]
	ldr	x8, [x8]
	str	x8, [sp, #16]
	b	LBB8_1
LBB8_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	x8, [sp, #16]
	cbz	x8, LBB8_3
	b	LBB8_2
LBB8_2:                                 ;   in Loop: Header=BB8_1 Depth=1
	ldr	x8, [sp, #16]
	ldr	w8, [x8]
                                        ; kill: def $x8 killed $w8
	mov	x9, sp
	str	x8, [x9]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	ldr	x8, [sp, #16]
	ldr	x8, [x8, #8]
	str	x8, [sp, #16]
	b	LBB8_1
LBB8_3:
	ldp	x29, x30, [sp, #32]             ; 16-byte Folded Reload
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_delnEnd                        ; -- Begin function delnEnd
	.p2align	2
_delnEnd:                               ; @delnEnd
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	x0, [x29, #-8]
	stur	w1, [x29, #-12]
	ldur	x8, [x29, #-8]
	ldr	x8, [x8]
	str	x8, [sp, #24]
                                        ; kill: def $x8 killed $xzr
	str	xzr, [sp, #16]
	str	wzr, [sp, #12]
	b	LBB9_1
LBB9_1:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #12]
	ldur	w9, [x29, #-12]
	subs	w9, w9, #1
	subs	w8, w8, w9
	b.ge	LBB9_6
	b	LBB9_2
LBB9_2:                                 ;   in Loop: Header=BB9_1 Depth=1
	ldr	x8, [sp, #24]
	cbnz	x8, LBB9_4
	b	LBB9_3
LBB9_3:
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	b	LBB9_7
LBB9_4:                                 ;   in Loop: Header=BB9_1 Depth=1
	ldr	x8, [sp, #24]
	str	x8, [sp, #16]
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #8]
	str	x8, [sp, #24]
	b	LBB9_5
LBB9_5:                                 ;   in Loop: Header=BB9_1 Depth=1
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB9_1
LBB9_6:
	ldr	x8, [sp, #24]
	ldr	x8, [x8, #8]
	ldr	x9, [sp, #16]
	str	x8, [x9, #8]
	ldr	x8, [sp, #24]
                                        ; kill: def $x9 killed $xzr
	str	xzr, [x8, #8]
	ldr	x0, [sp, #24]
	bl	_free
	b	LBB9_7
LBB9_7:
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w8, #0                          ; =0x0
	str	w8, [sp, #20]                   ; 4-byte Folded Spill
	stur	wzr, [x29, #-4]
	sub	x0, x29, #16
	str	x0, [sp]                        ; 8-byte Folded Spill
                                        ; kill: def $x8 killed $xzr
	stur	xzr, [x29, #-16]
	mov	w1, #1                          ; =0x1
	bl	_insertAtBegin
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	mov	w1, #2                          ; =0x2
	bl	_insertAtBegin
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	mov	w1, #3                          ; =0x3
	bl	_insertAtBegin
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	mov	w1, #4                          ; =0x4
	bl	_insertAtEnd
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	bl	_print
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	str	x0, [sp, #8]                    ; 8-byte Folded Spill
	bl	_printf
	ldr	x0, [sp]                        ; 8-byte Folded Reload
	bl	_reverse
	mov	x8, x0
	add	x0, sp, #24
	str	x8, [sp, #24]
	bl	_print
	ldr	x0, [sp, #8]                    ; 8-byte Folded Reload
	bl	_printf
	ldr	w0, [sp, #20]                   ; 4-byte Folded Reload
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"%d"

l_.str.1:                               ; @.str.1
	.asciz	"N less that length of LL"

l_.str.2:                               ; @.str.2
	.asciz	"\n"

.subsections_via_symbols
