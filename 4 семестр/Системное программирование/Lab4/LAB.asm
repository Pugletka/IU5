;  ������ୠ� ࠡ�� �3 (+ �������⥫�� �ॡ������)
MYCODE SEGMENT 'CODE'
ASSUME CS:MYCODE
LABTITLE db '������ୠ� ࠡ�� #4$'
STUDENTNAME db '���� ������ ����ਥ���$'
START:
; ����㧪� ᥣ���⭮�� ॣ���� ������ DS
     PUSH CS
     POP  DS
; ��⪠ �࠭�
     CALL CLRSCR
; �뢮� ���������
     MOV DX, offset LABTITLE
     CALL PUTSTR
     CALL CLRF
; �뢮� ��ࢮ�� ᨬ����
     MOV DL , '�'
     CALL PUTCH
SYMBOLLOOP:
; �뢮� ᨬ����� � ��ॢ�� ��ப�
     INC DL
     CALL PUTCH
     CALL CLRF
; if (symbol == '�')
     CMP AL, '�'
     JNE SYMBOLLOOP
; �������� �����襭�� �ணࠬ��
     CALL GETCH
; �뢮� �� �ணࠬ��
     MOV AL , 0
     MOV AH , 4CH
     INT 21H
; ��楤���:
; ��ॢ�� �� ����� ��ப�
CLRF PROC
    MOV DL , 10
    CALL PUTCH
    MOV DL , 13
    CALL PUTCH
    RET
CLRF ENDP
; ���⪠ �࠭�
CLRSCR PROC
    CALL CLRF
    MOV  AH , 0H
    MOV  AL , 3H
    INT  10H
    RET
CLRSCR ENDP
; �뢮� ������ ᨬ���� �� �࠭
PUTCH PROC
    MOV AH , 02H
    INT 021H
    RET
PUTCH ENDP
; �뢮� ��ப�
PUTSTR PROC
    MOV AH , 09H
    INT 021H
    RETN
PUTSTR ENDP
; ���� ᨬ���� � ���������� � AL
GETCH PROC
    MOV AH , 08H
    INT 021H
    RET
GETCH ENDP
MYCODE ENDS
END SYMBOLLOOP
END START
