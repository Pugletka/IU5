; ������ୠ� ࠡ�� �4
MYCODE SEGMENT 'CODE'
ASSUME CS:MYCODE
LABTITLE db '������ୠ� ࠡ�� #4$'
START:
; ����㧪� ᥣ���⭮�� ॣ���� ������ DS
     push CS
     pop  DS
; ��⪠ �࠭�
     CALL CLRSCR
; �뢮� ���������
     mov DX, offset LABTITLE
     call PUTSTR
     call CLRF
; �뢮� ��ࢮ�� ᨬ����
     mov DL , '�'
     call PUTCH
; ..��� ������ ���� 横� � �뢮��� ᨬ�����..
; �������� �����襭�� �ணࠬ��
     call GETCH
; �뢮� �� �ணࠬ��
     mov AL , 0
     mov AH , 4CH
     int 21H
; ��楤���:
; ��ॢ�� �� ����� ��ப�
CLRF PROC
    mov DL , 10
    call PUTCH
    mov DL , 13
    call PUTCH
    ret
CLRF ENDP
; ���⪠ �࠭�
CLRSCR PROC
    call CLRF
    mov  AH , 0H
    mov  AL , 3H
    int  10H
    ret
CLRSCR ENDP
; �뢮� ������ ᨬ���� �� �࠭
PUTCH PROC
    mov AH , 02H
    int 021H
    ret
PUTCH ENDP
; �뢮� ��ப�
PUTSTR PROC
    mov AH , 09H
    int 021H
    ret
PUTSTR ENDP
; ���� ᨬ���� � ����������
GETCH PROC
    mov AH , 08H
    int 021H
    ret
GETCH ENDP
MYCODE ENDS
END START
