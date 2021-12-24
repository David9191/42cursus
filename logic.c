/*
gnl 을 구현하는데 약간의 아이디어를 드리자면,  임시로 버퍼를 만들어서
char buff[BS];
read(fd, buff, BS); 를 해서 라인을 읽은 다음,
buff 안에 개행 문자가 있는지 없는지 검사를 합니다.
그런데 개행문자가 있는지 검사하기 전에
우선 함수 내부에 static char * 변수를 선언해서
지금까지 읽은 라인을 백업한 다음 개행 문자가 있다면
다음단계로 넘어가고, 아니라면 개행문자가 있을 때까지 읽고 또 읽어요
(이 과정에서 기존에 백업한 것과 계속 합쳐나가야합니다)
개행문자가 있다 -> 그 다음단계는 static char *에 있는 애들을 \n 전과 후로 잘라서,
\n 전까지는 line 에다가 주고 나머지는 다시 static 변수에 백업.... 하면됩니다.

	ft_read_to_left_str
	위에 애는 \n이 있을 때까지 읽는 함수.

	ft_get_line
	\n까지 꾾어서 주기.

	ft_new_left_str
	\n이후부터 주기.

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
*/

/* logic */
/* 큰 틀
1. main에서 fd를 연다.
2. fd를 우리에게 전달해준다.
3. 우리는 전달받은 fd로부터 \n이나 EOF를 만나기 전까지
	읽어서 걔를 리턴해준다.
*/

/* 작은 틀
1. fd 예외처리
2. 버퍼사이즈만큼 read로읽기
3. 읽어온 애를 검사(\n or EOF가 있는지)
3-1. \n or EOF가 있으면 걔까지 자르기
3-2. 자르고 남은 애를 backup에 저장.
3-3. abc\nde
3-4. 걔를 리턴
*/



















/*
	1. fd로 bs만큼 buf에다가 읽는다.
	2. 읽은 내용을 static backup에 붙인다.
	3. backup에 \n이 있는지 검사 있다면
	3-1. 없다면 move to 1.
	4. ret_buf에 malloc 후 \n까지 + '\0' 대입
	4-1. NO -> free(buf) 후 NULL 리턴
	5. backup은 \n을 기준으로 앞은 자르 뒤만 남겨둠.
	6. buf리턴
*/
