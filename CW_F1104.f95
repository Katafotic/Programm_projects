!F1104
!3430302/90003
!Biga V.S.

PROGRAM CW_F1104
INTEGER  X1,Y1,X2,Y2,FLAG
OPEN (UNIT=7, FILE="input1104.txt", STATUS="old", IOSTAT=FLAG)
IF (flag /= 0 ) THEN
    WRITE(*,*) "ERROR. File not found."
    STOP
END IF
READ (7,*) X1,Y1,X2,Y2
CLOSE (7)
IF ( abs( (X1-X2)*(Y1-Y2) ) == 2 ) THEN
    WRITE(*,*) "YES"
ELSE
    WRITE(*,*) "NO"
END IF
END PROGRAM
