# 📝 get_next_line
---
>## get_next_line 은 무엇인가?

<br>

| **함수 이름** | get_next_line |
|:-----------|:-------------|
| **프로토타입** | char	\*get_next_line(int fd);
| **제출할 파일** | get_next_line.c, get_next_line_utils.c, get_next_line.h |
| **매개변수** | 읽어들일 파일의 디스크립터 |
| **반환값** | 읽혀진 라인 : 한 줄이 제대로 읽힘<br>NULL : 읽을 라인('\n')이 더 이상 없거나 에러 발생 |
| **사용가능한 외부 함수** | read, malloc, free |
| **설명** | 매개변수로 넘어온 파일디스크립터로부터 한 줄을 읽고,<br>반환하는 함수를 작성하시오. |
<br>

get_next_line(이하 gnl)은 매개변수로 넘어온 파일디스크립터 값(fd)를 활용해
해당 파일디스크립터에 접근해서 new line('\n')이 있다면 new line을
포함해 new line까지 반환하고 new line이 없으면 한 줄만 반환하는 과제입니다.
예시 2가지를 들어보겠습니다. BUFFER_SIZE는 모두 42로 가정하겠습니다.
<br>

```c
// 예시1
// 파일이름 hello.txt로 가정

new

line
```
<br>

위 상황이라고 가정하면 gnl함수 호출 시 "new\n"를 반환해야 합니다.
한번 더 호출하게 되면 "\n"을 반환하고
다시 호출하면 "line"을 반환해야 합니다.
<br>

```c
// 예시2
// 파일이름 hello2.txt로 가정

new line
```
위 상황이라고 가정하면 gnl함수 호출 시 "new line"을 반환해야 합니다.
<br><br>

>## get_next_line 사전지식

<br>
* 파일디스크립터 [velog]:(https://dev-ahn.tistory.com/96)<br>
* read함수, open함수<br>
* 정적변수<br>
<br>

>## get_next_line 주의사항

<br>
EOF(End Of File)에 도달하였고 '\n'이 존재하지 않을 때를 제외하고,<br>
함수가 반환하는 문자열 한 줄에는 \n이 포함되어야 합니다.
<br><br>

>## get_next_line Tester
<br>
https://github.com/Tripouille/gnlTester
