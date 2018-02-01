#include "common.h"
#include "menu.h"
#include "client.h"

//전역변수 
extern CLIENT **client;  //회원 
extern int numofclient;  //회원수 

//전역변수 
extern BOOK **book;//도서 
extern int numofbook; //도서수 

//전역변수
extern BORROW **borrow;//대여 
extern int numofborrow; //대여수 

extern char g_userID[20]; 

int mainmenu(){
	int mnu; 

	printf("\n\t>> 도서관 서비스 ver0.0.1 <<\n\n");
		 
	printf("1. 회원가입\n"); 
	printf("2. 로그인\n"); 
	printf("3. 프로그램 종료\n");
	printf(">> ");
	
	scanf("%d",&mnu);
	
	return mnu; 
}

int client_menu(){
	int cmnu;
	
	printf(" >> 회원 메뉴<< \n");
	
	printf("1. 도서 검색\n");
	printf("2. 대여 목록\n"); 
	printf("3. 개인정보수정\n"); 
	printf("4. 회원 탈퇴\n"); 
	printf("5. 로그아웃\n"); 
	printf("6. 프로그램 종료\n");
	printf(">> ");
	
	scanf("%d",&cmnu);
	
	return cmnu;  
}

void clientMain(){
	CLIENTMNU cm;
	 
	while((cm=client_menu())!=LOGOUT){

		switch(cm) {
           case BOOKSRCH:
           		booksrch();
           	    break;
		   case BORROWLIST:
		   		borrowlist();
		   		break;
		   case UPDATEINFO:
		 		updateinfo();
		   		break;
		   case BYE:
		   		bye();
		   		file();
		   		break;
		   case EXIT: exit(0);
		   		break;
		   default : MenuError();
		   		break;
		}
	}

}

int admin_menu(){
	int amnu;
	
	printf(" >> 관리자 메뉴<< \n");
	
	printf("1. 도서 등록\n");
	printf("2. 도서 삭제\n"); 
	printf("3. 도서 대여\n"); 
	printf("4. 도서 반납\n"); 
	printf("5. 도서 검색\n"); 
	printf("6. 도서 목록\n");
	printf("7. 로그 아웃\n");
	printf("8. 프로그램 종료\n");
	printf(">> ");
	
	scanf("%d",&amnu);
	
	return amnu; 
}
void adminMain(){
	ADMINMNU am;
	
	while((am=admin_menu())!=BOOLOGOUT){
		switch(am) {
           case BOOKRGT:
           		regbook();
           		file();
           	    break;
		   case BOOKDEL:
		   		bookdel();
		   		break;
		   case BOOKRENT:
		   		borbook();
		   		break;
		   case BOOKRET:
		   		bookret();
		   		break;
		   case BOOKSerRCH:
		   		bookserrch();
		   		break;	
		   case CLIENTLIST:
		   		booklist();
		   		break;
		   case OUT: exit(0);
		   		break;
		   default : MenuError();
		   		break;
		}
	}
}
void login(){ //로그인 함수
	char ID[10];
	char PW[15];
	
	printf("ID : ");
	scanf("%s",ID);
	printf("Password : ");
	scanf("%s",PW);
	
	if(checkclient(ID, PW)==1){
		printf(" 로그인 성공!\n");
		strcpy(g_userID,ID);
		clientMain();
		
	}
	else if(strcmp(ID,ADMINID)==0 && strcmp(PW,ADMINPW)==0){
		printf(" 관리자 로그인 성공!\n"); 
		adminMain();
	}
	else {
		printf(" * 회원가입후 사용하세요* \n"); 
	}
}
int checkclient(char *ID,char *PW){ 
	int i;
	for(i=0; i<numofclient; i++){
		if(strcmp(client[i]->clientId,ID)==0 && strcmp(client[i]->clientPw,PW)==0){
			return 1;
		}
	}
	
	
	return 0;
}
