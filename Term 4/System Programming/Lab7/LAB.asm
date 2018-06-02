; ������ୠ� ࠡ�� �7

assume cs:CODE
CODE SEGMENT 'CODE'
; --------------------------------------
LABTITLE DB '������ୠ� ࠡ�� #7$'
HELP1 DB '����� ��ப� - enter$'
HELP2 DB '��室 �� �ணࠬ�� - *$'
ENTRMSGE DB '������ �᫮: $'
HEX_TABLE DB '0123456789ABCDEF$'
CURNTSMBL DB 'A'
EXITSMBL DB '*'
PRGRMFLAG DB	0
k	DW 10000,1000,100,10,1
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
; �뢮� �ࠢ��
  call CLRF
  mov dx , offset HELP1
  call PUTSTR
  call CLRF
  mov dx , offset HELP2
  call PUTSTR
  call CLRF
  call CLRF
  MAINLP:
  ; �뢮� ��ப� ��� �����
    mov dx , offset ENTRMSGE
    call PUTSTR
  ; ���� ���塠�⮢��� ᫮�� � 16-� ����
    call INPUTBIN
  ; �஢�ઠ �� '*'
    cmp	PRGRMFLAG , 1
    je EXITP
    push BX
  ; �뢮� ' = '
    mov dl , ' '
    call PUTCH
    mov dl , '='
    call PUTCH
    mov dl , ' '
    call PUTCH
  ; �뢮� ��㡠�⮢��� ᫮�� � 16-� ����
    mov dx , bx
    push dx
    mov CURNTSMBL , dh
  	call HEX ; ���� ����
  	pop dx
  	mov dh , dl
    mov CURNTSMBL , dh
  	call HEX ; ��ன ����
  	mov dl , 'h'
  	call PUTCH
    ; �뢮� ' ()'
    mov dl , ' '
  	call PUTCH
    mov dl , '('
  	call PUTCH
    ; �뢮� ���塠�⮢��� ᫮�� � 10-� ����
    pop	BX
    call DEC
    ; �뢮� ')'
    mov dl , ')'
  	call PUTCH
    ; �த������� 横��
    call CLRF
    mov cx , 2
    loop MAINLP
    EXITP:
    ; �뢮� �� �ணࠬ��
      mov al , 0
      mov ah , 4CH
      int 21H
; --------------------------------------
;             | ��楤��� |
; --------------------------------------
; ��ॢ�� ᨬ���� � ���
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
; --------------------------------------
; ���� ᫮�� � ��ॢ�� ���� � ����筮� �᫮
; --------------------------------------
INPUTBIN PROC
	mov	bp , 0	; ���稪 ��������� ᨬ�����
	mov bx , 0	; ��᫮
  INLOOP:
	  ; ���� ᨬ����
	  call GETCH
	  mov	dl , al
	  jmp	CHECK
  SHIFT:
	  ; �᫨ ᨬ��� �ࠢ����, � �� �뢮�����
	  call PUTCH
	  ; ����⠭������� �� �⥪� ��������� ����
	  pop	ax
	  ; ����ᥭ�� 0 � ah, � al ���
	  mov ah , 0
	  ; C���� �।��饣� १���� �� 4 �����
	  shl	bx , 1
	  shl	bx , 1
	  shl	bx , 1
	  shl	bx , 1
	  ; ���������� ��������� ���� � �।��饬� १�����
	  add	bx , ax
	  inc	bp	; C��稪 �����
	  ; �᫨ ������� 4 ����, � ��室��
	  cmp	bp , 4
	  je EXIT
	  jmp INLOOP
  CHECK:
	  cmp	al , EXITSMBL ; �᫨ ������ �� EXITSMBL � �஢������� ���� � �㪢�
	  jne	NUMBER
	  mov	PRGRMFLAG , 1 ; ���� ��⠭���� 䫠�� ��室� �� �ணࠬ�� � ������ �� ��楤���
	  jmp	EXIT
  NUMBER:
    ; �஢�ઠ ���
	  ; �᫨ ascii-��� ���������� ᨬ���� <'0' ��� '9'>, � �஢�ઠ ������ �㪢
	  cmp al , '0'
	  jb BIGCHR
	  cmp al , '9'
	  ja BIGCHR
	  ; ���� ���⠭�� ᨬ���� '0' �� ascii-���� ��������� ���� (�८�ࠧ������ "�㪢�" � �᫮)
	  sub al , '0'  ; al - �᫮
	  ; ���࠭���� �᫠ � �⥪�
	  push ax
	  ; ���室 �� ���������� १���� � bx
	  jmp	SHIFT
  BIGCHR:
  	; �᫨ ascii-��� ���������� ᨬ���� <'A' ��� >'F', � �஢�ઠ �����쪨� �㪢
  	cmp al , 'A'
  	jb SMALLCHR
  	cmp al , 'F'
  	ja SMALLCHR
  	; �८�ࠧ������ �㪢 � 16-� ����
  	sub al , 'A'-10 ; 'B'-'A'+10=11
  	; ���࠭���� �᫠ � �⥪�
  	push ax
  	jmp	SHIFT
  SMALLCHR:
    cmp al , 'a'
  	jb INLOOP
  	cmp al , 'f'
  	ja INLOOP
  	sub al , 'a'-10 ; 'b'-'a'+10=11
  	push ax
  	jmp	SHIFT
  EXIT:
    ret
INPUTBIN ENDP
; --------------------------------------
; ��ॢ�� �� 16-�� � 10-�� ��⥬�
; --------------------------------------
DEC PROC
	mov	ax , bx ; ��᫮
	mov	di , 0 ; ���稪 横��
  LOOP:
  	mov	dx , 0 ; ���訩 ���� ��������
  	mov	bx , k[di] ; ����⥫�
  	; �������
  	; dx:ax / bx = ax(dx)
  	; ax - ��⭮�, dx - ���⮪
    div	bx
  	; ���⮪ � �⥪
  	; ���⮪ ��⠥��� ���� �᫮�
  	push	dx
  	; �뢮� १���� �������
  	add	ax , '0'
  	mov	dl , al
  	call PUTCH
  	; � ax (����訩 ���� ��������) ����頥��� ���⮪
  	pop	ax
  	inc	di
  	inc	di
  	; 5 ��� - 10 ����
  	cmp	di , 10
  	jb LOOP
  ret
DEC	ENDP

END START
CODE ENDS
