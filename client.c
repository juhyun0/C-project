#include "common.h"
#include "client.h"
#include "book.h"
#include "file.h"

//전역변수 
extern BOOK **book;//도서 
extern int numofbook; //도서수 

//전역변수 
extern CLIENT **client;  //회원 
extern int numofclient;  //회원수 
extern char g_userID[20]; 

//전역변수
extern BORROW **borrow;//대여 
extern int numofborrow; //대여수 


extern char g_userID[20]; 

void joinClient(){ //회원 구조체 포인터배열에 저장

   if(numofclient==0){
   	client=(CLIENT **)malloc(sizeof(CLIENT*));
   }
   else {
   	client=(CLIENT **)realloc(client, (numofclient+1)*sizeof(CLIENT*));
   }
   client[numofclient++]=regClient();
}

CLIENT *regClient(){ //회원가입후 포인터 리턴  

   CLIENT *pParam=(CLIENT *)malloc(sizeof(CLIENT)); 
   
   fflush(stdin);
   printf("이름 : ");
   gets(pParam->clientName);
   
   fflush(stdin);
   printf("학번 : ");
   gets(pParam->clientNum);
   
   while(1){
	    fflush(stdin);
	    printf("아이디 : ");
	    gets(pParam->clientId);
		if(reID(pParam->clientId)==0){   
			break;
		}else{
			printf("새로운 아이디를 입력하세요.");
		}
    }
   
   fflush(stdin);
   printf("비밀번호 : ");
   gets(pParam->clientPw);
   
   fflush(stdin);
   printf("주소 : ");
   gets(pParam->clientAddr);
   
   fflush(stdin);
   printf("전화번호 : ");
   gets(pParam->clientPhone); 
   
   
   return pParam;
}
int reID(char *temp){
	int i;
	printf(" 회원수 %d\n", numofclient); 
	for(i=0; i<numofclient-1; i++){
		if(strcmp(temp,client[i]->clientId)==0){
			return 1;
		}
	}
	return 0;
}
void listClient(){ //회원 목록 
	int i;
	for(i=0; i<numofclient; i++){
		printf("학번 : %s\n",client[i]->clientNum); 
		printf("아이디 : %s\n",client[i]->clientId);
		printf("비밀번호 : %s\n",client[i]->clientPw);
		printf("이름 : %s\n",client[i]->clientName);
		printf("주소 : %s\n",client[i]->clientAddr);
		printf("전화번호 : %s\n",client[i]->clientPhone);
	}
}
void updateinfo(){//개인정보수정 
	int i;
	for(i=0; i<numofclient; i++){
		if(strcmp(g_userID, client[i]->clientId)==0){
			printf("학번 : %s\n",client[i]->clientNum); 
			printf("이름 : %s\n",client[i]->clientName);
			printf("비밀번호 : %s\n",client[i]->clientPw);
			printf("새 비밀번호 입력 : ");
			scanf("%s",client[i]->clientPw); 
			printf("주소 : %s\n",client[i]->clientAddr);
			printf("새 주소 입력 : ");
			scanf("%s",client[i]->clientAddr);
			printf("전화번호 : %s\n",client[i]->clientPhone);
			printf("새 전화번호 입력 : ");
			scanf("%s",client[i]->clientPhone);
			break;
		}
	}
}
void booksrch(){//도서 검색
	 int SCH;
	 int i;
	 char BNAME[20];
	 char BPUB[20];
	 char BISBN[20];
	 char BWRT[20];
	 printf("**도서 검색**");
	 printf("\n");
	 SCH=schmenu();
	 printf("번호를 입력하세요 : %d\n",SCH); 
	 switch(SCH){
	 	case 1:
		 	printf("도서명 입력 : ");
		 	fflush(stdin);
			gets(BNAME);
			for(i=0; i<numofbook; i++){
				if(strcmp(book[i]->bookName,BNAME)==0){	
					printf("도서명 : %s\n",book[i]->bookName);
					printf("출판사 : %s\n",book[i]->bookPublisher);
					printf("저자명 : %s\n",book[i]->bookWriter);
					printf("ISBN : %s\n",book[i]->bookISBN);
					printf("소장처 : %s\n",book[i]->bookHolding);
					break;
				}
			}
	     	break;
		case 2:
			printf("출판사명 입력 : ");
		 	fflush(stdin);
			gets(BPUB);
			for(i=0; i<numofbook; i++){
				if(strcmp(book[i]->bookName,BPUB)==0){	
					printf("도서명 : %s\n",book[i]->bookName);
					printf("출판사 : %s\n",book[i]->bookPublisher);
					printf("저자명 : %s\n",book[i]->bookWriter);
					printf("ISBN : %s\n",book[i]->bookISBN);
					printf("소장처 : %s\n",book[i]->bookHolding);
					break;
				}
			}
	     	break;
	    case 3:
	    	printf("ISBN 입력 : ");
		 	fflush(stdin);
			gets(BISBN);
			for(i=0; i<numofbook; i++){
				if(strcmp(book[i]->bookName,BISBN)==0){	
					printf("도서명 : %s\n",book[i]->bookName);
					printf("출판사 : %s\n",book[i]->bookPublisher);
					printf("저자명 : %s\n",book[i]->bookWriter);
					printf("ISBN : %s\n",book[i]->bookISBN);
					printf("소장처 : %s\n",book[i]->bookHolding);
					break;
				}
			}
	     	break;
	    case 4:
	    	printf("저자명 입력 : ");
		 	fflush(stdin);
			gets(BWRT);
			for(i=0; i<numofbook; i++){
				if(strcmp(book[i]->bookName,BWRT)==0){	
					printf("도서명 : %s\n",book[i]->bookName);
					printf("출판사 : %s\n",book[i]->bookPublisher);
					printf("저자명 : %s\n",book[i]->bookWriter);
					printf("ISBN : %s\n",book[i]->bookISBN);
					printf("소장처 : %s\n",book[i]->bookHolding);
					break;
				}
			}
	     	break;
	    case 5:
			booklist();
	     	break;
	    case 6:
	    	
	     	break;
		 
	 }
	 
}
int schmenu(){//도서검색메뉴 
	int Bnum;
	printf("1. 도서명 검색\n");
	printf("2. 출판사명 검색\n");
	printf("3. ISBN 검색\n");
	printf("4. 저자명 검색\n");
	printf("5. 전체 검색\n");
	printf("6. 나가기\n"); 
	scanf("%d",&Bnum);
	return Bnum;
}

