;  ������ୠ� ࠡ�� �3 (+ �������⥫�� �ॡ������)
MYCODE SEGMENT 'CODE'
ASSUME CS:MYCODE
LABTITLE db '������ୠ� ࠡ�� #3$'
STUDENTNAME db '���� ������ ����ਥ���$'
START:
MAIN:
; ����㧪� ᥣ���⭮�� ॣ���� ������ DS
     PUSH CS
     POP  DS
; ��⪠ �࠭�
     CALL CLRSCR
; �뢮� ���������
     MOV DX, offset LABTITLE
     CALL PUTSTR
     CALL CLRF
; �뢮� ᨬ����� � ��ॢ�� ��ப�
     MOV DL , '�'
     CALL PUTCH
     CALL CLRF
     MOV DL , '�'
     CALL PUTCH
     CALL CLRF
     MOV DL , '�'
     CALL PUTCH
     CALL CLRF
; �뢮� ��� ��㤥��
     MOV DX, offset STUDENTNAME
     CALL PUTSTR
; �������� �����襭�� �ணࠬ��
     CALL GETCH
; �஢��� �������� ᨬ���
     CMP AL, '*'
     JNE MAIN
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
END MAIN
END START
