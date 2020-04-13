!F1402
!3430302/90003
!Biga V.S.

      program F1402
      implicit none
      INTEGER :: M,N,S1,S2,i,tmp
      INTEGER ,ALLOCATABLE :: matrix(:,:)
      !INTEGER MATRIX(M,N)
      open (7, file="input1402.txt", IOSTAT=M)
      IF (M/=0) THEN
        PRINT *,'ERROR. Cannot open file.'
      END IF
      READ (7,*)  M, N
      READ (7,*)  S1, S2
      allocate ( matrix(M,N) )
      tmp=1
      DO i=1,M
          DO tmp=1,N
            READ (7,*) (matrix(i,tmp), tmp=1,N)
          END DO
      END DO
      CLOSE (7)

      !WRITE (*,'/') ''
      !WRITE (*, 'A,/') ''

      tmp=1
      DO i=1,M

            print*,(matrix(i,tmp), tmp=1, N)
            !WRITE (*,'/')

      END DO


      END PROGRAM F1402
