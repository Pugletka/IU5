echo off
:menu
cls  
echo ������ୠ� ࠡ�� #2
echo 1. �������� ��४�ਨ
echo 2. �������� ��४�ਨ
echo 3. � �������
echo 4. � ��㤥��
echo 5. ��室
REM ����� ������
be ask "�롥�� �㭪�: " '12345' default=2 timeout=10
REM ���������
if ERRORLEVEL 5 goto p5
if ERRORLEVEL 4 goto p4
if ERRORLEVEL 3 goto p3
if ERRORLEVEL 2 goto p2
if ERRORLEVEL 1 goto p1
goto fin
:p1
echo �������� ��४�ਨ  
mkdir newdir 
echo ����� ��४��� newdir ᮧ����
pause
goto menu
:p2
echo �������� ��४�ਨ
rmdir newdir  
echo ��४��� newdir 㤠����
pause
goto menu
:p3
echo �������� ������� - MKDIR
mkdir /?
pause
goto menu
:p4
call student.bat
pause
goto menu
:p5
goto fin
:fin
ECHO ��室 �� �ணࠬ��
if "%1"=="1" be ask "��� �� �ணࠬ��: " 'TF' default=2 timeout=10 
if "%2"=="1" pause
exit \b