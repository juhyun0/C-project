#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "common.h"

/*
   고객정보 
  
      programed by 이주현 v0.0.1
	   
  Date : 2016. 12. 1.
  Update : 2016. 12. 1
  Remarks ..  

*/

void joinClient(); //회원 구조체 포인터배열에 저장
CLIENT *regClient(); //회원가입후 포인터 리턴 
void listClient();//회원 목록 
void updateinfo();// 개인정보수정 
void bye();//회원 탈퇴 
void booksrch();//도서 검색 
int schmenu();//도서검색메뉴 
void borrowlist();//내 대여목록 
int borrowcheck();//리턴값
int reID();//아이디 중복 확인 리턴 
#endif
