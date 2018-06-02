; ������ୠ� ࠡ�� �8

assume cs:CODE
CODE SEGMENT 'CODE'
; --------------------------------------
LABTITLE DB '������ୠ� ࠡ�� #8$'
ENTRMSGE DB '������ ����: $'
EXITSMBL DB '*'
; --------------------------------------
HEX_TABLE DB '0123456789ABCDEF$'
CURNTSMBL DB 'A'
PRGRMFLAG DB	0
; ��६���� ��� ॣ���஢
regBP	DW	0
regDI	DW	0
regSI	DW	0
regSP	DW	0
regES	DW	0
regSS	DW	0
regDS	DW	0
regCS	DW  0
; ����
DUMP1 DW	0
DUMP2 DW	0
STRLEN EQU	16
STRINGS	EQU	15
BUFLEN EQU STRLEN*STRINGS
BUF	DB BUFLEN	DUP(0)
coef DW 10000,1000,100,10,1
; --------------------------------------
START:
  ; ����㧪� ᥣ���⭮�� ॣ���� ������ DS
  push cs
  pop  ds
  ; ��⪠ �࠭�
  call CLRSCR
  ; �뢮� ���������
  call CLRF
  mov dx , offset LABTITLE
  call PUTSTR
  call CLRF
  call CLRF
  ; ������ 横�
  MAINLP:
    ; ���࠭���� ॣ���஢
    call SAVEREGS
    ; �뢮� ��ப� �����
    mov dx , offset ENTRMSGE
    call PUTSTR
    ; ���� ᥣ���⭮� ��� ����
    call NEARIN
    ; �஢�ઠ �� ��室
    cmp PRGRMFLAG , 1
    je EXITP
    mov DUMP1 , bx
    ; �뢮� ':'
    mov dl , ':'
  	call PUTCH
    ; ���� ᬥ饭��
    call NEARIN
    cmp PRGRMFLAG , 1
    je EXITP
    mov DUMP2 , bx
    ; �뢮� ॣ���஢
    call PRINTREGS
    ; �⥭�� ������ ����� ��� �����
    call DUMPIN
    ; �뢮� �����
    call DUMPOUT
    call GETCH
    mov cx , 2
    call CLRF
    loop MAINLP
  ; �뢮� �� �ணࠬ��
  EXITP:
    mov al , 0
    mov ah , 4CH
    int 21H
; --------------------------------------
;             | ��楤��� |
; --------------------------------------
; ��ॢ�� ᨬ���� � 16-� ���
; --------------------------------------
HEX PROC
  mov dl , CURNTSMBL
  lea bx , HEX_TABLE ; ����㧪� ⠡����
  mov al , dl
  shr al , 4 ; ����뢠��� ������� ࠧ�冷�
  xlat ; �८�ࠧ������ � 16 ��⥬�
  mov dl , al
  call PUTCH
  mov dl , CURNTSMBL
  mov al , dl
  and al , 00001111b ; ����뢠��� ����� ࠧ�冷�
  xlat ; �८�ࠧ������ � 16 ��⥬�
  mov dl , al
  call PUTCH
  ret ; ��室
HEX ENDP
; --------------------------------------
; ��ॢ�� ᫮�� � 16-� ���
; --------------------------------------
DBLHEX PROC
  push dx
  mov dh , dl
  mov CURNTSMBL , dh
  call HEX
  pop dx
  mov dh , dl
  mov CURNTSMBL , dh
  call HEX
  ret ; ��室
DBLHEX ENDP
; --------------------------------------
; ��ॢ�� �� ����� ��ப�
; --------------------------------------
CLRF PROC
  mov dl , 10
  call PUTCH
  mov dl , 13
  call PUTCH
  ret ; ��室
CLRF ENDP
; --------------------------------------
; ���⪠ �࠭�
; --------------------------------------
CLRSCR PROC
  call CLRF
  mov  ah , 0H
  mov  al , 3H
  int  10H
  ret ; ��室
CLRSCR ENDP
; --------------------------------------
; �뢮� ������ ᨬ���� �� �࠭ (�� dl)
; --------------------------------------
PUTCH PROC
  mov ah , 02H
  int 21H
  ret
PUTCH ENDP
; --------------------------------------
; �뢮� ��ப� (�� dx)
; --------------------------------------
PUTSTR PROC
  mov ah , 09H
  int 21H
  ret
PUTSTR ENDP
; --------------------------------------
; ���� ᨬ���� � ���������� (� al)
; --------------------------------------
GETCH PROC
  mov ah , 08H
  int 21H
  ret
GETCH ENDP
;-------------------------------------
; ���࠭���� ॣ���஢
;-------------------------------------
SAVEREGS	PROC
	mov	regBP , bp
	mov	regDI , di
	mov	regSI , si
	mov	regSP , sp
	mov	regES , es
	mov	regSS , ss
	mov	regDS , ds
  mov	regCS , cs
	ret
SAVEREGS	ENDP
;-------------------------------------
; ���� � ��ॢ�� near-���� � ����筮� �᫮
;-------------------------------------
NEARIN PROC
	mov	bp , 0	; ���稪 ��������� ᨬ�����
	mov bx , 0	; �᫮
  NEARINLOOP:
  	call GETCH
  	mov	dl , al
  	jmp	CHECK
  SHIFT:
  	call PUTCH
  	pop	ax
  	mov ah , 0
  	shl	bx , 4
  	add	bx , ax
  	inc	bp ; ���稪 �����
  	cmp	bp , 4
  	je EXIT
  	jmp NEARINLOOP
  CHECK:
  	cmp	al , EXITSMBL
  	jne	NUMBER
  	mov	PRGRMFLAG , 1
  	jmp	EXIT
  NUMBER:
  	; �஢�ઠ ���
  	cmp al , '0'
  	jb BIGCHR
  	cmp al , '9'
  	ja BIGCHR
  	sub al , '0'
  	push ax
  	jmp	SHIFT
  BIGCHR:
    cmp al , 'A'
  	jb SMALLCHR
  	cmp al , 'F'
  	ja SMALLCHR
  	sub al , 'A'-10
  	push ax
  	jmp	SHIFT
  SMALLCHR:
  	cmp al , 'a'
  	jb NEARINLOOP
  	cmp al , 'f'
  	ja NEARINLOOP
  	sub al , 'a'-10 ; 'b'-'a'+10 = 11
  	push	ax
  	jmp	SHIFT
  EXIT:
    ret