void bye(){//회원탈퇴 **
	int i,j;
	char nID[10];
	char nPW[10];
	fflush(stdin);
	printf("ID 입력하세요: ");
	gets(nID);
	fflush(stdin);
	printf("비밀번호 입력하세요: ");
	gets(nPW);
	for(i=0; i<numofclient; i++){
		if(strcmp(client[i]->clientId,nID)==0 && strcmp(client[i]->clientPw,nPW)==0){
		     if(borrowcheck()==1){
				printf("반납하지 않은 도서가 있습니다!!\n");
			}
			else{
				for(j=i; j<numofclient-1; j++){
						client[j]=client[j+1];
						
				}
				numofclient--;
				
				printf(">>>memver delete<<<\n");
			}
		}
	}
}
int borrowcheck(){
	
	int i;

	for(i=0;i<numofborrow;i++){
		if(strcmp(g_userID, borrow[i]->bADMIN)==0 && borrow[i]->brent==0){
			
			return 1;
		}
		printf("==%d\n", borrow[i]->brent);
	}
	
	return 0;
}

void borrowlist(){//내 대여목록 **
	
	int aa; 
	BORROW *bor=(BORROW *)malloc(sizeof(BORROW));
	
	for(aa=0; aa<numofborrow; aa++){
		if(strcmp(g_userID, borrow[aa]->bADMIN)==0){
		printf(" == %s",g_userID);	
		printf("도서명 : %s\n",borrow[aa]->bnamE);
		printf("ISBN : %s\n",borrow[aa]->bisbN);
		printf("대여일 : %d년 %d월 %d일 %d시 %d분 %d초입니다.\n", 
		borrow[aa]->bYear,borrow[aa]->bMon,borrow[aa]->bDay,borrow[aa]->bHour,borrow[aa]->bMin,borrow[aa]->bSec);
		
		struct tm*t;
		time_t timer;
		
		timer = time(NULL);
		
		t=localtime(&timer);
		
		
		
		if(t->tm_mday+30>30){
			if(t->tm_mon+2>12){
				borrow[aa]->reYear=t->tm_year+1900+1;
				borrow[aa]->reMon=t->tm_mon+1-11;	
			}
			else {
				borrow[aa]->reYear=t->tm_year+1900;
				borrow[aa]->reMon=t->tm_mon+2;	
			}
				borrow[aa]->reDay=t->tm_mday;
		}
		else {
		    if(t->tm_mon+1>12){
		    	borrow[aa]->reYear=t->tm_year+1900+1;
		    	borrow[aa]->reMon=t->tm_mon+1;
			}
			else {
				borrow[aa]->reYear=t->tm_year+1900;	
			    borrow[aa]->reMon=t->tm_mon+1;
			}
			borrow[aa]->reDay=t->tm_mday+30;
		}
		
		
		borrow[aa]->reHour=t->tm_hour;
		borrow[aa]->reMin=t->tm_min;
		borrow[aa]->reSec=t->tm_sec;
		
		printf("반납예정일 : %d년 %d월 %d일 %d시 %d분 %d초입니다.\n", 
		borrow[aa]->reYear,borrow[aa]->reMon,borrow[aa]->reDay,borrow[aa]->reHour,borrow[aa]->reMin,borrow[aa]->reSec);
		}
	}
}

