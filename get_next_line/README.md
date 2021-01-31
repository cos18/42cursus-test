# get_next_line
GNL Tester에서 잡지 않는 메모리 누수를 확인하는 코드입니다.

### 사용법
현재 폴더에 gnl 삼총사(c파일, 유틸 c파일, 헤더)를 복사해 실행해야 합니다.

```console
$ gcc -D BUFFER_SIZE=32 -o test get_next_line.c get_next_line_utils.c test.c
$ ./test
// 실행을 종료하지 않고 터미널 새 창을 열어 실행
$ leaks test
```

> 버퍼 사이즈를 변경해서도 테스트해야합니다. Subject에서는 최대 10000000까지 핸들링 되어야한다고 언급되어있습니다.
