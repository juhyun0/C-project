#ifndef _BOOK_H_
#define _BOOK_H_

void regbook();//도서 구조체 포인터배열에 저장
void borbook(); //대여도서 구조체 포인터배열에 저장
BOOK *regBook();//도서 포인터 리턴 
BORROW *borBook();//대여도서 포인터 리턴
void booklist(); //도서 목록 
void bookdel();//관리자 도서삭제 
void bookserrch(); //관리자 도서검색 
int srchmenu();//검색메뉴 
void clist();//회원 목록 
int listmenu();//회원 목록 메뉴 
void bookrent();//도서대여 
void bookret();//도서반납 
int reBookisbn();//도서 중복 검사 
#endif
