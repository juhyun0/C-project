#include "common.h"
#include "book.h"
#include "client.h"
#include "file.h"

//전역변수 
extern BOOK **book;//도서 
extern int numofbook; //도서수 

//전역변수 
extern CLIENT **client;  //회원 
extern int numofclient;  //회원수 

//전역변수
extern BORROW **borrow;//대여 
extern int numofborrow; //대여수 

void regbook(){ //도서 구조체 포인터배열에 저장
	int i;
   if(numofbook==0){
   	book=(BOOK **)malloc(sizeof(BOOK*));
   }
   else {
   	book=(BOOK **)realloc(book, (numofbook+1)*sizeof(BOOK*));
   }
   book[numofbook++]=regBook();
   
   for(i=0; i<numofbook; i++){
		printf("%s %s %s %s %s %d\n",book[i]->bookName,book[i]->bookPublisher,book[i]->bookWriter,book[i]->bookISBN,book[i]->bookHolding,book[i]->rent);
   }
}

void borbook(){ //대여도서 구조체 포인터배열에 저장

   if(numofbook==0){
   	borrow=(BORROW **)malloc(sizeof(BORROW*));
   }
   else {
   	borrow=(BORROW **)realloc(borrow, (numofborrow+1)*sizeof(BORROW*));
   }
   borrow[numofborrow++]=borBook();
}

BOOK *regBook(){//도서 포인터 리턴
	
    BOOK *search=(BOOK *)malloc(sizeof(BOOK)); 
    
    fflush(stdin);
	printf("도서명 : ");
	gets(search->bookName);
	fflush(stdin);
	printf("출판사 : ");
	gets(search->bookPublisher);
	fflush(stdin);
	printf("저자명 : ");
	gets(search->bookWriter);
	while(1){
		fflush(stdin);	
		printf("ISBN : ");
		gets(search->bookISBN);
		printf("%s",search->bookISBN);
		
		if(reBookisbn(search->bookISBN)==0){
			break;
		}else{
			printf("새로운 ISBN 입력하세요.\n");
		}
	}
	
	fflush(stdin);
	printf("소장처 : ");
	gets(search->bookHolding);
	search->rent=1;
	
	printf("도서명 %s, 출판사 %s, 저자명 %s, ISBN %s, 소장처 %s, 대여 %d \n", search->bookName,search->bookPublisher,
	search->bookWriter,search->bookISBN,search->bookHolding,search->rent);
	
	return search;
}
int reBookisbn(char *temp){
	int i;
	
	//printf(" 총 %d 권\n", numofbook); 
	for(i=0; i<numofbook-1; i++){
		printf(">>>> %s, %s\n", temp, book[i]->bookISBN);
		if(strcmp(temp,book[i]->bookISBN)==0){
			return 1;
		}
	}
	return 0;
}

