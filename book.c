#include "common.h"
#include "book.h"
#include "client.h"
#include "file.h"

//�������� 
extern BOOK **book;//���� 
extern int numofbook; //������ 

//�������� 
extern CLIENT **client;  //ȸ�� 
extern int numofclient;  //ȸ���� 

//��������
extern BORROW **borrow;//�뿩 
extern int numofborrow; //�뿩�� 

void regbook(){ //���� ����ü �����͹迭�� ����
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

void borbook(){ //�뿩���� ����ü �����͹迭�� ����

   if(numofbook==0){
   	borrow=(BORROW **)malloc(sizeof(BORROW*));
   }
   else {
   	borrow=(BORROW **)realloc(borrow, (numofborrow+1)*sizeof(BORROW*));
   }
   borrow[numofborrow++]=borBook();
}

BOOK *regBook(){//���� ������ ����
	
    BOOK *search=(BOOK *)malloc(sizeof(BOOK)); 
    
    fflush(stdin);
	printf("������ : ");
	gets(search->bookName);
	fflush(stdin);
	printf("���ǻ� : ");
	gets(search->bookPublisher);
	fflush(stdin);
	printf("���ڸ� : ");
	gets(search->bookWriter);
	while(1){
		fflush(stdin);	
		printf("ISBN : ");
		gets(search->bookISBN);
		printf("%s",search->bookISBN);
		
		if(reBookisbn(search->bookISBN)==0){
			break;
		}else{
			printf("���ο� ISBN �Է��ϼ���.\n");
		}
	}
	
	fflush(stdin);
	printf("����ó : ");
	gets(search->bookHolding);
	search->rent=1;
	
	printf("������ %s, ���ǻ� %s, ���ڸ� %s, ISBN %s, ����ó %s, �뿩 %d \n", search->bookName,search->bookPublisher,
	search->bookWriter,search->bookISBN,search->bookHolding,search->rent);
	
	return search;
}
int reBookisbn(char *temp){
	int i;
	
	//printf(" �� %d ��\n", numofbook); 
	for(i=0; i<numofbook-1; i++){
		printf(">>>> %s, %s\n", temp, book[i]->bookISBN);
		if(strcmp(temp,book[i]->bookISBN)==0){
			return 1;
		}
	}
	return 0;
}

BORROW *borBook(){//�뿩���� ������ ����
	int o,a;
	int status=0;
	int sta=0;
	
	BORROW *bor=(BORROW *)malloc(sizeof(BORROW)); 
	printf("**���� �뿩**");
	printf("\n");
	fflush(stdin);
	bor->brent=0;//�����뿩����
	while(1){
		printf("ȸ�� ID�� �Է��ϼ��� : ");
		gets(bor->bADMIN);
		for(o=0; o<numofclient; o++){
			if(strcmp(bor->bADMIN,client[o]->clientId)==0){
				status=1;
				break;
			}
		}
		
		if(status==1){ 
		   printf("%s�� ȸ�� ��ܿ� �����մϴ�\n", bor->bADMIN);
		   break;
		}
		else { printf("�������� �ʴ� ȸ���Դϴ� �ٽ� �Է��ϼ���\n"); }
	}
	
	while(1){
		printf("ISBN �Է��ϼ��� : ");
		gets(bor->bisbN);
		
		for(a=0; a<numofbook; a++){
			if(strcmp(bor->bisbN,book[a]->bookISBN)==0){
				
				printf("������ : %s\n",book[a]->bookName);
				printf("���ǻ� : %s\n",book[a]->bookPublisher);
				printf("���� : %s\n",book[a]->bookWriter);
				printf("ISBN : %s\n",book[a]->bookISBN);
				printf("����ó : %s\n",book[a]->bookHolding);
				
				if(book[a]->rent==1){
					printf(" �뿩�����մϴ�\n"); 
					printf("%s ������  �뿩�ұ�� (Y/N)?", book[a]->bookName);
					char yn=getchar();
					if(yn=='y'||yn=='Y'){
						book[a]->rent=0;
						strcpy(bor->bisbN, book[a]->bookISBN);
						strcpy(bor->bnamE, book[a]->bookName);
					 	sta=1;
					    break;
					}
					else {
						printf(" �ٸ� ������ �����ϼ���\n\n");
					}
				}
				else {
					printf(" �̹� �뿩���Դϴ�. �ٸ� ���� �������ּ���\n");
				}
			}
		}
		
		if(sta==1){ printf("%s�� ISBN�� �����մϴ�.\n", bor->bisbN); 
		    break;
		}
		else { printf("�������� �ʴ� ISBN�Դϴ�. �ٽ� �Է��ϼ���.\n"); }
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
	
	printf("�뿩�� : %d�� %d�� %d�� %d�� %d�� %d���Դϴ�.\n", 
	bor->bYear,bor->bMon,bor->bDay,bor->bHour,bor->bMin,bor->bSec);
	return bor;
}
void bookret(){//�����ݳ� 
	char CNUM[15];
	int bi,bj;
	
	fflush(stdin);
	printf("ID �Է��ϼ��� : ");
	gets(CNUM);
	for(bi=0; bi<numofborrow; bi++){
		if(strcmp(CNUM,borrow[bi]->bADMIN)==0){
			printf("������ : %s\n",borrow[bi]->bnamE);
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
						borrow[bi]->brent=1;//�����ݳ�����
						printf("�뿩�� : %d�� %d�� %d�� %d�� %d�� %d���Դϴ�.\n", 
						borrow[bi]->bYear,borrow[bi]->bMon,borrow[bi]->bDay,borrow[bi]->bHour,borrow[bi]->bMin,borrow[bi]->bSec);
						printf("�ݳ��� : %d�� %d�� %d�� %d�� %d�� %d���Դϴ�.\n", 
						borrow[bi]->reYear,borrow[bi]->reMon,borrow[bi]->reDay,borrow[bi]->reHour,borrow[bi]->reMin,borrow[bi]->reSec);
				
		}
	}
}
void booklist(){ // ���� ��� 
	int i;
	
	for(i=0; i<numofbook; i++){
		printf("**���� �뿩**");
		printf("\n");
		printf("������ : %s\n",book[i]->bookName);
		printf("���ǻ� : %s\n",book[i]->bookPublisher);
		printf("���ڸ� : %s\n",book[i]->bookWriter);
		printf("ISBN : %s\n",book[i]->bookISBN);
		printf("����ó : %s\n",book[i]->bookHolding);		 
	}
}
void bookdel(){//�������� 
	int i,j;	
	int nnum;
	char BookName[20];
	char BookIsbn[20];
	printf("**���� ����**");
	printf("\n"); 
	nnum=srchmenu();
	printf("��ȣ�� �Է� : %d\n",nnum);
	fflush(stdin);
	if(nnum==1){ 
		printf("������ �Է��ϼ��� : ");
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
		printf("ISBN �Է��ϼ��� : ");
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
		printf("�ٽ� �Է��ϼ���.");
	}
}
void bookserrch(){
	int i,j;
	char BOOKname[20];
	char BOOKisbn[20];
	int num;
	printf("**���� �˻�**");
	printf("\n");
	num=srchmenu();
	printf("��ȣ�� �Է� : %d\n",num);
	if(num==1){ 
		fflush(stdin);
		printf("������ �Է��ϼ��� : ");
		gets(BOOKname);
		for(i=0; i<numofbook; i++){
			if(strcmp(book[i]->bookName,BOOKname)==0){	
				printf("������ : %s\n",book[i]->bookName);
				printf("���ǻ� : %s\n",book[i]->bookPublisher);
				printf("���ڸ� : %s\n",book[i]->bookWriter);
				printf("ISBN : %s\n",book[i]->bookISBN);
				printf("����ó : %s\n",book[i]->bookHolding);
			}
		}
	}else if(num==2){
		printf("ISBN �Է��ϼ��� : ");
		gets(BOOKisbn);
		for(i=0; i<numofbook; i++){
			if(strcmp(book[i]->bookISBN,BOOKisbn)==0){	
				printf("������ : %s\n",book[i]->bookName);
				printf("���ǻ� : %s\n",book[i]->bookPublisher);
				printf("���ڸ� : %s\n",book[i]->bookWriter);
				printf("ISBN : %s\n",book[i]->bookISBN);
				printf("����ó : %s\n",book[i]->bookHolding);
			}
		}
	}else{
		printf("�ٽ� �Է��ϼ���.");
	}
}

int srchmenu(){
	int NUM;
	printf("1. ������ �˻�\n");
	printf("2. ISBN �˻�\n"); 
	printf(">>");
	scanf("%d",&NUM);
	return NUM;
}
void clist(){//ȸ�� ��� 
	int lnum;
	int i;
	char cname[10];
	char cnum[10];
	
	printf("**���� �˻�**");
	printf("\n");
	lnum=listmenu();
	
	switch(lnum){
		case 1:
			printf("�̸� �Է� : ");
			fflush(stdin);
			gets(cname);
			for(i=0; i<numofbook; i++){
				if(strcmp(client[i]->clientName,cname)==0){
					printf("�й� : %s\n",client[i]->clientNum); 
					printf("��й�ȣ : %s\n",client[i]->clientPw);
					printf("�̸� : %s\n",client[i]->clientName);
					printf("�ּ� : %s\n",client[i]->clientAddr);
					printf("��ȭ��ȣ : %s\n",client[i]->clientPhone);
					break;
				}
			}
			break;
		case 2:
			fflush(stdin);
			printf("�й� �Է� : ");
			gets(cnum);
			for(i=0; i<numofbook; i++){
				if(strcmp(client[i]->clientNum,cnum)==0){
					printf("�й� : %s\n",client[i]->clientNum); 
					printf("��й�ȣ : %s\n",client[i]->clientPw);
					printf("�̸� : %s\n",client[i]->clientName);
					printf("�ּ� : %s\n",client[i]->clientAddr);
					printf("��ȭ��ȣ : %s\n",client[i]->clientPhone);
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
			printf("�ٽ� �Է��ϼ���.");
	}
	
}
int listmenu(){
	int LISTNUM;
	printf("1. �̸� �˻�\n"); 
	printf("2. �й� �˻�\n");
	printf("3. ��ü �˻�\n");
	printf("4. ���� �˻�\n");
	printf(">>");
	scanf("%d",&LISTNUM);
	return LISTNUM; 
}


