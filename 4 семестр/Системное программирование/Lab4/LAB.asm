; ������ୠ� ࠡ�� �4 (+ �������⥫�� �ॡ������)
MYCODE SEGMENT 'CODE'
ASSUME CS:MYCODE
LABTITLE DB '������ୠ� ࠡ�� #4$'
CURNTSMBL DB '�'
HEX_TABLE DB '0123456789ABCDEF'
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
; ��⠭���� ������⢠ ᨬ����� ��� �뢮��
     mov cx , 10
     call PRNTHEAD
; ���� �뢮�� ᨬ�����
  LOOPCH:
     mov dl , '�'
     call PUTCH
     mov dl, CURNTSMBL
     inc CURNTSMBL
     call PUTCH
     mov dl, '�'
     call PUTCH
     call HEX
     mov dl, 'h'
     call PUTCH
     mov dl , '�'
     call PUTCH
     mov dl, CURNTSMBL
     inc CURNTSMBL
     call PUTCH
     mov dl, '�'
     call PUTCH
     call HEX
     mov dl, 'h'
     call PUTCH
     mov dl , '�'
     call PUTCH
     call CLRF
     cmp cx , 1 ; �᫨ ��᫥���� ᨬ���, � ������ 墮��
��   je CONTINUE
     call PRNTSEPRTR
     loop LOOPCH
  CONTINUE:
     call PRNTTAIL
; �������� �����襭�� �ணࠬ��
     call GETCH
; �뢮� �� �ணࠬ��
     mov al , 0
     mov ah , 4CH
     int 21H

; ��楤���:
; -------------------------------
; ��ॢ�� ᨬ���� � ���
HEX PROC
    mov dl , CURNTSMBL
    lea bx , HEX_TABLE ; load data table.
    mov al , dl
    shr al , 4 ; leave high part only.
    xlat ; Get hex digit.
    mov ah , 0Eh ; Teletype sub-function.
    int 10h
    mov al , dl
    and al , 0Fh ; leave low part only.
    xlat ; Get hex digit.
    mov ah , 0Eh ; Teletype sub-function.
    int 10h
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
; -------------------------------
; ����� 蠯��
PRNTHEAD PROC
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    call CLRF
    ret
PRNTHEAD ENDP
; -------------------------------
; ����� 蠯��
PRNTSEPRTR PROC
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    call CLRF
    ret
PRNTSEPRTR ENDP
; -------------------------------
; ����� 蠯��
PRNTTAIL PROC
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    mov dl , '�'
    call PUTCH
    call CLRF
    ret
PRNTTAIL ENDP

END START
MYCODE ENDS