BORROW *borBook(){//대여도서 포인터 리턴
	int o,a;
	int status=0;
	int sta=0;
	
	BORROW *bor=(BORROW *)malloc(sizeof(BORROW)); 
	printf("**도서 대여**");
	printf("\n");
	fflush(stdin);
	bor->brent=0;//도서대여여부
	while(1){
		printf("회원 ID를 입력하세요 : ");
		gets(bor->bADMIN);
		for(o=0; o<numofclient; o++){
			if(strcmp(bor->bADMIN,client[o]->clientId)==0){
				status=1;
				break;
			}
		}
		
		if(status==1){ 
		   printf("%s는 회원 명단에 존재합니다\n", bor->bADMIN);
		   break;
		}
		else { printf("존재하지 않는 회원입니다 다시 입력하세요\n"); }
	}
	
	while(1){
		printf("ISBN 입력하세요 : ");
		gets(bor->bisbN);
		
		for(a=0; a<numofbook; a++){
			if(strcmp(bor->bisbN,book[a]->bookISBN)==0){
				
				printf("도서명 : %s\n",book[a]->bookName);
				printf("출판사 : %s\n",book[a]->bookPublisher);
				printf("저자 : %s\n",book[a]->bookWriter);
				printf("ISBN : %s\n",book[a]->bookISBN);
				printf("소장처 : %s\n",book[a]->bookHolding);
				
				if(book[a]->rent==1){
					printf(" 대여가능합니다\n"); 
					printf("%s 도서를  대여할까요 (Y/N)?", book[a]->bookName);
					char yn=getchar();
					if(yn=='y'||yn=='Y'){
						book[a]->rent=0;
						strcpy(bor->bisbN, book[a]->bookISBN);
						strcpy(bor->bnamE, book[a]->bookName);
					 	sta=1;
					    break;
					}
					else {
						printf(" 다른 도서를 선택하세요\n\n");
					}
				}
				else {
					printf(" 이미 대여중입니다. 다른 도서 선택해주세요\n");
				}
			}
		}
		
		if(sta==1){ printf("%s는 ISBN에 존재합니다.\n", bor->bisbN); 
		    break;
		}
		else { printf("존재하지 않는 ISBN입니다. 다시 입력하세요.\n"); }
	}	
	
	struct tm*t;
	time_t timer;
	
	timer = time(NULL);
	t=localtime(&timer);
	
	bor->bYear=t->tm_year+1900;
	bor->bMon=t->tm_mon+1;
	bor->bDay=t->tm_mday;
	bor->bHour=t->tm_hour;
	bor->bMin=t->tm_min;
	bor->bSec=t->tm_sec;
	
	printf("대여일 : %d년 %d월 %d일 %d시 %d분 %d초입니다.\n", 
	bor->bYear,bor->bMon,bor->bDay,bor->bHour,bor->bMin,bor->bSec);
	return bor;
}
void bookret(){//도서반납 
	char CNUM[15];
	int bi,bj;
	
	fflush(stdin);
	printf("ID 입력하세요 : ");
	gets(CNUM);
	for(bi=0; bi<numofborrow; bi++){
		if(strcmp(CNUM,borrow[bi]->bADMIN)==0){
			printf("도서명 : %s\n",borrow[bi]->bnamE);
			printf("ISBN : %s\n",borrow[bi]->bisbN);
					for(bj=0; bj<numofbook; bj++){
						book[bj]->rent=0;
						
					}
						struct tm*t;
						time_t timer;
						
						timer = time(NULL);
						
						t=localtime(&timer);
						
						borrow[bi]->reYear=t->tm_year+1900;
						borrow[bi]->reMon=t->tm_mon+1;
						borrow[bi]->reDay=t->tm_mday;
						borrow[bi]->reHour=t->tm_hour;
						borrow[bi]->reMin=t->tm_min;
						borrow[bi]->reSec=t->tm_sec;
						borrow[bi]->brent=1;//도서반납여부
						printf("대여일 : %d년 %d월 %d일 %d시 %d분 %d초입니다.\n", 
						borrow[bi]->bYear,borrow[bi]->bMon,borrow[bi]->bDay,borrow[bi]->bHour,borrow[bi]->bMin,borrow[bi]->bSec);
						printf("반납일 : %d년 %d월 %d일 %d시 %d분 %d초입니다.\n", 
						borrow[bi]->reYear,borrow[bi]->reMon,borrow[bi]->reDay,borrow[bi]->reHour,borrow[bi]->reMin,borrow[bi]->reSec);
				
		}
	}
}
void booklist(){ // 도서 목록 
	int i;
	
	for(i=0; i<numofbook; i++){
		printf("**도서 대여**");
		printf("\n");
		printf("도서명 : %s\n",book[i]->bookName);
		printf("출판사 : %s\n",book[i]->bookPublisher);
		printf("저자명 : %s\n",book[i]->bookWriter);
		printf("ISBN : %s\n",book[i]->bookISBN);
		printf("소장처 : %s\n",book[i]->bookHolding);		 
	}
}
void bookdel(){//도서삭제 
	int i,j;	
	int nnum;
	char BookName[20];
	char BookIsbn[20];
	printf("**도서 삭제**");
	printf("\n"); 
	nnum=srchmenu();
	printf("번호명 입력 : %d\n",nnum);
	fflush(stdin);
	if(nnum==1){ 
		printf("도서명 입력하세요 : ");
		gets(BookName);
		for(i=0; i<numofbook; i++){
			if(strcmp(book[i]->bookName,BookName)==0){
				for(j=i; j<numofbook-1; j++){
					book[j]==book[j+1];
					
				}
				numofbook--;
				break;
			}
		}
	}else if(nnum==2){
		printf("ISBN 입력하세요 : ");
		gets(BookIsbn);
		for(i=0; i<numofbook; i++){
			if(strcmp(book[i]->bookISBN,BookIsbn)==0){
				for(j=i; j<numofbook-1; j++){
					book[j]==book[j+1];
					
				}
				numofbook--;
				break;
			}
		}
	}else{
		printf("다시 입력하세요.");
	}
}
void bookserrch(){
	int i,j;
	char BOOKname[20];
	char BOOKisbn[20];
	int num;
	printf("**도서 검색**");
	printf("\n");
	num=srchmenu();
	printf("번호명 입력 : %d\n",num);
	if(num==1){ 
		fflush(stdin);
		printf("도서명 입력하세요 : ");
		gets(BOOKname);
		for(i=0; i<numofbook; i++){
			if(strcmp(book[i]->bookName,BOOKname)==0){	
				printf("도서명 : %s\n",book[i]->bookName);
				printf("출판사 : %s\n",book[i]->bookPublisher);
				printf("저자명 : %s\n",book[i]->bookWriter);
				printf("ISBN : %s\n",book[i]->bookISBN);
				printf("소장처 : %s\n",book[i]->bookHolding);
			}
		}
	}else if(num==2){
		printf("ISBN 입력하세요 : ");
		gets(BOOKisbn);
		for(i=0; i<numofbook; i++){
			if(strcmp(book[i]->bookISBN,BOOKisbn)==0){	
				printf("도서명 : %s\n",book[i]->bookName);
				printf("출판사 : %s\n",book[i]->bookPublisher);
				printf("저자명 : %s\n",book[i]->bookWriter);
				printf("ISBN : %s\n",book[i]->bookISBN);
				printf("소장처 : %s\n",book[i]->bookHolding);
			}
		}
	}else{
		printf("다시 입력하세요.");
	}
}