NEARIN ENDP
;-------------------------------------
; �뢮� ॣ���஢
;-------------------------------------
PRINTREGS	PROC
	call	CLRF
	mov	dl , 'C'
	call	PUTCH
	mov	dl , 'S'
	call	PUTCH
	mov	dl , '='
	call PUTCH
	mov	dx , regCS
	call DBLHEX
	mov dl , ' '
	call PUTCH
	mov	dl , 'D'
	call PUTCH
	mov dl , 'S'
	call PUTCH
	mov	dl , '='
	call PUTCH
	mov	dx , regDS
	call DBLHEX
	mov dl , ' '
	call PUTCH
	mov	dl , 'S'
	call PUTCH
	mov	dl , 'S'
	call PUTCH
	mov	dl , '='
	call PUTCH
	mov	dx , regSS
	call DBLHEX
	mov dl , ' '
	call PUTCH
	mov	dl , 'E'
	call PUTCH
	mov	dl , 'S'
	call PUTCH
	mov	dl , '='
	call PUTCH
	mov	dx , regES
	call DBLHEX
	mov dl , ' '
	call PUTCH
	mov	dl , 'S'
	call PUTCH
	mov	dl , 'P'
	call PUTCH
	mov	dl , '='
	call PUTCH
	mov	dx , regSP
	call DBLHEX
	mov dl , ' '
	call PUTCH
	mov	dl , 'S'
	call PUTCH
	mov	dl , 'I'
	call PUTCH
	mov dl , '='
	call PUTCH
	mov	dx , regSI
	call DBLHEX
	mov dl , ' '
	call PUTCH
	mov	dl , 'D'
	call PUTCH
	mov	dl , 'I'
	call PUTCH
	mov	dl , '='
	call PUTCH
	mov	dx , regDI
	call DBLHEX
	mov dl , ' '
	call PUTCH
	mov	dl , 'B'
	call PUTCH
	mov	dl , 'P'
	call PUTCH
	mov	dl , '='
	call PUTCH
	mov	dx , regBP
	call DBLHEX
	call CLRF
	mov	dx , DUMP1
	call DBLHEX
	mov dl , ':'
	call PUTCH
	mov dx , DUMP2
	call DBLHEX
	mov dl , '-'
	call PUTCH
	mov	dx , DUMP1
	call DBLHEX
	mov dl , ':'
	call PUTCH
	mov	dx , DUMP2
	add	dx , BUFLEN
	call DBLHEX
	call CLRF
	ret
PRINTREGS	ENDP
;-------------------------------------
; ����ᥭ�� �����
;-------------------------------------
DUMPIN PROC
	mov	ax , DUMP1
	push ax
	pop es
	mov	di , DUMP2
	mov	si , 0
	mov	cx , BUFLEN
  DUMPINLOOP:
  	mov	al , BYTE PTR es:[di]
  	mov	BUF[si] , al ; ����ᥭ�� ᨬ���� � ����
  	inc	di
  	inc	si
  	loop DUMPINLOOP
  	ret
DUMPIN ENDP
;-------------------------------------
; �뢮� �����
;-------------------------------------
DUMPOUT	PROC
	mov	cx , STRINGS
	mov	si , 0
  DUMPOUTLOOP:
  	push cx
  	CALL PRINTSTR
  	pop	cx
  	loop DUMPOUTLOOP
  	ret
DUMPOUT	ENDP
;-------------------------------------
; �뢮� ��ப� � �����
;-------------------------------------
PRINTSTR	PROC
	; �뢮� ����
	mov	dx , DUMP1
	call DBLHEX
	mov dl , ':'
	call PUTCH
	mov	dx , DUMP2
	add	dx , si
	call DBLHEX
	mov	dl , ':'
	call PUTCH
	mov	dl , ' '
	call PUTCH
	; �뢮� ���⮢ � ��⭠����筮� ����
	push si
	mov cx , STRLEN
  PRINTSTRLOOP:
  	mov	dl , BUF[si] ; ����ᥭ�� ⥪�饣� ᨬ���� � DL
  	inc	si
  	call HEX ; �뢮� ᨬ���� � HEX
  	mov	dl , ' '
  	call PUTCH ; �뢮� �஡���
  	loop PRINTSTRLOOP
  	mov	dl , ':'
  	call PUTCH
  	mov	dl , ' '
  	call PUTCH
  	; �뢮� � ���� ᨬ�����
  	pop	si
  	mov	cx , STRLEN
  PRINTSTRLOOP2:
  	mov	dl , BUF[si] ; ����ᥭ�� ⥪�饣� ᨬ���� � DL
  	inc	si
  	cmp	dl , 32	; ��� �஡���
  	jae	PRINT
  	mov	dl , EXITSMBL
  PRINT:
  	call PUTCH ; �뢮� �஡���
  	loop PRINTSTRLOOP2
  	call CLRF
  	ret
PRINTSTR ENDP

END START
CODE ENDS
