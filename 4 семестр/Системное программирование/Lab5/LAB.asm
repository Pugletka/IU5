; ������ୠ� ࠡ�� �5

assume cs:CODE
CODE SEGMENT 'CODE'
; -------------------------------
; ��ப��� ����⠭��
LABTITLE DB '������ୠ� ࠡ�� #5$'
HELP1 DB '����� ��ப� - enter$'
HELP2 DB '��室 �� �ணࠬ�� - esc$'
ESCSMBL DB 27 ; esc
ENTRSMBL DB 13 ; enter
; -------------------------------
; �ᯮ����⥫�� ��㪨
HEX_TABLE DB '0123456789ABCDEF'
CURNTSMBL DB 'A'
STRING db 41 dup ('$')
; -------------------------------
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
; ������ 横�
     call CLRF
     MAIN:
       mov si , 0
       mov cx , 40
       INPUTSTR:
       ; ���� ᨬ����
          call GETCH
          mov CURNTSMBL , al
       ; �஢�ઠ �� ᨬ��� ��室� �� �ணࠬ��
          cmp al , ESCSMBL
          je EXITP
       ; �஢�ઠ �� ����� ��ப�
          cmp al , ENTRSMBL
    			je FINDEND
       ; �뢮� ᨬ����
          mov dl , al
          call PUTCH
       ; ���������� ��ப�
          mov bh , CURNTSMBL
    			mov STRING[si] , bh
    			inc si
       ; ���� INPUTSTR
          loop INPUTSTR
     FINDEND:
       mov cx , si
       mov si , 0
       ; �뢮� ' ='
       mov dl , ' '
       call PUTCH
       mov dl , '='
       call PUTCH
       OUTPUTCH:
       ; �뢮� �஡���
         mov dl , ' '
         call PUTCH
       ; ��ॢ�� ᨬ���� � �뢮�
         mov bh , STRING[si]
         mov CURNTSMBL , bh
         call HEX
         inc si
       ; �뢮� ᨬ���� 'h'
         mov dl , 'h'
         call PUTCH
       ; ���� OUTPUTCH
         loop OUTPUTCH
       call CLRF
       dec di
   		 mov cx , di
       ; ���� MAIN
       loop MAIN
     EXITP:
     ; �뢮� �� �ணࠬ��
       mov al , 0
       mov ah , 4CH
       int 21H
; ��楤���:
; -------------------------------
; ��ॢ�� ᨬ���� � ���
HEX PROC
    mov dl , CURNTSMBL
    lea bx , HEX_TABLE ; Load data table.
    mov al , dl
    shr al , 4 ; Leave high part only.
    xlat ; Get hex digit.
    mov dl , al
    call PUTCH
    mov dl , CURNTSMBL
    mov al , dl
    and al , 00001111b ; leave low part only.
    xlat ; Get hex digit.
    mov dl , al
    call PUTCH
    ret
HEX ENDP
; -------------------------------
; ��ॢ�� �� ����� ��ப�
CLRF PROC
    mov dl , 10
    call PUTCH
    mov dl , 13
    call PUTCH
    ret
CLRF ENDP
; -------------------------------
; ���⪠ �࠭�
CLRSCR PROC
    call CLRF
    mov  ah , 0H
    mov  al , 3H
    int  10H
    ret
CLRSCR ENDP
; -------------------------------
; �뢮� ������ ᨬ���� �� �࠭
PUTCH PROC
    mov ah , 02H
    int 21H
    ret
PUTCH ENDP
; -------------------------------
; �뢮� ��ப�
PUTSTR PROC
    mov ah , 09H
    int 21H
    ret
PUTSTR ENDP
; -------------------------------
; ���� ᨬ���� � ����������
GETCH PROC
    mov ah , 08H
    int 21H
    ret
GETCH ENDP

END START
CODE ENDS
