#ifndef _COMMON_H_ 
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
  회원, 도서, 대여구조체
  
      programed by 이주현 v0.0.1
	   
  Date : 2016. 12. 1.
  Update : 2016. 12. 1
  Remarks ..  

*/
#define ADMINID "admin"
#define ADMINPW "0000"
#define MenuError() printf("메뉴선택오류!\n") 


// 메인메뉴 열거형 JOIN : 회원가입, LOGIN : 로그인 , QUIT : 프로그램 종료 
typedef enum Mainmenu { JOIN=1, LOGIN, QUIT } MAINMNU;

typedef enum Clientmenu { BOOKSRCH=1, BORROWLIST, UPDATEINFO, BYE, LOGOUT, EXIT } CLIENTMNU;
typedef enum Adminmenu { BOOKRGT=1, BOOKDEL, BOOKRENT, BOOKRET, BOOKSerRCH, CLIENTLIST, BOOLOGOUT, OUT } ADMINMNU;

//회원 목록 구조체 
typedef struct client{
	char clientNum[10]; // 학번 
	char clientPw[20]; //비밀번호
	char clientName[10]; //이름
	char clientAddr[80]; //주소
	char clientPhone[20]; //전화번호 
	char clientId[20];//아이디 
}CLIENT;

//도서 목록 구조체 
typedef struct book{
	char bookName[20]; //도서명 
	char bookPublisher[15]; //출판사 
	char bookWriter[15]; //저자명
	char bookISBN[15]; //ISBN
	char bookHolding[15]; //소장처 
	char bookRent[15]; //대여가능 여부 
	int rent; 
}BOOK;
//도서 대여 구조체 
typedef struct borrow{
	char bADMIN[20]; //사용자ID 
	char bisbN[20]; //도서번호 ISBN
	char bnamE[20];//도서명
	int bYear; //(대여일자)년 
	int bMon; //(대여일자)월
	int bDay; //(대여일자)일 
	int bHour; //(대여일자)시 
	int bMin; //(대여일자)분
	int bSec; //(대여일자)초 
	int reYear; //(반납일자)년
	int reMon; //(반납일자)월
	int reDay; //(반납일자)일 
	int reHour; //(반납일자)시 
	int reMin; //(반납일자)분 
	int reSec; //(반납일자)초 
	int brent;//도서반납여부 대여1,반납0 
}BORROW;
 

#endif
