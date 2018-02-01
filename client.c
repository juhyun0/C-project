#include "common.h"
#include "client.h"
#include "book.h"
#include "file.h"

//�������� 
extern BOOK **book;//���� 
extern int numofbook; //������ 

//�������� 
extern CLIENT **client;  //ȸ�� 
extern int numofclient;  //ȸ���� 
extern char g_userID[20]; 

//��������
extern BORROW **borrow;//�뿩 
extern int numofborrow; //�뿩�� 


extern char g_userID[20]; 

void joinClient(){ //ȸ�� ����ü �����͹迭�� ����

   if(numofclient==0){
   	client=(CLIENT **)malloc(sizeof(CLIENT*));
   }
   else {
   	client=(CLIENT **)realloc(client, (numofclient+1)*sizeof(CLIENT*));
   }
   client[numofclient++]=regClient();
}

CLIENT *regClient(){ //ȸ�������� ������ ����  

   CLIENT *pParam=(CLIENT *)malloc(sizeof(CLIENT)); 
   
   fflush(stdin);
   printf("�̸� : ");
   gets(pParam->clientName);
   
   fflush(stdin);
   printf("�й� : ");
   gets(pParam->clientNum);
   
   while(1){
	    fflush(stdin);
	    printf("���̵� : ");
	    gets(pParam->clientId);
		if(reID(pParam->clientId)==0){   
			break;
		}else{
			printf("���ο� ���̵� �Է��ϼ���.");
		}
    }
   
   fflush(stdin);
   printf("��й�ȣ : ");
   gets(pParam->clientPw);
   
   fflush(stdin);
   printf("�ּ� : ");
   gets(pParam->clientAddr);
   
   fflush(stdin);
   printf("��ȭ��ȣ : ");
   gets(pParam->clientPhone); 
   
   
   return pParam;
}
int reID(char *temp){
	int i;
	printf(" ȸ���� %d\n", numofclient); 
	for(i=0; i<numofclient-1; i++){
		if(strcmp(temp,client[i]->clientId)==0){
			return 1;
		}
	}
	return 0;
}
void listClient(){ //ȸ�� ��� 
	int i;
	for(i=0; i<numofclient; i++){
		printf("�й� : %s\n",client[i]->clientNum); 
		printf("���̵� : %s\n",client[i]->clientId);
		printf("��й�ȣ : %s\n",client[i]->clientPw);
		printf("�̸� : %s\n",client[i]->clientName);
		printf("�ּ� : %s\n",client[i]->clientAddr);
		printf("��ȭ��ȣ : %s\n",client[i]->clientPhone);
	}
}
void updateinfo(){//������������ 
	int i;
	for(i=0; i<numofclient; i++){
		if(strcmp(g_userID, client[i]->clientId)==0){
			printf("�й� : %s\n",client[i]->clientNum); 
			printf("�̸� : %s\n",client[i]->clientName);
			printf("��й�ȣ : %s\n",client[i]->clientPw);
			printf("�� ��й�ȣ �Է� : ");
			scanf("%s",client[i]->clientPw); 
			printf("�ּ� : %s\n",client[i]->clientAddr);
			printf("�� �ּ� �Է� : ");
			scanf("%s",client[i]->clientAddr);
			printf("��ȭ��ȣ : %s\n",client[i]->clientPhone);
			printf("�� ��ȭ��ȣ �Է� : ");
			scanf("%s",client[i]->clientPhone);
			break;
		}
	}
}
void booksrch(){//���� �˻�
	 int SCH;
	 int i;
	 char BNAME[20];
	 char BPUB[20];
	 char BISBN[20];
	 char BWRT[20];
	 printf("**���� �˻�**");
	 printf("\n");
	 SCH=schmenu();
	 printf("��ȣ�� �Է��ϼ��� : %d\n",SCH); 
	 switch(SCH){
	 	case 1:
		 	printf("������ �Է� : ");
		 	fflush(stdin);
			gets(BNAME);
			for(i=0; i<numofbook; i++){
				if(strcmp(book[i]->bookName,BNAME)==0){	
					printf("������ : %s\n",book[i]->bookName);
					printf("���ǻ� : %s\n",book[i]->bookPublisher);
					printf("���ڸ� : %s\n",book[i]->bookWriter);
					printf("ISBN : %s\n",book[i]->bookISBN);
					printf("����ó : %s\n",book[i]->bookHolding);
					break;
				}
			}
	     	break;
		case 2:
			printf("���ǻ�� �Է� : ");
		 	fflush(stdin);
			gets(BPUB);
			for(i=0; i<numofbook; i++){
				if(strcmp(book[i]->bookName,BPUB)==0){	
					printf("������ : %s\n",book[i]->bookName);
					printf("���ǻ� : %s\n",book[i]->bookPublisher);
					printf("���ڸ� : %s\n",book[i]->bookWriter);
					printf("ISBN : %s\n",book[i]->bookISBN);
					printf("����ó : %s\n",book[i]->bookHolding);
					break;
				}
			}
	     	break;
	    case 3:
	    	printf("ISBN �Է� : ");
		 	fflush(stdin);
			gets(BISBN);
			for(i=0; i<numofbook; i++){
				if(strcmp(book[i]->bookName,BISBN)==0){	
					printf("������ : %s\n",book[i]->bookName);
					printf("���ǻ� : %s\n",book[i]->bookPublisher);
					printf("���ڸ� : %s\n",book[i]->bookWriter);
					printf("ISBN : %s\n",book[i]->bookISBN);
					printf("����ó : %s\n",book[i]->bookHolding);
					break;
				}
			}
	     	break;
	    case 4:
	    	printf("���ڸ� �Է� : ");
		 	fflush(stdin);
			gets(BWRT);
			for(i=0; i<numofbook; i++){
				if(strcmp(book[i]->bookName,BWRT)==0){	
					printf("������ : %s\n",book[i]->bookName);
					printf("���ǻ� : %s\n",book[i]->bookPublisher);
					printf("���ڸ� : %s\n",book[i]->bookWriter);
					printf("ISBN : %s\n",book[i]->bookISBN);
					printf("����ó : %s\n",book[i]->bookHolding);
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
int schmenu(){//�����˻��޴� 
	int Bnum;
	printf("1. ������ �˻�\n");
	printf("2. ���ǻ�� �˻�\n");
	printf("3. ISBN �˻�\n");
	printf("4. ���ڸ� �˻�\n");
	printf("5. ��ü �˻�\n");
	printf("6. ������\n"); 
	scanf("%d",&Bnum);
	return Bnum;
}

void bye(){//ȸ��Ż�� **
	int i,j;
	char nID[10];
	char nPW[10];
	fflush(stdin);
	printf("ID �Է��ϼ���: ");
	gets(nID);
	fflush(stdin);
	printf("��й�ȣ �Է��ϼ���: ");
	gets(nPW);
	for(i=0; i<numofclient; i++){
		if(strcmp(client[i]->clientId,nID)==0 && strcmp(client[i]->clientPw,nPW)==0){
		     if(borrowcheck()==1){
				printf("�ݳ����� ���� ������ �ֽ��ϴ�!!\n");
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

void borrowlist(){//�� �뿩��� **
	
	int aa; 
	BORROW *bor=(BORROW *)malloc(sizeof(BORROW));
	
	for(aa=0; aa<numofborrow; aa++){
		if(strcmp(g_userID, borrow[aa]->bADMIN)==0){
		printf(" == %s",g_userID);	
		printf("������ : %s\n",borrow[aa]->bnamE);
		printf("ISBN : %s\n",borrow[aa]->bisbN);
		printf("�뿩�� : %d�� %d�� %d�� %d�� %d�� %d���Դϴ�.\n", 
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
		
		printf("�ݳ������� : %d�� %d�� %d�� %d�� %d�� %d���Դϴ�.\n", 
		borrow[aa]->reYear,borrow[aa]->reMon,borrow[aa]->reDay,borrow[aa]->reHour,borrow[aa]->reMin,borrow[aa]->reSec);
		}
	}
}