int srchmenu(){
	int NUM;
	printf("1. 도서명 검색\n");
	printf("2. ISBN 검색\n"); 
	printf(">>");
	scanf("%d",&NUM);
	return NUM;
}
void clist(){//회원 목록 
	int lnum;
	int i;
	char cname[10];
	char cnum[10];
	
	printf("**도서 검색**");
	printf("\n");
	lnum=listmenu();
	
	switch(lnum){
		case 1:
			printf("이름 입력 : ");
			fflush(stdin);
			gets(cname);
			for(i=0; i<numofbook; i++){
				if(strcmp(client[i]->clientName,cname)==0){
					printf("학번 : %s\n",client[i]->clientNum); 
					printf("비밀번호 : %s\n",client[i]->clientPw);
					printf("이름 : %s\n",client[i]->clientName);
					printf("주소 : %s\n",client[i]->clientAddr);
					printf("전화번호 : %s\n",client[i]->clientPhone);
					break;
				}
			}
			break;
		case 2:
			fflush(stdin);
			printf("학번 입력 : ");
			gets(cnum);
			for(i=0; i<numofbook; i++){
				if(strcmp(client[i]->clientNum,cnum)==0){
					printf("학번 : %s\n",client[i]->clientNum); 
					printf("비밀번호 : %s\n",client[i]->clientPw);
					printf("이름 : %s\n",client[i]->clientName);
					printf("주소 : %s\n",client[i]->clientAddr);
					printf("전화번호 : %s\n",client[i]->clientPhone);
					break;
				}
			}
			break;
		case 3:
			listClient();
			break;
		case 4:
			lnum--;
			break;
		default :
			printf("다시 입력하세요.");
	}
	
}
int listmenu(){
	int LISTNUM;
	printf("1. 이름 검색\n"); 
	printf("2. 학번 검색\n");
	printf("3. 전체 검색\n");
	printf("4. 이전 검색\n");
	printf(">>");
	scanf("%d",&LISTNUM);
	return LISTNUM; 
}


